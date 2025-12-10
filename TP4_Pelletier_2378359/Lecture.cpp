#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Constantes.h"
#include "chaine.h"
#include "Lecture.h"

using namespace std;

// Lit le fichier des utilisateurs et retourne seulement ceux qui sont valides
vector<Utilisateurs> lireFichierUtilisateurs(const string& nomFichier)
{
    vector<Utilisateurs> utilisateurs;

    ifstream fichierDossiers;
    fichierDossiers.open(nomFichier, ios::in);

    // Vérifie si le fichier s'ouvre correctement
    if (!fichierDossiers.is_open())
    {
        cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en lecture.\n", nomFichier);
        return utilisateurs;
    }

    int compteurLigne = 0;
    string ligne;

    // Lecture ligne par ligne du fichier
    while (getline(fichierDossiers, ligne))
    {
        ++compteurLigne;

        // Sépare la ligne en champs (id, nom, mot de passe)
        vector<string> tokens = split(ligne, ',');

        // On s'attend à 3 valeurs par ligne
        if (tokens.size() != 3)
        {
            cout << format("Erreur : Ligne {} - Nombre delimiteurs invalide: {} - {}\n", compteurLigne, tokens.size(), ligne);
            continue;
        }

        Utilisateurs utilisateur;

        // Conversion de l'id en int
        if (!tryParseInt(tokens[0], utilisateur.identifiantUtilisateur))
        {
            cout << format("Erreur : Ligne {} - id invalide : {}\n", compteurLigne, tokens[2]);
            continue;
        }

        // Vérifie que le nom d'utilisateur n'est pas vide
        if (tokens[1].empty())
        {
            cout << format("Erreur : Ligne {} - utilisateur vide.\n", compteurLigne);
            continue;
        }
        utilisateur.nomUtilisateur = tokens[1];

        // Vérifie que le mot de passe n'est pas vide
        if (tokens[2].empty())
        {
            cout << format("Erreur : Ligne {} - utilisateur vide.\n", compteurLigne);
            continue;
        }
        utilisateur.motDePasse = tokens[2];

        // Ajoute l'utilisateur au vecteur
        utilisateurs.push_back(utilisateur);
    }

    // Ferme le fichier après la lecture
    fichierDossiers.close();

    return utilisateurs;
}

// Lit le fichier des dossiers et construit le vecteur de Dossiers
vector<Dossiers> lireFichierDossiers(const string& nomFichier)
{
    vector<Dossiers> dossiers;

    ifstream fichierDossiers;
    fichierDossiers.open(nomFichier, ios::in);

    if (!fichierDossiers.is_open())
    {
        cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en lecture.\n", nomFichier);
        return dossiers;
    }

    int compteurLigne = 0;
    string ligne;

    while (getline(fichierDossiers, ligne))
    {
        ++compteurLigne;

        // Sépare la ligne en champs avec ';'
        vector<string> tokens = split(ligne, ';');

        // On attend 6 champs pour un dossier
        if (tokens.size() != 6)
        {
            cout << format("Erreur : Ligne {} - Nombre delimiteurs invalide: {} - {}\n", compteurLigne, tokens.size(), ligne);
            continue;
        }

        Dossiers dossier;

        // identifiant du dossier
        if (!tryParseInt(tokens[0], dossier.identifiantDossier))
        {
            cout << format("Erreur : Ligne {} - id invalide : {}\n", compteurLigne, tokens[2]);
            continue;
        }

        if (tokens[1].empty())
        {
            cout << format("Erreur : Ligne {} - dossiers vide.\n", compteurLigne);
            continue;
        }
        dossier.nomDossier = tokens[1];

        // proprietaire du dossier
        if (!tryParseInt(tokens[2], dossier.identifiantProprietaire))
        {
            cout << format("Erreur : Ligne {} - identifiant Proprietaire invalide : {}\n", compteurLigne, tokens[2]);
            continue;
        }

        // dossier parent
        if (!tryParseInt(tokens[3], dossier.identifiantDossierParent))
        {
            cout << format("Erreur : Ligne {} - identifiant Dossier Parent invalide: {}\n", compteurLigne, tokens[3]);
            continue;
        }

        // timestamp
        if (!tryParseDouble(tokens[4], dossier.timestamp))
        {
            cout << format("Erreur : Ligne {} - timestamp invalide: {}\n", compteurLigne, tokens[3]);
            continue;
        }

        // permissions (rwx)
        if (tokens[5].empty())
        {
            cout << format("Erreur : Ligne {} - Dossier vide.\n", compteurLigne);
            continue;
        }
        dossier.permissions = tokens[5];

        // Ajoute le dossier valide
        dossiers.push_back(dossier);
    }

    fichierDossiers.close();

    return dossiers;
}

// Lit le fichier des fichiers et crée le vecteur de Fichiers
vector<Fichiers> lireFichierFichiers(const string& nomFichier)
{
    vector<Fichiers> fichiers;

    ifstream fichierFichiers;
    fichierFichiers.open(nomFichier, ios::in);

    if (!fichierFichiers.is_open())
    {
        cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en lecture.\n", nomFichier);
        return fichiers;
    }

    int compteurLigne = 0;
    string ligne;

    while (getline(fichierFichiers, ligne))
    {
        ++compteurLigne;

        // Découpe les champs avec '|'
        vector<string> tokens = split(ligne, '|');

        // 7 champs attendus pour un fichier
        if (tokens.size() != 7)
        {
            cout << format("Erreur : Ligne {} - Nombre delimiteurs invalide: {} - {}\n", compteurLigne, tokens.size(), ligne);
            continue;
        }

        Fichiers fichier;

        // id fichier
        if (!tryParseInt(tokens[0], fichier.identifiantFichier))
        {
            cout << format("Erreur : Ligne {} - identifiant Fichier invalide : {}\n", compteurLigne, tokens[2]);
            continue;
        }

        // nom fichier
        if (tokens[1].empty())
        {
            cout << format("Erreur : Ligne {} - nom Fichier vide.\n", compteurLigne);
            continue;
        }
        fichier.nomFichier = tokens[1];

        // proprietaire
        if (!tryParseInt(tokens[2], fichier.identifiantProprietaire))
        {
            cout << format("Erreur : Ligne {} - identifiant Proprietaire invalide : {}\n", compteurLigne, tokens[2]);
            continue;
        }

        // dossier parent
        if (!tryParseInt(tokens[3], fichier.identifiantDossierParent))
        {
            cout << format("Erreur : Ligne {} - identifiant Dossier Parent invalide : {}\n", compteurLigne, tokens[3]);
            continue;
        }

        // timestamp
        if (!tryParseDouble(tokens[4], fichier.timestamp))
        {
            cout << format("Erreur : Ligne {} - timestamp invalide : {}\n", compteurLigne, tokens[3]);
            continue;
        }

        // permissions
        if (tokens[5].empty())
        {
            cout << format("Erreur : Ligne {} - permissions vide.\n", compteurLigne);
            continue;
        }
        fichier.permissions = tokens[5];

        // contenu du fichier (peut être vide dans certains cas, mais ici tu le refuses)
        if (tokens[6].empty())
        {
            cout << format("Erreur : Ligne {} - contenuTexte vide.\n", compteurLigne);
            continue;
        }
        fichier.contenuTexte = tokens[6];

        // Ajoute le fichier valide
        fichiers.push_back(fichier);
    }

    fichierFichiers.close();

    return fichiers;
}

// Affiche le menu d'accueil + un petit résumé du système de fichiers
void afficherMenu(const vector<Utilisateurs>& utilisateurs, vector<Dossiers>& dossier, vector<Fichiers>& fichiers)
{
    cout << "**************************************************************"
        << "\n*\t\tSysteme de gestion de fichiers\t\t     *"
        << "\n*\t\tPar Pelletier (2378359)\t\t\t     *"
        << "\n**************************************************************";

    cout << "\n\nSysteme de fichier : \n"
        << utilisateurs.size() << " utilisateurs valides, "
        << dossier.size() << " dossiers valides, "
        << fichiers.size() << " fichiers valides";
}

// Demande un nom d'utilisateur et un mot de passe, puis retourne son id ou -1
int rechercherUtilisateur(vector<Utilisateurs>& utilisateurs)
{
    string nomUtilisateur;
    cout << "\n\nNom utilisateur : ";
    getline(cin, nomUtilisateur);

    string motDePasse;
    cout << "Mot de passe : ";
    getline(cin, motDePasse);

    // Parcourt tous les utilisateurs pour trouver une correspondance
    for (int i = 0; i < utilisateurs.size(); i++)
    {
        if (utilisateurs[i].nomUtilisateur == nomUtilisateur &&
            utilisateurs[i].motDePasse == motDePasse)
        {
            return utilisateurs[i].identifiantUtilisateur;
        }
    }

    cout << "Erreur : Nom utilisateur ou mot de passe invalide.";
    return -1;
}

// Génère le prompt (user@/home/user: ) selon l'utilisateur connecté
string genererChemin2(const vector<Dossiers>& dossiers, int id, string& prompt)
{
    // Cas spécial pour root (id 1000 dans ton système)
    if (id == 1000)
    {
        string promptLocal = "\n" + dossiers[2].nomDossier + "@/" + dossiers[1].nomDossier + "/" + dossiers[2].nomDossier + ": ";
        cout << promptLocal;
        prompt = promptLocal;
        return promptLocal;
    }
    else
    {
        // Cherche le dossier correspondant à l'utilisateur courant
        for (int i = 0; i < dossiers.size(); i++)
        {
            if (dossiers[i].identifiantProprietaire == id)
            {
                string promptLocal = "\n" + dossiers[i].nomDossier + "@/" + dossiers[1].nomDossier + "/" + dossiers[i].nomDossier + ": ";
                cout << promptLocal;
                prompt = promptLocal;
                return promptLocal;
            }
        }
    }

    // Si rien trouvé, retourne une chaîne vide
    return "";
}
