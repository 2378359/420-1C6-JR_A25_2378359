/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-09
	Description		: cours 07 Enum
*/

// Inclusion des librairies
// TODO: Modifier la version du Projet à C++20 pour la librairie <format>
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

// enum Couleur est équivalent à déclarer les 3 constantes entières
int COULEUR_ROUGE = 0;
int COULEUR_VERT = 1;
int COULEUR_BLEU = 2;

// *** Enums ***
// Nomenclature : PascalCase
// Définir dans la zone globale avant ou après les constantes globales

// Débute toujours avec la première entrée à 0 si non spécifié
enum Couleur
{
	Rouge,  // = 0
	Vert,   // = 1
	Bleu,   // = 2
};

// Continue les prochaines valeurs au dernière entrée + 1 si non spécifié
enum Texte
{
	Normal = 10,
	Gras, // = 11
	Souligne, // = 12
};

// Spécifier des nombres négatifs ou chaque entrée manuellement
enum Police
{
	Invalide = -1,

	Arial = 1000,
	Helvetica = 2000,
	TimesNewRoman = 3000,
};

// Spécifier des caractères, car ils ont des valeurs entières (int)
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
// 1) Impossible d'avoir 2 enums avec le même nom
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
//	Virgule = 70		// Virgule manquante n'est pas une erreur, mais suggérée si on ajoute après
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

	// Affichage de l'en-tête
	cout << "--- Cours 08 - Enum ---\n";

#pragma region Enum
	// *** Enumération (enum) ***
	// - Définir des nombres entiers avec des noms prédéfinis
	// - Rend le programme plus clair en remplaçant les nombres magiques
	// - Plus facile à regrouper nombres ensemble que de créer plusieurs constantes

	// Affecter ou comparer avec les valeurs du enum
	int texteEntier = Texte::Normal;
	if (texteEntier == Texte::Normal)
	{
		cout << "Entier - Texte normal\n";
	}
	else
	{
		cout << "Entier - Texte spécial utilisé\n";
	}

	// Enum aussi utilisable comme type de données (entier déguisé)
	Texte texte = Texte::Normal;
	if (texte == Texte::Normal)
	{
		cout << "Enum - Texte normal\n";
	}
	else
	{
		cout << "Enum - Texte spécial utilisé\n";
	}

	// TODO: Modifier le switch avec entier (int) suivant afin d'utiliser un enum
	cout << "\n--- Switch enum (int) ---\n";

	// Lire un nombre à la Console
	cout << "Entrer un nombre à calculer (0, 1, 1000) : ";
	int nombre;
	cin >> nombre;

	// Initialiser le résultat avec une valeur qui indique une erreur
	int resultat = -1;

	// Effectuer le calcul et afficher le message selon le nombre entré par l'utilisateur
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

	// Afficher le résultat si le nombre entré n'est pas une erreur
	if (resultat != -1)
	{
		cout << format("Resultat {} : pour le nombre {}\n", resultat, nombre);
	}

	// TODO: Modifier le switch avec caractères (char) suivant afin d'utiliser un enum

	// Afficher le menu de conversion de température
	cout << "\n--- Switch enum (char) ---\n\n";

	cout << "c) Celsius\n";
	cout << "f) Farenheit\n";

	// Lire le choix de conversion de l'utilisateur à la Console
	cout << "\nEntre le format de la température : ";
	char choixTemperature;
	cin >> choixTemperature;

	// Calculer la températeur selon le choix de l'utilisateur
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
		cout << format("{} n'est pas un choix de conversion de température valide.\n", choixTemperature);
		break;
	}

#pragma endregion

#pragma region ComparaisonDoubles
	cout << "\n--- Comparaison doubles ---\n";

	// *** Comparaison doubles ***
	// - Nombres à virgules se comparent mal avec les opérateurs d'égalité (==, !=)
	// - Binaire en mémoire de la Mantisse approxime un nombre décimal
	//		- Mantissen contient
	//			- Partie entière  : ... 16 8 4 2 1 
	//			- Partie décimale : 1/2 1/4 1/8 1/16 ...
	//			- Ex. 1010.1001 = 8 + 2 + 1/2 + 1/16 = 10 + 9/16 = 10.5625
	//		- Certains nombres qui ne sont pas 100% représentables en Base 2
	//			- 10.5625 + 0.00001 = 10.56251
	//			- Comment ajouter au nombre précédent 1 / 100000 avec des multiples de 2 ?

	// Nombre 0.1 approximé à 0.100000001 en mémoire
	double x = 0.1;

	// Calcul avec nombre approximé
	//	- 0.100000001 + 0.100000001 + 0.100000001 = 0.300000003
	//  - Résultat 0.300000003 approximé à 0.300000004 en mémoire
	double sommeX = x + x + x;

	// Nombre 0.3 approximé correctement à 0.3 en mémoire
	double y = 0.3;

	// Erreur de comparaison avec égalité (==)
	// 0.300000004 == 0.3 = false
	cout << format("Doubles sans epsilon : {} == {} = {}\n", sommeX, y, sommeX == y);

	if (sommeX == y)
	{
		cout << format("Sans epsilon - Nombres {} et {} sont considérés égaux.", sommeX, y);
	}
	else
	{
		cout << format("Sans epsilon - Nombres {} et {} sont considérés différents.", sommeX, y);
	}

	// Soustraire plutôt les nombres et comparer avec une différence maximale acceptable (EPSILON)

	// TODO: Définir une constante EPSILON avec la ifférence maximale acceptable
	const double epsilon = 0.000001;

	// TODO: Calculer la valeur absolue de la différence des 2 nombres à virgule
	// | (0.300000004 - 0.3) |


	// TODO: Vérifier que la différence des 2 nombres ne dépasse pas la limite définie (EPSILON)
	// | (0.300000004 - 0.3) | < 0.000001 = true

	// TODO: Afficher la différence obtenue
	// cout << format("Doubles avec epsilon : ({} - {}) < {} = {}\n", sommeX, y, EPSILON, estInferieurEpsilon);

	// TODO: Effectuer un travail différent avec la comparaison EPSILON au lieu de l'égalité (==)
	if (sommeX == y)
	{
		cout << format("Avec epsilon - Nombres {} et {} sont considérés égaux.", sommeX, y);
	}
	else
	{
		cout << format("Avec epsilon - Nombres {} et {} sont considérés différents.", sommeX, y);
	}
#pragma endregion

#pragma region OperateurTernaire
	// *** Opérateur ternaire (?) ***
	// - Alternative à l'instruction if / else 
	//		- Retourne une expression (valeur) au lieu de contenir plusieurs travaux
	//		- Ressemble beaucoup au if dans Excel
	//		- N'utiliser pas généralement pas l'opérateur pour le cours
	//		- Comprendre seulement comment le lire si vous en voyez un dans du code
	// - Suggéré de toujours mettre les parenthèses autour de la condition
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

	// Possible d'enchainer plusieurs mais difficilemet lisible, préférer un bloc if
	// - Supérieur à 10		: 1000
	// - Inférieur à -10	: -1000
	// - Autres cas			: 0
	int plusieurs = (nombre >= 10) ? 1000 : ((nombre < -10) ? -1000 : 0);

	// TODO: Enregistrer à l'aide de 2 opérateurs ternaires les valeurs d'un message
	// 
	// Vérifier si le nombre est entre 0 et 100 en générer les 3 variables pour le message
	// 
	// - Code		: 0 ou -1
	// - Texte		: "Succès" ou "Erreur"
	// - Couleur	: Couleur::Vert ou Couleur::Rouge


#pragma endregion
}
