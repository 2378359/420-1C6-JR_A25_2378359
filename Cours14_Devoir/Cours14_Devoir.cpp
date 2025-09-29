/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-25
	Description		: cours 13 Devoir
*/
#include <format>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	if (false)
	{
		// int i 	: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
		// Affichage	: 012345678

		int somme = 0;
		for (int i = 0; i < 9; ++i)
		{
			somme += i;
			cout << i;
		}
		cout << "\n\n";

		// int i 	: -5, -3, -1, 1, 3, 5, 7, 9
		// Affichage	: -5, 0, -3, 1, -1, 2, 1, 3, 3, 4, 5, 5, 7, 6, 9, 7
		// compteur		: 0, 1, 2, 3, 4, 5, 6, 7
		int compteur = 0;
		for (int i = -5; i <= 10; i += 2)
		{
			cout << i << ", ";
			cout << compteur++ << ", ";
		}

		cout << "\n\n";

		// int i 	: 0, 1, 2, 3, 4, 5
		// Affichage	: 0, -3, -3, -6, -6, -9
		int total = 0;
		for (int i = 0; i <= 5; i++)
		{
			total += i * 3;
			total *= -1;
			cout << format("{} ", total);

			if (total > 0)
			{
				cout << "\n";
			}
		}

	}

	if (false)
	{
		for (int i = 0; i < 6; i++)
		{
			int valeur = 1 + i * 2;
			cout << valeur << "\n";
		}

		cout << "\n\n";

		for (int i = 0; i < 5; i++)
		{
			int valeur = 18 - i * 4;
			cout << valeur << "\n";
		}

		cout << "\n\n";

		for (int i = 0; i < 8; i++)
		{
			int valeur = 5 + i * 5;
			cout << valeur << ", ";
		}
	}

	if (false)
	{
		cout << "--- Nombre entiers ---\n\n";

			int nombre;
		while (true)
		{
			cout << "Entrer le nombre de fin : ";
			cin >> nombre;

			if (cin.fail() || nombre < 0) {
				cout << "Erreur : nombre invalide.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				break;
			}
		}
		cout << format("Nombres entiers de 0 jusqu’à {} sont : ", nombre);
		for (int i = 0; i <= nombre; i++)
		{
			cout << i;

			if (i < nombre)
				cout << ", ";
		}
	}

	if (false)
	{
		cout << "--- Nombre entiers ---\n\n";

		int nombreDepart;
		int nombreFin;

		while (true)
		{
			cout << "Entrer le nombre de départ : ";
			cin >> nombreDepart;

			if (cin.fail())
			{
				cout << "Erreur : nombre invalide.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Entrer le nombre de fin : ";
			cin >> nombreFin;

			if (cin.fail())
			{
				cout << "Erreur : nombre invalide.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				break;
			}
		}

		cout << format("Nombres entiers de {} jusqu’à {} sont : ", nombreDepart, nombreFin);
		if (nombreDepart > nombreFin)
		{
			for (int i = nombreDepart; i >= nombreFin; i--)
			{
				cout << i;

				if (i > nombreFin)
					cout << ", ";
			}
		}
		else
		{
			for (int i = nombreDepart; i <= nombreFin; i++)
			{
				cout << i;

				if (i < nombreFin)
					cout << ", ";
			}
		}

	}

}