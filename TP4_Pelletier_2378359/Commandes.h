#pragma once
#include <string>
#include <vector> 
#include "Constantes.h"

using namespace std;

string verifierCommande(string& commandeDonner, const string& prompt);
void commandeHelp(int id);
void commandeLs(const vector<Dossiers>& dossiers, const vector<Fichiers>& fichiers, int id);
bool aDroitLecture(const vector<Dossiers>& dossiers, int idUtilisateur);
void commandeCd(const vector<Dossiers>& dossiers, int& idDossierCourant, int idUtilisateur);
void commandeMkdir(vector<Dossiers>& dossiers, int& idDossierCourant, int idUtilisateur, const vector<string>& arguments);
void commandeRmdir(vector<Dossiers>& dossiers, int idDossierCourant, int idUtilisateur, const vector<string>& arguments);
void commandeTouch(vector<Fichiers>& fichiers, int& idDossierCourant, int idUtilisateur, const vector<string>& arguments);
void commandeRm(vector<Fichiers>& fichiers, int idDossierCourant, int idUtilisateur, const vector<string>& arguments);
void commandeCat(const vector<Fichiers>& fichiers, int idDossierCourant, int idUtilisateur, const vector<string>& arguments);
string decoderPercentA(const string& texte);
void commandeTee(vector<Fichiers>& fichiers, int idDossierCourant, int idUtilisateur, const vector<string>& arguments);
void commandePasswd(vector<Utilisateurs>& utilisateurs, int idUtilisateur, const vector<string>& arguments);
void commandeAdduser(vector<Utilisateurs>& utilisateurs, const vector<string>& arguments);
void commandeDeluser(vector<Utilisateurs>& utilisateurs, const vector<string>& arguments);




