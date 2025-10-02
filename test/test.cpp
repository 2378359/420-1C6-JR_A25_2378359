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
	double resultat = 0;
	do
	{
		cout << "***********************************************************\n"
			<< "*                       Calculatrice                      *\n"
			<< "*             Par Votre Hugo (Votre 2378359)              *\n"
			<< "***********************************************************\n\n";

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

		bool estChoixValide = false;
		while (!estChoixValide)
		{
			// Lire une chaîne au clavier qui peut contenir un nombre ou un caractère
			cout << "Choisir une opération ou entrer un nouveau résultat : ";
			string choixOperation;
			cin >> choixOperation;

			char choixMenu = choixOperation.length() == 1 ? choixOperation[0] : '\0';

			//if (choixMenu == 'q')
				//return 0;

			
				switch (choixMenu)
				{
				case Operation::Addition:

					break;
				case Operation::Soustraction:

					break;
				case Operation::Multiplication:

					break;
				case Operation::Division:

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
			
			if (estChoixValide == false)
			{
				try
				{
					// Convertir la chaîne de caractères en nombre à virgule
					// stod() : string to double
					size_t nombreCaracteresConvertis;
					double nombre = stod(choixOperation, &nombreCaracteresConvertis);

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
					estChoixValide = true;
				}
				catch (exception& e)
				{
					// Chaine n’a pas pu être convertie en nombre
					cout << "Erreur : l'opération ou le nombre est invalide.\n";

				}


			}
		}
	} while (true);
#pragma

}
