#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Constantes.h"
#include "chaine.h"

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
		vector<string> tokens = split(ligne, ';');

		// TODO: Vérifier le nombre de tokens attendus
		if (tokens.size() != 5)
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
		if (tokens.size() != 5)
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
			cout << format("Erreur : Ligne {} - utilisateur vide.\n", compteurLigne);
			continue;
		}

		dossier.nomDossier = tokens[1];

		// TODO: Pour les champs 'int' et 'double', utiliser les fonctions 'tryParse' pour convertir les chaînes en nombres
		if (!tryParseInt(tokens[2], dossier.identifiantProprietaire))
		{
			cout << format("Erreur : Ligne {} - Annee de publication invalide : {}\n", compteurLigne, tokens[2]);
			continue;
		}

		if (!tryParseInt(tokens[3], dossier.identifiantDossierParent))
		{
			cout << format("Erreur : Ligne {} - Prix invalide : {}\n", compteurLigne, tokens[3]);
			continue;
		}

		if (tokens[4].empty())
		{
			cout << format("Erreur : Ligne {} - utilisateur vide.\n", compteurLigne);
			continue;
		}

		dossier.permissions = tokens[4];

		// TODO: Ajouter le livre au vefcteur des livres valides
		dossiers.push_back(dossier);
	}

	// Fermer le fichier après la lecture des livres
	fichierDossiers.close();

	return dossiers;
}



