#pragma once

#include <string>
using namespace std;

const string FICHIER_UTILISATEUR = "utilisateurs.csv";
const string FICHIER_DOSSIERS = "dossiers.txt";
const string FICHIER_FICHIERS = "fichiers.txt";

struct Dossiers
{
	int identifiantDossier = -1;
	string nomDossier = "";
	int identifiantProprietaire = -1;
	int identifiantDossierParent = -1;
	string permissions = "";
};

struct Utilisateurs
{
	int identifiantUtilisateur = -1;
	string nomUtilisateur = "";
	string motDePasse = "";
};