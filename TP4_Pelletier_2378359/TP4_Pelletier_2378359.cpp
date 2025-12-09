/*

	TP 4
	Auteur : Hugo Pelletier
	Matricule : 2378359
	Date : 2025 - 12 - 01

*/


#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <format>
#include <fstream>
#include <string>
#include <vector>
#include "chaine.h"
#include "Commandes.h"
#include "Dossiers.h"
#include "Fichiers.h"
#include "Lecture.h"
#include "Utilisateurs.h"
#include "Constantes.h"

int main()
{
    setlocale(LC_ALL, "en_US");
    srand((unsigned int)time(0));

    // Lis les fichiers
    vector<Utilisateurs> utilisateurs = lireFichierUtilisateurs(FICHIER_UTILISATEUR);
    vector<Dossiers> dossiers = lireFichierDossiers(FICHIER_DOSSIERS);
    vector<Fichiers> fichiers = lireFichierFichiers(FICHIER_FICHIERS);

    while (true)
    {
        // Afficher le menu avec les size() vector
        afficherMenu(utilisateurs, dossiers, fichiers);

        // Demander login
        int idUser = rechercherUtilisateur(utilisateurs);

        string prompt = " ";
        int idDossier = 0;
        genererChemin2(dossiers, idUser, prompt);

        bool session = true;

        while (session == true)
        {
            genererChemin2(dossiers, idUser, prompt);

            string commande = "";
            verifierCommande(commande, prompt);

            if (commande == "exit")
            {
                session = false;
                break;   // revient à la boucle écran de login
            }


            if (commande == "help")
            {
                commandeExit(idUser);
            }

            if (commande == "ls")
            {
                commandeLs(dossiers, fichiers, idUser);
            }

            if (commande == "cd")
            {
            }
        }
    }
}
  


