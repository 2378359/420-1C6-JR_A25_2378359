#pragma on
#include "Constantes.h"
using namespace std;

vector<Utilisateurs> lireFichierUtilisateurs(const string& nomFichier);

vector<Dossiers> lireFichierDossiers(const string& nomFichier);

vector<Fichiers> lireFichierFichiers(const string& nomFichier);

void afficherMenu(const vector<Utilisateurs>& utilisateurs, vector<Dossiers>& dossier, vector<Fichiers>& fichiers);

int rechercherUtilisateur(vector<Utilisateurs>& utilisateurs);

string genererChemin2(const vector<Dossiers>& dossiers, int id, string& prompt);