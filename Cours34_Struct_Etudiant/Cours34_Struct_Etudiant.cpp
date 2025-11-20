#include <algorithm>
#include <format>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Etudiant
{
	string prenom = "";
	string nom = "";
	int age = -1;
	double moyenne = 0.0;
};

struct Position 
{
	int ligne;
	int colonne;
};

struct ReponseNombre
{
	int nombre;
	Position position;
};

Position trouverPositionPremierNombre(const int tableau[][8], const int nombreRecherche);
vector<Position> trouverTousNombres(const int tableau[][8], const int nombreRecherche);
vector<ReponseNombre> trouverNombresPlusGrand(const int tableau[][8], const int minimum);
void afficherEtudiant(const Etudiant& etudiant);

bool comparerReponseNombre(const ReponseNombre& a, const ReponseNombre& b)
{
	return a.nombre < b.nombre;
}

int main()
{
	std::cout << "--- Cours 34 - Classes (struct) ---\n";

	// *** Classes (struct) ***
	// - Définir un type de données personnalisé contenant plusieurs variables
	//		- int, double, char, bool, string
	//		- int[], vector<double>, etc.
	//		- Peut contenir d'autres classes / struct
	// - Utilisation
	//		- Représenter des objets du monde réel (ex. Etudiant, Cours)
	//		- Regrouper des données liées ensemble dans un seul objet
	//		- Retourner plusieurs valeurs d'une fonction
	// - Syntaxe
	// 		- class MaClasse { ... };
	//		- struct MaStruct { ... };
	//		- Nomenclature
	//			- PascalCase
	//			- Normalement nom au singulier
	//				- Etudiant, Cours, Voiture, etc.
	// - Différences
	//		- class : variables sont privée par défaut
	//		- struct : variables sont publiques par défaut
	// - Classes seront utilisées dans le prochain cours de programmation

	if (false)
	{
		class MaClasse
		{
			// Variables sont privées par défaut, mot clé 'private:' implicite au début de la classe
			// private:
			int variablePrivee1 = -1;			// Bonne pratique de définir des valeurs par défaut
			double variablePrivee2 = 0;			// Bonne pratique de définir des valeurs par défaut
			char variablePrivee3 = '\0';		// Bonne pratique de définir des valeurs par défaut
			bool variablePrivee4 = false;		// Bonne pratique de définir des valeurs par défaut
			string variablePrivee5 = "Vide";	// Bonne pratique de définir des valeurs par défaut

			// Variables après le mot clé 'public:' sont publiques
		public:
			int variablePublique1 = -1;			// Bonne pratique de définir des valeurs par défaut
			double variablePublique2 = 0;		// Bonne pratique de définir des valeurs par défaut
			char variablePublique3 = '\0';		// Bonne pratique de définir des valeurs par défaut
			bool variablePublique4 = false;		// Bonne pratique de définir des valeurs par défaut
			string variablePublique5 = "Vide";	// Bonne pratique de définir des valeurs par défaut
		};
		// Attention au point-virgule à la fin de la classe

		struct MaStruct
		{
			// Variables sont publiques par défaut, mot clé 'public:' implicite au début de la classe
			// public:
			int variablePublique1 = -1;			// Bonne pratique de définir des valeurs par défaut
			double variablePublique2 = 0;		// Bonne pratique de définir des valeurs par défaut
			char variablePublique3 = '\0';		// Bonne pratique de définir des valeurs par défaut
			bool variablePublique4 = false;		// Bonne pratique de définir des valeurs par défaut
			string variablePublique5 = "Vide";	// Bonne pratique de définir des valeurs par défaut

			// Variables après le mot clé 'private:' sont privées
		private:
			int variablePrivee1 = -1;			// Bonne pratique de définir des valeurs par défaut
			double variablePrivee2 = 0;			// Bonne pratique de définir des valeurs par défaut
			char variablePrivee3 = '\0';		// Bonne pratique de définir des valeurs par défaut
			bool variablePrivee4 = false;		// Bonne pratique de définir des valeurs par défaut
			string variablePrivee5 = "Vide";	// Bonne pratique de définir des valeurs par défaut
		};
		// Attention au point-virgule à la fin de la struct

		// TOOD: Créer une instance de MaClasse et MaStruct et assigner des valeurs aux variables publiques
		MaClasse maClasse1;
		maClasse1.variablePublique1 = 123;

		MaStruct maStruct1;
		maStruct1.variablePublique3 = 'A';

		// TODO: Tentrer de modifier des variables privées
		//maClasse.variablePrivee1 = 5;  // Erreur : variable privée inaccessible
		//maStruct.variablePrivee1 = 15; // Erreur : variable privée inaccessible

		// TODO: Créer un vecteur de MaStruct et ajouter 2 copies de MaStruct au vecteur
		vector<MaStruct> elements;

		elements.push_back(maStruct1);
		elements.push_back(maStruct1);
		elements.push_back(maStruct1);
		elements.push_back(maStruct1);

		elements[0].variablePublique1 = 456;
	}

	// *** Utilisation *** 
	// - Fichier d'en-tête séparé (.h)
	//		- Définir une nouveau type de données struct contenant des variables avec des valeurs par défaut
	//			struct MaStruct
	// 			{
	//			    int variable1 = 0;
	//			    int variable2 = -1;
	// 			};
	// - Utilisation dans un autre fichier source (ex. main.cpp)
	//		- Inclure le fichier d'en-tête
	//			#include "MaStruct.h"
	// 		- Déclarer des variables du nouveau type (instances) et assigner les valeurs des variables
	//			MaStruct maStruct;
	//			maStruct.variable1 = valeur;
	// 			maStruct.variable2 = valeur;
	//		- Utiliser les valeurs des variables lorsque nécessaires
	//			cout << maStruct.variable1;
	//			cout << "Total : " << maStruct.variable1 + maStruct.variable2;

	if (false)
	{
		// TODO: Créer une struct Etudiant avec les données prenom, nom, age, moyenne


		// TODO: Créer un premier étudiant avec des valeurs
		// - John Doe, 20 ans, moyenne 85.5
		Etudiant etudiant1;
		etudiant1.prenom = "John";
		etudiant1.nom = "Doe";
		etudiant1.age = 20;
		etudiant1.moyenne = 85.5;

		// TODO: Afficher l'étudiant à l'écran à l'aide des données de la struct
		cout << format("--- Etudiant : {}, {} ---\n", etudiant1.nom, etudiant1.prenom);
		cout << format("Age: {}\n", etudiant1.age);
		cout << format("Moyenne: {}\n\n", etudiant1.moyenne);

		// TODO: Créer un deuxième étudiant avec une initialisation rapide des valeurs
		// - Jane Smith, 21 ans, moyenne 90.0
		// - Attention, les valeur doivent être dans le même ordre que la struct
		//		- Etudiant etudiant = { "Prenom", "Nom", age, moyenne };
		//		- Dangeureux pour se tromper ou si la struct est modifiée plus tard
		//			- Ajouter une variable 'adresse' entre 'nom' et 'age' brise les initialisations rapides
		//			- Inverser l'ordre de 'prenom' et 'nom' brise les initialisations rapides
		Etudiant etudiant2 = { "Jane", "Smith", 21, 90.0 };

		// TODO: Afficher l'étudiant à l'écran
		cout << format("--- Etudiant : {}, {} ---\n", etudiant2.nom, etudiant2.prenom);
		cout << format("Age: {}\n", etudiant2.age);
		cout << format("Moyenne: {}\n\n", etudiant2.moyenne);

		// TODO: Initialiser le vecteur d'étudiants avec 3 etudiants
		// - Alan Turing, 19 ans, moyenne 80.2
		// - Bob Gratton, 50 ans, moyenne 65.3
		// - Carl Sagan, 21 ans, moyenne 78.4
		vector<Etudiant> etudiants =
		{
			{ "Alan", "Turing", 19, 80.2 },
			{ "Bob", "Gratton", 50, 65.3 },
			{ "Carl", "Sagan", 21, 78.4 },
		};
		// TODO: Ajouter les 2 étudiants créés précédemment au vecteur
		etudiants.push_back(etudiant1);
		etudiants.push_back(etudiant2);

		// TODO : Afficher tous les étudiants du vecteur avec la fonction 'afficherEtudiant'
		for (int i = 0; i < etudiants.size(); i++)
		{
			afficherEtudiant(etudiants[i]);
		}

		// TODO: Modifier la moyenne de tous les étudiants du vecteur directement un index [i]
		for (int i = 0; i < etudiants.size(); i++)
		{
			etudiants[i].moyenne = 0;
		}

		// TODO : Afficher tous les étudiants du vecteur à l'écran


		// TODO: Récupérer un 'Etudiant' à partir de l'index du vecteur et modifier la moyenne
		// - Copie temporaire modifiée, n'affecte pas le tableau
		for (int i = 0; i < etudiants.size(); i++)
		{
			Etudiant& etudiant = etudiants[i];
			etudiant.moyenne = 50;
		}

		// TODO : Afficher tous les étudiants du vecteur à l'écran
		for (int i = 0; i < etudiants.size(); i++)
		{
			afficherEtudiant(etudiants[i]);
		}

		// TODO: Récupérer un 'Etudiant&' à partir de l'index du vecteur et modifier la moyenne
		// - Modifications une référence modifient les éléments du tableau


		// TODO : Afficher tous les étudiants du vecteur à l'écran

	}

	// *** Fonctions ***
	// - Paramètre par valeur (copie) 
	// 		- void fonction(MaStruct parametre) { ... }
	//		- Aucune des modifications des variables n'affectent l'original
	//		- Sauf les pointeurs comme les tableaux qui pointent sur la même adresse
	//			- Ex. int[], int[][]
	// - Paramètre par référence (&)
	// 		- void fonction(MaStruct& parametre) { ... }
	//		- Modifications des variables affectent l'original
	// - Retour d'une struct
	//		- Retourner une struct pour retourner plusieurs valeurs d'une seule fonction
	//			- MaStruct fonction() { ... return maStruct; }
	//			- Préférable à l'utilisation de plusieurs références (&)
	//			- Empêcher les 'effets de bord' des fonctions (modifications involontaires ou cachées)
	//			- Assigner les valeurs retournées aux bonnes variables rend le code plus facile à suivre
	//		- Éviter
	//			void fonction(int& valeur1, int& valeur2) { ... }
	//		- Préférer
	//			MaStruct fonction(int valeur1, int valeur2) 
	//		    {
	//				MaStruct maStruct;
	//				maStruct.valeur1 = valeur1 + 5;
	//				maStruct.valeur2 = valeur2 + 10;
	//				return maStruct; 
	//		    }
	//	
	//			MaStruct maStructReponse = fonction(10, 20);
	//		    variable1 = maStructReponse.valeur1;
	//		    variable2 = maStructReponse.valeur2;
	if (true)
	{
		int tableau[8][8] =
		{
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 8, 7, 6, 5, 4, 3, 2, 1 },
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 8, 7, 6, 5, 4, 3, 2, 1 },
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 8, 7, 6, 5, 4, 3, 2, 1 },
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 8, 7, 6, 5, 4, 3, 2, 1 },
		};

		// Afficher le tableau à l'écran
		cout << "Tableau 8x8 :\n";
		for (int ligne = 0; ligne < 8; ligne++)
		{
			for (int colonne = 0; colonne < 8; colonne++)
			{
				cout << format("{:3} ", tableau[ligne][colonne]);
			}
			cout << "\n";
		}

		// TODO: Trouver la première position du tableau ('ligne' et 'colonne') qui contient une valeur spécifique (ex. 8 ou 123)
		// TODO: Créer une structure 'Position' pour les fonctions avec : ligne et colonne
		Position position8 = trouverPositionPremierNombre(tableau, 8);
		Position position123 = trouverPositionPremierNombre(tableau, 123);

		cout << format("Position du premier 8   : ({}, {})\n", position8.ligne, position8.colonne);
		cout << format("Position du premier 123 : ({}, {})\n", position123.ligne, position123.colonne);

		// TODO: Trouver toutes les positions du tableau 'ligne' et 'colonne' qui contiennent une valeur spécifique
		vector<Position> positions8 = trouverTousNombres(tableau, 8);

		cout << format("Positions de tous les nombres 8 :\n");
		for (int i = 0; i < positions8.size(); i++)
		{
			cout << format(" ({}, {})\n", positions8[i].ligne, positions8[i].colonne);
		}

		// TODO: Trouver tous les nombres du tableau plus grand qu'une valeur spécifique (ex. 5)
		// TODO: Créer une structure ReponseNombre pour les fonctions avec : valeur et position (ligne et colonne)
		vector<ReponseNombre> nombresPlusGrand5 = trouverNombresPlusGrand(tableau, 5);


		cout << format("Nombres plus grand que 5 :\n");
		for (int i = 0; i < nombresPlusGrand5.size(); i++)
		{
			cout << format("  Valeur {} a la position ({}, {})\n", 
				nombresPlusGrand5[i].nombre, nombresPlusGrand5[i].position.ligne, nombresPlusGrand5[i].position.colonne);
		}

		// TODO: Trier les résultats par valeur croissante avec sort et  une fonction de comparaison personnalisée
		// bool comparerReponseNombre(const ReponseNombre& a, const ReponseNombre& b)
		// sort(, ,);

		sort(nombresPlusGrand5.begin(), nombresPlusGrand5.end(), comparerReponseNombre);
		cout << format("Nombres plus grand que 5 :\n");
		for (int i = 0; i < nombresPlusGrand5.size(); i++)
		{
			cout << format("  Valeur {} a la position ({}, {})\n",
				nombresPlusGrand5[i].nombre, nombresPlusGrand5[i].position.ligne, nombresPlusGrand5[i].position.colonne);
		}
	}

	// TODO: Déplacer les structures et les fonctions dans des fichiers d'en-tête séparés (.h)
	// - C# : simplement faire 'Ctrl+.' sur le nom de la classe et choisir 'Déplacer vers le fichier...'
	// - C++ : option n'existe pas
}

Position trouverPositionPremierNombre(const int tableau[][8], const int nombreRecherche)
{
	// Initialiser la position à des valeurs invalides
	Position positionReponse;
	positionReponse.ligne = -1;
	positionReponse.colonne = -1;

	for (int ligne = 0; ligne < 8; ligne++)
	{
		for (int colonne = 0; colonne < 8; colonne++)
		{
			int nombre = tableau[ligne][colonne];
			if (nombre == nombreRecherche)
			{
				positionReponse.ligne = ligne;
				positionReponse.colonne = colonne;

				// Retourner immédiatement la position trouvée
				return positionReponse;
			}
		}
	}

	return positionReponse;
}

vector<Position> trouverTousNombres(const int tableau[][8], const int nombreRecherche)
{
	// Initialiser la position à des valeurs invalides
	vector<Position> positions;
	for (int ligne = 0; ligne < 8; ligne++)
	{
		for (int colonne = 0; colonne < 8; colonne++)
		{
			int nombre = tableau[ligne][colonne];
			if (nombre == nombreRecherche)
			{
				Position positionReponse;
				positionReponse.ligne = ligne;
				positionReponse.colonne = colonne;

				// Retourner immédiatement la position trouvée
				positions.push_back(positionReponse);
			}
		}
	}

	
	return positions;
}

vector<ReponseNombre> trouverNombresPlusGrand(const int tableau[][8], const int minimum)
{
	// Initialiser la position à des valeurs invalides
	vector<ReponseNombre> reponseNombres;
	for (int ligne = 0; ligne < 8; ligne++)
	{
		for (int colonne = 0; colonne < 8; colonne++)
		{
			int nombre = tableau[ligne][colonne];
			if (nombre > minimum)
			{
				ReponseNombre reponseNombre;
				reponseNombre.nombre = nombre;
				reponseNombre.position.ligne = ligne;
				reponseNombre.position.colonne = ligne;

				reponseNombres.push_back(reponseNombre);
			}
		}
	}


	return reponseNombres;
}

void afficherEtudiant(const Etudiant& etudiant)
{
	cout << format("--- Etudiant : {}, {} ---\n", etudiant.nom, etudiant.prenom);
	cout << format("Age: {}\n", etudiant.age);
	cout << format("Moyenne: {}\n\n", etudiant.moyenne);
}
