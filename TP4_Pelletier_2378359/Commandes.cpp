#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Constantes.h"
#include "chaine.h"
#include "Lecture.h"
#include "Commandes.h"

using namespace std;

// Lit une commande au clavier, valide qu'elle existe, et retourne la commande complète
string verifierCommande(string& commandeDonner, const string& prompt)
{
    const vector<string> commandesValides = {
        "help",
        "exit",
        "exit",
        "ls",
        "cd",
        "mkdir",
        "rmdir",
        "touch",
        "rm",
        "cat",
        "tee",
        "$",
        "passwd",
    };

    while (true)
    {
        cout << prompt;
        getline(cin, commandeDonner);

        // Si la lecture échoue (EOF ou autre), on affiche une erreur
        if (cin.fail())
        {
            cout << format("Erreur : Commande inconnue {}, utiliser la commande 'help' pour voir les commandes disponibles\n", commandeDonner);
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Mise en forme de la commande (minuscules + trim)
        commandeDonner = toLower(commandeDonner);
        commandeDonner = trim(commandeDonner);

        if (commandeDonner.empty())
        {
            std::cout << "Erreur : Commande vide.\n";
            continue;
        }

        // Découpe la commande en mots (commande + arguments)
        vector<string> tokens = split(commandeDonner, ' ');

        if (tokens.empty())
        {
            std::cout << "Erreur : Commande vide.\n";
            continue;
        }

        string commande = tokens[0];

        // Vérifie si la commande existe dans la liste des commandes valides
        bool existe = find(commandesValides.begin(), commandesValides.end(), commande) != commandesValides.end();

        if (!existe)
        {
            std::cout << format("Erreur : Commande inconnue '{}', utiliser la commande 'help' pour voir les commandes disponibles\n", commande);
            continue;
        }

        // Cas spécial : exit pour sortir de la boucle principale
        if (commande == "exit")
        {
            return "exit";
        }

        // Retourne la commande complète (avec les arguments)
        return commandeDonner;
    }
}

// Affiche la liste des commandes disponibles pour l'utilisateur courant
void commandeHelp(int id)
{
    cout << "*** Commande disponnibles ***\n\n";

    cout << "exit\t\t\t\t\t : Deconnecter l'utilisateur connecte\n";
    cout << "ls\t\t\t\t\t : Changer le dossier actuel\n";
    cout << "cd <dossier> \t\t\t\t : Afficher le contenu du dossier actuel\n";
    cout << "mkdir <dossier> [<dossier>...]\t\t : Creer un ou plusieurs dossiers\n";
    cout << "rmdir <dossier> [<dossier>...]\t\t : Supprimer un ou plusieurs dossiers\n";
    cout << "touch <fichier> [<fichier>...]\t\t : Creer un ou plusieurs fichiers\n";
    cout << "rm <fichier> [<fichier>...]\t\t : Supprimer un ou plusieurs fichiers\n";
    cout << "cat <fichier>\t\t\t\t : Afficher le contenu d'un fichier\n";
    cout << "tee <fichier>\t\t\t\t : Ajouter du texte a la fin d'un fichier jusqu'au symbole de fin '$'\n";
    cout << "passwd <ancien-mdp> <nouveau-mdp>\t : Changer le mot de passe de l'utilisateur connecte\n\n";

    // Commandes réservées à l'admin (id 1000)
    if (id == 1000)
    {
        cout << "adduser <nom> <mot-passe>\t\t : Ajouter un utilisateur\n";
        cout << "deluser <nom>\t\t\t\t : Supprimer un utilisateur\n";
    }
}

// Affiche le contenu du dossier courant (dossiers et fichiers)
void commandeLs(const vector<Dossiers>& dossiers, const vector<Fichiers>& fichiers, int id)
{
    // Affiche les dossiers
    for (int i = 0; i < dossiers.size(); i++)
    {
        if (dossiers[i].identifiantDossierParent == -1)
        {
            cout << format("\ndrwx{} {} \t\t  0 {} ..\n", dossiers[i].permissions, dossiers[2].nomDossier, fichiers[i].timestamp);
        }
    }

    // Affiche les fichiers appartenant à l'utilisateur
    for (int i = 0; i < fichiers.size(); i++)
    {
        if (fichiers[i].identifiantProprietaire == id)
        {
            // S'il y a un '.' dans le nom, on considère que c'est un fichier normal
            if (fichiers[i].nomFichier.find('.') != string::npos)
            {
                cout << format("-rwx{} {} \t\t {} {} {}\n", fichiers[i].permissions, dossiers[i].nomDossier, fichiers[i].contenuTexte.size(), fichiers[i].timestamp, fichiers[i].nomFichier);
            }
            else
            {
                // Sinon on l'affiche comme un "dossier"
                cout << format("drwx{} {} \t\t 0 {} {}\n", fichiers[i].permissions, dossiers[i].nomDossier, fichiers[i].timestamp, fichiers[i].nomFichier);
            }
        }
    }
}

// Change de dossier (pour l'instant seulement vérification des droits)
void commandeCd(const vector<Dossiers>& dossiers, int& idDossierCourant, int idUtilisateur)
{
    // Vérifie si l'utilisateur a le droit de lecture sur le dossier
    aDroitLecture(dossiers, idUtilisateur);

    if (aDroitLecture(dossiers, idUtilisateur) == false)
    {
        cout << format("Erreur : acces refuse en lecture pour le dossier {}.", dossiers[1].nomDossier);
    }
}

// Vérifie si l'utilisateur a le droit de lecture sur au moins un dossier
bool aDroitLecture(const vector<Dossiers>& dossiers, int idUtilisateur)
{
    // root a toujours les droits
    if (idUtilisateur == 0)
    {
        return true;
    }

    for (int i = 0; i < dossiers.size(); i++)
    {
        // Propriétaire du dossier
        if (dossiers[i].identifiantProprietaire == idUtilisateur)
        {
            return true;
        }

        // Permission de lecture (r)
        if (!dossiers[i].permissions.empty() && dossiers[i].permissions[0] == 'r')
        {
            return true;
        }
    }

    return false;
}

// Crée un ou plusieurs dossiers dans le dossier courant
void commandeMkdir(vector<Dossiers>& dossiers, int& idDossierCourant, int idUtilisateur, const vector<string>& arguments)
{
    if (arguments.empty())
    {
        cout << "Erreur : la commande 'mkdir' doit avoir au moins 1 argument.\n";
        return;
    }

    for (size_t i = 0; i < arguments.size(); i++)
    {
        string nomNouveauDossier = arguments[i];
        bool existeDeja = false;

        // Vérifie si le dossier existe déjà dans le dossier courant
        for (size_t j = 0; j < dossiers.size(); j++)
        {
            const Dossiers& dossier = dossiers[j];

            if (dossier.nomDossier == nomNouveauDossier &&
                dossier.identifiantDossierParent == idDossierCourant)
            {
                existeDeja = true;
                break;
            }
        }

        if (existeDeja)
        {
            cout << format("Erreur : le dossier {} existe déjà.\n", nomNouveauDossier);
            continue;
        }

        // Création du nouveau dossier
        Dossiers nouveauDossier;
        nouveauDossier.identifiantDossier = static_cast<int>(dossiers.size()) + 1;
        nouveauDossier.nomDossier = nomNouveauDossier;
        nouveauDossier.identifiantProprietaire = idUtilisateur;
        nouveauDossier.identifiantDossierParent = idDossierCourant;
        nouveauDossier.timestamp = static_cast<double>(time(0));
        nouveauDossier.permissions = "rwx";

        dossiers.push_back(nouveauDossier);
        cout << format("Le dossier '{}' à été créé avec succes.\n", nomNouveauDossier);
    }
}

// Supprime un ou plusieurs dossiers dans le dossier courant
void commandeRmdir(vector<Dossiers>& dossiers, int idDossierCourant, int idUtilisateur, const vector<string>& arguments)
{
    if (arguments.empty())
    {
        cout << "Erreur : la commande 'rmdir' doit avoir au moins 1 argument.\n";
        return;
    }

    for (size_t i = 0; i < arguments.size(); i++)
    {
        string nomDossierASupprimer = arguments[i];
        bool trouve = false;
        size_t indexTrouve = 0;

        // Recherche du dossier à supprimer
        for (size_t j = 0; j < dossiers.size(); j++)
        {
            if (dossiers[j].nomDossier == nomDossierASupprimer &&
                dossiers[j].identifiantDossierParent == idDossierCourant)
            {
                trouve = true;
                indexTrouve = j;
                break;
            }
        }

        if (!trouve)
        {
            cout << format("Erreur : le dossier {} n’existe pas.\n", nomDossierASupprimer);
            continue;
        }

        // Vérifie que l'utilisateur est propriétaire (ou admin selon ta logique)
        if (dossiers[indexTrouve].identifiantProprietaire != idUtilisateur)
        {
            cout << format("Erreur : acces refuse en ecriture pour le dossier {}. \n", nomDossierASupprimer);
            continue;
        }

        // Suppression du dossier
        dossiers.erase(dossiers.begin() + indexTrouve);
        cout << format("Le dossier '{}' a ete supprime avec succes.\n", nomDossierASupprimer);
    }
}

// Crée un ou plusieurs fichiers vides dans le dossier courant
void commandeTouch(vector<Fichiers>& fichiers, int& idDossierCourant, int idUtilisateur, const vector<string>& arguments)
{
    if (arguments.empty())
    {
        cout << "Erreur : la commande 'touch' doit avoir au moins 1 argument.\n";
        return;
    }

    for (size_t i = 0; i < arguments.size(); i++)
    {
        string nomNouveauFichier = arguments[i];
        bool existeDeja = false;

        // Vérifie si le fichier existe déjà dans le dossier courant
        for (size_t j = 0; j < fichiers.size(); j++)
        {
            const Fichiers& fichier = fichiers[j];
            if (fichier.nomFichier == nomNouveauFichier &&
                fichier.identifiantDossierParent == idDossierCourant)
            {
                existeDeja = true;
                break;
            }
        }

        if (existeDeja)
        {
            cout << format("Erreur : le fichier {} existe deja.\n", nomNouveauFichier);
            continue;
        }

        // Création du nouveau fichier
        Fichiers nouveauFichier;
        nouveauFichier.identifiantFichier = static_cast<int>(fichiers.size()) + 1;
        nouveauFichier.nomFichier = nomNouveauFichier;
        nouveauFichier.identifiantProprietaire = idUtilisateur;
        nouveauFichier.identifiantDossierParent = idDossierCourant;
        nouveauFichier.timestamp = static_cast<double>(time(0));
        nouveauFichier.permissions = "rwx";
        nouveauFichier.contenuTexte = "";

        fichiers.push_back(nouveauFichier);
        cout << format("Le fichier '{}' a été créé avec succes.\n", nomNouveauFichier);
    }
}

// Supprime un ou plusieurs fichiers dans le dossier courant
void commandeRm(vector<Fichiers>& fichiers, int idDossierCourant, int idUtilisateur, const vector<string>& arguments)
{
    if (arguments.empty())
    {
        cout << "Erreur : la commande 'rm' doit avoir au moins 1 argument.\n";
        return;
    }

    for (size_t i = 0; i < arguments.size(); i++)
    {
        string nomFichierASupprimer = arguments[i];
        bool trouve = false;
        size_t indexTrouve = 0;

        // Recherche du fichier à supprimer
        for (size_t j = 0; j < fichiers.size(); j++)
        {
            if (fichiers[j].nomFichier == nomFichierASupprimer &&
                fichiers[j].identifiantDossierParent == idDossierCourant)
            {
                trouve = true;
                indexTrouve = j;
                break;
            }
        }

        if (!trouve)
        {
            cout << format("Erreur : le fichier '{}' n'existe pas.\n", nomFichierASupprimer);
            continue;
        }

        // Vérifie les droits : propriétaire ou root (id 0)
        if (fichiers[indexTrouve].identifiantProprietaire != idUtilisateur && idUtilisateur != 0)
        {
            cout << format("Erreur : Vous n'avez pas la permission de supprimer le fichier '{}'.\n", nomFichierASupprimer);
            continue;
        }

        fichiers.erase(fichiers.begin() + indexTrouve);
        cout << format("Le fichier '{}' à été supprimé avec succes.\n", nomFichierASupprimer);
    }
}

// Remplace les séquences %0A par des retours à la ligne
string decoderPercentA(const string& texte)
{
    string resultat;

    for (size_t i = 0; i < texte.size(); i++)
    {
        if (texte[i] == '%' && i + 2 < texte.size() &&
            texte[i + 1] == '0' &&
            (texte[i + 2] == 'A' || texte[i + 2] == 'a'))
        {
            resultat += '\n';
            i += 2; // saute les caractères '0' et 'A'
        }
        else
        {
            resultat += texte[i];
        }
    }

    return resultat;
}

// Affiche le contenu d'un fichier si l'utilisateur a les droits
void commandeCat(const vector<Fichiers>& fichiers, int idDossierCourant, int idUtilisateur, const vector<string>& arguments)
{
    if (arguments.size() != 1)
    {
        cout << "Erreur : la commande 'cat' doit avoir 1 argument.\n";
        return;
    }

    string nomFichierAAfficher = arguments[0];
    bool trouve = false;

    for (size_t i = 0; i < fichiers.size(); i++)
    {
        if (fichiers[i].nomFichier == nomFichierAAfficher && fichiers[i].identifiantDossierParent == idDossierCourant)
        {
            trouve = true;

            // Vérifie les droits de lecture (root, propriétaire ou 'r')
            bool aDroitLecture = false;

            if (idUtilisateur == 0)
            {
                aDroitLecture = true;
            }
            else if (fichiers[i].identifiantProprietaire == idUtilisateur)
            {
                aDroitLecture = true;
            }
            else if (!fichiers[i].permissions.empty() && fichiers[i].permissions[0] == 'r')
            {
                aDroitLecture = true;
            }

            if (!aDroitLecture)
            {
                cout << format("Erreur : acces refuse en lecture pour le fichier '{}'.\n", nomFichierAAfficher);
                return;
            }

            // Décodage du contenu avant affichage
            string contenuDecode = decoderPercentA(fichiers[i].contenuTexte);

            cout << format("Contenu du fichier '{}':\n{}\n", nomFichierAAfficher, contenuDecode);
            return;
        }
    }

    if (!trouve)
    {
        cout << format("Erreur : le fichier '{}' n'existe pas.\n", nomFichierAAfficher);
    }
}

// Ajoute du texte à la fin d'un fichier jusqu'à la ligne contenant seulement '$'
void commandeTee(vector<Fichiers>& fichiers, int idDossierCourant, int idUtilisateur, const vector<string>& arguments)
{
    if (arguments.size() != 1)
    {
        cout << "Erreur : la commande 'tee' doit avoir 1 argument.\n";
        return;
    }

    string nomFichierAAjouterTexte = arguments[0];
    bool trouve = false;

    for (size_t i = 0; i < fichiers.size(); i++)
    {
        if (fichiers[i].nomFichier == nomFichierAAjouterTexte && fichiers[i].identifiantDossierParent == idDossierCourant)
        {
            trouve = true;

            // Vérifie les droits d'écriture (root, propriétaire ou 'w')
            bool aDroitEcriture = false;
            if (idUtilisateur == 0)
            {
                aDroitEcriture = true;
            }
            else if (fichiers[i].identifiantProprietaire == idUtilisateur)
            {
                aDroitEcriture = true;
            }
            else if (!fichiers[i].permissions.empty() && fichiers[i].permissions.size() > 1 && fichiers[i].permissions[1] == 'w')
            {
                aDroitEcriture = true;
            }

            if (!aDroitEcriture)
            {
                cout << format("Erreur : acces refuse en ecriture pour le fichier '{}'.\n", nomFichierAAjouterTexte);
                return;
            }

            cout << "Entrez le texte a ajouter au fichier (terminer par '$' sur une nouvelle ligne) :\n";

            string ligne;
            string texteAAjouter;

            // Lecture du texte à ajouter, ligne par ligne
            while (true)
            {
                getline(cin, ligne);
                if (ligne == "$")
                {
                    break;
                }
                texteAAjouter += ligne + "%0A";
            }

            fichiers[i].contenuTexte += texteAAjouter;
            fichiers[i].timestamp = static_cast<double>(time(0));

            cout << format("Le texte a ete ajoute avec succes au fichier '{}'.\n", nomFichierAAjouterTexte);
            return;
        }
    }

    if (!trouve)
    {
        cout << format("Erreur : le fichier '{}' n'existe pas.\n", nomFichierAAjouterTexte);
    }
}

// Change le mot de passe de l'utilisateur courant
void commandePasswd(vector<Utilisateurs>& utilisateurs, int idUtilisateur, const vector<string>& arguments)
{
    if (arguments.size() != 2)
    {
        cout << "Erreur : la commande 'passwd' doit avoir 2 arguments.\n";
        return;
    }

    string ancienMotDePasse = arguments[0];
    string nouveauMotDePasse = arguments[1];

    for (size_t i = 0; i < utilisateurs.size(); i++)
    {
        if (utilisateurs[i].identifiantUtilisateur == idUtilisateur)
        {
            if (utilisateurs[i].motDePasse != ancienMotDePasse)
            {
                cout << "Erreur : ancien mot de passe incorrect.\n";
                return;
            }

            utilisateurs[i].motDePasse = nouveauMotDePasse;
            cout << "Le mot de passe a ete change avec succes.\n";
            return;
        }
    }

    cout << "Erreur : utilisateur non trouve.\n";
}

// Ajoute un nouvel utilisateur (nom + mot de passe)
void commandeAdduser(vector<Utilisateurs>& utilisateurs, const vector<string>& arguments)
{
    if (arguments.size() != 2)
    {
        cout << "Erreur : la commande 'adduser' doit avoir 2 arguments.\n";
        return;
    }

    string nomNouvelUtilisateur = arguments[0];
    string motDePasseNouvelUtilisateur = arguments[1];

    // Vérifie si le nom existe déjà
    for (size_t i = 0; i < utilisateurs.size(); i++)
    {
        if (utilisateurs[i].nomUtilisateur == nomNouvelUtilisateur)
        {
            cout << format("Erreur : l'utilisateur '{}' existe deja.\n", nomNouvelUtilisateur);
            return;
        }
    }

    Utilisateurs nouvelUtilisateur;
    nouvelUtilisateur.identifiantUtilisateur = static_cast<int>(utilisateurs.size()) + 1;
    nouvelUtilisateur.nomUtilisateur = nomNouvelUtilisateur;
    nouvelUtilisateur.motDePasse = motDePasseNouvelUtilisateur;

    utilisateurs.push_back(nouvelUtilisateur);
    cout << format("L'utilisateur '{}' a ete ajoute avec succes.\n", nomNouvelUtilisateur);
}

// Supprime un utilisateur existant
void commandeDeluser(vector<Utilisateurs>& utilisateurs, const vector<string>& arguments)
{
    if (arguments.size() != 1)
    {
        cout << "Erreur : la commande 'deluser' doit avoir 1 argument.\n";
        return;
    }

    string nomUtilisateurASupprimer = arguments[0];

    for (size_t i = 0; i < utilisateurs.size(); i++)
    {
        if (utilisateurs[i].nomUtilisateur == nomUtilisateurASupprimer)
        {
            utilisateurs.erase(utilisateurs.begin() + i);
            cout << format("L'utilisateur '{}' a ete supprime avec succes.\n", nomUtilisateurASupprimer);
            return;
        }
    }

    cout << format("Erreur : l'utilisateur '{}' n'existe pas.\n", nomUtilisateurASupprimer);
}
