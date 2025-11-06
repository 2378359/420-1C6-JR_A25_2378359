/*
	Auteur			: Hugo Pelletier
	Date			: 2025-10-30
	Description		: TP3 (7.5%) - CALCULATRICE AVEC FONCTIONS
*/

// Bibliothèques
#include <format>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Constantes.h"
#include "Operations.h"
#include "Math.h"
#include "Lecture.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "en_US");

#pragma region Menu
	bool estChoixValide = false;
	bool afficherOperation = true;

	string operation = "";
	string calcul = "";

	int resultat = 0.0;
	double totalOperation = 0.0;
	double nombre = 0.0;
	double nombreOperation = 0.0;
	double aire = 0.0;
	double hypotenuse = 0.0;
	double perimetre = 0.0;
	double hauteur = 0.0;
	double largeur = 0.0;
	double x = 0;
	double n = 0;
	double somme = 0.0;
	double puissance = 1.0;
	double factorielle = 1.0;
	double total = 0.0;
	do
	{

		AfficherMenuCalculatrice(operation, calcul, resultat);

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
				choixMenu == 't' || choixMenu == 'q' || choixMenu == 'd' || choixMenu == 'p' || choixMenu == 'i'
				|| choixMenu == 'b' || choixMenu == 'c' || choixMenu == 'l' || choixMenu == 'a')
			{
				switch (choixMenu)
				{
					// Les opérations simples
				case Operation::Addition:

					verifierNombreDonner(nombreOperation);

					CalculerOperationAddition(totalOperation, resultat, nombreOperation);
					break;

				case Operation::Soustraction:

					verifierNombreDonner(nombreOperation);

					CalculerOperationSoustraction(totalOperation, resultat, nombreOperation);

					break;

				case Operation::Multiplication:

					verifierNombreDonner(nombreOperation);

					CalculerOperationMultiplication(totalOperation, resultat, nombreOperation);
					break;

				case Operation::Division:

					verifierNombreDonner(nombreOperation);
					CalculerOperationDivision(totalOperation, resultat, nombreOperation);
					break;

				case Operation::Exposant:

					

					verifierNombreDonner(nombreOperation);
					if (resultat == 0 && nombreOperation < 0)
					{
						cout << "Opération annulée : impossible pour 0 d'avoir un exposant négatif !";
						estChoixValide = true;
						continue;
					}
					else
					{
						double premierNombre = totalOperation;
						CalculerOperationExposant(calcul, nombreOperation, totalOperation, resultat, premierNombre);
					}
					break;

				case Operation::Factorielle:
					verifierNombreDonner(nombreOperation);
					CalculerOperationFactoriel(calcul, nombreOperation, totalOperation);

					resultat = totalOperation;
					afficherOperation = false;
					operation = format("\nOpération : {}! = {}\n\n", nombreOperation, resultat);

					break;

				case Operation::SerieDeTaylor:

					verifierNombreDonner(x);
					verifierSerieTaylorN(n);

					CalculerOperationTaylor(calcul, n, x, somme, total, factorielle, puissance);

					cout << somme;
					afficherOperation = false;
					break;

				case Operation::Rectangle:
					
					 CalculerFormeRectangle(hauteur, largeur);

					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::Triangle:
					CalculerFormeTriangle(hauteur, aire, hypotenuse, perimetre);

					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::Quitter:
					return 0;
					break;

				case Operation::Diviseurs:
					verifierNombreDonner(nombreOperation);
					CalculerOperationDiviseurs(nombreOperation);
					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::NombrePremier:
					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::Inverser:
					CalculerOperationInverser(nombreOperation);
					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::Transformer:
					TransforrmerBase();
					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::Seed:
					InitialiserSeedAutomatique();
					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::LancerDes:
					LancerLesDes(resultat);
					estChoixValide = true;
					afficherOperation = false;
					break;

				case Operation::Aleatoire:
					estChoixValide = true;
					afficherOperation = false;
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
