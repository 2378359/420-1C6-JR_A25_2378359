/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-09
	Description		: cours 07 Enum
*/

// Inclusion des librairies
// TODO: Modifier la version du Projet � C++20 pour la librairie <format>
// TODO: Compiler le code pour le tester et sauvegarder sur Git local et puis sur GitHub
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

// *** Constantes ***
const int TEMPERATURE_FARENHEIT_ZERO = 32;
const int TEMPERATURE_CELSIUS_FACTEUR = 9.0 / 5.0;
const int TEMPERATURE_FARENHEIT_FACTEUR = 5.0 / 9.0;

// enum Couleur est �quivalent � d�clarer les 3 constantes enti�res
int COULEUR_ROUGE = 0;
int COULEUR_VERT = 1;
int COULEUR_BLEU = 2;

// *** Enums ***
// Nomenclature : PascalCase
// D�finir dans la zone globale avant ou apr�s les constantes globales

// D�bute toujours avec la premi�re entr�e � 0 si non sp�cifi�
enum Couleur
{
	Rouge,  // = 0
	Vert,   // = 1
	Bleu,   // = 2
};

// Continue les prochaines valeurs au derni�re entr�e + 1 si non sp�cifi�
enum Texte
{
	Normal = 10,
	Gras, // = 11
	Souligne, // = 12
};

// Sp�cifier des nombres n�gatifs ou chaque entr�e manuellement
enum Police
{
	Invalide = -1,

	Arial = 1000,
	Helvetica = 2000,
	TimesNewRoman = 3000,
};

// Sp�cifier des caract�res, car ils ont des valeurs enti�res (int)
enum Raccourci
{
	Annuler = 'z',
	AnnulerMajuscule = 'Z',
	Copier = 'c',
	CopierMajuscule = 'C',
	Coller = 'v',
	CollerMajuscule = 'V',
};

// *** Erreurs ***
// 1) Impossible d'avoir 2 enums avec le m�me nom
//enum Couleur
//{
//	Orange,
//	Mauve,
//	Brun,
//};

// 2) Virgule manquante
//enum Caracteres
//{
//	PointVirgule = 50	// Erreur, virgule manquante
//	DeuxPoints = 60		// Erreur, virgule manquante
//	Virgule = 70		// Virgule manquante n'est pas une erreur, mais sugg�r�e si on ajoute apr�s
//};

// 3) Virgule et non point-virgule
//enum Caracteres
//{
//	PointVirgule = 50;	// Erreur
//	DeuxPoints = 60;	// Erreur
//	Virgule = 70;		// Erreur
//};

// 4) Point-virgule manquant
//enum Caracteres
//{
//	PointVirgule = 50,
//	DeuxPoints = 60,
//	Virgule = 70,
//} // Erreur

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "");

	// Affichage de l'en-t�te
	cout << "--- Cours 08 - Enum ---\n";

#pragma region Enum
	// *** Enum�ration (enum) ***
	// - D�finir des nombres entiers avec des noms pr�d�finis
	// - Rend le programme plus clair en rempla�ant les nombres magiques
	// - Plus facile � regrouper nombres ensemble que de cr�er plusieurs constantes

	// Affecter ou comparer avec les valeurs du enum
	int texteEntier = Texte::Normal;
	if (texteEntier == Texte::Normal)
	{
		cout << "Entier - Texte normal\n";
	}
	else
	{
		cout << "Entier - Texte sp�cial utilis�\n";
	}

	// Enum aussi utilisable comme type de donn�es (entier d�guis�)
	Texte texte = Texte::Normal;
	if (texte == Texte::Normal)
	{
		cout << "Enum - Texte normal\n";
	}
	else
	{
		cout << "Enum - Texte sp�cial utilis�\n";
	}

	// TODO: Modifier le switch avec entier (int) suivant afin d'utiliser un enum
	cout << "\n--- Switch enum (int) ---\n";

	// Lire un nombre � la Console
	cout << "Entrer un nombre � calculer (0, 1, 1000) : ";
	int nombre;
	cin >> nombre;

	// Initialiser le r�sultat avec une valeur qui indique une erreur
	int resultat = -1;

	// Effectuer le calcul et afficher le message selon le nombre entr� par l'utilisateur
	switch (nombre)
	{
	case 0:
		resultat += nombre;
		cout << format("Choix {} : Message seulement pour 0\n", nombre);
		break;

	case 1:
		resultat += nombre * nombre;
		cout << format("Choix {} : Message seulement pour 1\n", nombre);
		break;

	case 1000:
		resultat += nombre * nombre * nombre;
		cout << format("Choix {} : Message seulement pour 1000\n", nombre);
		break;

	default:
		cout << format("Choix {} : n'est pas un choix valide\n", nombre);
		break;
	}

	// Afficher le r�sultat si le nombre entr� n'est pas une erreur
	if (resultat != -1)
	{
		cout << format("Resultat {} : pour le nombre {}\n", resultat, nombre);
	}

	// TODO: Modifier le switch avec caract�res (char) suivant afin d'utiliser un enum

	// Afficher le menu de conversion de temp�rature
	cout << "\n--- Switch enum (char) ---\n\n";

	cout << "c) Celsius\n";
	cout << "f) Farenheit\n";

	// Lire le choix de conversion de l'utilisateur � la Console
	cout << "\nEntre le format de la temp�rature : ";
	char choixTemperature;
	cin >> choixTemperature;

	// Calculer la temp�rateur selon le choix de l'utilisateur
	switch (choixTemperature)
	{
	case 'c':
	case 'C':
	{
		double celsius = nombre * TEMPERATURE_CELSIUS_FACTEUR + TEMPERATURE_FARENHEIT_ZERO;
		cout << format("Celsius : {}\n", celsius);
	}
	break;

	case 'f':
	case 'F':
	{
		double farenheit = (nombre - TEMPERATURE_FARENHEIT_ZERO) * TEMPERATURE_FARENHEIT_FACTEUR;
		cout << format("Farenheit : {}\n", farenheit);
	}
	break;

	default:
		cout << format("{} n'est pas un choix de conversion de temp�rature valide.\n", choixTemperature);
		break;
	}

#pragma endregion

#pragma region ComparaisonDoubles
	cout << "\n--- Comparaison doubles ---\n";

	// *** Comparaison doubles ***
	// - Nombres � virgules se comparent mal avec les op�rateurs d'�galit� (==, !=)
	// - Binaire en m�moire de la Mantisse approxime un nombre d�cimal
	//		- Mantissen contient
	//			- Partie enti�re  : ... 16 8 4 2 1 
	//			- Partie d�cimale : 1/2 1/4 1/8 1/16 ...
	//			- Ex. 1010.1001 = 8 + 2 + 1/2 + 1/16 = 10 + 9/16 = 10.5625
	//		- Certains nombres qui ne sont pas 100% repr�sentables en Base 2
	//			- 10.5625 + 0.00001 = 10.56251
	//			- Comment ajouter au nombre pr�c�dent 1 / 100000 avec des multiples de 2 ?

	// Nombre 0.1 approxim� � 0.100000001 en m�moire
	double x = 0.1;

	// Calcul avec nombre approxim�
	//	- 0.100000001 + 0.100000001 + 0.100000001 = 0.300000003
	//  - R�sultat 0.300000003 approxim� � 0.300000004 en m�moire
	double sommeX = x + x + x;

	// Nombre 0.3 approxim� correctement � 0.3 en m�moire
	double y = 0.3;

	// Erreur de comparaison avec �galit� (==)
	// 0.300000004 == 0.3 = false
	cout << format("Doubles sans epsilon : {} == {} = {}\n", sommeX, y, sommeX == y);

	if (sommeX == y)
	{
		cout << format("Sans epsilon - Nombres {} et {} sont consid�r�s �gaux.", sommeX, y);
	}
	else
	{
		cout << format("Sans epsilon - Nombres {} et {} sont consid�r�s diff�rents.", sommeX, y);
	}

	// Soustraire plut�t les nombres et comparer avec une diff�rence maximale acceptable (EPSILON)

	// TODO: D�finir une constante EPSILON avec la iff�rence maximale acceptable
	const double epsilon = 0.000001;

	// TODO: Calculer la valeur absolue de la diff�rence des 2 nombres � virgule
	// | (0.300000004 - 0.3) |


	// TODO: V�rifier que la diff�rence des 2 nombres ne d�passe pas la limite d�finie (EPSILON)
	// | (0.300000004 - 0.3) | < 0.000001 = true

	// TODO: Afficher la diff�rence obtenue
	// cout << format("Doubles avec epsilon : ({} - {}) < {} = {}\n", sommeX, y, EPSILON, estInferieurEpsilon);

	// TODO: Effectuer un travail diff�rent avec la comparaison EPSILON au lieu de l'�galit� (==)
	if (sommeX == y)
	{
		cout << format("Avec epsilon - Nombres {} et {} sont consid�r�s �gaux.", sommeX, y);
	}
	else
	{
		cout << format("Avec epsilon - Nombres {} et {} sont consid�r�s diff�rents.", sommeX, y);
	}
#pragma endregion

#pragma region OperateurTernaire
	// *** Op�rateur ternaire (?) ***
	// - Alternative � l'instruction if / else 
	//		- Retourne une expression (valeur) au lieu de contenir plusieurs travaux
	//		- Ressemble beaucoup au if dans Excel
	//		- N'utiliser pas g�n�ralement pas l'op�rateur pour le cours
	//		- Comprendre seulement comment le lire si vous en voyez un dans du code
	// - Sugg�r� de toujours mettre les parenth�ses autour de la condition
	//
	// type variable = condition ? valeur si condition true : valeur si condition false;
	// type variable = (condition) ? valeur si condition true : valeur si condition false;

	// Impossible d'affecter une valeur avec un if / else
	//int valeur = if (nombre >= 10) { 1000 } else { 2000 }

	// Possible d'affecter une valeur de n'importe quel type
	int entier = (nombre >= 10) ? 1000 : 2000;
	double nombreVirgule = (nombre >= 10) ? 1.234 : 99.8765;
	char caractere = (nombre >= 10) ? 'a' : 'z';
	string valeur = (nombre >= 10) ? "bien" : "mal";

	// Possible d'enchainer plusieurs mais difficilemet lisible, pr�f�rer un bloc if
	// - Sup�rieur � 10		: 1000
	// - Inf�rieur � -10	: -1000
	// - Autres cas			: 0
	int plusieurs = (nombre >= 10) ? 1000 : ((nombre < -10) ? -1000 : 0);

	// TODO: Enregistrer � l'aide de 2 op�rateurs ternaires les valeurs d'un message
	// 
	// V�rifier si le nombre est entre 0 et 100 en g�n�rer les 3 variables pour le message
	// 
	// - Code		: 0 ou -1
	// - Texte		: "Succ�s" ou "Erreur"
	// - Couleur	: Couleur::Vert ou Couleur::Rouge


#pragma endregion
}
