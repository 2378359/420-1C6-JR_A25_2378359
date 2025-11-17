#include <format>
#include <iostream>
#include <string>

using namespace std;

double calculerAfficherRabais(double prix, double rabais, bool estAffichage, string nom)
{
	double prixFinal = prix * rabais;

	if (estAffichage)
	{
		cout << format("Article : {}\n", nom);
		cout << format("Rabais de {} $\n", prix - prixFinal);
		cout << format("Prix final {} $\n", prixFinal);
	}

	return prixFinal;
}

bool estNombreEgal(int nombre1, int nombre2, int nombre3)
{
	if (nombre1 != nombre2)
		return false;

	if (nombre3 != INT_MIN
		&& nombre2 != nombre3)
		return false;

	return true;
}

int calculerResultat(int nombre1, int nombre2)
{
	int resultat = nombre1 + nombre2;

	nombre1 = 100;
	nombre2 = 200;

	return resultat;
}

int calculerResultatReference(int nombre1, int& nombre2)
{
	int resultat = nombre1 + nombre2;

	nombre1 = 100;
	nombre2 = 200;

	return resultat;
}

int calculerResultatConstantes(int nombre1, string& chaineNonModifiable, string& chaineModifiable)
{
	// Constante garanti que la valeur ne sera pas modifiée du début à la fin de la fonction
	// Erreur : paramètre const ne peut être modifié
	nombre1 = 9999;

	// Erreur : paramètre constant previent les erreurs d'affectation
	if (nombre1 == 123)
	{
		cout << "Oups : erreur d'affectation dans un if !\n";
	}

	int resultat = nombre1 + 10000;

	// Erreur : la chaîne non modifiable (const&) ne peut être modifiée
	chaineNonModifiable = "Nouveau message";

	// Ajouter le calcul à la fin de la chaîne modifiable
	chaineModifiable += format("Resultat du nombre {} : {}\n", nombre1, resultat);

	return resultat;
}

double calculerEfficaciteEnergie(double energieSortie, double energieEntree, string& messageErreur)
{
	// TODO: Transformer cette fonction pour utiliser des 'early exit' afin de réduire les niveaux d'indentation
	if (energieEntree > 0)
	{
		if (energieSortie >= 0)
		{
			double eff = (energieSortie / energieEntree) * 100.0;
			if (eff <= 100)
			{
				return eff;
			}
			else
			{
				cout << "Erreur : efficacité supérieure à 100%.\n";
				return -1;
			}
		}
		else
		{
			cout << "Erreur : énergie de sortie négative.\n";
			return -1;
		}
	}
	else
	{
		cout << "Erreur : énergie d'entrée nulle ou négative.\n";
		return -1;
	}
}

/// <summary>
/// Calculer un terme entier de la série de Fibonacci en utilisant une fonction recursive.
/// <para>Fibonacci : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, etc.</para>
/// </summary>
/// <param name="terme">: Valeur entière de la position de la série à partir du terme 0.</param>
/// <returns>Valeur entière du terme de la série Fibonacci. (ex. pour le terme 6 retourne 8)</returns>
int calculerFibonacci(int terme)
{
	// Retourner les valeurs pour les termes 0 et 1 afin de terminer la récursion
	if (terme == 0)
		return 0;

	if (terme == 1)
		return 1;

	// Exemple
	// calculerFibonnaci(3) = calculerFibonnaci(1) + calculerFibonnaci(2);
	// calculerFibonnaci(3) = calculerFibonnaci(1) + (calculerFibonnaci(0) + (calculerFibonnaci(1))
	// calculerFibonnaci(3) = 1 + (0 + 1)
	// calculerFibonnaci(3) = 2
	return calculerFibonacci(terme - 2) + calculerFibonacci(terme - 1);
}