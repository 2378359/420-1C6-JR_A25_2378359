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
        bool session = true;

        while (session == true)
        {
            genererChemin2(dossiers, idUser, prompt);

            string commande = "";
            verifierCommande(commande, prompt);

            vector<string> tokens = split(commande, ' ');
            string commandePrincipale;
            if (tokens.empty())
            {
                commandePrincipale = "";
            }
            else
            {
                commandePrincipale = tokens[0];
            }
            vector<string> arguments;
            if (tokens.size() > 1)
            {
                arguments.assign(tokens.begin() + 1, tokens.end());
            }

            if (commandePrincipale == "exit")
            {
                session = false;
                break;   // revient à la boucle écran de login
            }
            else if (commandePrincipale == "help")
            {
                commandeHelp(idUser);
            }
            else if (commandePrincipale == "ls")
            {
                commandeLs(dossiers, fichiers, idUser);
            }
            else if (commandePrincipale == "cd")
            {
                commandeCd(dossiers, idDossier, idUser);
            }
            else if (commandePrincipale == "mkdir")
            {
                commandeMkdir(dossiers, idDossier, idUser, arguments);
            }
            else if (commandePrincipale == "rmdir")
            {
                commandeRmdir(dossiers, idDossier, idUser, arguments);
            }
            else if (commandePrincipale == "touch")
            {
                commandeTouch(fichiers, idDossier, idUser, arguments);
            }
            else if (commandePrincipale == "rm")
            {
                commandeRm(fichiers, idDossier, idUser, arguments);
            }
            else if (commandePrincipale == "cat")
            {
                commandeCat(fichiers, idDossier, idUser, arguments);
            }
            else if (commandePrincipale == "tee")
            {
                commandeTee(fichiers, idDossier, idUser, arguments);
            }
            else if (commandePrincipale == "passwd")
            {
                commandePasswd(utilisateurs, idUser, arguments);
            }
            else if (commandePrincipale == "adduser")
            {
                commandeAdduser(utilisateurs, arguments);
            }
            else if (commandePrincipale == "deluser")
            {
                commandeDeluser(utilisateurs, arguments);
            }
        }
    }
}
  


