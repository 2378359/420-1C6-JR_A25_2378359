/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-023
	Description		: cours 13 while
*/

// Inclusion des librairies
// TODO: Modifier la version du Projet à C++20 pour la librairie <format>
// TODO: Compiler le code pour le tester et sauvegarder sur Git local et puis sur GitHub
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

// TODO: Montrer le corrigé de l'examen

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "");

	// Affichage de l'en-tête
	cout << "--- Cours 13 - While ---\n";

	// *** While ***
	// - Instruction de boucle qui permet de faire plusieurs fois un même travail
	// - Permet de 'remonter' dans le code afin de rexécuter une partie de code
	// 
	// while ( condition )
	// {
	//		// Travail à exécuter
	//		// Attention : Travail doit changer la condition du while(), sinon boucle infinie
	// }

	// TODO: Dessin avec if() et while() et condition true et false

	// TODO: Programmer une boucle infinie qui affiche Hello world!
	if (false)
	{
		cout << "--- Hello world sans fin ---\n";

		while (true)
		{
			cout << "Hello World!\n";
		}

		cout << "Fin de la boucle infinie Hello world !\n";
	}

	// Boucle pour la lecture au clavier
	// - Déclarer une variable avant le 

	// TODO: Programmer une boucle qui arrête lorsque l'utilisateur entre "stop" à la Console
	if (false)
	{
		cout << "--- Hello world avec fin ---\n";

		string choixUtilisateur = ""; // != "stop"

		while (choixUtilisateur != "stop")
		{
			cout << "Hello world!\n";
			cout << "Entrer stop pour quitter : ";
			cin >> choixUtilisateur;
		}

		cout << "Fin de la boucle avec fin Hello world !\n";
	}

	// *** Scope ***
	// - Scope de la boucle while est détruit à la fin de chaque boucle
	//		- Début du Scope : 
	//		- Fin du Scope : Variables dans le Scope du while sont libérées en mémoire
	// 
	// - Pour conserver une valeur à travers plusieurs itération de la boucle while()
	//		- Déclarer la variable à l'extérieur du while() avant le while()
	//		- Ne pas redéfinir de nouvelle valeur avant le while
	if (false)
	{
		cout << "--- Addition ---\n\n";

		double addition = 0;
		cout << format("Valeur addition avant le while() : {}\n\n", addition);

		while (addition < 100)
		{
			cout << format("Valeur addition au début du while() : {}\n", addition);
			addition += 20;
			cout << format("Valeur addition a la fin du while() : {}\n\n", addition);
		}

		cout << format("Valeur addition après le while() : {}\n\n", addition);
	}

	// Erreur
	// - Attention, C++ est un peu traitre, il vous laisse vous tirer dans le pied
	// - Possible de déclarer une variable
	if (false)
	{
		cout << "--- Addition avec boucle infinie ---\n\n";

		double addition = 0;
		cout << format("Valeur addition avant le while() : {}\n\n", addition);

		while (addition < 100)
		{
			// Erreur, définition d'une 2ème variable qui est supprimer à la fin de chaque boucle
			double addition = 0;

			cout << format("Valeur addition au début du while() : {}\n", addition);
			addition += 20;
			cout << format("Valeur addition a la fin du while() : {}\n\n", addition);
		}

		cout << format("Valeur addition après le while() : {}\n\n", addition);
	}

	// TODO: Faire une lecture au clavier qui arrête lorsque l'utilisateur saisit une entrée valide
	// 
	// cin.fail()
	// - Retourne 'true' ou 'false' qui indique si la dernière lecture cin >> ... a échouée ou réussie
	// - Ex. Lors de la lecture d'un entier avec cin >> ...
	//		- L'utilisateur entre '12345' cin.fail() => retourne 'false'
	//		- L'utilisateur entre 'abcde' cin.fail() => retourne 'true'
	// 
	// cin.clear()
	// - Vide le contenu entier du contenu des lectures de cin (buffer) qui n'a pas encore été utilisé
	// - Supprimer les espaces et lignes vides que l'utilisateur a pu entrer par erreur

	// TODO: Lire un nombre entier et arrêter lorsque le nombre est valide
	if (true)
	{
		cout << "--- Lire un nombre ---\n\n";

		int nombre = 0;
		bool estNombreInvalide = true;

		while (estNombreInvalide)
		{
			cout << "Entrer un nombre entier : ";
			cin >> nombre;
			

			bool resultatCin = cin.fail();

			if (estNombreInvalide)
			{
				cout << "Erreur : nombre n'est pas entier.";
				cin.clear();
				cin.ignore();
			}
		}
		cout << "Fin de lecture du nombre !\n";
	}

	// *** Continue et break ***
	// - Permettent de passer à la prochaine boucle ou de terminer la boucle
	// - Utiles dans certains cas pour décomplexifier la condition de la boucle
	// - Préférer d'utiliser condition de la boucle au lieu de continue et break lorsque possible

	// TODO: Exemple de boucle avec condition complexe sur 2 éléments distinct
	if (false)
	{
		cout << "--- 10 nombres ---\n";

		// Initialiser les variables afin d'entrer dans la boucle
		int nombresValides = 0;

		// Lire et comptabiliser jusqu'à 10 nombres à la Console tant que l'utilisateur n'entre pas un nombre négatif
		while (nombresValides < 10)
		{
			// Lire un nombre à la Console
			cout << format("Entrer le nombre {} : ", nombresValides + 1);
			int nombre = 0;
			cin >> nombre;

			// Vérifier si un nombre négatif pour terminer
			if (nombre < 0)
				break;

			// Vérifier si le nombre doit être comptabilisé ou écrire une erreur à l'écran
			if (nombre > 1000)
			{
				cout << format("Erreur : Nombre {} est trop grand, maximum 1000.\n", nombre);
			}
			else if (nombre >= 0)
			{
				nombresValides += 1;
			}
		}

		cout << "Fin du programme qui lit 10 nombres !\n";
	}

	// TODO: Simplifier la boucle avec break pour terminer la lecture des nombres
	// TODO: Simplifier la boucle avec continue pour passer à la prochaine lecture
	if (false)
	{
		cout << "--- 10 nombres avec break et continue ---\n";

		// Débuter la lecture des nombres avec le premier nombre
		int nombresValides = 0;

		// Lire et comptabiliser jusqu'à 10 nombres à la Console tant que l'utilisateur n'entre pas un nombre négatif
		while (nombresValides < 10)
		{
			// Lire un nombre à la Console
			cout << format("Entrer le nombre {} : ", nombresValides + 1);
			int nombre = 0;
			cin >> nombre;

			// Arrêter la lecture des nombres lorsqu'un nombre négatif est entré
			if (nombre < 0)
				break;

			// Afficher un message d'erreur et demander une nouvelle saisie lorsque le nombre est trop gros
			if (nombre > 1000)
			{
				cout << format("Erreur : Nombre {} est trop grand, maximum 1000.\n", nombre);
				continue;
			}

			// Comptabiliser le nombre entré valide
			nombresValides += 1;
		}

		cout << "Fin du programme 10 nombres avec break et continue !\n";
	}

	
	// *** do {} while(); ***
	// - Différence entre les 2 types de boucles
	//		- while() {} : exécuté 0 fois ou plus
	//		- do {} while(); : exécuté 1 fois ou plus
	// - while()
	//		- Généralement plus utilisé
	//		- Simplement initialiser la condition afin de rentrer au moins 1 fois dans la boucle
	if (false)
	{
	do
	{
		cout << "Hello world!\n";
	} while (true);
		
	cout << "fin";
	}
	// Erreur
	// - Point-virgule manquant à la fin du while(); pour indiquer qu'il n'y aura pas d'accolades {}
	//do
	//{
	//	cout << "Erreur de point-virgule manquant\n";
	//} while (true) // Erreur

	// TODO: Programmer Hello world avec une boucle do ... while(false)  
	if (false)
	{
		cout << "--- Hello world au moins une fois ---\n";


		cout << "Fin du Hello world au moins une fois !\n";
	}

	// TODO: Ajouter une condition de fin au Hello World lorsque l'utilisateur entre la valeur 10
	if (false)
	{
		cout << "--- Hello world avec do ... while() ---\n";
		int nombre; // initialisation non nécessaire

		do
		{
			cout << "Hello world!\n";

			cout << "Entrer 10 pour terminer : ";
			cin >> nombre;
		} while (nombre != 10);
		cout << "Fin du Hello world avec do ... while() !\n";
	}

	// *** Programmes ***
	// Dans un programme, standard contient les éléments suivants :
	// - Une boucle principale infinie qui permet de recommencer le programme
	// - Plusieurs boucles de lectures, une par variable à saisir à la Console
	// - Au moins une des saisie permet à l'utilisateur de terminer le programme
	// - Calculer et afficher les résultats

	if (false)
	{
		cout << "--- Structure de programme ---\n";

		// Alternative pour ne pas faire un while (true)
		// int variable1 = -1;
		// while (variable1 != 0)
		// {
		//	//Lire la variable 1
		//	cin >> variable1;
		// 
		//  // Vérifier pour ne pas effectuer le reste du code et terminer la boucle
		//	if (variable1 != 0)
		//  {
		//		
		//	}
		// }
		// 

		// Boucle principale pour recommencer le programme à l'infini
		while (true)
		{
			// Lecture et validation de la variable 1
			int variable1 = 0;

			// Version 1 : Avec condition de fin de boucle dans le while
			while (variable1 >= 0)
			{
				cout << "Entrer la variable 1 (0 pour quitter le programme) : ";
				cin >> variable1;

				bool estVariable1Valide = variable1 >= 0;
				if (!estVariable1Valide)
				{
					// Afficher une erreur et recommencer la boucle
					cout << "Erreur : variable 1\n";
				}
			}

			// Vérifier la variable qui permet de terminer le programme
			if (variable1 == 0)
				break;

			// Lecture et validation de la variable 2
			int variable2 = 0;

			// Version 2 : Avec boucle infinie terminée par un break;
			while (true)
			{
				cout << "Entrer la variable 2 : ";
				cin >> variable2;

				// Terminer la boucle avec break si la valeur entrée est valide
				bool estVariable2Valide = variable2 >= 0;
				if (estVariable2Valide)
					break;

				// Afficher une erreur et recommencer la boucle
				cout << "Erreur : variable 2\n";
			}

			// Lecture et validation de la variable 3, 4, 5, etc.

			// Calculs avec les variables validées
			int resultat = variable1 + variable2;

			// Affichage des résultats des calculs
			cout << format("Résultat : {}\n", resultat);
		}

		cout << "Fin du programme !\n";
	}
}
