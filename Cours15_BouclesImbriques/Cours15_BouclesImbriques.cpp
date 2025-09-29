// TODO: Ajouter un en-tête


// Inclure les librairies
// TODO: Modifier la version du Projet à C++20 pour la librairie <format>
// TODO: Compiler le code pour le tester et sauvegarder sur Git local et puis sur GitHub
#include <format>
#include <iostream>
#include <string>

// Utiliser le namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "");

	std::cout << "--- Cours 15 - Boucles imbriquées ---\n";

	// *** Boucles imbriquées ***
	// - Imbriquer les boucles for permet des travaux super puissants
	// - Dans les éléments les plus difficiles à apprendre à utiliser
	// - Visualiser les boucles comme des dimensions
	//		- Exemple avec 2 boucles (x par y)
	//		- Dessiner un écran (hauteur par largeur)
	//		- Calculer le total pour des utilisateurs leurs transactions (transactions par utilisateur)
	// - Par convention
	//		- Variables itérateurs sont nommées à partir de 'i' (i, j, k, etc.)
	//		- Recommandé de les renommer pour aider la compréhension de la boucle

	// TODO: Tracer les valeurs des variables et affichage à la console de la boucle imbriquée
	if (false)
	{
		cout << "\n--- Tracer la boucle 1 ---\n\n";

		// Variables
		// i : 0, 1, 2, 3
		// j : 0, 1, 2, 3, x 0, 1, 2, 3, x 0, 1, 2, 3, x
		//
		// Sortie à la Console
		// 0:0 1 2
		// 1:0 1 2
		// 2:0 1 2

		for (int i = 0; i < 3; i++)
		{
			cout << i << ":";

			for (int j = 0; j < 3; j++)
			{
				cout << j << " ";
			}

			cout << "\n";
		}
	}

	// TODO: Tracer les valeurs des variables et affichage à la console de la boucle imbriquée
	if (false)
	{
		cout << "\n--- Tracer la boucle 2 ---\n\n";

		// Variables
		// i : 0, 1
		// j : 0, 1, 2 x, 0, 1, 2, x
		// k : 0, 1, 2 x, 0, 1, 2 x, 0, 1, 2 x, 0, 1, 2, x
		//
		// Sortie à la Console
		// DEBUT
		// *0.1
		// 1..
		// #*1.1
		// 2..
		// FIN

		cout << "DEBUT\n";

		for (int i = 0; i < 2; i++)
		{
			cout << "*";

			for (int j = 0; j < 2; j++)
			{
				cout << i + j;

				for (int k = 0; k < 2; k++)
				{
					if (k > j)
						cout << k;
					else
						cout << ".";
				}

				cout << "\n";
			}

			cout << "#";
		}

		cout << "FIN\n";
	}

	// TODO: Afficher le message suivant avec une seule boucle for
	// 1 2 3 4 5 6 7 8 9
	if (false)
	{
		cout << "\n--- Boucle à 1 niveau ---\n\n";

		for (int i = 0; i < 9; i++)
		{
			int numero = i + 1;
			cout << numero << " ";
		}
	}

	// TODO: Afficher le message suivant avec 2 boucles for
	// 
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 
	// - Englober la boucle for du dernier exercice (ligne) dans une autre boucle pour la reproduire 5 fois
	// - Renommer la variable 'i' de la boucle intérieure à 'j' par convention
	// - Retour de ligne doit être fait à la fin de chaque ligne donc dans la boucle !
	//		1 2 3 4 5 6 7 8 9\n
	//		...\n
	//		1 2 3 4 5 6 7 8 9\n
	if (false)
	{
		cout << "\n--- Boucle à 2 niveaux ---\n\n";

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int numero = j + 1;
				cout << numero << " ";
			}
			cout << "\n";
		}
	}

	// TODO:  Afficher les nombres descendant par ligne avec 2 boucles for
	// 9 8 7 6 5 4 3 2 1
	// 9 8 7 6 5 4 3 2 1
	// 9 8 7 6 5 4 3 2 1
	// 9 8 7 6 5 4 3 2 1
	// 9 8 7 6 5 4 3 2 1
	if (false)
	{
		cout << "\n--- Boucle négative 1 ---\n\n";

		for (int i = 0; i < 5; i++)
		{
			for (int j = 9; j < 1; j--)
			{
				cout << j;
			}
			cout << "\n";
		}
	}

	if (false)
	{
		cout << "\n--- Boucle négative 2 ---\n\n";

		// Version 2 : Avec itération positive
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++) // 0 ... 8
			{
				// 9 - 0 9 - 1 ...
				int nombre = 9 - j;
				cout << nombre << " ";
			}
			cout << "\n";
		}
	}

	// TODO: Afficher le même nombre par ligne plusieurs fois avec 2 boucles for
	// 1 1 1 1 1
	// 2 2 2 2 2
	// 3 3 3 3 3
	// 4 4 4 4 4
	// 5 5 5 5 5
	// 6 6 6 6 6
	// 7 7 7 7 7
	// 8 8 8 8 8
	// 9 9 9 9 9
	if (false)
	{
	cout << "\n--- Plusieurs fois un nombre ---\n\n";

		for (int ligne = 0; ligne < 9; ligne++)
		{
			int numeroLigne = ligne + 1;
			for (int colonne = 0; colonne < 5; colonne++)
			{
				cout << numeroLigne << " ";
			}

			cout << "\n";
		}
		
	}

	// TODO: Afficher le message suivant avec 3 boucles for
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 
	// ---
	// 
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 
	// ---
	// 
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	if (false)
	{
		cout << "\n--- Boucle 3 niveaux ---\n\n";

		

		for (int bloc = 0; bloc < 3; bloc++)
		{
			// Afficher le bloc de nombres

			// Afficher ligne vide, tirests et autre ligne vide
			for (int ligne = 0; ligne < 5; ligne++)
			{
				// 1 2 3 4 5 6 7 8 9
				for (int nombre = 0; nombre < 9; nombre++)
				{
					int nombreAffichage = nombre + 1;
					cout << nombreAffichage << " ";
				}
				cout << "\n";
			}

			if (bloc < 2)
			{
			cout << "\n";
			cout << "---\n";
			cout << "\n";
			}
		}

	}

	// TODO: Exclure les nombres (4 et 7) avec 2 boucles for
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 
	// TODO: Modifier pour afficher seulement les 20 premiers nombres
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 
	if (false)
	{
		cout << "\n--- Nombres sauf 4 et 7 ---\n\n";
		int compteurNombre = 0;
		for (int ligne = 0; ligne < 5; ligne++)
		{
			for (int nombre = 0; nombre < 9; nombre++)
			{
				int nombreAffichage = nombre + 1;
				/*if (nombreAffichage != 4 && nombreAffichage != 7)
				{
				cout << nombreAffichage << " ";
				}*/

				// Passer au prochain nombre si on est 4 ou 7

				if (nombreAffichage == 4 || nombreAffichage == 7)
					continue;

				cout << nombreAffichage << " ";

				++compteurNombre;
				// Terminer au 20ieme nombre
				if (compteurNombre >= 20)
					break;
			}

			// Terminer au 20ieme nombre
			if (compteurNombre >= 20)
				break;

			cout << "\n";
		}
	}

	// TODO: Version avec lecture de nombre maximal et nombre de lignes au clavier
	if (false)
	{
		cout << "\n--- Boucles avec lecture au clavier ---\n\n";

		cout << "Entrer le nombre maximal d'une ligne : ";
		int nombreMaximal;
		cin >> nombreMaximal;

		cout << "Entrer le nombre de lignes : ";
		int nombreLignes;
		cin >> nombreLignes;

		for (int ligne = 0; ligne < nombreMaximal; ligne++)
		{
			for (int nombre = 0; nombre < nombreMaximal; nombre++)
			{
				int nombreAffichage = nombre + 1;
				cout << nombreAffichage << " ";
			}
			cout << "\n";
		}
	}

	// TODO : Faire la somme des nombres entre les nombres et la somme totale
	// 
	// Somme 0 à 99	: ###
	// Somme 1000 à 1099 : ###
	// Somme 2000 à 2099 : ###
	// Somme 3000 à 3099 : ###
	// Somme 4000 à 4099 : ###
	// Somme 5000 à 5099 : ###
	// 
	// Somme de tous les nombres : ###
	if (true)
	{
		cout << "\n--- Sommes des nombres ---\n\n";

		// Initialiser le total à 0
		int total = 0;

		

		for (int groupe = 0; groupe < 6; groupe++)
		{
			int nombreDebut = groupe * 1000;

			int totalGroupeNombre = 0;
			for (int nombre = 0; nombre <= 99; nombre++)
			{
				int nombreCalcul = nombreDebut + nombre;

				//cout << nombreCalcul << "\n";
				totalGroupeNombre += nombreCalcul;
			}

			cout << format("Somme {} à {} : {}\n", nombreDebut, nombreDebut + 99, totalGroupeNombre);
			total += totalGroupeNombre;
			// Afficher le total une fois les boucles terminées
		}

			cout << format("Somme de tous les nombres : {}\n", total);
	}
}
