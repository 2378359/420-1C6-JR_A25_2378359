/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-30
	Description		: TP2 (10%) - CALCULATRICE
*/

// Bibliothèques
#include <format>
#include <iostream>
#include <string>
using namespace std;

enum Operation
{
	Addition = '+',
	Soustraction = '-',
	Multiplication = '*',
	Division = '/',
	Exposant = '^',
	Factorielle = '!',
	SerieDeTaylor = 's',
	Rectangle = 'r',
	Triangle = 't',
	Quitter = 'q',
};

int main()
{
	setlocale(LC_ALL, "en_US");

#pragma region Menu
	bool estChoixValide = false;
	bool afficherOperation = false;

	string operation = "";

	double resultat = 0.0;
	double totalOperation = 0.0;
	double nombre = 0.0;
	double nombreOperation;
	do
	{
		cout << "\n***********************************************************\n"
			<< "*                       Calculatrice                      *\n"
			<< "*             Par Votre Hugo (Votre 2378359)              *\n"
			<< "***********************************************************\n\n";

		if (afficherOperation == true)
		{
			cout << operation;
		}

		cout << format("Résultat : {}\n\n", resultat);
		cout << "+) Addition\n" // Opérations qui utilisent le résultat dans le calcul
			<< "-) Soustraction\n"
			<< "*) Multiplication\n"
			<< "/) Division\n"
			<< "^) Exposant\n\n"
			<< "!) Factorielle\n" // Opérations qui écrasent le résultat avec le calcul
			<< "s) Série de Taylor\n\n"
			<< "r) Rectangle\n" // Opérations qui ne changent pas le résultat
			<< "t) Triangle\n\n"
			<< "q) Quitter\n\n";

		estChoixValide = false;

		while (!estChoixValide)
		{
			// Lire une chaîne au clavier qui peut contenir un nombre ou un caractère
			cout << "Choisir une opération ou entrer un nouveau résultat : ";
			string choixOperation;
			cin >> choixOperation;

			char choixMenu = choixOperation.length() == 1 ? choixOperation[0] : '\0';

			if (choixMenu == '+' || choixMenu == '-' || choixMenu == '*' || choixMenu == '/' ||
				choixMenu == '^' || choixMenu == '!' || choixMenu == 's' || choixMenu == 'r' ||
				choixMenu == 't' || choixMenu == 'q')
			{

				switch (choixMenu)
				{
				case Operation::Addition:
					cout << "Entrer un nombre : ";
					cin >> nombreOperation;
					totalOperation = resultat + nombreOperation;
					break;

				case Operation::Soustraction:
					cout << "Entrer un nombre : ";
					cin >> nombreOperation;
					totalOperation = resultat - nombreOperation;
					break;

				case Operation::Multiplication:
					cout << "Entrer un nombre : ";
					cin >> nombreOperation;
					totalOperation = resultat * nombreOperation;
					break;

				case Operation::Division:
					cout << "Entrer un nombre : ";
					cin >> nombreOperation;

					if (nombreOperation == 0)
					{
						cout << "\nOpération annulée : impossible de diviser par 0 !\n\n";
						cout << "Résultat : " << resultat << "\n\n";
						continue;
					}
					totalOperation = resultat / nombreOperation;
					break;

				case Operation::Exposant:

					break;

				case Operation::Factorielle:

					break;

				case Operation::SerieDeTaylor:

					break;

				case Operation::Rectangle:

					break;

				case Operation::Triangle:

					break;

				case Operation::Quitter:
					return 0;
					break;

				default:
					break;
				}
				estChoixValide = true;
				afficherOperation = true;
				operation = format("Opération : {} {} {} = {}\n", resultat, choixMenu, nombreOperation, totalOperation);
				resultat = totalOperation;
			}
			else
			{
				try
				{
					// Convertir la chaîne de caractères en nombre à virgule
					// stod() : string to double
					size_t nombreCaracteresConvertis;
					nombre = stod(choixOperation, &nombreCaracteresConvertis);

					// Lancer une erreur si la chaîne au complet n'a pas pu être convertie
					// Ex. "10abc123" réussi à convertir "10" => 10, mais il reste "abc123"
					if (nombreCaracteresConvertis < choixOperation.length())
					{
						// Exécution du code passe au catch() du try { ... } catch () { ... }
						throw exception();
					}

					// Nombre peut être utilisé ici pour l’affecter comme nouveau résultat
					cout << "La chaine convertie en nombre : " << nombre << "\n\n";

					resultat = nombre;
					afficherOperation = false;
					estChoixValide = true;
				}
				catch (...)
				{
					// Chaine n’a pas pu être convertie en nombre
					cout << "Erreur : l'opération ou le nombre est invalide.\n";

				}

				
			}
		}
	} while (true);
#pragma

}
