#pragma once
#include <string>
#include <vector> 
#include "Constantes.h"

using namespace std;

string verifierCommande(string& commandeDonner, const string& prompt);

void commandeExit(int id);

void commandeLs(const vector<Dossiers>& dossiers, const vector<Fichiers>& fichiers, int id);

bool aDroitLecture(const vector<Dossiers>& dossiers, int idUtilisateur);
