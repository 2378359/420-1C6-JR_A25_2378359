/*
	Auteur		:
	Date		:
	Description	:
*/

// *** Librairies ***
// Inclure les librairies
// TODO: Modifier la version du Projet à C++20 pour la librairie <format>
#include <format>
#include <iostream>
#include <string>

// *** Namespace ***
// Utiliser le namespace Standard (std::) pour les librairies
using namespace std;

// *** Déclaration des fonctions (Prototypes) ***
// - Ajouter les déclarations de fonctions avant le main()
// - Sinon, erreur de compilation lors des appels des fonctions dans la fonction main()
//		- C3861 : fonctionA() : identificateur introuvable
// TODO: Ctrl+F12 permet d'aller à la définition d'une fonction à partir de sa définition ou d'un appel de fonction
// TODO: Ctrl+. permet de créer une définition à l'aide d'une déclaration
#pragma region DeclarationFonctions

void fonctionA();
int fonctionB(int);

// TODO: Ajouter d'autres déclarations de fonctions ici
void afficherEnTete();
void afficherMessageNombre(string, int);
void afficherEtoiles(int);
void afficherLignesEtoiles(int, int);
int calculerSomme(int, int);
double calculerMoyenne(int, int, int);
bool estPlusGrand(int, int);

void afficherValeur();
void afficherValeur(string);
void afficherValeur(double);
void afficherValeur(double, double);

//void afficherAdmission(string, int, int, string, string);
#pragma endregion

// *** Fonction main() ***
// - Lancée automatiquement comme point d'entrée du programme
// - Une seule fonction main() dans le programme, sinon erreur
int main()
{
	// Configuration de la Console pour la saisie des nombres à virgule avec un point (.)
	setlocale(LC_ALL, "en_US");

	cout << "--- Cours 23 - Fonctions ---\n\n";

	// *** Fonctions ***
	// - Découper le code en plusieurs blocs logiques comme si le code containait des mini-programmes
	// - Réutiliser des blocs de code qui effectuent le même travail pour éviter les répétitions de code
	//		- Éviter les bogues en garantissant que le même code exact est exécuté à plusieurs endroits
	//		- Modifier la fonction permet de modifier le fonctionnement ou corriger les bogues à un seul endroit
	// - Simplifier la longueur du code pour la lisibilité
	//		- Par convention
	//			- Code d'une fonction devrait rentrer dans 1 à 2 écrans (50 à 100 lignes)
	//			- Sinon, rediviser à l'aide d'autres fonctions jusqu'à obtenir du code dans 1 à 2 écrans (50 à 100 lignes)
	//		- Par expérience
	//			- Préférable de faire une fonction de 100 lignes que 10 fonctions de 10 lignes
	//			- Plus facile à comprendre le code d'une suele fonction que de sauter entre plusieurs fonctions
	// 
	// *** Déclaration de la fonction (Prototype) ***
	// type nomFonction(type, type);
	// 
	// *** Définition de la fonction (Corps) ***
	// type nomFonction(type nomParametre1, type nomParametre2)
	// {
	//		// Travail à effectuer
	// 
	//		// Valeur de retour de la fonction
	//		return ...;
	// }
	//
	// *** Exemple ***
	// int exempleFonction(int, string);
	// 
	// int exempleFonction(int parametre1, string parametre2)
	// {
	//		// Travail à effectuer
	//		cout << parametre2;
	// 
	//		// Valeur de retour de la fonction
	//		return parametre1 + 10;
	// }

	// *** Type de retour ***
	// - Contrat à remplir à la fin de la fonction
	//		- Valeur ou variable du bon type doit être retourné par la fonction par l'instruction 'return'
	//		- Tous les chemins de la fonction doivent retourne une valeur du bon type
	//			- Tous les branches possible de if/else if/else, switch, etc.
	//		- Un seul type de retour possible
	//			- Fonctions retourne une seul valeur pour l'instant (voir tableaux et structs plus tard)
	// - Types de base
	//		- int		=>		return 10;
	//		- double	=>		return 10.123;
	//		- char		=>		return 'a';
	//		- string	=>		return "bonjour";
	//		- etc.
	// - Aucune valeur
	//		- void		=>		return; ou atteindre la fin de la fonction '}'

	// *** Nomenclature de fonctions ***
	// - Notation 'camelCase' pour le cours avec les mêmes règles que les variables
	//		- Pas d'accents
	//		- Pas d'abréviations
	//		- Pas de prépositions (ex. le, de, au, etc.)
	// - Commencer par un verbe d'action à l'infinitif suivi de noms et/ou adjectifs descriptifs
	//		- void afficherMenuPrincipal()
	//		- void afficherEnTete()
	//		- void afficherOperation()
	//			- afficher...() (display...() ou print...() en anglais) 
	//			- Implique une fonction d'affichage seulement à la Console qui ne retourne pas de valeur
	//			- Type de retour (void)
	//		- double calculerMoyenne()
	//		- int calculerNombreJoursEntreDates()
	//		- double trouverPlusPetitNombre()
	//		- double trouverMinimum()
	//		- int trouverNombreVoyelles()
	//		- int lireEntier()
	//		- int lireExemplaires()
	//		- char lireChoixMenu()
	//		- etc.
	// - Fonctions qui retourne un bool doivent plutôt commencer par 'est...()' (ou 'is...()' en anglais), etc.
	//		- bool estNegatif()
	//		- bool estVoyelle()
	//		- bool peutTerminer()
	//		- etc.

	// *** Paramètres de fonctions ***
	// - Fonctionnement similaire aux variables, mais l'appellation pour une fonction est 'paramètre'
	// - À l'appel de la fonction
	//		- Espace est reservé en mémoire
	//		- Valeurs passées lors de l'appel de la fonction sont copiées
	//			- calculerMoyenne(10, 20, 30)
	//			- Copier 10 dans la variable 1
	//			- Copier 20 dans la variable 2
	//			- Copier 30 dans la variable 3
	//		- Sinon, la valeur par défaut est assignée à la variable
	// - À la fin de la fonction ou lors d'une instruction 'return' qui termine la fonction
	//		- Fin du 'Scope' de la fonction
	//		- Espace est libéré	comme les variables normales
	//		- Seule la valeur de retour est conservée temporairement
	// - Par convention
	//		- Suivre le plus possible le même ordre des paramètres dans fonctions similaire
	//		- Aide autre programmeurs à utiliser les fonctions
	//		- Exemple, pour les fonction afficher string est toujours au début, ensuite, int, etc.
	//			- afficherNom(string)
	//			- afficherMessage(string, int)
	//			- afficherErreur(string, int, double)

	// *** Fonctionnement d'un appel de fonction ***
	// TODO: Dessiner le fonctionnement des fonctions
	// - Rappel du fonctionnement du Stack et des Scopes
	// - Appel d'une fonction
	//		- Réservation des espaces mémoires
	//			- Adresse de retour après appel de fonction
	//			- Valeur de retour lors du retour de la fonction
	//			- Paramètres de la fonction
	//			- Variables de la fonction
	//		- Notions de pointeur d'instruction et d'exécution des programmes
	//		- Saut à l'adresse du code de la fonction
	// - Retour d'une fonction
	//		- Écriture de la valeur dans la case de valeur de retour temporaire
	//		- Retour à l'adresse de retour dans la fonction originale
	//		- Utilisation de la valeur de retour
	//		- Suppression du Stack des espacers mémoires reservés pour l'appel de la fonction
	//			- Adresse retour, valeur de retour, paramètres et variables
	// - Tracer les fonction : main(), fonctionA(), fonctionB()
	fonctionA();

	// *** Définition et déclaration de fonctions ***
	// - Langages compilés comme C++
	//		- Programmes sont générées entièrement lors de la compilation et liaison du programme
	//		- Compilation
	//			- Génération de bloc de code binaire incomplets
	//			- Certaines notes et espaces sont ajoutés pour imbriquer les blocs binaires ensmebles
	//		- Liaison
	//			- Remplacer les notes est espace laissés par blocs binaires qui ont été compilés
	// - Lors de l'étape de compilation
	//		- Appel de fonction
	//			- Note est conservé par le compilateur d'insérer le code ou lien vers la fonction après la compilation
	//		- Définition de fonction (prototype)
	//			- Permet au compilateur de preparer l'appel et le retour de la fonction sans avoir le contenu
	//			- Seul les éléments suivants sont nécessaires dans une définition de fonction
	//				- Types de retour et variables pour préparer l'espace mémoire de l'appel et du retour
	//				- Nom de la fonction pour trouver le code compilé de la fonction
	//			- Exemple de code machine à cette étape
	//					- MOV eax, 2;			// Valeur du paramètre 1 de la fonction
	//					- MOV ebx, 3;			// Valeur du paramètre 2 de la fonction
	//					- CALL NOM_FONCTION_1;	// Appel de la fonction compilée à l'adresse en mémoire du programme
	//		- Déclaration de fonction (corps)
	//			- Compilée en code binaire indépendemment comme s'il s'agissait d'un autre programme
	// - Lors de l'étape de la liaison statique (linking)
	//		- Table avec les noms de fonctions et leurs adresses dans le programme final
	//			- NOM_FONCTION_1 = 0x400100
	//			- NOM_FONCTION_2 = 0xA08180
	//			- NOM_FONCTION_3 = 0xB27640
	//			- etc.
	//		- Appels de fonction sont remplacsé par l'adresse mémoire de la fonction
	//			- CALL NOM_FONCTION_1; => CALL 0x400100;
	//			- CALL NOM_FONCTION_2; => CALL 0xA08180;
	//			- CALL NOM_FONCTION_3; => CALL 0xB27640;
	// - Optimisation de fonctions inline
	//		- Lors de la compilation ou du linking, le compilateur peut tenter d'optimiser les appels de fonctions
	//			- Appel d'une fonction (CALL) a un coût élevé comparativement à une instruction simple (ex. ADD, SUB, etc.)
	//			- Compilateur peut juger que le code de la fonction est trop petit ou trop simple
	//		- Chaque appel de la fonction est remplacé entièrement par les instructions machines de la fonction
	//			- Exemple : fonction qui additionne 2 nombres ensemble (MOV, MOV, CALL remplacé par ADD seulement)

	// TODO: Déplacer le code d'affichage suivant dans le fonction pour raccourcir la fonction main()
	if (false)
	{
		cout << "==========================================\n";
		cout << "          DEMONSTRATION D'EN-TETE         \n";
		cout << "==========================================\n";
		cout << " Enseignant  : Mael Perreault\n";
		cout << " Cours       : Programmation structuree\n";
		cout << " Sujet       : Exemple de fonctions\n";
		cout << "------------------------------------------\n";
		cout << " Ce programme affiche un message\n";
		cout << " sur 20 lignes dans la console.\n";
		cout << "------------------------------------------\n";
		cout << " Contenu de l'en-tete :\n";
		cout << "   - Utilisation de cout\n";
		cout << "   - Retour de lignes\n";
		cout << "------------------------------------------\n";
		cout << " Date de compilation : 2025-10-21\n";
		cout << "------------------------------------------\n";
		cout << "       BONNE EXECUTION DU PROGRAMME !     \n";
		cout << "==========================================\n";

		

		
	}

	// TODO: Prendre le code d'affichage qui change et créer une fonction appelée 3 fois
	if (false)
	{
		cout << "\nSans fonction :\n";
		cout << "Votre message d'aujourdhui est : 'Bonjour' et le nombre est : 10\n";
		cout << "Votre message d'aujourdhui est : 'Hello' et le nombre est : 5555\n";
		cout << "Votre message d'aujourdhui est : 'Buenos Dias' et le nombre est : 123456789\n";

		cout << "\Avec fonction :\n";

		 afficherMessageNombre("Bonjour", 10);
		 afficherMessageNombre("Hello", 5555);
		 afficherMessageNombre("Buenos Dias", 123456789);
	}

	// TODO: Créer une fonction qui affiche le nombre d'étoiles demandés
	if (false)
	{
		cout << "\nSans fonction :\n";
		cout << "**************************************\n";
		cout << "******************************************************************************\n";

		cout << "\nAvec fonction :\n";

		
		afficherEtoiles(40);
		afficherEtoiles(80);
	}

	// TODO: Appeler autre fonction 5 fois afficherEtoiles(80);
	if (true)
	{
		cout << "\nSans fonction :\n";
		cout << "**************************************\n";
		cout << "**************************************\n";
		cout << "**************************************\n";

		cout << "******************************************************************************\n";
		cout << "******************************************************************************\n";
		cout << "******************************************************************************\n";
		cout << "******************************************************************************\n";
		cout << "******************************************************************************\n";

		cout << "\nAvec fonction :\n";
		afficherLignesEtoiles(3, 40);
		afficherLignesEtoiles(5, 80);
	}

	// TODO: Créer une fonction pour afficher n'importe quel caractère fourni par l'utilisateur	
	if (true)
	{
		//afficherCaracteres(80, '*');
		//afficherCaracteres(80, '-');
		//afficherLignesCaracteres(5, 80, '*');
		//afficherLignesCaracteres(5, 80, '-');
	}

	// TODO: Créer une fonction qui retourne une valeur entière (int)
	if (true)
	{
		int resultatSomme1 = calculerSomme(10, 20);
		cout << format("Resultat somme : 10 + 20 = {}\n", resultatSomme1);
		 
		int resultatSomme2 = calculerSomme(15, 45);
		cout << format("Resultat somme : 15 + 45 = {}\n", resultatSomme2);
		 
		int resultatSomme3 = calculerSomme(18, 34);
		cout << format("Resultat somme : 18 + 34 = {}\n", resultatSomme3);
	}

	// TODO: Créer une fonction qui retourne une un nombre à virgule (double)
	if (true)
	{
		 double resultatCalculMoyenne = calculerMoyenne(10, 15, 30); // 18.333...
		 cout << format("Resultat calcul moyenne : {}\n", resultatCalculMoyenne); 
	}

	// TODO: Créer une fonction qui retourne un booléen (bool)
	if (true)
	{
		// Plus grand que 10
		bool estPlusGrand0 = estPlusGrand(123, 10);
		bool estPlusGrand1 = estPlusGrand(-10, 10);

		// Plus grand que 1000
		bool estPlusGrand2 = estPlusGrand(1001, 1000);
		bool estPlusGrand3 = estPlusGrand(999, 1000);

		cout << format("Plus grand : {} {} {} {}\n", estPlusGrand0, estPlusGrand1, estPlusGrand2, estPlusGrand3);
	}

	// TODO: Créer une fonction qui retourne un caractère (char)
	if (false)
	{
		//char voyelle0 = obtenirVoyelle(0); // 'a'
		//char voyelle1 = obtenirVoyelle(1); // 'e'
		//char voyelle2 = obtenirVoyelle(2); // 'i'
		//char voyelle3 = obtenirVoyelle(3); // 'o'
		//char voyelle4 = obtenirVoyelle(4); // 'u'
		//char voyelle5 = obtenirVoyelle(5); // '\0'
		//cout << format("Voyelles : {} {} {} {} {} {}\n", voyelle0, voyelle1, voyelle2, voyelle3, voyelle4, voyelle5);
	}

	// TODO: Créer une fonction qui retourne une chaîne de caractère (string)
	if (false)
	{
		//string messageBienvenue = genererMessageBienvenue("Mael");
		//cout << messageBienvenue;
	}

	// *** Surchage de fonctions ***
	// - 2 fonctions ne peuvent avoir le même nom et types de paramètres
	// - Signature d'une fonction doit être unique dans le namespace
	//		- Nom de la fonction
	//		- Types des paramètres dans l'ordre
	// - Surcharge de fonctions
	//		- 2 fonctions peut avoir le même nom, mais un nombre et/ou types de paramètres différents
	//		- Exemples
	//			- calculerValeur()
	//			- calculerValeur(int)
	//			- calculerValeur(double)
	//			- calculerValeur(int, double)
	//			- calculerValeur(double, int)
	//				- Note : non recommandé de faire fonction (int, double) et (double, int)
	//		- Langage de programmation 
	//			- Appelle la bonne fonction selon les paramètres utilisés pour l'appel de fonction
	//			- calculerValeur(10) => calculerValeur(int)
	//			- calculerValeur(10.5) => calculerValeur(double)
	//			- etc.
	// - Conversion implicite
	//		- Plupart des langages de programmation ont de la conversion implicite entre les types de données des paramètres
	//		- Permet de déclarer uniquement une fonction avec paramètres (ex. double)
	//			- calculerResultat(int, int) => seulement int
	//			- calculerResultat(double, double) => double ou conversion implicite int
	//		- Attention
	//			- Peut mener à des erreurs de précision non voulues (calculs avec des doubles au lieu de int)
	//			- En C++ commercial, définir des fonctions pour chaque type de données afin d'éviter les erreurs inattendues

	if (true)
	{
		// TODO: Créer les 4 surcharges de la fonction afficherValeur() avec des messages différents
		afficherValeur();
		afficherValeur("chaine");
		afficherValeur(10);
		afficherValeur(10, 20);

		// TODO: Transformer les paramètres int vers double pour permettre l'appel de la fonction avec conversion implicite
		// Attention : les appels avec des entiers plus haut sont maintenant convertis implicitement en double
		afficherValeur(10.0);
		afficherValeur(10.0, 20.0);
	}

	if (true)
	{
		// TODO: Afficher un messsage selon les paramètres entrés et les messages fournis
		 //afficherAdmission(nom, age, ageMinimum, messageAdmis, messageErreur);
		 //afficheradmission("alan", 20, 18, "bienvenue {} vous avez {} ans.", "erreur : {} vous etes trop jeune!");
		 //afficheradmission("bob", 50, 18, "bienvenue {} vous avez {} ans.", "erreur : {} vous etes trop jeune!");
		 //afficheradmission("carl", 10, 18, "bienvenue {} vous avez {} ans.", "erreur : {} vous etes trop jeune!");

		// TODO: Retourner les messages d'admission plu^tot que les afficher immédiatement afin de les affiche à un moment opportun
		//string messagesAdmission = "";
		//messagesAdmission += genererMessageAdmission("Alan", 20, 18, "Bienvenue {} vous avez {} ans.", "Erreur : {} vous etes trop jeune!");
		//messagesAdmission += "\n";
		//messagesAdmission += genererMessageAdmission("Bob", 50, 18, "Bienvenue {} vous avez {} ans.", "Erreur : {} vous etes trop jeune!");
		//messagesAdmission += "\n";
		//messagesAdmission += genererMessageAdmission("Carl", 10, 18, "Bienvenue {} vous avez {} ans.", "Erreur : {} vous etes trop jeune!");
		//messagesAdmission += "\n";
		//
		//cout << "*** Messages d'admission ***\n";
		//cout << messagesAdmission;
	}
}

// *** Définitions des fonctions (Corps) ***
// - Ajouter les définitions de fonctions après le main() par convention
// - Fonction déclarée, mais non définie est une erreur
//		- LNK2019 : symbole externe non résolu "void __cdecl fonctionA(void)" référencé dans la fonction main
//		- LNK1120 : 1 externes non résolus
// TODO: F12 permet d'aller à la définition d'une fonction à partir de sa déclaration ou d'un appel de fonction
// TODO: Ctrl+. permet de créer une définition à l'aide d'une déclaration
#pragma region DefinitionsFonctions

void fonctionA()
{
	cout << "--- Bienvenue dans la fonction A ---\n";

	cout << "\nAppel 1 de la fonction B avec valeur 10 :\n";
	int valeurRetour1 = fonctionB(10);
	cout << format("Valeur de retour 1 : {}\n", valeurRetour1);

	cout << "\nAppel 2 de la fonction B avec valeur 20 :\n";
	int valeurRetour2 = fonctionB(20);
	cout << format("Valeur de retour 2 : {}\n", valeurRetour2);

	// Ordre de résolution
	// 1. fonctionB(10) = 25
	// 2. fonctionB(20) = 35
	// 3. 25 + 35 = 60
	// 4. fonctionB(30) = 45
	// 5. 60 + 45 = 105
	// 6. 105 + 1000 = 1105
	cout << "\nAppels 3, 4, 5 de la fonction B avec valeurs 10, 20, 30 + 1000 :\n";
	int valeurRetour3 = fonctionB(10) + fonctionB(20) + fonctionB(30) + 1000;
	cout << format("Valeur de retour 3 : {}\n", valeurRetour3);

	// Ordre de résolution
	// 1. fonctionB(10) = 25
	// 2. 25 + 50 = 75
	// 2. fonctionB(75) = 90
	cout << "\nAppels 6-7 de la fonction B avec valeurs 10 et la réponse de l'appel 6 + 50 :\n";
	int valeurRetour4 = fonctionB(fonctionB(10) + 50);
	cout << format("Valeur de retour 4 : {}\n", valeurRetour4);

	cout << "\n--- Fin de la fonction A ---\n";
}



int fonctionB(int valeur)
{
	cout << format("\t--- Bienvenue dans la fonction B ({}) ---\n", valeur);

	cout << format("\tValeur : {}\n", valeur);
	cout << format("\tValeur + 100 : {}\n", valeur + 100);

	int valeurRetour = valeur + 15;
	cout << format("\t--- Fin de la fonction B ({}) retourne {}  ---\n", valeur, valeurRetour);

	return valeurRetour;
}

// TODO: Ajouter d'autres définitions de fonctions ici
void afficherEnTete() {
	cout << "==========================================\n";
	cout << "          DEMONSTRATION D'EN-TETE         \n";
	cout << "==========================================\n";
	cout << " Enseignant  : Mael Perreault\n";
	cout << " Cours       : Programmation structuree\n";
	cout << " Sujet       : Exemple de fonctions\n";
	cout << "------------------------------------------\n";
	cout << " Ce programme affiche un message\n";
	cout << " sur 20 lignes dans la console.\n";
	cout << "------------------------------------------\n";
	cout << " Contenu de l'en-tete :\n";
	cout << "   - Utilisation de cout\n";
	cout << "   - Retour de lignes\n";
	cout << "------------------------------------------\n";
	cout << " Date de compilation : 2025-10-21\n";
	cout << "------------------------------------------\n";
	cout << "       BONNE EXECUTION DU PROGRAMME !     \n";
	cout << "==========================================\n";
}

void afficherMessageNombre(string message, int nombre)
{

}
void afficherEtoiles(int nombreEtoiles)
{
	for (int i = 0; i < 40; i++)
	{
		cout << "*";
	}
	cout << "\n";
}
void afficherLignesEtoiles(int nombreLigne, int nombreEtoiles)
{
	for (int i = 0; i < nombreLigne; i++)
	{
		afficherEtoiles(nombreEtoiles);
	}
}
int calculerSomme(int nombre1, int nombre2)
{
	int somme = nombre1 + nombre2;
	return somme;
}
double calculerMoyenne(int nombre1, int nombre2, int nombre3)
{
	int somme = nombre1 + nombre2 + nombre3;
	double moyenne = somme / 3.0;
	return moyenne;
}
bool estPlusGrand(int nombre, int minimum)
{
	if (nombre > minimum)
		return true;

	return false;
}

void afficherValeur()
{
	cout << "Rien a afficher\n";
}

void afficherValeur(string message)
{
	cout << format("La valeur du message : {}  \n", message);
}

void afficherValeur(double nombre)
{
	cout << format("La valeur du nombre : {}\n", nombre);
}

void afficherValeur(double nombre1, double nombre2)
{
	cout << format("La valeur des nombres : {} et {}\n", nombre1, nombre2);
}
//void afficherAdmission(string nom, int age, int ageMinimum, string messageAdmis, string messageErreur)
//{
//	if (age >= ageMinimum) {
//		cout << format(messageAdmis, age);
//	}
//	else
//	{
//		cout << messageErreur;
//	}
//}
#pragma endregion