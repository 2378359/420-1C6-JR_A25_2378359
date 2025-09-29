/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-25
	Description		: cours 13 For
*/

#include <format>
#include <iostream>
#include <string>

// Utiliser le namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "");

	std::cout << "--- Cours 14 - For ---\n\n";

#pragma region OperateursIncrementation
	if (false)
	{
		std::cout << "--- Operateurs (++, --) ---\n\n";
		// *** Incr�mentation et d�cr�mentation ***
		// - Raccourci qui permet d'incr�menter (++) ou de d�cr�menter (--) une variable
		// 
		// Op�rateur d'incr�mentation
		// ----------------------------
		// ++variable;
		// 
		// variable += 1;
		// variable = variable + 1;
		// 
		// Op�rateur de d�cr�mentation
		// ----------------------------
		// --variable;
		// 
		// variable -= 1;
		// variable = variable - 1;
		// 
		// - Existe 2 types d'op�rateurs selon s'il sont �crit avant ou apr�s la variable
		//		- Pr�-incrementation
		//			- ++nombre, --nombre
		//		- Post-incremenation
		//			- nombre++, nombre--
		int pre = 0;
		int post = 0;

		// Op�rateurs ont un comportement diff�rent sur la ligne o� ils sont utilis�s
		cout << format("Pre sur la ligne : {}\n", ++pre);		// Incr�mente avant (0 + 1) et retourne pour la ligne (1)
		cout << format("Post sur la ligne : {}\n\n", post++);	// Retourne pour la ligne (0) et incr�mente apr�s (0 + 1)

		// Op�rateurs sont �quivalent une fois la ligne pass�e
		cout << format("Pre apres la ligne : {}\n", pre);		// 1
		cout << format("Post apres la ligne : {}\n\n", post);	// 1

		// Pour ne pas se tromper, utiliser l'op�rateur sur une ligne seule et non dans un affichage ou un calcul
		++pre;  // Incr�mente (1 + 1) et n'est pas utilis� sur la ligne
		post++; // N'est pas utilis� sur la ligne et incr�mente apr�s (1 + 1)

		cout << format("Pre apres la ligne : {}\n", pre);		// 2
		cout << format("Post apres la ligne : {}\n\n", post);	// 2

		// Exemple d'un programme qui utilise les op�rateurs d'incr�mentation et de d�cr�mentation
		// - D�buter avec x = -5 et y = 10
		// - Apr�s chaque affichage 
		//			- Incr�menter x
		//			- D�cr�menter y
		// - Continuer tant que x est un nombre n�gatif

		std::cout << "--- Programme avec operateurs (++, --) ---\n\n";

		int x = -5;
		int y = 10;

		while (x < 0)
		{
			int resultat = x * y;
			cout << format("Resultat : {} * {} = {}\n", x, y, resultat);

			++x; // x = x + 1;
			--y; // y = y - 1;
		}

		cout << "Fin du programme avec operateurs\n";
	}
#pragma endregion

#pragma region For
	if (false)
	{
		// *** For ***
		// - Autre type de boucle afin de r�p�ter un travail un nombre de fois pr�d�fini
		// - While
		//		- Nombre de r�p�titions inconnues ou infinies
		//		- Ex. lecture utilisateur, boucle principale infinie du programme, etc.
		// - For
		//		- Nombre de r�p�tition connu
		//		- Ex. afficher 10 messages, permettre 10 tentatives de mot de passe, etc.
		// 
		// for ( d�claration iterateur; condition; incr�mentation de l'it�rateur )
		// {
		//		// Travail � effectuer un certain nombres de fois (it�rations)
		// }
		//
		// Note : par convention, utiliser 'int i' comme variable it�rateur dans une boucle for()

		// *** for() ***
		// Afficher � la Console les nombre 1 � 5 s�par�s par un espace
		cout << "\n--- Instruction for() ---\n\n";

		// 1) Variable i d�finie avec la valeur de d�part une seule fois avant le d�but de la boucle
		// 2) Condition est v�rifi�e � chaque d�but de boucle passer � l'�tape 3 (true) ou 5 (false)
		for (int i = 1; i <= 5; i++)
		{
			// 3) Travail � effectuer � chaque it�ration de la boucle
			cout << i;
			cout << " ";

			// 4) D�truire le Scope, incr�menter la variable i (i++) et recommencer � l'�tape 2
		}
		// 5) Variable i d�truite apr�s l'ex�cution compl�te de la boucle

		cout << "Fin du for\n\n";

		// Erreur : variable i a �t� d�truite apr�s la fin du for() bien qu'elle semble �tre contenue dans le main()
		//cout << i;

		// *** while() ***
		// Afficher � la Console les nombre 1 � 5 s�par�s par un espace
		cout << "\n\n--- Instruction while() equivalente ---\n\n";

		{
			// 1) Variable i d�finie avec la valeur de d�part une seule fois avant le d�but de la boucle
			int i = 1;

			// 2) Condition est v�rifi�e � chaque d�but de boucle passer � l'�tape 3 (true) ou 5 (false)
			while (i <= 5)
			{
				// 3) Travail � effectuer � chaque it�ration de la boucle
				cout << i;
				cout << " ";

				// 4) D�truire le Scope, incr�menter la variable i et recommencer � l'�tape 2
				++i;

				// Note : post ou pr�-incr�mentation n'a aucun impact sur la boucle
				// i++;
			}
		}
		// 5) Variable i d�truite apr�s l'ex�cution compl�te de la boucle

		cout << "Fin du while\n\n";

		// Erreur : variable i a �t� d�truite apr�s la fin du while() car elle est dans un Scope
		//cout << i;

		// *** It�rateur ***
		// Incr�mentation 1
		for (int i = 0; i < 10; i++)
		{
			// Travail
		}

		// D�cr�mentation 1 (boucle n�gative)
		for (int i = 10; i >= 0; i--)
		{
			// Travail
		}

		// Incr�mentation d'une valeur sup�rieure � 1 (non standard)
		for (int i = 0; i < 10; i += 2)
		{
			// Travail
		}

		// D�cr�mentation  d'une valeur sup�rieure � 1 (non standard)
		for (int i = 10; i >= 0; i -= 3)
		{
			// Travail
		}
	}
#pragma endregion

#pragma region TracerBouclesFor
	// *** Tracer une boucle for ***
	// Il faut tout avant tout �tre capable de tracer les r�sultats des boucles
	// Plus tard, les boucles contiendront des erreurs et il faudra les trouver
	// Il faut donc 

	// TODO: Tracer la boucle 1 suivante
	if (false)
	{
		cout << "\n\n--- Tracer boucle 1 ---\n\n";

		// Variables
		// i : 1, 2, 3, 4, 5
		// 
		// Sorties � la Console
		// Avant
		// 1 2 3 4 5 Apres

		cout << "Avant\n";

		for (int i = 1; i <= 5; i++)
		{
			cout << i;
			cout << " ";
		}

		cout << "Apres\n";
	}

	// TODO: Tracer la boucle 2 suivante
	if (false)
	{
		cout << "\n\n--- Tracer boucle 2 ---\n\n";

		// Variables
		// i		:  5, 4, 3, 2, 1
		// valeur	:  50, 40, 30, 20
		// resultat : 10, -40, 0, -30, -10 
		//
		// Sorties � la Console
		// 50 40
		// 30 20 
		// resultat : -10


		int resultat = 10;

		for (int i = 5; i > 1; i--)
		{
			int valeur = i * 10;

			cout << valeur;

			if (i == 2 || i == 4)
			{
				cout << "\n";

				resultat += valeur;
			}
			else
			{
				cout << " ";

				resultat -= valeur;
			}
		}

		cout << format("Resultat : {}\n", resultat);
	}
#pragma endregion

#pragma region EcrireBouclesFor
	// *** Techniques d'�criture de boucle ***

	if (false)
	{
		// *** Exemple simple ***
		// 1) Identifier un travail r�p�titif � optimiser
		// Parfois le travail est simple � identifier, car les lignes se r�p�tent exactement sans changements
		// Compter le nombre d'it�rations � effectuer (ex. 10 fois)
		cout << "--- Version sans for ---\n\n";

		cout << "Bonjour!\n"; // 1
		cout << "Bonjour!\n"; // 2
		cout << "Bonjour!\n"; // 3
		cout << "Bonjour!\n"; // 4
		cout << "Bonjour!\n"; // 5
		cout << "Bonjour!\n"; // 6
		cout << "Bonjour!\n"; // 7
		cout << "Bonjour!\n"; // 8
		cout << "Bonjour!\n"; // 9
		cout << "Bonjour!\n"; // 10

		// 2) Cr�er une boucle avec le nombre d'it�rations et le travail � r�p�ter

		// TODO : Utiliser 0 comme valeur initiale pour l'utilisateur de tableaux plus tard (0 < it�rations)
		// 10 it�rations : 0 1 2 3 4 5 6 7 8 9
		cout << "\n--- Version 1 ---\n\n";
		for (int i = 0; i < 10; i++)
		{
			cout << "Bonjour!\n";
		}


		// TODO : Commencer � 1 et arr�ter au nombre d'it�rations  (1 <= it�rations)
		// 10 it�rations : 1 2 3 4 5 6 7 8 9 10
		cout << "\n--- Version 2 ---\n\n";
		for (int i = 1; i <= 10; i++)
		{
			cout << "Bonjour!\n";
		}

	}

	if (false)
	{
		// *** Exemple avec it�rateur ***
		// 1) Identifier un travail r�p�titif � optimiser
		// Parfois le travail se r�p�te, mais une partie du travail change (1, 2, 3 ... 12)
		// Bonjour �tudiant ###! (12 fois)
		cout << "--- Version sans for ---\n\n";

		cout << "Bonjour etudiant 1!\n";
		cout << "Bonjour etudiant 2!\n";
		cout << "Bonjour etudiant 3!\n";
		cout << "Bonjour etudiant 4!\n";
		cout << "Bonjour etudiant 5!\n";
		cout << "Bonjour etudiant 6!\n";
		cout << "Bonjour etudiant 7!\n";
		cout << "Bonjour etudiant 8!\n";
		cout << "Bonjour etudiant 9!\n";
		cout << "Bonjour etudiant 10!\n";
		cout << "Bonjour etudiant 11!\n";
		cout << "Bonjour etudiant 12!\n";

		// 2) Cr�er une boucle avec le bon nombre d'it�rations et le travail inclus une seule fois

		// TODO : Version avec le nombre d'it�rations (1 <= it�rations)
		// 12 it�rations : 1 2 3 4 5 6 7 8 9 10 11 12
		cout << "\n--- Version 1 ---\n\n";
		for (int i = 1; i <= 12; i++)
		{
			cout << format("Bonjour etudiant {}!\n", i);
		}


		// TODO : Version avec 0 comme valeur initiale pour l'utilisateur de tableaux plus tard (0 < it�rations)
		// 12 it�rations :  0 1 2 3 4 5 6 7 8 9 10 11
		// - Utiliser l'it�rateur afin de g�n�rer le nombre � utiliser
		cout << "\n--- Version 2 ---\n\n";
		for (int i = 0; i < 12; i++)
		{
			cout << format("Bonjour etudiant {}!\n", i+1);
		}

	}

	if (false)
	{
		// *** Exemple complexe ***
		// 1) Identifier un travail r�p�titif � optimiser
		// Parfois le travail se r�p�te, mais une partie du travail change
		// Bonjour �tudiant ###! (2500000 + 1001, 2002, 3003 ...  9009)
		cout << "--- Version sans for ---\n\n";

		cout << "Bonjour etudiant 2501001!\n";
		cout << "Bonjour etudiant 2502002!\n";
		cout << "Bonjour etudiant 2503003!\n";
		cout << "Bonjour etudiant 2504004!\n";
		cout << "Bonjour etudiant 2505005!\n";
		cout << "Bonjour etudiant 2506006!\n";
		cout << "Bonjour etudiant 2507007!\n";
		cout << "Bonjour etudiant 2508008!\n";
		cout << "Bonjour etudiant 2509009!\n";

		const int NUMERO_ETUDIANT_BASE = 2500000;

		// �viter, car difficile � suivre et � d�boguer
		// Penser plut�t en terme de nombre d'it�rations � effecter pour les it�rateurs
		cout << "--- Version a eviter ---\n\n";

		// 9 it�rations : 2501001, ... ???
		for (int i = 2501001; i <= 2509009; i += 1001)
		{
			cout << format("Bonjour etudiant {}!\n", i);
		}

		// TODO : Version avec le nombre d'it�rations (1 <= it�rations)
		// 9 it�rations : 1 2 3 4 5 6 7 8 9
		cout << "\n--- Version 1 ---\n\n";
		for (int i = 1; i <= 9; i++)
		{
			int  milliers = 1000 * i;
			int dernierChiffre = i;
			int numeroEtudiant = NUMERO_ETUDIANT_BASE + milliers + dernierChiffre;
			cout << format("Bonjour etudiant {}!\n", numeroEtudiant);
		}


		// TODO : Version avec 0 comme valeur initiale pour l'utilisateur de tableaux plus tard (0 < it�rations)
		// 9 it�rations : 0 1 2 3 4 5 6 7 8
		cout << "\n--- Version 2 ---\n\n";
		for (int i = 0; i < 9; i++)
		{
			int  milliers = 1000 * (i + 1);
			int dernierChiffre = (i + 1);
			int numeroEtudiant = NUMERO_ETUDIANT_BASE + milliers + dernierChiffre;
			cout << format("Bonjour etudiant {}!\n", numeroEtudiant);
		}
	}

	if (false)
	{
		cout << "--- Plusieurs operations ---\n\n";

		// TODO: Plusieurs calculs ou travaux en m�me temps dans une it�ration de la boucle for()
		// 
		// Hello, 0 valeur 10 et 100 !
		// Hello, 1 valeur 11 et 200 !
		// Hello, 2 valeur 12 et 300 !
		for (int i = 0; i < 3; i++)
		{
			int hello = i;
			int valeur = 10 + i;
			int et = (i + 1) * 100;
			cout << format("Hello, {} valeur {} et {} !\n", hello, valeur, et);
		}

	}

	if (false)
	{
		cout << "--- Somme nombres ---\n\n";

		// Accumuler un r�sultat plusieurs fois et l'afficher apr�s la boucle
		// TODO: Faire une somme des nombres 0 � 99

		int somme = 0;
		for (int i = 1; i <= 99; i++)
		{
			somme = +i;
		}


		cout << format("Somme des nombres : {}\n", somme);

		// TODO: Cr�er une constante pour la valeur de fin de la boucle
	}

#pragma endregion

#pragma region ProgrammeFor
	// TODO: Compl�ter le programme afin d'afficher les num�ros pour les �tudiants : 1000, 1001, 1002, etc.
	if (true)
	{
		while (true)
		{
			// Lire le nombre d'�tudiant entier
			cout << "Entrer le nombre d'etudiants (negatif pour terminer) : ";
			int nombreEtudiant;
			cin >> nombreEtudiant;

			// Afficher une erreur si le nombre d'�tudiants n'est pas un entier et recommencer la lecture
			if (cin.fail())
			{
				cout << "Erreur : le nombre d'etudiant doit etre un entier.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			// Terminer la boucle si le nombre d'�tudiant est n�gatif
			if (nombreEtudiant < 0)
				break;
			// Afficher les num�ros d'�tudiants : 1000, 1001, 1002
			for (int i = 0; i < nombreEtudiant; i++)
			{
				int numeroEtudiant = 1000 + i;
				cout << format("Numero etudiant : {}\n", numeroEtudiant);
			}
		}
	}
#pragma endregion
}
