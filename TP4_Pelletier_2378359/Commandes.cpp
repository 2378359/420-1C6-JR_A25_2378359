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
	 "cat"
	 "tee"
	 "$"
	 "passwd"
	};

	while (true)
	{
		cout << prompt;
		getline(cin, commandeDonner);

		if (cin.fail())
		{
			cout << format("Erreur : Commande inconnue {}, utiliser la commande 'help' pour voir les commandes disponibles\n", commandeDonner);
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		commandeDonner = toLower(commandeDonner);
		commandeDonner = trim(commandeDonner);
		
		if (commandeDonner.empty())
		{
			std::cout << "Erreur : Commande vide.\n";
			continue;
		}

		vector<string> tokens = split(commandeDonner, ' ');

		if (tokens.empty())
		{
			std::cout << "Erreur : Commande vide.\n";
			continue;
		}

		string commande = tokens[0];

		bool existe = find(commandesValides.begin(), commandesValides.end(), commande) != commandesValides.end();

		if (!existe)
		{
			std::cout << format("Erreur : Commande inconnue '{}', utiliser la commande 'help' pour voir les commandes disponibles\n", commande);
			continue;
		}

		if (commande == "exit")
		{
			return "exit";
		}

		return commandeDonner;
	}
}

void commandeExit(int id) 
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

	if (id == 1000)
	{
		cout << "adduser <nom> <mot-passe>\t\t : Ajouter un utilisateur\n";
		cout << "deluser <nom>\t\t\t\t : Supprimer un utilisateur\n";
	}
}

void commandeLs(const vector<Dossiers>& dossiers, const vector<Fichiers>& fichiers, int id)
{
	for (int i = 0; i < dossiers.size(); i++)
	{
		if (dossiers[i].identifiantDossierParent == -1)
		{
			cout << format("\ndrwx{} {} \t\t  0 {} ..\n", dossiers[i].permissions, dossiers[2].nomDossier, fichiers[i].timestamp);
		}
	}
	for (int i = 0; i < fichiers.size(); i++)
	{
		
		if (fichiers[i].identifiantProprietaire == id)
		{
			if (fichiers[i].nomFichier.find('.') != string::npos)
			{
				cout << format("-rwx{} {} \t\t {} {} {}\n", fichiers[i].permissions, dossiers[i].nomDossier, fichiers[i].contenuTexte.size(), fichiers[i].timestamp, fichiers[i].nomFichier);
			}
			else
			{
				cout << format("drwx{} {} \t\t 0 {} {}\n", fichiers[i].permissions, dossiers[i].nomDossier, fichiers[i].timestamp, fichiers[i].nomFichier);
			}
		}
	}
}

void commandeCd(const vector<Dossiers>& dossiers, int& idDossierCourant, int idUtilisateur)
{


	if (args.size() != NOMBRE_ARGUMENT_ATTENDU)
	{
		cout << "Erreur : la commande 'cd' doit avoir 1 argument.\n";
		return;
	}

	aDroitLecture(dossiers, idUtilisateur);

	if (aDroitLecture(dossiers, idUtilisateur) == false)
	{
		cout << format("Erreur : acces refuse en lecture pour le dossier {}.", dossiers[1].nomDossier);
	}
}

bool aDroitLecture(const vector<Dossiers>& dossiers, int idUtilisateur)
{
	if (idUtilisateur == 0)
	{
		return true;
	}

	for (int i = 0; i < dossiers.size(); i++)
	{
		if (dossiers[i].identifiantProprietaire == idUtilisateur)
		{
			return true;
		}

		if (!dossiers[i].permissions.empty() && dossiers[i].permissions[0] == 'r')
		{
			return true;
		}
	}
	

	
	return false;
}
