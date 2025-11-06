#include <format>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Lecture.h"
#include "Operations.h"

using namespace std;

double CalculerOperationAddition(double& total, double resultat, double nombreInitial)
{
	total = resultat + nombreInitial;
	return total;
}

double CalculerOperationSoustraction(double& total, double resultat, double nombreInitial)
{
	total = resultat - nombreInitial;
	return total;
}

double CalculerOperationMultiplication(double& total, double resultat, double nombreInitial)
{
	total = resultat * nombreInitial;
	return total;
}

double CalculerOperationDivision(double& total, double resultat, double nombreInitial)
{
	total = resultat / nombreInitial;
	if (nombreInitial == 0)
	{
		cout << "\nOpération annulée : impossible de diviser par 0 !\n\n";
		return;
	}
	return total;
}

double CalculerOperationExposant(string& calcul, double& nombreOperation, double& totalOperation, int& resultat, double& premierNombre)
{
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
	return totalOperation;
}

double CalculerOperationFactoriel(string& calcul, double nombreOperation, double& totalOperation)
{
	// Si nombre 0 et 1
	if (nombreOperation < 0)
	{
		cout << "Erreur : factorielle invalide, doit être un entier positif!\n";
		return;
	}

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
	return totalOperation;
}

double CalculerOperationTaylor(string& calcul, double n, double x, double somme, double& total, double factorielle, double puissance)
{
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

	return total;
}

double CalculerOperationDiviseurs(double& nombreDonner)
{

	if (nombreDonner <= 0)
	{
		cout << "Erreur : le nombre doit être un entier positif.\n";
	}
	int entier = static_cast<int>(nombreDonner);
	cout << format("\n--- Diviseurs du nombre {} ---\n\n", entier);

	int compteur = 0;
	for (int i = 1; i <= entier; i++)
	{
		if (entier % i == 0)
		{
			cout << format("Divisible par : {:<5} ({} x {})\n", i, i, entier / i);
			compteur++;
		}
	}

	return entier;
	cout << format("\n--- {} diviseurs trouvés pour le nombre {} ---\n\n", compteur, entier);

	system("pause");
}

int extraireChiffre(int& nombre)
{
	int chiffre = nombre % 10;
	nombre /= 10;
	return nombre;
}

void CalculerOperationInverser(double& nombreDonner)
{
	verifierNombreDonner(nombreDonner);

	int nombre = static_cast<int>(nombreDonner);

	bool estNegatif = (nombreDonner < 0);

	if (estNegatif)
		nombre = -nombre; // On travaille avec le positif

	int inverse = 0;
	while (nombreDonner > 0)
	{
		int chiffre = extraireChiffre(nombre);
		inverse = inverse * 10 + chiffre;
	}

	if (estNegatif)
		inverse = -inverse;
	
	cout << format("Operation : Inverser {} = {}\n\n", nombreDonner, inverse);
	cout << format("Resultat : {}\n\n", inverse);
}

void TransforrmerBase()
{
	string nombreStr;
	int baseOrigine, nouvelleBase;

	while (true)
	{
		cout << "Entrez un nombre à transformer : ";
		cin >> nombreStr;

		cout << "Entrez la base du nombre: ";
		cin >> baseOrigine;

		cout << "Entrez la nouvelle base : ";
		cin >> nouvelleBase;

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

void InitialiserSeedAutomatique() {
	srand(static_cast<unsigned int>(time(nullptr)));
}

void ConfigurerLaSeed() {
	int seed;
	cout << "Entrer la seed : ";
	cin >> seed;

	srand(seed);
}

void LancerLesDes(int& resultat) {
	int nombreDes;
	int nombreFaces;
	int bonus;

	while (true) {
		cout << "Entrez un nombre de des : ";
		cin >> nombreDes;
		if (cin.fail() || nombreDes <= 0) {
			cout << "Erreur : nombre de dés invalide, doit être un entier positif !\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}

	while (true) {
		cout << "Entrez un nombre de faces : ";
		cin >> nombreFaces;
		if (cin.fail() || nombreFaces <= 0) {
			cout << "Erreur : nombre de faces invalide, doit être un entier positif !\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}

	while (true) {
		cout << "Entrez un bonus : ";
		cin >> bonus;
		if (cin.fail()) {
			cout << "Erreur : bonus invalide, doit être un entier !\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}


	cout << "Operation : " << nombreDes << "d" << nombreFaces;
	if (bonus != 0) cout << (bonus > 0 ? "+" : "") << bonus;
	cout << " valeurs possibles [" << nombreDes + bonus << ", " << nombreDes * nombreFaces + bonus << "]\n\n";

	int somme = 0;
	for (int i = 1; i <= nombreDes; ++i) {
		int lancer = rand() % nombreFaces + 1;
		cout << "Lancer " << i << " (1d" << nombreFaces << "): " << lancer << " (" << somme << "+" << lancer << " = ";
		somme += lancer;
		cout << somme << ")\n";
	}

	if (bonus != 0) {
		cout << "\nBonus : " << bonus << " (" << somme;

		if (bonus > 0) {
			cout << "+" << bonus;
		}
		else {
			cout << bonus;
		} 
		cout << bonus << " = ";
		somme += bonus;
		cout << somme << ")\n";
	}

	resultat = somme;
}
