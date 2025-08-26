// TODO: Avant de créer le Projet, faire un git clone ou un git pull si déjà présent
// TODO: Après chaque TODO, compiler le programme et envoyer sur GitHub

// TODO: Ajouter un en-tête
/*

	Auteur      : Hugo Pelletier
	Date        : 2025-08-26
	Description : Introduction à la programmation

*/


#include <iostream>

int main()
{
	std::cout << "--- Cours 03 - Variables ---\n";

#pragma region Theorie

#pragma region Litteraux
	// *** Littéraux (Litteral en anglais) ***
	// - Valeurs constantes prédéfinies lors de la compilation du programme
	// - Ne font rien par elle même, doivent être utilisées dans des opérations

	// Entier (int)
	100;
	-100;

	// Nombre à virgule (double)
	1.23456789;
	-1.23456789;
	3.123E20;   // 3.123 x 10^20
	100.0;      // Attention, différent de 100 (entier)

	// Nombre à virgule (float)
	1.23456789f;
	-1.23456789f;
	3.123E20f;  // 3.123 x 10^20
	100.0f;     // Attention, différent de 100 (entier)

	// Attention, ne pas utiliser de virgule (,) toujours le point (.)
	// Défini 2 entiers 1 et 2346789 au lieu du double 1.2345656789
	1, 23456789;

	// Charactère (char)
	'a';
	'b';
	'c';
	'1';
	'2';
	'3';

	// Erreurs) Oublier les 2 guillemets simples (')
	//a;
	//'a;
	//a';

	// Chaîne de caractères (string)
	"abc 1234567890 \n \t \0";

	// Erreur) Ne pas utiliser 2 guillemets doubles anglais : Shift+2 (")
	//abc;
	//"abc;
	//"abc";
	//'abc';

	// Erreur) Ne pas englober l'ensemble de la chaîne de caractères entre guillemets (")
	// - Peut survenir lors de l'édition si le curseur est mal positionné lors de l'écriture
	//"abc"def;
	//abc"def";
	//"abc"def";
#pragma endregion

#pragma region TypesVariables
// *** Variables ***
// - Définit un espace en mémoire pour enregistrer des données d'une taille en bits prédéfinie 
//		- 1 octet (1 byte) = 8 bits
//		- https://learn.microsoft.com/en-us/cpp/cpp/cpp-type-system-modern-cpp?view=msvc-170
//		- Bits représente des valeurs de façon complètement différentes en mémoire
// - Pour chaque déclaration de variable
//		- Boîte est réservée dans la mémoire de l'ordinateur
//		- Boîtes sont collées les unes avec les autres selon l'ordre de définition des variables

// *** Entiers ***
// int : entier signé 32 bits (4 octets)
// 0 0000000 00000000 00000000 000000001 = 1
// 0 0000000 00000000 00000000 000000010 = 2
// 0 0000000 00000000 00000000 000000011 = 3
// 0 0000000 00000000 00000000 000000100 = 4
// 0 1111111 11111111 11111111 111111111 = 2147483647 (INT_MAX)
// 
// Nombres négatifs sont encodés à l'envers
// 1 1111111 11111111 11111111 111111111 = -1
// 1 0000000 00000000 00000000 000000000 = -2147483648 (INT_MIN)

// Encodage à l'envers permet au processeur de faire rapidement des calculs
//       1 1111111 11111111 11111111 111111111 (-1)
// +     0 0000000 00000000 00000000 000000001 (1)
// -------------------------------------------
//   (1) 0 0000000 00000000 00000000 000000000 (0)

	int monEntierPositif = 100;
	int monEntierNegatif = -100;

	// *** Limites en mémoire ***
	// - Raccourcis sont programmés pour identifier les valeur minimale et maximales
	// - https://learn.microsoft.com/fr-ca/cpp/cpp/integer-limits?view=msvc-170
	int monEntierMin = INT_MIN;
	int monEntierMax = INT_MAX;

	// Attention, de ne pas dépasser les limites, sinon les réponses deviennent éronnées !
	// Il existe plein de bogues connus à cause de cette erreur classique de dépassement (integer overflow)
	//   0 1111111 11111111 11111111 111111111 (INT_MAX)
	// +                                     1
	// ---------------------------------------
	//   1 0000000 00000000 00000000 000000000 (INT_MIN!!!)
	int monEntierDepassementMax1 = INT_MAX + 1;
	int monEntierDepassementMax2 = 2147483647 + 1;

	//   1 0000000 00000000 00000000 000000000 (INT_MIN)
	// -                                     1
	// ---------------------------------------
	//   0 1111111 11111111 11111111 111111111 (INT_MAX!!!)
	int monEntierDepassementMin1 = INT_MIN - 1;
	int monEntierDepassementMin2 = -2147483648 - 1;

	// unsigned int : entier non signé 32 bits (4 octets)
	unsigned int monEntierNonSigne = 100;
	unsigned int monEntierNonSigneNegatif = -1;

	// short : entier non signé 16 bits (2 octets)
	// - Rarement utilisé de nos jours
	short monEntierCourtMax = SHRT_MAX;
	short monEntierCourtMin = SHRT_MIN;

	// long long : Entier non signé 64 bits (8 octets)
	// - Utilisé pour manipuler de plus gros nombres
	long long monEntieLongMax = LLONG_MAX;
	long long monEntieLongMin = LLONG_MIN;

	// *** Nombres à virgule ***
	// double : nombre à virgule 64 bits (8 octets)
	// Signe (1 bit)    Exposant (11 bits)  Mantisse (52 bits)
	// 0                00000000000         00000000000000000000000000000000000000000000000000000
	// Max :  1.7 × 10 ^ 308
	// Min : -1.7 x 10 ^ 308
	double monNombreVirguleDouble1 = 0.123456789;
	double monNombreVirguleDouble2 = 12345.6789;

	double monNombreVirguleDoubleMax = 1.7E308;
	double monNombreVirguleDoubleMin = -1.7E308;

	// float : Nombre à virgule 32 bits (4 octets)
	// Signe (1 bit)    Exposant (8 bits)   Mantisse (23 bits)
	// 0                00000000            00000000000000000000000
	// Max :  3.4 × 10 ^ 38
	// Min : -3.4 x 10 ^ 38
	float monNombreVirguleFlotant1 = 0.123456789f;
	float monNombreVirguleFlotant2 = 12345.6789f;

	float monNombreVirguleFlotantMax = 3.4E38;
	float monNombreVirguleFlotantMin = -3.4E38;

	// *** Perte de précision ***
	// - Mantisses des nombres à virgule sont limités
	//		- Il n'est pas possible d'enregistrer lse nombres suivants complets dans la Mantisse
	//		- float : Perte de précision plus rapide, car la Mantisse est plus petite
	float monNombreVirguleFlotantPertePrecision = 123456789.123456789123456789f;
	double monNombreVirguleDoublePertePrecision = 123456789.123456789123456789;

	// char : Caractère ASCII 8 bits (1 octet)
	// 00000000 = '\0' (0)
	// 01000001 = 'A'  (64 + 1 = 65)
	// 01100001 = 'a'  (64 + 32 + 1 = 97)
	// 11111111 = 'a'  (255)
	char monCaractereA = 'a'; // 97
	char monCaractereB = 'b'; // 98
	char monCaractereC = 'c'; // 99

	char monCaractereAEntier = 97; // 'a'

	// Attention, ne pas dépasser les valeurs d'un char (8-bits) sinon les valeurs seront tronquées et erronées
	char monCaractereTropGrand1 = 'abc';  // 6382179 => tronqué à 99 'c'
	char monCaractereTropGrand2 = 123456; // 123456 => tronqué à 64 '@'

	// Les caractères majuscules ont des valeurs différentes des minuscules
	char monCaractereAMajuscule = 'A'; // 65
	char monCaractereBMajuscule = 'B'; // 66
	char monCaractereCMajuscule = 'C'; // 67

	// Les caractères spéciaux ont chacun une valeur différente
	char monCaracterePoint = '.';      // 46
	char monCaractereParenthese = '('; // 38

	// Les caractères numériques n'équivalent pas à leur valeur entière !
	char monCaractereChiffre0 = '0'; // 48 et non 0
	char monCaractereChiffre1 = '1'; // 49 et non 1
	char monCaractereChiffre9 = '9'; // 57 et non 9

	// Si on comprend que les caractères sont en fait des nombres entier, on peut faire des maths !
	char monCaractereCalcul1 = 'A' + 25; // 65 + 25 = 90 ('Z')
	char monCaractereCalcul2 = 'a' + 25; // 97 + 25 = 122 ('z')

	// string : Chaîne de caractères
	// Pour entreposer une chaîne de caractères, nous verrons la librairie <string> au prochain cours.
	// std::string maChaineCaracteres = "abc"
#pragma endregion

#pragma region DeclarationVariables
// *** Déclaration de variables ***
// Respecter avec les différents éléments avec les espaces
// type nomVariable = valeurInitiale;

// TODO: Déclarer une variable de chaque type (100, 5.25, 'Z')

	
	int variable1 = 100;
	double variable2 = 5.25;
	char variable3 = 'Z';


// Erreur E0020) Espaces manquant entre le type de variable et le nom de variable
//intmaVariableSansEspace = 10;

// Erreur E0084) Utiliser un mot clé du langage comme nom de variable
// https://learn.microsoft.com/fr-ca/cpp/cpp/keywords-cpp?view=msvc-170
//int int = 10;
//double double = 5.123;
//char char = 'a';

// Erreur de compilation) Définition 2 fois du même nom de variable
//int maVariableDefiniePlusieursFois = 10;
//int maVariableDefiniePlusieursFois = 20; // Erreur à la 2ème définition
#pragma endregion

#pragma region NomenclatureVariables
// *** Nomenclature de variables ***
// Afin d'avoir du code facilement compréhensible, toujours suivre les règles de nomenclature des variables

// 1) Utiliser la notation 'camelCase'
// - 1ère lettre en minuscule
// - Chaque mot suivant avec 1ère lettre en majuscule
	int monNomVariable = 10;	// camelCase

	// Éviter
	int moNNoMVaRiAble = 10;
	int MonNomVariable = 10;	// PascalCase
	int mon_nom_variable = 10;	// snake_case
	int MON_NOM_VARIABLE = 10;	// UPPER_SNAKE_CASE

	// 2) Utiliser des noms descriptifs
	int exemplairesVendus = 50;
	double prixBillet = 9.99;

	// Éviter
	int x = 10;
	double y = 8.54;
	int valeur = 10;
	int entier = 20;

	// 3) Utiliser des noms sans abbréviations
	int nombreJours = 4;
	int nbJrs = 4; // Éviter

	// 4) Utiliser des noms qui décrivent le plus posisble le contenu de la variable
	int nombre = 1; // Éviter
	int nombreJoursConnexion = 1; // Passable, mais peut porter à confusion
	int nombreJoursDepuisDerniereConnexion = 1; // Excellent

	// 5) Éviter les prépositions
	int lesJours = 4; // Éviter
	int leNombreDeJoursDepuisLaDerniereConnexion = 1; // Éviter

	// TODO: Corriger dans les problèmes suivants les noms de variables afin de respecter la nomenclature

	// Problème 1 : Achat de billets de cinéma
	// Le prix d’un billet est 12.5 $ et 4 billets ont été vendus au client
	// 
	// double prix_Billet = 12.5;
	double prixBilletCinema = 12.5;

	// int nbDeBil = 4;
	int nombreDeBillet = 4;

	// double LePrixTotal = 50.0;
	double lePrixTotalCinema = 50.0;

	// Problème 2 : Moyenne de la température extérieure
	// La température extérieure du matin est 15.2°C, de l'après-midi 23.8°C et du soir 20.5°
	// 
	// double matin = 15.2;
	double temperatureMatin = 15.2;

	// double tempAprem = 23.8;
	double temperatureApresMidi = 23.8;

	// double Temperaturesoir = 20.5;
	double temperatureSoir = 20.5;

	// double valeurTemperature = 19.8;
	double moyenneTemperature = 19.8;

	// Problème 2 : Jeu vidéo
	// Un jeu vidéo doit enregistrer les informations du joueur.
	// Le joueur débute avec :
	// - 1000 points avec 3 vies
	// - au niveau 1 sur 10 niveaux
	// - 100 or et 3 potions

	// int Score = 1000;
	int pointsJoueur = 1000;

	// int lesVies = 3;
	int viesJoueur = 3;

	// int NIVEAUACTUEL = 1;
	int niveauJoueurActuel = 1;

	//int lvlMax = 10;
	int niveauMaxJoueur = 10;

	//int montantDeLor = 100;
	int OrJoueur = 100;

	// int p = 3;
	int potionsJoueur = 3;

#pragma endregion

#pragma region Operations
	// *** Opérateurs de base ***
	// +, -, *, / (voir clavier numérique)

	// TODO: Afficher un calcul simple avec chaque opérateur avec des entiers
	std::cout << "\nOperateurs de base (+, -, * /)\n";
	std::cout << "5 + 10 = " << 5 + 10 << "\n";
	std::cout << "5 - 10 = " << 5 - 10 << "\n";
	std::cout << "5 * -10 = " << 5 * -10 << "\n";
	std::cout << "5 / 10 = " << 5 / 10 << "\n";

	// TODO: Afficher une division entière avec reste (ex. 5/8)
	// Seule la partie entière est conservée (voir prochain cours)
	std::cout << "5 / 8 = " << 5 / 8 << "\n";

	// Erreur E3049) Opérateur exposant (^) n'existe pas en C++
	// Symbole utilisé pour une autre opération dans le langage de programmation (XOR binaire)
	//std::cout << 5 ^ 8;

	// TODO: Calculer l'exposant à la main pour l'instant (voir boucles plus tard)
	std::cout << "5 ^ 8 = " << 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 << "\n";

	// *** Ordre des opérations ***
	// Respecte l'ordre normal en mathématique gauche vers la droite (PEMDAS) :
	// 1) Parenthèses
	// 2) Multiplication / Division
	// 3) Ajout / Soustraction
	// Il existe aussi des mots clés avec priorité qui sont propres à la programmation (ex. fonctions, cast, etc.)
	//
	// Exemple
	// (10 + 2) * (15 + (10 - 20 / 4))
	// 1) 12 * (15 + (10 - 20 / 4))
	// 2) 12 * (15 + (10 - 5))
	// 3) 12 * (15 + 5)
	// 4) 12 * 20
	// 5) 240
	//
	// TODO: Afficher la réponse du calcul
	std::cout << "Reponse operation 1 : " << (10 + 2) * (15 + (10 - 20 / 4)) << "\n";

	// Exercice 
	// (50 - (8 * 5 + 2)) + (9 + 3 * (12 / (14 - 8)))
	// 1) ...
	// 2) ...
	// ...
	//
	// Réponse
	// 1) (50 - (40 + 2)) + (9 + 3 * (12 / (14 - 8)))
	// 2) (50 - 42) + (9 + 3 * (12 / (14 - 8)))
	// 3) 8 + (9 + 3 * (12 / 6))
	// 4) 8 + (9 + 3 * 2)
	// 5) 8 + (9 + 6)
	// 6) 8 + 15
	// 7) 23

	// TODO: Afficher la réponse du calcul
	std::cout << "Reponse operation 2 : " << (50 - (8 * 5 + 2)) + (9 + 3 * (12 / (14 - 8))) << "\n";

	// *** Utilisation de variables ***
	// - Variable conteient une seule valeur à la fois représenté par l'ensemble des bits
	// - Par défaut, variables ne sont pas initialisées
	//		- Valeur aléatoire selon les bits dans cet espace mémoire la dernière fois qu'il a été utilisé
	//		- Valeur initiale écrase immédiatement la valeur par défaut aléatoire
	// - Affectations
	//		- Chaque autre affectation écrase dans la boîte en mémoire la valeur de la variable
	//      - Ne pas écrire le type lors d'une affectation sinon on définit une nouvelle variable 2 fois (erreur) !

	// TODO: Déclarer une variable sans valeur initiale (valeur aléoire), à éviter le plus possible


	// TODO: Déclarer une variable avec valeur initiale littérale


	// TODO: Déclarer une variable qui vaut 10 + (20 * 5) - 5
	// - Calcul complet de la valeur initiale est effectué avant l'affectation de la valeur à la variable


	// *** Opérations sur les variables ***
	std::cout << "\n--- Opérations sur des variables ---\n";

	int inconnu;		    // Variable non initialisée avec une valeur aléatoire (Avertissement)
	int total = 0;          // Variable initialisée à la valeur 0

	// Opération à droite du = (expression) est résolue avant l'affectation de la nouvelle valeur à la variable
	total = total + 2;      // 0 + 2  => total vaut maintenant 2
	total = total - 1;      // 2 - 1  => total vaut maintenant 1
	total = total * 10;     // 1 * 10 => total vaut maintenant 10
	total = total / 2;      // 10 / 2 => total vaut maintenant 5

	std::cout << "Total en utilisant la variable est : " << total << "\n";

	// TODO: Voir dessin en mémoire des calculs

	// *** Opérateurs d'affectaion combinés (+=, -=, *=, /=) ***
	// - Utiliser afin de ne pas avoir à écrire le nom de la variable à chaque fois
	// - Équivalent du bloc précédent en continuant d'utiliser la même variable

	total = 0;				// Variable réinitialisée à la valeur 0
	//int total = 0;    	// Ne pas écrire int devant total, définit une autre variable avec même nom (erreur!)

	total += 2;             // 0 + 2  => total vaut maintenant 2
	total -= 1;             // 2 - 1  => total vaut maintenant 1
	total *= 10;            // 1 * 10 => total vaut maintenant 10
	total /= 2;             // 10 / 2 => total vaut maintenant 5

	std::cout << "Total en utilisant les operateurs (+=, -=, *=, /=) : " << total << "\n";

	// Erreur 0029) Ne pas mettre d'espaces entre l'opération (+,-,*,/) et le égal (=)
	//total + = 2;

	// *** Assembleur ***
	// - Pour voir les instructions généré en Assembleur lors de la compilation du projet (x64)
	//		- Démarrer le débogage avec un Point d'arrêt (F5)
	//		- Déboguer > Fenêtres > Code Machine

#pragma endregion

#pragma endregion

	// TODO: Faire le premier exercice du Devoir ensemble

	// **** Exercice 01 *****
	// Moyenne de 3 nombres

	double nombre1 = 81.42;
	double nombre2 = -24.2;
	double nombre3 = 65.142;
	double moyenneNombres = (nombre1 + nombre2 + nombre3) / 3;

	std::cout << "Moyenne des 3 nombres : " << moyenneNombres << "\n";

	std::cout << "\n\n" << "****** Exercice 02 ******" << "\n" << "Calcule Rectangle" << "\n\n";


	int longueurRectangle = 12;
	int largeurRectangle = 7;

	int perimetreRectangle = (longueurRectangle * 2) + (largeurRectangle *2);
	int airRectangle = longueurRectangle * largeurRectangle;

	std::cout << "Perimetre du rectangle : " << perimetreRectangle << "\n";
	std::cout << "air du rectangle : " << airRectangle << "\n";

	std::cout << "\n\n" << "****** Exercice 03 ******" << "\n" << "  Volume Sphere  " << "\n\n";

	int rayonSphere = 6;
	double pi = ;
	double volumeSphere;


	// TODO: Faire le reste du Devoir et remettre avant la date sur Léa

}
