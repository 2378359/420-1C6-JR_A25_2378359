/*
	Auteur		:
	Date		:
	Description	:
*/

#include <format>
#include <iostream>
#include <string>

#include "fonctions.h"
#include "Constantes.h"


// TODO : Ctrl+M,O : Réduire toutes les régions de code
// TODO : Ctrl+M,L : Développer toutes les régions de code
// TODO : Ctrl+M,M : Réduire ou développer la région actuelle ou sélectionnée

using namespace std;



int main()
{
	cout << "--- Cours 24 - Parametres et fichier d'en-tete ---\n\n";

	// *** Paramètres par défaut ***
	// - Permettent lors de l'appel d'une fonction de ne pas avoir à entrer des valeurs pour tous les paramètres
	// - Utile pour ne pas avoir une fonction surchargée en 3-4 exemplaires avec code redondant
	// - En C++ spécifiquement
	//		- Définir une valeur par défaut dans la déclaration (prototype) de la fonction
	//		- Paramètres avec valeur doivent se suivre en bloc à partir de la fin
	//		- Dès qu'un paramètre a une valeur par défaut
	//		- Autres paramètres suivants doivent aussi avoir une valeur par défaut

	if (true)
	{
		double rabais1 = calculerAfficherRabais(100.0, 0.20, true, "Chaussures");
		double rabais2 = calculerAfficherRabais(100.0, 0.15, false, "");

		// TODO: Modifier la fonction afin de convertir les 2 dernier paramètres avec des valeurs par défaut
		//double rabais3 = calculerAfficherRabais(100.0, 0.3);

		// Erreur : paramètre obligatoire manquant
		//double rabais4 = calculerAfficherRabais(100.0);

		// Erreur : non pemis de sauter par dessus un paramètre avec valeur par défaut
		//double rabais5 = calculerAfficherRabais(100.0, 30, "");
	}

	// TODO: Modifier les fonctions afin d'avoir une seule fonction avec 3 paramètres avec une valeur par défaut 'INT_MIN'
	if (false)
	{
		bool estNombreEgal1 = estNombreEgal(10, 10);
		bool estNombreEgal2 = estNombreEgal(10, 10, 10);
	}

	// *** Références (&) et pointeurs (*) ***
	// - Normalement, les cases en mémoire qui contiennent des valeurs
	//		- int, double, char, string, etc.
	// - Possible de définir des liens vers une autre case en mémoire
	//		- Références (&)
	//			 - int&, double&, char&, string&, etc.
	//		- Pointeurs (*)
	//			- int*, double*, char*, string*, etc.
	//		- Très similaires, simplement un lien vers une adresse en mémoire (ex. 0x123456)
	//		- Pour le cours
	//			- Références (&) seront utilisées, car elles sont plus simples
	//			- Pointeurs (*) sont plus puissants, mais beaucoup de langages empêchent leur utilisation directe

	// TODO : Dessiner le fonctionnement en mémoire des références
	if (false)
	{
		// Variables réservent des emplacements mémoire
		int x = 10;
		int y = 50;

		cout << format("Adresse memoire de x : {:#x}\n", (unsigned long)(&x));
		cout << format("Valeur de x : {}\n\n", x);

		cout << format("Adresse memoire de y : {:#x}\n", (unsigned long)(&y));
		cout << format("Valeur de y : {}\n\n", y);

		// & : pas une nouvelle case mémoire, mais une référence (pointeur) à l'emplacement mémoire de 'x'
		int& reference = x;

		cout << format("Adresse memoire de reference : {:#x}\n", (unsigned int)(&reference));
		cout << format("Valeur de reference : {}\n\n", reference);

		// Référence permet de modifier la valeur de la case mémoire 'x' à la valeur 20
		reference = 20;

		cout << format("Adresse memoire de x : {:#x}\n", (unsigned int)(&x));
		cout << format("Adresse memoire de reference : {:#x}\n", (unsigned int)(&reference));

		cout << format("Valeur de x : {}\n", x);
		cout << format("Valeur de reference : {}\n\n", reference);

		cout << format("Valeur de x après modification via référence : {}\n", x);

		// & : pas une nouvelle case mémoire, mais une référence (pointeur) à l'emplacement mémoire de 'x'
		const int& referenceConstante = x;

		cout << format("Adresse memoire de referenceConstante : {:#x}\n", (unsigned int)(&referenceConstante));
		cout << format("Valeur de referenceConstante : {}\n\n", referenceConstante);

		// Erreur : la référence est constante (const&) et ne peut modifier la valeur de la case mémoire 'x'
		//referenceConstante = 30;			
	}

	// *** Paramètre par référence (&) ***
	// - Permettent de recevoir un pointeur vers une variable de la fonction parant afin de modifier sa valeurs
	// - Paramètre par copie
	//		- Par défaut, les valeurs des paramètres sont passées par 'copie'
	//			- int calculerResultat(int nombre)
	//		- Appel de la fonction
	//			- Nouvelle boite en mémoire est créée
	//			- Valeur est copiée dans la nouvelle boite
	//		- Fin de la fonction
	//			- Boites sont détruites
	//			- Valeurs modifiées sont perdues
	// - Paramètre par référence
	//		- Utiliser la syntaxe (&) après le type d'un paramètre
	//			- int calculerResultat(int& nombre)
	//		- Appel de la fonction
	//			- Nouvelle boite en mémoire est créée
	//			- Adresse de la variable originale est inscrite dans la boite plutôt que la valeur
	//		- Fin de la fonction
	//			- Nouvelle boite en mémoire est créée
	//			- Paramètres est maintenant un lien vers l'adresse
	// - Utile pour avoir une fonction qui 'retourne' plusieurs valeurs
	//		- int calculerResultat(int& nombre, double& valeur, string& chaine)
	//			- Valeur du type de retour
	//				- 1 valeur int retourné
	//			- Chaque variable passée par référence (&) est aussi 'retournée' ou en fait 'modifiée' par la fonction
	//				- 3 variables modifiées : int&, double&, string&

	// TODO : Dessiner le fonctionnement en mémoire de l'appel des fonctions suivantes
	if (false)
	{
		cout << "--- calculerResultat() ---\n\n";

		int nombre1 = 10;
		int nombre2 = 20;

		cout << format("Nombre 1 (avant appel) : {}\n", nombre1);
		cout << format("Nombre 2 (avant appel) : {}\n\n", nombre2);

		int resultat1 = calculerResultat(nombre1, nombre2);

		cout << format("Resultat 1 : {}\n\n", resultat1);

		cout << format("Nombre 1 (apres appel) : {}\n", nombre1);
		cout << format("Nombre 2 (apres appel) : {}\n\n", nombre2);

		// TODO : Convertir le 2ème paramètre de la fonction 'calculerResultatReference()' en paramètre par référence (&)
		cout << "--- calculerResultatReference() ---\n\n";

		int nombre3 = 10;
		int nombre4 = 20;

		cout << format("Nombre 3 (avant appel) : {}\n", nombre3);
		cout << format("Nombre 4 (avant appel) : {}\n\n", nombre4);

		int resultat2 = calculerResultatReference(nombre3, nombre4);

		cout << format("Resultat 2 : {}\n\n", resultat2);

		cout << format("Nombre 3 (apres appel) : {}\n", nombre3);
		cout << format("Nombre 4 (apres appel) : {}\n\n", nombre4);
	}

	// *** Paramètres constants (const) ***
	// - S'assurer que la variable n'est jamais modifiée par la fonction
	// - Indiquer au programmeur des informations sur la fonction
	//		- Fonction fait uniquement un calcul avec les valeurs des paramètres
	//		- Ne pas modifier le paramètre dans les calculs de la fonction
	//      - Toujours utiliser 'const' pour les paramètres qui n'ont pas besoin d'être modifiés
	// - Permettre aussi des copies en mémoire inutiles de gros objets (ex. string, vector, etc.)
	//		- String sont toujours passées en référence ou référence constantes
	// 			- string& chaineModifiable
	//			- const string& chaineNonModifiable

	// TODO: Modifier la fonction 'calculerResultatConstantes()' pour utiliser des paramètres constants
	if (false)
	{
		int nombre = 123;
		string message1 = "Message a conserver\n";
		string message2 = "--- En-tete a suivre avec le resultat --- \n";

		int resultat = calculerResultatConstantes(nombre, message1, message2);

		cout << format("Resultat : {}\n\n", resultat);

		cout << format("Nombre : {}\n", nombre);
		cout << format("Message 1 : {}\n", message1);
		cout << format("Message 2 : \n{}\n", message2);
	}

	// *** Early exit ***
	// - Permet de conserver le code des fonctions simples et if/else imbriqués
	// - Erreurs
	//		- Vérifier chaque erreur possible au début de la fonction
	//		- Retourner immédiatement une erreur
	// - Boucles
	//		- Retourner immédiatement lorsqu'une condition de fin est rencontrée
	//		- À voir plus tard avec les tableaux

	if (false)
	{
		//// todo: transformer la fonction suivante avec 3 niveau de if avec des 'early exit'
		//double efficacite1 = calculerefficaciteenergie(100, 200);
		//cout << ("efficacite 1 : {}%\n", efficacite1);

		//double efficacite2 = calculerefficaciteenergie(0, 200);
		//cout << ("efficacite 2 : {}%\n", efficacite2);

		//double efficacite3 = calculerefficaciteenergie(100, -1);
		//cout << ("efficacite 3 : {}%\n", efficacite3);

		 //TODO: Créer une surcharge de la fonction afin d'écrire le message affiché dans une variable passée par référence (&)
		string messageErreurEfficacite4;
		double efficacite4 = calculerEfficaciteEnergie(100, -1, messageErreurEfficacite4);
		if (efficacite4 != -1)
		{
			cout << ("Efficacite 4 : {}%\n", efficacite4);
		}
		else
		{
			cout << ("Efficacite 4 : {}%\n", messageErreurEfficacite4);
		}
	}

	// *** Fichiers ***
	// - Permettent d'organiser et répartir le code afin de se retrouver plus facilement
	// - Fichier d'en-tête (header file) .h
	//     - Contient des définitions des fonctions (prototypes)
	//     - Contient des définitions globales (constantes, enums)
	//	   - Note : C++ est un des rares langages à utiliser des fichiers d'en-tête
	// - Fichier d'implémentation (C++ file) .cpp
	//     - Contient les définitions (corps) des fonctions

	// *** Fichier d'en tête (header file) ***
	// - Contient seulement les déclaration des fonctions
	// - Doit inclure les définitions des types de données utilisées afin que les définitions de fonctions soient valides
	//		- Types de base toujours disponibles : int, double, char, bool
	//		- Problème classique : std::string
	// - Inclure le fichier dans les autres fichiers (.cpp) qui doivent avoir les définitions des fonctions
	//		- #include "FichierEnTete.h"
	//		- Fichiers qui doivent inclure l'en-tête
	//			- Contient une définition (Corps) d'au moins une des fonctions définie dans le fichier d'en-tête
	//			- Contient au moins un appel d'une des fonctions définie dans le fichier d'en-tête
	// - #pragma once
	//	    - Fichier d'en-tête est inclus plusieurs fois les définitions de fonctions serait normalement définies en doubles
	// 	    - S'assurer que le code est seulement présent une seule fois dans le projet au complet
	//		- Fichier d'en-tête doit toujours commencer par l'instruction #pragma once

	// TODO: Déplacer les déclarations de fonctions (prototypes) créées précédemment dans le fichier d'en-tête
	// TODO: Compiler le code afin d'avoir un exemple d'erreurs d'inclusion de l'en-tête manquant
	// TODO: Fixer l'erreur en incluant le fichier d'en-tête dans le fichier cpp

	// *** Fichiers d'implémentation ***
	// - Permettent de distribuer le code des fonctions du projet
	// - Rend le code plus facile à lire
	// - Classes dans le cours de Programmation 2 utiliseront beaucoup de fichiers

	// TODO: Déplacer les définitions de fonctions (corps) dans un nouveau fichier 'Fonctions.cpp'
	// TODO: Dans l'en-tête, créer une fonction avec 'string' comme type de retour ou comme paramètre

	// *** Fichier de constantes ***
	// - Permettent de regrouper l'ensemble des valeurs constantes du projet
	//		- Constantes
	//		- Enums
	// - Dans un vrai projet qui doit supporter qui doit être localisé	
	//		- Chaînes de caractères des différents messages
	//		- Voir plus tard avec les tableaux pour supporter plusieurs langages

	// TODO: Ajouter un fichier de constantes 'Constantes.h' avec les valeurs des constantes et enums
	if (false)
	{
		cout << format("Taux de taxe : {}\n", TAUX_TAXE);
		cout << format("Valeur entiere de la couleur jaune : {}\n", (int)Couleur::Jaune);
	}

	// *** Raccourcis claviers ***
	// Utile pour naviguer à travers plusieurs fichiers
	// - F12		: Aller à la définition (corps) de la fonction ou 
	// - Ctrl+F12	: Aller à la déclaration (prototype) de la fonction
	// - Ctrl+-		: Retourner au dernier emplacement du curseur (avant un F12, Ctrl+F12, clic de souris, etc.)
	// 
	// Utile pour modifier les fonctions (refactoriser)
	// - Ctrl+R,R	: Renommer un symbole (fonction, constante, enum) dans tous les fichiers du projet
	// - Ctrl+.		: Modifier la signature de la fonction (ordre des paramètres)

	// *** Documentation de fonctions ***
	// - Permet aux autres programmeurs de comprendre comment utilsier la fonction sans lire le code
	//		- Excellente pratique dans un cadre profesionnel, surtout pour :
	// 			- Bibliothèque de code (ex. <iostream>, <cmath>, etc.)
	//			- API
	// - '///' génére un bloc de documentation pour la fonction (C++/C#)
	//		- <summary>
	//			- Description générale de la fonction avec explication complète
	//			- Donner un exemple ou le plus de contexte possible à l'utilisateur
	//			- <para> ... </para>
	// 				- Permet de sauter une ligne afin de rendre le texte plus lisible
	//		- <param>
	//			- Description de chaque paramètre avec valeurs attendues (entier, nombre virgule)
	//			- Spécifier aussi les limitations (plus grand que 0, etc.)
	//		- <returns>
	//			- Description du type de retour avec contexte
	//			- Donner un exemple d'entrée et de sortie retournée (ex. "abc" => 'a')
	// - Difficile de bien documenter des fonctions simples, mais il faut se pratiquer ! 

	// TODO: Voir la documentation de la fonction 'calculerFibonacci()' et mettre souris sur la fonction
	if (false)
	{
		int fibonnaci = calculerFibonacci(6);
		cout << format("Suite de Fibonacci au terme 6 : {}\n\n", fibonnaci);
	}

	// TODO: Documenter une des fonctions ensemble (ex. 'calculerEfficacite()')

	// *** Récursion ***
	// - Seulement pour le plaisir, n'est pas dans la matière du cours
	// - Façon avancée et complexe d'écrire une fonction 
	//		- Fonction s'appelle elle-même une ou plusieurs fois (récursion)
	//		- Terminer la récursion
	//			- Appels décrémentent la valeur ou épuisent les cas à traiter
	//			- Cas de base retournent une valeur au début de la fonction pour terminer la récursion
	// - Certains problèmes complexes sont beaucoup plus simples avec la récursion (ex. graphes)
	//		- Peu optimisé car les fonctions ont un coût d'appel
	//		- Peu être résolu par des boucles ou programmation avancée (voir dynamic programming)

	// TODO: Exemple de fonction récursive
	if (false)
	{
		// Afficher les 20 premiers termes de la suite de Fibonnaci
		for (int terme = 0; terme <= 20; terme++)
		{
			int resultatFibonacci = calculerFibonacci(terme);
			cout << format("Fibonacci {} : {}\n", terme, resultatFibonacci);
		}
	}
}
