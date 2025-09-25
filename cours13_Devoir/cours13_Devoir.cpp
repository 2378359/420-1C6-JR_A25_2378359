/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-023
	Description		: cours 13 devoir while
*/

#include <format>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

	if (false)
	{
		cout << "--- Lire des nombres ---\n";
		int nombre = 1;
		int nombreLus = 0;
		bool estNombreInvalide = true;

		while (nombre != 0)
		{
			cout << "Entrer un nombre (0 pour quitter) : ";
			cin >> nombre;
			if (!estNombreInvalide)
			{
				cout << "Erreur : nombre n'est pas entier.";
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.clear();
			}

			cout << format("\nNombre {} entré !\n", nombre);
			nombreLus++;

		}
		cout << format("\nFin de la lecture des nombres ({} nombres lus) !", nombreLus - 1);
	}

	if (false)
	{
		cout << "--- Moyenne ---\n";
		int nombre = 1;
		int nombreLus = 0;
		double total = 0.0;
		do
		{
			while (true) {
				cout << "Entrer un nombre (0 pour quitter) : ";
				cin >> nombre;

				if (cin.fail()) {
					cout << "Erreur : nombre invalide.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					break;
				}
			}
			if (nombre != 0)
			{
				total += nombre;
				nombreLus++;
				cout << format("\nNombre {} entré ! \n", nombre);
			}

		} while (nombre != 0);

		if (nombreLus == 0)
		{
			cout << "\nAucun nombre entré !\n";
		}
		else
		{
			double moyenne = total / nombreLus;
			cout << format("\nMoyenne : {:.2f}\n", moyenne);
		}
	}

	if (true)
	{
		cout << "--- Retrait bancaire ---\n\n";
		double argent = 1000;
		double retrait = 0;

		while (true)
		{
			cout << format("\nEntrer un retrait ({:.2f} $ restant) ou - 1 pour terminer : ", argent);
			cin >> retrait;

			if (cin.fail()) {
				cout << "\nErreur : nombre invalide.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else if (retrait < -1 || retrait == 0)
			{
				cout << format("\nErreur : impossible de retirer {:.2f} $, le montant doit être un nombre positif.\n\n", retrait);
				continue;
			}
			else if (retrait > argent)
			{
				cout << format("\nErreur : impossible de retirer {:.2f} compte contient uniquement {:.2f} $", retrait, argent);
				continue;
			}

			if (retrait == -1)
			{
				cout << format("\nRetraits terminés, total restant dans le compte : {:.2f} $", argent);
				return 0;
			}

			argent = argent - retrait;

		}
	}
}
