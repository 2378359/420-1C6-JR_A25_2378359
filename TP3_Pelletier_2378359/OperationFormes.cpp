#include <format>
#include <iostream>
#include <string>
#include "Lecture.h"

using namespace std;

void CalculerFormeRectangle(double nombre1, double nombre2)
{
	verifierNombreDonner(nombre1);

	if (nombre1 <= 0)
	{
		cout << "Erreur : hauteur doit être plus grand que 0 !\n";
		return;
	}

	verifierNombreDonner(nombre2);

	if (nombre2 <= 0)
	{
		cout << "Erreur : largeur doit être plus grand que 0 !\n";
		return;
	}

	for (int i = 0; i < nombre1; i++)
	{
		for (int i = 0; i < nombre2; i++)
		{
			cout << "* ";
		}
		cout << "\n";
	}
	cout << "\n";
	// Calcul le tout
	cout << "Aire\t  : " << nombre1 * nombre2 << "\n";
	cout << "Périmetre : " << (nombre1 * 2) + (nombre2 * 2) << "\n";

	system("pause");
}

void CalculerFormeTriangle(double nombre1, double aire, double hypotenuse, double perimetre)
{
	verifierNombreDonner(nombre1);
	if (nombre1 <= 0)
	{
		cout << "Erreur : hauteur doit être plus grand que 0 !\n";
	}

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

	cout << format("\nAire\t\t: {:.3f}\n", aire);
	cout << format("Hypotenuse\t: {:.3}\n", hypotenuse);
	cout << format("Périmetre\t: {:.3}\n\n", perimetre);
	system("pause");
}