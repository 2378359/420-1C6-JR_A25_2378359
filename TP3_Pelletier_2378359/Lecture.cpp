#include <format>
#include <iostream>
#include <string>
#include "Lecture.h"
#include "Operations.h"


using namespace std;
void verifierNombreDonner(double& nombreDonner)
{
	while (true)
	{
		cout << "Entrer un nombre : ";
		cin >> nombreDonner;
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

//INCOMPLET
void verifierNombreZeroDivision(double nombreDonner) 
{
		if (nombreDonner == 0)
		{
			cout << "\nOpération annulée : impossible de diviser par 0 !\n\n";

		}
}

void verifierSerieTaylorN(double& nombre1)
{
	while (true)
	{
		cout << "Entrer le n de la série de Taylor :";
		cin >> nombre1;

		if (cin.fail() || nombre1 < 0)
		{
			cout << "Erreur : n invalide, doit être un nombre entier positif !\n";
		}
		else
			break;
	}
}


