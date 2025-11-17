#include <format>
#include <iostream>
#include <string>
#include "Lecture.h"

using namespace std;

/// Fonction qui affiche un rectangle et calcule son aire et périmètre
void CalculerFormeRectangle(double nombre1, double nombre2)
{
	// Vérifie la hauteur
	verifierNombreDonner(nombre1);

	if (nombre1 <= 0)
	{
		cout << "Erreur : hauteur doit être plus grand que 0 !\n";
		return;
	}

	// Vérifie la largeur
	verifierNombreDonner(nombre2);

	if (nombre2 <= 0)
	{
		cout << "Erreur : largeur doit être plus grand que 0 !\n";
		return;
	}

	// Affiche le rectangle avec des *
	for (int i = 0; i < nombre1; i++)
	{
		for (int i = 0; i < nombre2; i++)
		{
			cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// Calcul et affichage de l'aire et du périmètre
	cout << "Aire\t  : " << nombre1 * nombre2 << "\n";
	cout << "Périmetre : " << (nombre1 * 2) + (nombre2 * 2) << "\n";

	system("pause");
}

/// Fonction qui affiche un triangle et calcule son a
void CalculerFormeTriangle(double nombre1, double aire, double hypotenuse, double perimetre)
{
	// Vérifie la hauteur
	verifierNombreDonner(nombre1);
	if (nombre1 <= 0)
	{
		cout << "Erreur : hauteur doit être plus grand que 0 !\n";
	}

	// Affiche la forme du triangle
	for (int i = 0; i <= nombre1; i++)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << "* ";
		}
		cout << "\n";
	}

	// Fait les calculs
	aire = (nombre1 * nombre1) / 2;
	hypotenuse = sqrt(nombre1 * nombre1 + nombre1 * nombre1);
	perimetre = nombre1 + nombre1 + hypotenuse;

	// Affiche les résultats
	cout << format("\nAire\t\t: {:.3f}\n", aire);
	cout << format("Hypotenuse\t: {:.3}\n", hypotenuse);
	cout << format("Périmetre\t: {:.3}\n\n", perimetre);
	system("pause");
}
