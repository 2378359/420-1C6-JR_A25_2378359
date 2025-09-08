// TODO: V�rifier les devoir, revoir ensemble l'Exercice 1

// TODO: Avant de cr�er le Projet, faire un 'git clone' ou un 'git pull' si dossier Git est d�j� pr�sent

/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-04
	Description		: Cours 06 Conditions
*/

// Inclusion des librairies
// TODO: Modifier la version du Projet � C++20 pour la librairie <format>
// TODO: Compiler le code pour le tester et sauvegarder sur Git local et puis sur GitHub
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "");

	// Affichage de l'en-t�te
	cout << "--- Cours 06 - Conditions avanc�es ---\n";

#pragma region Theorie
	// *** Op�rateurs logiques ***
	// 
	// Op�rateur &&
	// - ET (AND)
	// - 2 conditions doivent etre vraie (true) afinb d'�tre vrai (true)
	// 
	//   &&  | false | true
	// ----------------------
	// false | false | false
	//  true | false | true
	// 
	// Op�rateur ||
	// - OU (OR)
	// - Au moins une des 2 condition doit etre vraie (true) afin d'�tre vrai (true)
	// 
	//   ||  | false | true
	// ---------------------
	// false | false | true
	//  true | true  | true
	// 
	// Op�rateur !
	// - NON (NOT)
	// - Inverse la variable ou condition qui suit :
	//		- !variable bool�ene
	//		- !( condition avec op�rateur )
	// 
	// !true	= false
	// !(true)	= false
	// !false	= true
	// !(false)	= true

	cout << "Nombre : ";
	int nombre;
	cin >> nombre;

	// Exemples op�rateur && (ET)
	// 
	// nombre > 10 && nombre < 20
	// 
	// nombre = 15            | nombre = 0              | nombre = 100
	// -----------------------------------------------------------------------
	// 15 > 10 && 15 < 20     | 0 > 10 && 0 < 20        | 100 > 10 && 100 < 20
	// true && true           | false && true           | true && false
	// true                   | false                   | false
	bool estNombreEntre10Et20 = nombre > 10 && nombre < 20;

	// Exemple op�rateur || (OU)
	// 
	// nombre > 10 || nombre < 20
	// 
	// nombre = 15            | nombre = 0              | nombre = 100
	// -----------------------------------------------------------------------
	// 15 > 10 || 15 < 20     | 0 > 10 || 0 < 20        | 100 > 10 || 100 < 20
	// true || true           | false || true           | true || false
	// true                   | true                    | true
	//
	// Toujours vrai, car essentiellement la condition est :
	// - (> 10) 'nombre positif' (||) OU (< 20) 'nombre n�gatif' 
	// - Impossible d'avoir un nombre qui ne respecte pas au moins une de 2 conditions
	bool estNombrePlusGrand10OuPlusPetit20 = nombre > 10 || nombre < 20;

	// Exemple op�rateur ! (NON)
	// 
	// !(nombre > 10 && nombre < 20)
	// 
	// nombre = 15            | nombre = 0              | nombre = 100
	// -----------------------------------------------------------------------
	// !(15 > 10 && 15 < 20)  |  !(0 > 10 && 0 < 20)    | !(100 > 10 || 100 < 20)
	// !(true && true)        |  !(false && true)       | !(true || false)
	// !true                  |  !(false)               | !(false)
	// false				  |  true                   | true
	bool nestPasNombreEntre10Et20 = !(nombre > 10 && nombre < 20);

	// Lire une lettre au clavier
	char lettre = 'a';
	cout << "Entrer une lettre : ";
	cin >> lettre;

	// TODO: Afficher si la lettre est une voyelle (a, e, i, o, u) ou une consonne
	if (lettre == 'a' || lettre == 'e' || lettre == 'i' || lettre == 'o' || lettre == 'u')
	{
		cout << format("\n{} est une voyelle", lettre);
	}
	else
	{
		cout << format("\n{} est une consonne", lettre);
	}

	// __________________ OU _______________________

	bool estVoyelle = lettre == 'a' || lettre == 'e' || lettre == 'i' || lettre == 'o' || lettre == 'u';
	if (estVoyelle)
	{
		cout << format("\n{} est une voyelle", lettre);
	}
	else
	{
		cout << format("\n{} est une consonne", lettre);
	}
	// *** Erreurs ***

	// Erreur 1) Oublier de r�p�ter la variable � comparer avec un op�rateur de comparaison
	// Condition est toujours vraie (true)
	// lettre == 'x' || (bool)'y' || (bool)'z'
	// lettre == 'x' || true || true
	// false || true || true
	// true
	if (lettre == 'x' || 'y' || 'z') // Erreur
	{
		cout << format("Lettre est 'x', 'y' ou 'z'\n");
	}

	// TODO: Version corrig�e


	// Erreur 2) Utiliser le mauvais op�rateur logique && ||
	// - Impossible d'�tre 'x' et 'y' en m�me temps
	// - lettre == 'x' && lettre == 'y' ...
	// - true && false ...
	// - false
	if (lettre == 'x' && lettre == 'y' && lettre == 'z') // Erreur
	{
		cout << format("Lettre est 'x' ET 'y' ET 'z'\n");
	}

	// TODO: Version corrig�e


	// TODO: V�rifier le nombre entr� afin d'afficher les messages suivants selon le nombre :
	// 'bien' : 10, 20, entre 100 et 200
	// 'moyen' : 50, 70, plus petit que 0
	// 'secret' : lettre 'a', nombre 1000
	// 'mal' : dans les autres cas
	if (nombre == 10 || nombre == 20 || (nombre >= 100 && nombre <= 200))
	{
		cout << format("Votre nombre {} est un bien\n", nombre);
	}
	else if (nombre == 50 || nombre == 70 || nombre < 0)
	{
		cout << format("Votre nombre {} est un moyen\n", nombre);
	}
	else if (lettre == 'a' && nombre == 1000)
	{
		cout << format("Votre nombre {} et lettre {} est un secret\n", nombre, lettre);
	}
	else
	{
		cout << format("Votre nombre {} est un mal\n", nombre);
	}


	// *** R�solution d'une condition logique ***
	// Priorit� des op�rations � partir de la gauche
	// - Parenth�ses
	// - Casts ()
	// - Division / Multiplication
	// - Addition / Soustraction
	// - ! Non
	// - && Et
	// - || Ou

	// TODO: Exemple de condition logique
	// 
	// A = true
	// B = false
	// C = false
	// D = true
	// 
	// (A && B) || !(C || D)
	// (true && false) || !(false || true)
	// 
	// 1) false || !(false || true)
	// 2) false || !true 
	// 3) false || false
	// 4) false
	// 5) 
	// 6) 
	// 7) 
	// 8) 
	// 9) 

	// Optimisation pour l'op�rateur ET (&&) :
	// - Si la premi�re condition fausse (false) 
	//		- Impossible que la r�ponse du ET (&&) soit vraie (true)
	//		- false && ... && ... = false
	//      - Retourne faux (false) imm�diatement
	// - Prochaines conditions ne sont pas �valu�es
	// - Tr�s utile pour �viter les crash dans les prochains cours de Programmation 2 et 3

	// TODO: Exemple de condition op�rateur 
	// 
	// A = true;
	// B = false;
	// C = false;
	// D = true;
	// E = false;
	// F = true;
	// 
	// A && B && C && (D || E) || F
	// true && false && false && (true || false) || true
	// 
	// 1) true && false && false && (true || false) || true
	// 2) false && false && (true || false) || true
	// 3) false || true
	// 4) true
	// 
	// Conditions C, D et E
	// - Reli�es ensemble � A et B par des op�rateurs ET (&&) ne seront jamais �valu�es, car B est faux (false)
	// 
	// Condition F
	// - Reli�e par un op�rateur || (OU) avec le reste doit quand m�me �tre �valu�e

	int a = 5;
	int b = 15;
	int c = -20;

	// TODO: Exemple 1
	bool estConditionExemple1 = (a + b > c) || !((b > 100) && !(c - a > 0)) || !(a - c > b);

	// 1) (5 + 15 > -20) || !((15 > 100) && !(-20 - 5 > 0)) || !(5 - -20 > 15)
	// 2) (20 > -20) || !((15 > 100) && !(-20 - 5 > 0)) || !(5 - -20 > 15)
	// 3) (true) || !((15 > 100) && !(-20 - 5 > 0)) || !(5 - -20 > 15)
	// 4) (true) || !((fales) && !(-20 - 5 > 0)) || !(5 - -20 > 15)
	// 5) (true) || !((fales) && !(-25 > 0)) || !(5 - -20 > 15)
	// 6) (true) || !((fales) && !(false)) || !(5 - -20 > 15)
	// 7) (true) || !(fales && true) || !(5 - -20 > 15)
	// 8) (true) || true || !(5 - -20 > 15)
	// 9) (true) || !(5 - -20 > 15)
	// 10) true || !(25 > 15)
	// 11) true || !(true)
	// 12) true || false
	// 13) true

	// TODO: Exemple 2
	bool estConditionExemple2 = (a - 5 <= c + 20) && !(c > b) || ((a + b + c > b - c) && (c > 0 || b > 0));

	// 1) (5 - 5 <= -20 + 20) && !(-20 > 15) || ((5 + 15 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) (0 <= -20 + 20) && !(-20 > 15) || ((5 + 15 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) (0 <= 0) && !(-20 > 15) || ((5 + 15 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) (true) && !(-20 > 15) || ((5 + 15 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) (true) && !(false) || ((5 + 15 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) (true) && true || ((5 + 15 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) (true) && true || ((5 + 15 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) true || ((5 + 15 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) true || ((20 + -20 > 15 - -20) && (-20 > 0 || 15 > 0));
	// 1) true || ((0 > 35) && (-20 > 0 || 15 > 0));
	// 1) true || false && (-20 > 0 || 15 > 0));
	// 1) true || false && (false || 15 > 0));
	// 1) true || false && (false || true));
	// 1) true || false && true;
	// 1) true || false;
	// 1) true;


	cout << format("Exemple 1 : {}\n", estConditionExemple1);
	cout << format("Exemple 2 : {}\n", estConditionExemple2);

#pragma endregion
}
