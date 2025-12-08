#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Constantes.h"
#include "chaine.h"
#include "Lecture.h"

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