/*
	Auteur		: Mael Perreault
	Date		: 2025-10-24
	Description	: Introduction aux appels de fonctions avec tableaux et tableaux à 2 dimensions (arrays)
*/

#include <format>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma region Constantes
enum Piece
{
	Vide = 0,
	Pion,
	Cavalier,
	Fou,
	Tour,
	Reine,
	Roi,

	PieceQuantite
};

const string PIECE_SYMBOLES[] =
{
	".",
	"p",
	"c",
	"f",
	"t",
	"r",
	"R",
};

const int LIGNES = 8;
const int COLONNES = 8;
#pragma endregion

#pragma region DeclarationFonctions

void afficherTableau(const int tableau[], int tailleTableau);
void ajouterValeur(int tableau[], int tailleTableau, int valeurAjout);

int* creerNouveauTableauAjouterValeur(const int tableau[], int tailletableau, int valeur);

void remplirLigneRoi(int grille[][COLONNES], int ligne);
void remplirLignePiece(int grille[][COLONNES], int ligne, Piece piece);
void afficherGrille(const int grille[][COLONNES]);
#pragma endregion

int main()
{
	setlocale(LC_ALL, "en_US");

	std::cout << "--- Cours 32 - Tableaux 2D ---\n\n";

	// *** Fonctionnement mémoire ***
	// - Tableaux sont seulement une adresse mémoire, donc un pointeur déguisé
	// - Tableau
	//		- Pointeur vers l'adresse du début du bloc mémoire
	// - Opérateur [] est un raccourci pour calculer les adresses mémoires
	//		- [index] = adresse du début du tableau + (index * taille d'un élément du tableau)
	//		- 
	// 
	// Exemple :
	// 
	// int tableau[5];
	// 
	// Adresse tableau		: 0xabc23200
	// Taille int			: 4 octets
	// 
	// Adresse tableau[0]	: 0xabc23200 + (0 * 4) = 0xabc23200
	// Adresse tableau[1]	: 0xabc23200 + (1 * 4) = 0xabc23204
	// Adresse tableau[2]	: 0xabc23200 + (2 * 4) = 0xabc23208
	//
	// Note : tableau et tableau[0] pointent donc vers la même adresse mémoire

	// TODO: Faire un dessin du fonctionnement en mémoire

	if (false)
	{
		const int TAILLE_TABLEAU = 5;
		int valeurs[] = { 10, 20, 30, 40, 50 };

		// Utilisation de [] pour accéder aux valeurs
		for (int i = 0; i < TAILLE_TABLEAU; i++)
		{
			cout << format("valeurs[{}] : {}\n", i, valeurs[i]);
		}

		// Afficher les adresses mémoires du tableau et des éléments
		cout << format("\nAdresse 'valeurs' : {:#x}\n", (unsigned long long)valeurs);

		for (int i = 0; i < TAILLE_TABLEAU; i++)
		{
			cout << format("Adresse 'valeurs[{}]' : {:#x}\n", i, (unsigned long long) & valeurs[i]);
		}

		cout << "\n";

		// Calculer à la main les adresses mémoires pour obtenir les valeurs équivalent à utiliser l'opérateur []
		for (int i = 0; i < 5; i++)
		{
			// Calculer l'adresse mémoire de l'élément
			unsigned long long adresseTableau = (unsigned long long)valeurs;
			int tailleElementTableau = sizeof(int);
			unsigned long long adresseElement = adresseTableau + (i * tailleElementTableau);

			// Trouver un pointeur vers l'élément et la valeur de l'élément
			int* pointeurElement = (int*)adresseElement;
			int valeurElement = *pointeurElement;

			cout << format("Adresse element {} : {:#x} avec valeur {}\n", i, adresseElement, valeurElement);
		}
	}

	// *** Fonctions avec tableau ***
	// - Tableaux comme paramètres de fonctions
	//		- Tableau est seulement une adresse mémoire comme les références (&)
	//			- Toujours passé par référence (pointeur)
	//			- Pas de copie de chaque élément du tableau lorsque passé en paramètre
	// 			- Modifications du tableau dans la fonction affectent le tableau original
	//			- Équivalent
	//				- void maFonction(int tableau[]) { ... }
	//				- void maFonction(int& tableau[]) { ... }
	//			- Préférer passer par copie pour simplifier la compréhension
	//  - Information de la taille du tableau est perdue
	//		- Tableau est uniquement une adresse mémoire (ex. 0xabc23200)
	//		- Passer aussi la taille en paramètre pour pouvoir itérer sur le tableau avec une boucle for
	//			- void maFonction(int tableau[], int taille) { ... }

	if (false)
	{
		// TODO: Créer constante pour la taille du tableau
		const int TAILLE_TABLEAU = 10;

		// TODO: Initialiser un tableau de 10 entiers à 0
		int tableau[TAILLE_TABLEAU] = { 0 };

		// TODO: Créer une fonction 'afficherTableau' qui affiche les valeurs du tableau
		afficherTableau(tableau, TAILLE_TABLEAU);

		cout << "\n";

		// TODO: Créer une fonction 'ajouterValeur' qui permet d'ajouter une valeur à chaque élément du tableau
		ajouterValeur(tableau, TAILLE_TABLEAU, 5); 
		afficherTableau(tableau, TAILLE_TABLEAU);
		// 
		ajouterValeur(tableau, TAILLE_TABLEAU, 10);
		afficherTableau(tableau, TAILLE_TABLEAU);

		// *** Retourner un tableau dans une fonction ***
		// - Erreur
		//		- Impossible de retourner un tableau défini dans une fonction 
		// - Tableau retourne seulement une adresse mémoire
		//		- Bloc mémoire du tableau détruit du stack à la fin de la fonction '}'
		//		- Adresse retournée pointe vers un bloc mémoire invalide
		// 
		// int[] retournerTableau() 
		// { 
		// 	int tableau[5]; 
		// 	return tableau; 
		// }
		// 
		// int nouveauTableau[] = retournerTableau();
		//
		// Solution : 
		// - Utiliser un pointeur int*
		//		- Allouer dynamiquement avec 'new'
		//		- Libérer la mémoire avec 'delete[]'
		// - Trop compliqué pour le cadre du cours
		//		- Non nécessaire grace aux collection de la librairie STL (vector, etc.)

		// TODO: Décommenter le code suivant pour tester la fonction qui retourne un nouveau tableau
		// int* nouveauTableau = creerNouveauTableauAjouterValeur(tableau, TAILLE_TABLEAU, 100);
		// 
		// afficherTableau(tableau, TAILLE_TABLEAU); // Tableau original non modifié
		// afficherTableau(nouveauTableau, TAILLE_TABLEAU);
		// 
		// // Libérer la mémoire allouée dynamiquement par 'new' dans la fonction
		// delete[] nouveauTableau; 
	}

	// *** Tableaux à plusieurs dimensions ***
	// - Possible de créer des tableaux avec plusieurs dimensions
	//		- Souvent 2 dimensions
	// - Utilisé pour représenter des éléments visuels ou mathématiques
	//		- Grilles (échecs, labyrinthes, etc.)
	//		- Matrices
	//		- Images
	//
	// *** Fonctionnement mémoire ***
	// - Seulement encore une fois un raccourci
	// - Tableau 2D est un tableau 1D "aplati" en mémoire
	// - Opérateurs [][] calculent l'adresse mémoire finale en fonction des dimensions
	// 
	// Exemple pour un tableau de 3 lignes et 5 colonnes
	// - Adresse d'un élément du tableau [ligne][colonne]
	//		- adresseBase + ((ligne * colonnesTableau) + colonne) * tailleElement
	// - Taille d'un élément du tableau (en octets)
	//		- sizeof(type)

	// TODO: Faire un dessin en mémoire d'un tableau à 2 dimensions (plusieurs tableaux de suite)

	if (false)
	{
		// Définir un tableau 2D avc 3 lignes et 5 colonnes
		const int LIGNES = 3;
		const int COLONNES = 5;

		int tableau2D[LIGNES][COLONNES] =
		{
			{10, 20, 30, 40, 50},		// Ligne [0] avec 5 éléments [0][0] à [0][4]
			{60, 70, 80, 90, 100},		// Ligne [1] avec 5 éléments [1][0] à [1][4]
			{110, 120, 130, 140, 150}	// Ligne [2] avec 5 éléments [2][0] à [2][4]
		};

		// Afficher les adresses en mémoire et valeurs de chaque élément du tableau 2D
		for (int ligne = 0; ligne < LIGNES; ligne++)
		{
			for (int colonne = 0; colonne < COLONNES; colonne++)
			{
				// Calculer l'adresse mémoire
				unsigned long long adresseBase = (unsigned long long)tableau2D;
				int tailleElement = sizeof(int);
				unsigned long long adresseElement = adresseBase + ((ligne * COLONNES) + colonne) * tailleElement;

				// Trouver le pointeur vers l'élément et la valeur de l'élément
				int* pointeurElement = (int*)adresseElement;
				int valeurElement = *pointeurElement;

				cout << format("Adresse element[{}][{}] : {:#x} avec valeur {}\n", ligne, colonne, adresseElement, valeurElement);
			}
		}
	}

	// *** Syntaxe ***
	// - type nomTableau[tailleDimension1][tailleDimension2];
	//
	// Exemple tableau de 3 lignes et 5 colonnes
	// - int valeurs[3][5];
	// 
	// *** Initialisation valeurs ***
	// - Chaque dimension crée un nouveau {} et est séparé par une virgule (,)
	// - int valeurs[3][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15} };
	// 
	// *** Initialisation à zéro ***
	// - int valeurs[3][5] = {};
	// 
	// - Équivlents :
	// - int valeurs[3][5] = { {}, {}, {} };
	// - int valeurs[3][5] = { { 0 }, { 0 }, { 0 } };
	// - int valeurs[3][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
	// 
	// *** Accès aux éléments ***
	// - nomTableau[indexDimension1][indexDimension2];
	//
	// Exemple
	// - valeurs[0][0] = 123; // Modification de la première valeur (ligne 1, colonne 1)
	// - valeurs[1][2] = 456; // Modification d'une autre valeur (ligne 2, colonne 3)
	// - valeurs[2][4] = 789; // Modification de la dernière valeur (ligne 3, colonne 5)
	// 
	// *** Itération avec 2 boucles for imbriquées ***
	// - Utiliser une boucle for pour chaque dimension afin d'itérer sur chaque élément
	//
	// for (int ligne = 0; ligne < 3; ligne++)
	// {
	//     for (int colonne = 0; colonne < 5; colonne++)
	//     {
	//         cout << valeurs[ligne][colonne] << " ";
	//     }
	// 
	//     cout << "\n";
	// }

	// Exemples simples d'utilisation de tableaux 2D
	if (false)
	{
		// TODO: Définir un tableau 3 par 5 avec valeurs non initialisées
		int tableauNonInitialise[3][5];

		// TODO: Définir un tableau 3 par 5 initialisé à zéro
		int tableauZero[3][5] = {};

		// TODO: Définir un tableau 3 par 5 avec initialisation des valeurs :
		// - Ligne 1 [0] : 10, 20, 30, 40, 50		[0][0] à [0][4]
		// - Ligne 2 [1] : 60, 70, 80, 90, 100		[1][0] à [1][4]
		// - Ligne 3 [2] : 110, 120, 130, 140, 150  [2][0] à [2][4]

		int tableauValeurs[3][5] =
		{
			{ 10, 20, 30, 40, 50 },
			{ 60, 70, 80, 90, 100 },
			{ 110, 120, 130, 140, 150 }
		};

		// TODO: Regarder les valeurs en mémoire avec le débogueur
		//cout << "debug";

		// TODO: Afficher les valeurs du tableau avec valeurs avec 2 boucles for imbriquées
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int valeur = tableauValeurs[i][j];
				cout << valeur << " ";
			}

			cout << "\n";
		}

		// TODO: Modifier la valeur du 7ème élément à 555
		// 7ème élément		(ligne 2, colonne 2)
		tableauValeurs[1][1] = 555;


		// TODO: Modifier la valeur du 11ème élément à 666
		// 11ème élément	(ligne 3, colonne 1)
		tableauValeurs[2][0] = 666;


		// TODO: Afficher les valeurs du tableau avec valeurs avec 2 boucles for imbriquées

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int valeur = tableauValeurs[i][j];
				cout << valeur << " ";
			}

			cout << "\n";
		}

		// TODO: Modifier la valeur de la 2ème ligne à 99 pour tous les éléments avec une boucle for
		for (int colonne = 0; colonne < 5; colonne++)
		{
			tableauValeurs[1][colonne] = 99;
		}

		// TODO: Afficher les valeurs du tableau avec valeurs avec 2 boucles for imbriquées
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int valeur = tableauValeurs[i][j];
				cout << valeur << " ";
			}

			cout << "\n";
		}

		// TODO: Modifier la valeur de la 3ème colonne à 88 pour tous les éléments avec une boucle for
		for (int ligne = 0; ligne < 3; ligne++)
		{
			tableauValeurs[ligne][2] = 88;
		}

		// TODO: Afficher les valeurs du tableau avec valeurs avec 2 boucles for imbriquées
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int valeur = tableauValeurs[i][j];
				cout << valeur << " ";
			}

			cout << "\n";
		}
	}

	// Exemple d'utilisation d'un tableau 2D pour une grille d'échec
	if (false)
	{
		// TODO: Créer un tableau à 2 dimension pour une grille d'échec vide (8 x 8)
		int grille[8][8] = {}; // Piece::Vide = 0

		// TODO: Remplir la 1ère ligne des pièces du joueur blanc dans l'ordre à l'aide du enum Piece :
		// - Tour, Cavalier, Fou, Reine, Roi, Fou, Cavalier, Tour
		grille[0][0] = Piece::Tour;
		grille[0][1] = Piece::Cavalier;
		grille[0][2] = Piece::Fou;
		grille[0][3] = Piece::Reine;
		grille[0][4] = Piece::Roi;
		grille[0][5] = Piece::Fou;
		grille[0][6] = Piece::Cavalier;
		grille[0][7] = Piece::Tour;

		// TODO: Remplir la 1ère ligne des pièces du joueur blanc dans l'ordre à l'aide du enum Piece :
		// - Tour, Cavalier, Fou, Reine, Roi, Fou, Cavalier, Tour
		grille[7][0] = Piece::Tour;
		grille[7][1] = Piece::Cavalier;
		grille[7][2] = Piece::Fou;
		grille[7][3] = Piece::Reine;
		grille[7][4] = Piece::Roi;
		grille[7][5] = Piece::Fou;
		grille[7][6] = Piece::Cavalier;
		grille[7][7] = Piece::Tour;

		// TODO: Remplir avec une boucle la 2ème ligne de pions pour le joueur blanc
		for (int colonne = 0; colonne < 8; colonne++)
		{
			grille[1][colonne] = Piece::Pion;
		}

		// TODO: Remplir avec une boucle la 7ème ligne de pions pour le joueur noir
		for (int colonne = 0; colonne < 8; colonne++)
		{
			grille[6][colonne] = Piece::Pion;
		}

		// TODO: Afficher la grille avec 2 boucles for imbriquées à l'aide des symboles du tableau PIECE_SYMBOLES
		for (int ligne = 0; ligne < 8; ligne++)
		{
			for (int colonne = 0; colonne < 8; colonne++)
			{
				int piece = grille[ligne][colonne];
				string symbole = PIECE_SYMBOLES[piece];
				cout << symbole << " ";
			}
			cout << "\n";
				
		}
	}

	// *** Fonctions avec tableau 2D ***
	// - Tableau 2D est aussi un pointeur déguisé
	//		- Modifications dans la fonction affectent le tableau original
	// - Moins puissant que les tableau à une dimension
	//		- Doit spécifier la taille de toutes les dimensions sauf la première dimension
	//		- Passe en paramètre la taille de la premiere dimension
	//		- void utiliserTableau(int tableau[][COLONNES], int lignes) { ... }
	// - Normalement les pointeurs sont utilisés pour plus de flexibilité
	//		- void utiliserTableau(int** tableau, int lignes, int colonnes) { ... }
	//		- Dépasse largement le cadre du cours
	//		- En C#, les pointeurs ne sont pas manipulés directement de la même manière
	if (true)
	{
		int grille[LIGNES][COLONNES] = {};

		// TODO: Utiliser les 3 fonctions qui prennent le tableau en paramètre pour remplir et afficher la grille :
		// - 'remplirLignePiece'
		// - 'remplirLigneRoi'
		// - 'afficherGrille'
		const int LIGNE_ROI_BLANC = 0;
		const int LIGNE_PIONS_BLANC = 1;
		const int LIGNE_PIONS_NOIR = 6;
		const int LIGNE_ROI_NOIR = 7;

		remplirLigneRoi(grille, LIGNE_ROI_BLANC);
		remplirLigneRoi(grille, LIGNE_ROI_NOIR);

		remplirLignePiece(grille, LIGNE_PIONS_BLANC, Piece::Pion);
		remplirLignePiece(grille, LIGNE_PIONS_NOIR, Piece::Pion);

		afficherGrille(grille);
	}

	// TODO: Transformer l'affichage du tableau du bloc plus haut en une fonction 'afficherTableau2D'


	// *** Exemple de programme avec tableau 2D ***
	// - Programme qui enregistre le score d'une partie de bowling à 10 manches avec 4 joueurs
	if (true)
	{
		const int NOMBRE_MANCHES = 10;
		const int NOMBRE_JOUEURS = 4;

		// TOOD: Initialiser un tableau 2D pour stocker les scores des joueurs et des manches à 0
		int scores[NOMBRE_MANCHES][NOMBRE_JOUEURS] = {};

		// TODO: Jouer chaque manche en inscrivant à tour de role le score de chaque joueur
		for (int manche = 0; manche < NOMBRE_MANCHES; manche++)
		{
			cout << format("\n--- Manche {} ---\n", manche + 1);

			for (int joueur = 0; joueur < NOMBRE_JOUEURS; joueur++)
			{
				cout << format("Entrez le score du joueur {} : ", joueur + 1);
				int scoreJoueur;
				cin >> scoreJoueur;
				scores[manche][joueur] = scoreJoueur;
			}
		}

		// TODO: Afficher un tableau de scores avec chaque score sur 4 caractères {:4}
		int totalScoreJoueurs[NOMBRE_JOUEURS] = {};

		cout << "\n--- Scores Manches ---\n";
		for (int joueur = 0; joueur < NOMBRE_JOUEURS; joueur++)
		{
			cout << format("Joueur {} : ", joueur);

			for (int manche = 0; manche < NOMBRE_MANCHES; manche++)
			{
				int score = scores[manche][joueur];
				cout << format("{:4} ", score);

				totalScoreJoueurs[joueur] += score;
			}

			cout << "\n";
		}

		// TODO: Afficher le score total de chaque joueur à la fin de la partie
		cout << "\n--- Scores Total ---\n";
		for (int joueur = 0; joueur < NOMBRE_JOUEURS; joueur++)
		{
			int total = totalScoreJoueurs[joueur];
			cout << format("Joueur {} : {}\n", joueur, total);
		}
	}
}

#pragma region DefinitionFonctions
void afficherTableau(const int tableau[], int tailleTableau)
{
	for (int i = 0; i < tailleTableau; i++)
	{
		cout << format("tableau[{}] : {}\n", i, tableau[i]);
	}
}

void ajouterValeur(int tableau[], int tailleTableau, int valeurAjout)
{
	for (int i = 0; i < tailleTableau; i++)
	{
		tableau[i] += valeurAjout;
	}
}

int* creerNouveauTableauAjouterValeur(const int tableau[], int tailletableau, int valeur)
{
	int* nouveauTableau = new int[tailletableau];

	for (int i = 0; i < tailletableau; i++)
	{
		nouveauTableau[i] = tableau[i] + valeur;
	}

	return nouveauTableau;
}

void remplirLigneRoi(int grille[][COLONNES], int ligne)
{
	grille[ligne][0] = Piece::Tour;
	grille[ligne][1] = Piece::Cavalier;
	grille[ligne][2] = Piece::Fou;
	grille[ligne][3] = Piece::Reine;
	grille[ligne][4] = Piece::Roi;
	grille[ligne][5] = Piece::Fou;
	grille[ligne][6] = Piece::Cavalier;
	grille[ligne][7] = Piece::Tour;
}

// TODO: Demander d'avoir une taille constante pour 
void remplirLignePiece(int grille[][COLONNES], int ligne, Piece piece)
{
	for (int colonne = 0; colonne < COLONNES; colonne++)
	{
		grille[ligne][colonne] = piece;
	}
}

void afficherGrille(const int grille[][COLONNES])
{
	// Afficher les numéros de colonne
	cout << "   ";
	for (int colonne = 0; colonne < COLONNES; colonne++)
	{
		cout << format("{} ", colonne + 1);
	}
	cout << "\n\n";

	// Afficher une ligne de la grille
	for (int ligne = 0; ligne < LIGNES; ligne++)
	{
		// Afficher la lettre de la ligne
		char caracterLigne = 'A' + ligne;
		cout << caracterLigne << "  ";

		// Afficher les pièces de la ligne dans chaque colonne de la ligne
		for (int colonne = 0; colonne < COLONNES; colonne++)
		{
			int indexPiece = grille[ligne][colonne];
			string caracterePiece = PIECE_SYMBOLES[indexPiece];
			cout << format("{:<2}", caracterePiece);
		}

		cout << "\n";
	}
}
#pragma endregion