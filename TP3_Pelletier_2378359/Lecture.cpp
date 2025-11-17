#include <format>
#include <iostream>
#include <string>
#include "Lecture.h"
#include "Operations.h"

using namespace std;

/// Fonction qui demande à l'utilisateur d'entrer un nombre
/// et valide que l'entrée est bien un nombre valide
void verifierNombreDonner(double& nombreDonner)
{
	while (true)
	{
		// Demande du nombre à l'utilisateur
		cout << "Entrer un nombre : ";
		cin >> nombreDonner;

		// Vérifie si l'entrée est invalide
		if (cin.fail())
		{
			cout << "Erreur : nombre invalide, doit être un nombre à virgule !\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
}

/// Fonction incomplète qui vérifie si un nombre est égal à zéro
/// utilisée pour éviter une division par 0
void verifierNombreZeroDivision(double nombreDonner)
{
	// Vérifie si le nombre est nul
	if (nombreDonner == 0)
	{
		cout << "\nOpération annulée : impossible de diviser par 0 !\n\n";
	}
}

/// Fonction qui valide la valeur de n pour la série de Taylor
/// (n doit être un entier positif)
void verifierSerieTaylorN(double& nombre1)
{
	while (true)
	{
		// Lecture du paramètre n
		cout << "Entrer le n de la série de Taylor :";
		cin >> nombre1;

		// Vérifie la validité du nombre
		if (cin.fail() || nombre1 < 0)
		{
			cout << "Erreur : n invalide, doit être un nombre entier positif !\n";
		}
		else
			break;
	}
}
