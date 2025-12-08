#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Constantes.h"
#include "chaine.h"
#include "Lecture.h"

using namespace std;


vector<Utilisateurs> lireFichierUtilisateurs(const string& nomFichier)
{
	vector<Utilisateurs> utilisateurs;

	ifstream fichierDossiers;
	fichierDossiers.open(nomFichier, ios::in);

	if (!fichierDossiers.is_open())
	{
		cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en lecture.\n", nomFichier);
		return utilisateurs;
	}

	// Lire chaque ligne du fichier et tenter de convertir le texte en une instance de la struct 'Livre'
	int compteurLigne = 0;
	string ligne;
	while (getline(fichierDossiers, ligne))
	{
		++compteurLigne;

		// TODO: Séparer la ligne en tokens avec la fonction 'split()' en utilisant la virgule comme délimiteur ','
		vector<string> tokens = split(ligne, ',');

		// TODO: Vérifier le nombre de tokens attendus
		if (tokens.size() != 3)
		{
			cout << format("Erreur : Ligne {} - Nombre delimiteurs invalide: {} - {}\n", compteurLigne, tokens.size(), ligne);
			continue;
		}

		// TODO: Créer une instance de 'Livre'
		Utilisateurs utilisateur;

		if (!tryParseInt(tokens[0], utilisateur.identifiantUtilisateur))
		{
			cout << format("Erreur : Ligne {} - id invalide : {}\n", compteurLigne, tokens[2]);
			continue;
		}

		if (tokens[1].empty())
		{
			cout << format("Erreur : Ligne {} - utilisateur vide.\n", compteurLigne);
			continue;
		}
		utilisateur.nomUtilisateur = tokens[1];

		if (tokens[2].empty())
		{
			cout << format("Erreur : Ligne {} - utilisateur vide.\n", compteurLigne);
			continue;
		}
		utilisateur.motDePasse = tokens[2];

		// TODO: Ajouter le livre au vefcteur des livres valides
		utilisateurs.push_back(utilisateur);
	}

	// Fermer le fichier après la lecture des livres
	fichierDossiers.close();

	return utilisateurs;
}

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

	// Lire chaque ligne du fichier et tenter de convertir le texte en une instance de la struct 'Livre'
	int compteurLigne = 0;
	string ligne;
	while (getline(fichierDossiers, ligne))
	{
		++compteurLigne;

		// TODO: Séparer la ligne en tokens avec la fonction 'split()' en utilisant la virgule comme délimiteur ','
		vector<string> tokens = split(ligne, ';');

		// TODO: Vérifier le nombre de tokens attendus
		if (tokens.size() != 6)
		{
			cout << format("Erreur : Ligne {} - Nombre delimiteurs invalide: {} - {}\n", compteurLigne, tokens.size(), ligne);
			continue;
		}

		// TODO: Créer une instance de 'Livre'
		Dossiers dossier;

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

		// TODO: Pour les champs 'int' et 'double', utiliser les fonctions 'tryParse' pour convertir les chaînes en nombres
		if (!tryParseInt(tokens[2], dossier.identifiantProprietaire))
		{
			cout << format("Erreur : Ligne {} - identifiant Proprietaire invalide : {}\n", compteurLigne, tokens[2]);
			continue;
		}

		if (!tryParseInt(tokens[3], dossier.identifiantDossierParent))
		{
			cout << format("Erreur : Ligne {} - identifiant Dossier Parent invalide: {}\n", compteurLigne, tokens[3]);
			continue;
		}

		if (!tryParseDouble(tokens[4], dossier.timestamp))
		{
			cout << format("Erreur : Ligne {} - timestamp invalide: {}\n", compteurLigne, tokens[3]);
			continue;
		}

		if (tokens[5].empty())
		{
			cout << format("Erreur : Ligne {} - Dossier vide.\n", compteurLigne);
			continue;
		}

		dossier.permissions = tokens[5];

		// TODO: Ajouter le livre au vefcteur des livres valides
		dossiers.push_back(dossier);
	}

	// Fermer le fichier après la lecture des livres
	fichierDossiers.close();

	return dossiers;
}

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

	// Lire chaque ligne du fichier et tenter de convertir le texte en une instance de la struct 'Livre'
	int compteurLigne = 0;
	string ligne;
	while (getline(fichierFichiers, ligne))
	{
		++compteurLigne;

		// TODO: Séparer la ligne en tokens avec la fonction 'split()' en utilisant la virgule comme délimiteur ','
		vector<string> tokens = split(ligne, '|');

		// TODO: Vérifier le nombre de tokens attendus
		if (tokens.size() != 7)
		{
			cout << format("Erreur : Ligne {} - Nombre delimiteurs invalide: {} - {}\n", compteurLigne, tokens.size(), ligne);
			continue;
		}

		// TODO: Créer une instance de 'Livre'
		Fichiers fichier;

		if (!tryParseInt(tokens[0], fichier.identifiantFichier))
		{
			cout << format("Erreur : Ligne {} - identifiant Fichier invalide : {}\n", compteurLigne, tokens[2]);
			continue;
		}

		if (tokens[1].empty())
		{
			cout << format("Erreur : Ligne {} - nom Fichier vide.\n", compteurLigne);
			continue;
		}

		fichier.nomFichier = tokens[1];

		// TODO: Pour les champs 'int' et 'double', utiliser les fonctions 'tryParse' pour convertir les chaînes en nombres
		if (!tryParseInt(tokens[2], fichier.identifiantProprietaire))
		{
			cout << format("Erreur : Ligne {} - identifiant Proprietaire invalide : {}\n", compteurLigne, tokens[2]);
			continue;
		}

		if (!tryParseInt(tokens[3], fichier.identifiantDossierParent))
		{
			cout << format("Erreur : Ligne {} - identifiant Dossier Parent invalide : {}\n", compteurLigne, tokens[3]);
			continue;
		}

		if (!tryParseDouble(tokens[4], fichier.timestamp))
		{
			cout << format("Erreur : Ligne {} - timestamp invalide : {}\n", compteurLigne, tokens[3]);
			continue;
		}

		if (tokens[5].empty())
		{
			cout << format("Erreur : Ligne {} - permissions vide.\n", compteurLigne);
			continue;
		}
		fichier.permissions = tokens[5];

		if (tokens[6].empty())
		{
			cout << format("Erreur : Ligne {} - contenuTexte vide.\n", compteurLigne);
			continue;
		}
		fichier.permissions = tokens[6];

		// TODO: Ajouter le livre au vefcteur des livres valides
		fichiers.push_back(fichier);
	}

	// Fermer le fichier après la lecture des livres
	fichierFichiers.close();

	return fichiers;
}


void afficherMenu(const vector<Utilisateurs>& utilisateurs, vector<Dossiers>& dossier, vector<Fichiers>& fichiers) 
{

	cout << "**************************************************************"
		<< "\n*\t\tSysteme de gestion de fichiers\t\t     *"
		<< "\n*\t\tPar Pelletier (2378359)\t\t\t     *"
		<< "\n**************************************************************";
	cout << "\n\n" << "Systeme de fichier : \n" << utilisateurs.size() << " utilisateurs valides, " 
		<< dossier.size() << " dossiers valides, " << fichiers.size() << " fichiers valides";
}

int rechercherUtilisateur(vector<Utilisateurs>& utilisateurs)
{
	string nomUtilisateur;
	cout << "\n\nNom utilisateur : ";
	getline(cin, nomUtilisateur);

	string motDePasse;
	cout << "Mot de passe : ";
	getline(cin, motDePasse);

	Utilisateurs utilisateurActuel;


	for (int i = 0; i < utilisateurs.size(); i++)
	{
		if (utilisateurs[i].nomUtilisateur == nomUtilisateur &&
			utilisateurs[i].motDePasse == motDePasse)
		{
			{
				return utilisateurs[i].identifiantUtilisateur;
			}
		}
	}
	cout << "Erreur : Nom utilisateur ou mot de passe invalide.";
	return -1;
}

string genererChemin2(const vector<Dossiers>& dossiers, int id, string& prompt)
{

	if (id == 1000)
	{
		string prompt = "\n" + dossiers[2].nomDossier + "@/" + dossiers[1].nomDossier + "/" + dossiers[2].nomDossier + ": ";
		cout << prompt;
		return prompt;

	}

	for (int i = 0; i < dossiers.size(); i++)
	{
		if (dossiers[i].identifiantProprietaire == id)
		{
			string prompt = "\n" + dossiers[i].nomDossier + "@/" + dossiers[1].nomDossier + "/" + dossiers[i].nomDossier + ": ";
			cout << prompt;
			return prompt;
		}
	}

	return "";
}