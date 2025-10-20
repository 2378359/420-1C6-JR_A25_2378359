/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-30
	Description		: TP2 (10%) - CALCULATRICE
*/

// Bibliothèques
#include <format>
#include <iostream>
#include <string>
#include <cmath>
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
	setlocale(LC_ALL, "en_US.UTF - 8");

#pragma region Menu
	bool estChoixValide = false;
	bool afficherOperation = true;

	string operation = "";
	string calcul = "";

	double resultat = 0.0;
	double totalOperation = 0.0;
	double nombre = 0.0;
	double nombreOperation;
	double aire;
	double hypotenuse;
	double perimetre;
	double hauteur;
	double largeur;
	double x = 0;
	double n = 0;
	double somme = 0.0;
	double puissance = 1.0;
	double factorielle = 1.0;
	double total = 0.0;
	do
	{
		cout << "\n***********************************************************\n"
			<< "*                       Calculatrice                      *\n"
			<< "*             Par Votre Hugo (Votre 2378359)              *\n"
			<< "***********************************************************\n\n";

			cout << operation;
			operation = "";

			cout << calcul;
			calcul = "";

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
					// Les opérations simples
				case Operation::Addition:
					while (true)
					{
						cout << "Entrer un nombre : ";
						cin >> nombreOperation;
						if (cin.fail())
						{
							cout << "Erreur : nombre invalide, doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else
							break;
					}

					totalOperation = resultat + nombreOperation;
					break;

				case Operation::Soustraction:
					while (true)
					{
						cout << "Entrer un nombre : ";
						cin >> nombreOperation;
						if (cin.fail())
						{
							cout << "Erreur : nombre invalide, doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else
							break;
					}

					totalOperation = resultat - nombreOperation;
					break;

				case Operation::Multiplication:
					while (true)
					{
						cout << "Entrer un nombre : ";
						cin >> nombreOperation;
						if (cin.fail())
						{
							cout << "Erreur : nombre invalide, doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else
							break;
					}

					totalOperation = resultat * nombreOperation;
					break;

				case Operation::Division:
					while (true)
					{
						cout << "Entrer un nombre : ";
						cin >> nombreOperation;
						if (cin.fail())
						{
							cout << "Erreur : nombre invalide, doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else
							break;
					}
					if (nombreOperation == 0)
					{
						cout << "\nOpération annulée : impossible de diviser par 0 !\n\n";
						estChoixValide = true;
						continue;
					}

					totalOperation = resultat / nombreOperation;
					break;

					// Choix Exposant
				case Operation::Exposant:

					// Vérification du nombre choisi
					while (true)
					{
						cout << "Entrer l'exposant : ";

						cin >> nombreOperation;

						if (cin.fail())
						{
							cout << "Erreur : exposant invalide, doit être un entier !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else
							break;
					}
					if (resultat == 0 && nombreOperation < 0)
					{
						cout << "Opération annulée : impossible pour 0 d'avoir un exposant négatif !";
						estChoixValide = true;
						continue;
					}
					// Nombre 0, -1 et 1
					if (nombreOperation == 0)
					{
						totalOperation = 1;
					}
					else if (nombreOperation == 1)
					{
						totalOperation = resultat;
					}
					else if (nombreOperation == -1)
					{
						totalOperation = nombreOperation / resultat;
						totalOperation *= -1;
					}
					// Calcul de l'exposant choisi
					else if (nombreOperation >= 2)
					{
						totalOperation = resultat;
						for (int i = 1; i < nombreOperation; i++)
						{
							double premierNombre = totalOperation;
							totalOperation *= resultat;
							calcul += format("{} * {} = {}\n", premierNombre, resultat, totalOperation);
						}
					}
					else
					{
						totalOperation = 1 / resultat;

						for (int i = 1; i < -nombreOperation; i++)
						{
							double premierNombre = totalOperation;
							totalOperation /= resultat;
							calcul += format("{} / {} = {}\n", premierNombre, resultat, totalOperation);
						}
					}

					break;

				case Operation::Factorielle:

					// Vérification du nombre choisi
					while (true)
					{
						cout << "Entrer la factoriel : ";
						cin >> nombreOperation;

						if (cin.fail())
						{
							cout << "Erreur : nombre invalide, doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else if (nombreOperation < 0)
						{
							cout << "Erreur : factorielle invalide, doit être un entier positif!\n";
						}
						else
							break;
					}
					// Si nombre 0 et 1
					if (nombreOperation == 0)
					{
						totalOperation = 1;
					}
					else if (nombreOperation == 1)
					{
						totalOperation = 1;
					}
					// Calcul de l'opération
					else
					{
						totalOperation = 1;
						for (int i = 1; i <= nombreOperation; i++)
						{

							double premierNombre = totalOperation;
							totalOperation *= i;
							calcul += format("{} * {} = {}\n", premierNombre, i, totalOperation);

						}
					}
					// Écrase le résultat
					resultat = totalOperation;
					// N'affiche pas l'opération mais lui même
					afficherOperation = false;
					operation = format("\nOpération : {}! = {}\n\n", nombreOperation, resultat);

					break;

				case Operation::SerieDeTaylor:
					
					while (true)
					{
						cout << "Entrer le x de la série de Taylor :";
						cin >> x;

						if (cin.fail())
						{
							cout << "Erreur : x invalide doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else
							break;
					}

					while (true)
					{
						cout << "Entrer le n de la série de Taylor :";
						cin >> x;

						if (cin.fail() || n < 0)
						{
							cout << "Erreur : n invalide, doit être un nombre entier positif !\n";
						}
						else
							break;
					}
					
					
					for (int i = 1; i <= n; i++)
					{
						calcul += format("+ ({}^{} / {}!)", x, i, i);
						
					}
					for (int i = 1; i <= n; i++)
					{
						puissance *= x;
						factorielle *= i;
						total = puissance / factorielle;
						somme += total;
						calcul += format("+ {} / {})", puissance, factorielle);
					}
					
					cout << somme;
					afficherOperation = false;
					break;

				case Operation::Rectangle:
					
					// Vérification des valeurs entrées
					while (true)
					{
						cout << "Entrer une hauteur : ";
						cin >> hauteur;

						if (cin.fail())
						{
							cout << "Erreur : hauteur doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else if (hauteur <= 0)
						{
							cout << "Erreur : hauteur doit être plus grand que 0 !\n";
						}
						else
							break;
					}

					while (true)
					{
						cout << "\nEntrer une largeur : ";
						cin >> largeur;

						if (cin.fail())
						{
							cout << "Erreur : largeur doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else if (largeur <= 0)
						{
							cout << "Erreur : largeur doit être plus grand que 0 !\n";
						}
						else
							break;
					}

					// Fait le rectangle avec la hauteur demandée
					for (int i = 0; i < hauteur; i++)
					{
						for (int i = 0; i < largeur; i++)
						{
							cout << "* ";
						}
						cout << "\n";
					}
					cout << "\n";
					// Calcul le tout
					cout << "Aire\t  : " << hauteur * largeur << "\n";
					cout << "Périmetre : " << (hauteur * 2) + (largeur * 2) << "\n";

					system("pause");

					// Cache l'opération et sort de la boucle
					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::Triangle:

					// Vérification des valeurs entrées
					while (true)
					{
						cout << "Entrer une hauteur : ";
						cin >> hauteur;

						if (cin.fail())
						{
							cout << "Erreur : hauteur doit être un nombre à virgule !\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else if (hauteur <= 0)
						{
							cout << "Erreur : hauteur doit être plus grand que 0 !\n";
						}
						else
							break;
					}

					// Fait le triangle avec la hauteur demandée
					for (int i = 0; i <= hauteur; i++)
					{
						for (int j = 1; j <= i; ++j)
						{
							cout << "* ";
						}
						cout << "\n";
					}

					// Fait les calculs
					aire = (hauteur * hauteur) / 2;
					hypotenuse = sqrt(hauteur * hauteur + hauteur * hauteur);
					perimetre = hauteur + hauteur + hypotenuse;

					cout << format("\nAire\t\t: {:.3f}\n", aire);
					cout << format("Hypotenuse\t: {:.3}\n", hypotenuse);
					cout << format("Périmetre\t: {:.3}\n\n", perimetre);

					estChoixValide = true;
					afficherOperation = false;

					system("pause");

					break;

				case Operation::Quitter:
					// Quitte
					return 0;
					break;

				default:
					break;
				}
				
				// Sort de la boucle
				estChoixValide = true;

				// Affiche l'opération des opérateur valide
				if (afficherOperation == true)
				{
					operation = format("Opération : {} {} {} = {}\n", resultat, choixMenu, nombreOperation, totalOperation);
					resultat = totalOperation;
				}
				// Remet la valeur à vrai par défaut
				afficherOperation = true;
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
}
