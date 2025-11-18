/*
	Auteur		:
	Date		:
	Description	: Introduction aux collections génériques avec vector<T>
*/

#include <algorithm>
#include <format>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma region DeclarationFonctions
void afficherVecteurParCopie(const vector<int> vecteur, const string& nom);
void afficherVecteurParReference(const vector<int>& vecteur, const string& nom);
void modifierValeurParCopie(vector<int> vecteur, const int valeur);
void modifierValeurParReference(vector<int>& vecteur, const int valeur);
void testerRedimensionnementVecteur(const int taillerReservationVecteur, const int nombreAjouts, const bool estAfficherVecteurs);
vector<int> retournerNouveauVecteur();
#pragma endregion

int main()
{
	cout << "--- Cours 34 - Vecteurs ---\n\n";

	// *** Collections génériques ***
	// - Conteneurs qui peuvent contenir plusieurs types de données selon un type générique spécifié
	//		- <T> (type)			: <int>, <double>, <string>, <CustomStruct>, etc.
	//		- <K, V> (key, value)	: <int, string>, <int, CustomStruct>, etc.
	// - Fournissent des fonctionnalités avancées pour la gestion des collections
	// 
	// C++ Standard Template Library (STL) | C#                          | JavaScript
	// ---------------------------------------------------------------------------------
	// std::vector<T>                      | List<T>			         | Array
	// std::unordered_map<K, V>            | Dictionary<K, V>            | Map
	// std::queue<T>                       | Queue<T>                    | Queue
	// std::stack<T>                       | Stack<T>                    | Stack
	// std::set<T>                         | HashSet<T>                  | Set
	// ...

	// *** Tableau dynamique (std::vector<T>) ***
	// - Conteneur qui peut redimensionner automatiquement les éléments afin d'en ajouter et d'en supprimer
	// - Tableau continu en mémoire du type de données spécifié
	//		- vector<int>	 : contient un tableau int[] en mémoire
	//		- vector<string> : contient un tableau string[] en mémoire
	//		- etc.
	// - Gère automatiquement la mémoire du tableau (allocation, libération, redimensionnement)
	//		- Définition
	//			- Allocation dynamique de mémoire d'un tableau sur le tas (heap)
	//				- Taille définie lors de la définition
	//				- Taille par défaut de 10 éléments si non spécifiée lors de la définition du vecteur
	//					- C++ : tableau de taille 0 par défaut
	//					- C#  : tableau de taille 10 par défaut (List<T>)
	//          - Informations conservées
	//				- Pointeur vers un tableau dynamique en mémoire sur le tas (heap)
	//				- Nombre d'éléments actuellement utilisés (.size())
	// 				- Capacité actuelle du tableau (.capacity())
	//		- Ajout d'un élément
	//			- Tableau ne contient pas le maximum d'élément
	//				- Ajout de l'élément au premier index libre
	//			- Tableau contient le maximum d'éléments
	//				- Allocation d'un nouveau tableau avec une capacité doublée sur le tas (heap)
	//					- C++ : capacité +25%
	//					- C#  : capacité x2 (List<T>)
	//				- Copie de chaque élément de l'ancien tableau vers le nouveau tableau
	//				- Changement du pointeur vers le nouveau tableau
	//				- Libération de l'ancien tableau en mémoire
	//		- Suppression d'un élément
	//			- Éléments du tableau doivent toujours rester contigu en mémoire
	//				- Permet un accès par index []
	//				- Permet de connaitre le nombre d'éléments avec .size()
	//			- Déplacement des éléments lors de l'ajout ou de la suppression
	//				- Supprimer premier élément (0)
	//					- Tous les éléments suivants doivent être décalés d'un index vers le début
	// 				- Supprimer dernier élément (size() - 1)
	// 					- Aucun déplacement nécessaire

	if (false)
	{
		cout << "--- Redimensionnement automatique ---\n\n";

		const int NOMBRE_AJOUTS = 100; // TODO: 1000, 1000000
		const bool EST_AFFICHER_VECTEURS = true;

		testerRedimensionnementVecteur(0, NOMBRE_AJOUTS, EST_AFFICHER_VECTEURS);
		system("pause");

		testerRedimensionnementVecteur(NOMBRE_AJOUTS, NOMBRE_AJOUTS, EST_AFFICHER_VECTEURS);
		system("pause");
	}

	// *** Syntaxe ***
	// #include <vector>
	// 
	// // Tableau prédéfini avec taille par défaut (10 éléments)
	// vector<type> nomVecteur;	
	// 
	// // Tableau avec taille personnalisée
	// vector<type> nomVecteur(tailleInitiale);
	// vector<type> nomVecteur(tailleInitiale, valeurInitiale);
	// 
	// // Initialisation avec des valeurs
	// vector<type> nomVecteur = { valeur1, valeur2, valeur3, ... };
	//

	// TODO: Dessin de la mémoire d'un vecteur (pointeur, capacity, size, tableau)

	if (false)
	{
		cout << "--- Declaration des vecteurs ---\n\n";

		// *** Déclaration des vecteurs ***
		// - Plusieurs façons de déclarer un vecteur
		// - Différences entre capacity (taille du tableau en mémoire) et size (nombre d'éléments utilisés)

		// Déclaration d'un vecteur avec un tableau par défaut vide
		// Capacity		: 0
		// Size			: 0
		// Tableau		: 
		vector<int> vecteurVide;

		afficherVecteurParReference(vecteurVide, "vecteurVide");

		// Déclarer un vecteur sans aucun élément, mais 20 espaces en mémoire
		// Capacity		: 20
		// Size			: 0
		// Tableau		: 
		// Note : Rare, seulement pour optimisation de ne pas avoir à agrandir le tableau
		vector<int> vecteurVidePredefini;
		vecteurVidePredefini.reserve(20);

		afficherVecteurParReference(vecteurVidePredefini, "vecteurVidePredefini");

		// Déclarer un vecteur avec 5 valeurs, donc 5 espaces en mémoire
		// Capacity		: 5
		// Size			: 5
		// Tableau		: 10, 20, 30, 40, 50
		vector<int> vecteurValeurs = { 10, 20, 30, 40, 50 };

		afficherVecteurParReference(vecteurValeurs, "vecteurValeursPredefinies");

		// Vecteur avec un tableau par défaut de 20 éléments initialisé à une valeur
		// Capacity		: 20
		// Size			: 20
		// Tableau		: 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5
		vector<int> vecteurValeurPredefinie1(20, 5);
		vector<int> vecteurValeurPredefinie2 = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

		// Erreur de syntaxe
		//vector<int> vecteurValeurPredefinie2(20) = {5}; 

		afficherVecteurParReference(vecteurValeurPredefinie1, "vecteurValeursPredefini1");
		afficherVecteurParReference(vecteurValeurPredefinie2, "vecteurValeursPredefini2");
	}

	// *** Utilisation des vecteurs ***
	// - Créer un vecteur
	//		- vector<int> vecteur;
	// - Ajouter des éléments à la fin du tableau avec push_back()
	//		- vecteur.push_back(valeur);
	// - Accéder aux éléments avec une boucle for sur le nombre d'éléments du tableau 'size()' et l'opérateur '[]'
	//		for (int i = 0; i < vecteur.size(); i++)
	//		{
	//			cout << vecteur[i];
	//		}
	// - C#
	//		- List<int> nomListe = new List<int>();
	//		- Fonctions similaires : 
	//			- Add(), Remove(), Insert(), Clear(), Count, Capacity, etc.
	// - JavaScript
	//		- let nomTableau = [];
	//		- Fonctions similaires :
	//			- push(), pop(), splice(), length, etc.
	//		- Tout est une chaine de caractères ou un objet, donc possible de mélanger les types dans un même tableau
	//
	// *** Méthodes courantes de std::vector ***
	// * Initilisation *
	// - .reserve(tailleTableau): Réserver un tableau en mémoire de la taille spécifiée dans le 'heap'
	//
	// * Informations *
	// - .size()				: Retourner le nombre d'éléments dans le vecteur
	// - .capacity()			: Retourner la capacité actuelle du tableau (taille du tableau alloué en mémoire)
	// - .empty()				: Vérifier si le vecteur est vide (raccourci de .size() == 0)	
	// 
	// * Ajout / Insertion *
	// - .push_back(valeur)	
	//		- Ajouter un élément à la fin du tableau au premier index libre
	//		- Tableau plein cause le redimensionnement automatique avec copie de chaque élément
	// 
	// - .insert(.begin() + index, valeur)	    
	//     - Insèrer une valeur à la position spécifiée en déplace les autres éléments du tableau
	//	   - Tableau plein cause le redimensionnement automatique avec copie de chaque élément
	// 
	// * Obtenir des éléments * 
	// - .front()					: Obtenir le premier élément du vecteur
	// - .back()					: Obtenir le dernier élément du vecteur
	// - [index]	
	//		- Accèder à l'élément à l'index spécifié sans vérification des limites
	//		- Crash si l'index est hors limites [0, .size() - 1]
	// 
	// * Supprimer des éléments *
	// - .clear()					: Supprimer tous les éléments
	// - .pop_back()				: Supprimer le dernier élément du vecteur
	// - .erase(.begin() + index)   : Supprimer l'élément à l'index spécifié à partir du début du vecteur (.begin())
	//
	// * Trier * 
	// - #include <algorithm>
	// - sort(.begin(), .end()) : Trier les éléments en ordre croissant

	if (false)
	{
		cout << "--- Utilisation des vecteurs ---\n\n";

		// TODO: Créer un vecteur
		vector<int> vecteur;

		// TODO: Ajouter les valeurs à la fin du vecteur avec .push_back() : 10, 20, 30, 40, 50
		vecteur.push_back(10);
		vecteur.push_back(20);
		vecteur.push_back(30);
		vecteur.push_back(40);
		vecteur.push_back(50);

		// Lire une valeur à ajouter à la Console
		int valeurAjoutee;
		cout << "Entrer une valeur a ajouter 3 fois a la fin du vecteur : ";
		cin >> valeurAjoutee;

		// TODO: Ajouter 3 fois la valeur lue à la Console à la fin du vecteur
		vecteur.push_back(valeurAjoutee);
		vecteur.push_back(valeurAjoutee);
		vecteur.push_back(valeurAjoutee);

		// Afficher les valeurs à la main en utilisant l'opérateur []
		cout << format("Premier element   [0] : {}\n", vecteur[0]);
		cout << format("Deuxieme element  [1] : {}\n", vecteur[1]);
		cout << format("Troisieme element [2] : {}\n", vecteur[2]);
		cout << format("Quatrieme element [3] : {}\n", vecteur[3]);
		cout << format("Cinquieme element [4] : {}\n", vecteur[4]);
		cout << format("Sixieme element   [5] : {}\n", vecteur[5]);
		cout << format("Septieme element  [6] : {}\n", vecteur[6]);
		cout << format("Huitieme element  [7] : {}\n", vecteur[7]);
		//cout << format("Premier element   [0] : {}\n", vecteur[-1]); // Crash
		//cout << format("Premier element   [0] : {}\n", vecteur[8]); // Crash

		// TODO: Afficher le nombre d'éléments du vecteur et les valeurs avec une boucle for et l'opérateur []
		cout << format("\nNombre d'elements : {}\n", vecteur.size());
		for (int i = 0; i < vecteur.size(); i++)
		{
			cout << format("vecteur[{}] : {}\n", i, vecteur[i]);
		}

		// TODO: Modifier la valeur du 3ème et 5ème élément à 123 et 456 avec l'opérateur []
		vecteur[2] = 123;
		vecteur[4] = 456;

		// TODO: Insérer la valeur 777 à la fin du vecteur
		vecteur.push_back(777);

		// TODO: Insérer la valeur 999 au début du vecteur avec .insert(.begin() + index, valeur)
		vecteur.insert(vecteur.begin(), 999);

		// TODO: Insérer la valeur 888 à l'avant-dernier index du vecteur and utilisant .size() - 1
		int avantDernierIndex = vecteur.size() - 1;
		vecteur.insert(vecteur.begin() + avantDernierIndex, 888);

		// TODO: Réafficher les valeurs en utilisant la boucle précédente
		cout << format("\nNombre d'elements : {}\n", vecteur.size());
		for (int i = 0; i < vecteur.size(); i++)
		{
			cout << format("vecteur[{}] : {}\n", i, vecteur[i]);
		}

		// TODO: Récupérer la valeur et supprimer le premier élément du vecteur (index 0) avec .erase(.begin() + index)
		int premierElement = vecteur[0];
		vecteur.erase(vecteur.begin());

		// TODO: Récupérer la valeur et supprimer le 4ème élément du vecteur (index 3)
		int quatriemeElement = vecteur[3];
		vecteur.erase(vecteur.begin() + 3);

		// TODO: Retirer le dernier élément du vecteur (size() - 1)
		int dernierElement = vecteur[vecteur.size() - 1];
		vecteur.erase(vecteur.begin() + vecteur.size() - 1);

		// TODO: Alternative avec .back() et .pop_back()
		int dernierElement2 = vecteur.back();
		vecteur.pop_back();

		// TODO: Réafficher les valeurs en utilisant la boucle précédente
		cout << format("\nNombre d'elements : {}\n", vecteur.size());
		for (int i = 0; i < vecteur.size(); i++)
		{
			cout << format("vecteur[{}] : {}\n", i, vecteur[i]);
		}

		// TODO: Trier le vecteur en ordre croissant avec l'algorithme sort(.begin(), .end())
		sort(vecteur.begin(), vecteur.end());

		// TODO: Réafficher les valeurs en utilisant la boucle précédente
		cout << format("\nNombre d'elements : {}\n", vecteur.size());
		for (int i = 0; i < vecteur.size(); i++)
		{
			cout << format("vecteur[{}] : {}\n", i, vecteur[i]);
		}

	}

	// *** Supprimer des éléments ***
	// - Déconseillé d'utiliser une boucle for positive pour supprimer des éléments (for)
	//		- Modifie la taille du vecteur et décale les éléments
	// - Pas d'impact pour une seule suppression
	// - Cause des erreurs ou des éléments non supprimés

	// TODO: Supprimer la première valeur 30 du vecteur
	// - Ne requiert pas de travail spécifique du au break qui arrete après la première suppression
	// - Débuter avec		: 0			(premier élément)
	// - Terminer i à		: size() 	(après premier)
	// - Incrémentation i	: i--
	if (false)
	{
		vector<int> vecteur = { 10, 20, 30, 10, 20, 30, 10, 10, 10, 20, 30, 30, 30, 10, 20, 20, 20, 30, 30, 30 };

		for (int i = 0; i < vecteur.size(); i++)
		{
			if (vecteur[i] == 30)
			{
				vecteur.erase(vecteur.begin() + i); 
				break;
			}
		}

		afficherVecteurParReference(vecteur, "vecteur sans premier 30 (for positif)");
	}

	// TODO: Supprimer la dernière valeur 30 du vecteur
	// - Ne requiert pas de travail spécifique du au break qui arrete après la première suppression
	// - Débuter avec		: size() - 1	(dernier élément)
	// - Terminer i à		: 0				(premier élément)
	// - Incrémentation i	: i--
	if (false)
	{
		vector<int> vecteur = { 10, 20, 30, 10, 20, 30, 10, 10, 10, 20, 30, 30, 30, 10, 20, 20, 20, 30, 30, 30 };

		for (int i = vecteur.size() - 1; i >= 0; i--)
		{
			if (vecteur[i] == 30)
			{
				vecteur.erase(vecteur.begin() + i);
				break;
			}
		}

		afficherVecteurParReference(vecteur, "Vecteur sans dernier 30 (forr negatif)");
	}

	// TODO: Supprimer toutes les valeurs 30 du vecteur avec une boucle for positive
	// - Attention, erreur avec une boucle for positive du a la suppression et au decalage des elements
	// - Ex. erreur de suppression avec 2 valeurs 30 de suite
	//      [10] 20  30  30  40   i = 0
	// 
	//       10 [20] 30  30  40   i = 1
	// 
	//       10  20 [30]<30<<40   i = 2 (30 est supprimé et les valeur 30 et 40 sont décalées vers la gauche)
	//       10  20 [30] 40             (besoin de retraiter l'index i = 2, nouvelle valeur 30)
	// 
	//		 10  20 [30]<40       i = 2 (30 est supprimé et les valeur 30 et 40 sont décalées vers la gauche)
	//       10  20 [40]                (besoin de retraiter l'index i = 2, nouvelle valeur 40)
	// 
	//       10  20 [40]          i = 2
	//
	// Erreur : utiliser vecteur.size(), car la taille peut changer pour éviter les crash
	// - size() initiale = 5
	//		- 10  20  30  30  40 = 5
	//		- 10  20  30  40     = 4 (après suppression d'un 30)
	//		- 10  20  40         = 3 (après suppression d'un autre 30)
	// - size() finale = 3
	//		- [3]/[4] crash car index hors limites [0] ... [2]
	// 
	if (false)
	{
		vector<int> vecteur = { 10, 20, 30, 10, 20, 30, 10, 10, 10, 20, 30, 30, 30, 10, 20, 20, 20, 30, 30, 30 };

		// TODO: Exemple de crash
		// int tailleInitiale = vecteur.size();
		// for (int i = 0; i < tailleInitiale; i++) // Crash (Ex. [19] n'existe plus avec les suppressions)

		for (int i = 0; i < vecteur.size(); i++) // [0] ... [19]
		{
			if (vecteur[i] == 30)
			{
				// Erreur !
				// - Supprimer un élément décale les éléments suivant vers la gauche d'un index - 1
				// - Saute par dessus le prochain élément à cause du i++
				vecteur.erase(vecteur.begin() + i);

				// TODO: Fixer le problème
				// - Reculer l'index de 1 pour compenser le décalage vers la gauche des éléments
				// - Forcer de retraiter l'index actuel, car un nouvel élément y est maintenant présent
				i--;
			}
		}

		afficherVecteurParReference(vecteur, "Vecteur sans 30 (for positif)");
	}

	// TODO: Supprimer toutes les valeurs 30 du vecteur avec une boucle négative (forr)
	// - Rien à corriger, les éléments qui sont décalés ont déjà été traités
	// - Ex. fonctionnement correct peu importe le nombre de valeurs 30 de suite
	//		 10   20   30  30 [10]  i = 4 
	// 
	//		 10   20   30 [30]<10   i = 3 (supprimer 30, 10 décalé vers la gauche)
	//       10   20   30 [10]            (pas besoin de retraiter 10, passer à i = 2)
	// 
	//       10   20  [30]<10       i = 2 (supprimer 30, 10 décalé vers la gauche)
	//       10   20  [10]                (pas besoin de retraiter 10, passer à i = 1)
	// 
	//       10  [20]  10			i = 1
	// 
	//      [10]  20   10			i = 0
	if (false)
	{
		vector<int> vecteur = { 10, 20, 30, 10, 20, 30, 10, 10, 10, 20, 30, 30, 30, 10, 20, 20, 20, 30, 30, 30 };

		for (int i = vecteur.size() - 1; i >= 0; i--)
		{
			if (vecteur[i] == 30)
			{
				vecteur.erase(vecteur.begin() + i);
			}
		}

		afficherVecteurParReference(vecteur, "Vecteur sans 30 (forr negatif)");
	}

	// *** Fonctions avec des vecteurs ***
// - Passer un vecteur en paramètre crée une copie du vecteur (tous les éléments sont copiés)
//		- Modifications dans la fonction n'affectent pas le vecteur original
// - Passer un vecteur par référence avec '&' évite la copie du vecteur
//		- Modifications dans la fonction affectent le vecteur original
	if (true)
	{
		// Initialiser un vecteur original avec des valeurs dans main()
		vector<int> vecteur;
		vecteur.reserve(100);

		vecteur.push_back(10);
		vecteur.push_back(20);
		vecteur.push_back(30);
		vecteur.push_back(40);
		vecteur.push_back(50);

		// Afficher les informations du vecteur original
		cout << "--- Vecteur original ----\n";
		cout << format("Adresse du vecteur : {:#x}\n", (unsigned long long) & vecteur);
		cout << format("Capacity           : {}\n", vecteur.capacity());
		cout << format("Size               : {}\n", vecteur.size());
		cout << format("Adresse du tableau : {:#x}\n\n", (unsigned long long) & vecteur[0]);

		// Tester un affichage par copie et par référence
		afficherVecteurParCopie(vecteur, "Vecteur par copie");
		afficherVecteurParReference(vecteur, "Vecteur par reference (&)");

		// Tester une modification par copie et par référence
		modifierValeurParCopie(vecteur, 555);
		afficherVecteurParReference(vecteur, "Vecteur apres modification par copie (manquant)");

		modifierValeurParReference(vecteur, 999);
		afficherVecteurParReference(vecteur, "Vecteur apres modification par reference (&) (present)");

		// Tester le retour d'un nouveau vecteur depuis une fonction
		vector<int> nouveauVecteur = retournerNouveauVecteur();
		afficherVecteurParReference(nouveauVecteur, "Nouveau vecteur apres retour par fonction");
	}

	return 0;
}

#pragma region DefinitionFonctions
void testerRedimensionnementVecteur(const int taillerReservationVecteur, const int nombreAjouts, const bool estAfficherVecteurs)
{
	// Déclaration d'un vecteur vide sans tableau alloué en mémoire
	vector<int> vecteur;

	// Créer un tableau en mémoire pour les éléments dans le 'heap' afin d'éviter les redimensionnements
	vecteur.reserve(taillerReservationVecteur);

	// Ajouter des 100 valeurs de 10 à 1000 dans le vecteur
	int compteurRedimensionnement = 0;
	int ancienneCapacity = vecteur.capacity();

	for (int i = 0; i < nombreAjouts; i++)
	{
		int valeur = (i + 1) * 10; // 10, 20, 30, ..., 1000
		vecteur.push_back(valeur);

		if (estAfficherVecteurs)
			afficherVecteurParReference(vecteur, "vecteur");

		if (vecteur.capacity() != ancienneCapacity)
		{
			++compteurRedimensionnement;
			ancienneCapacity = vecteur.capacity();
		}
	}

	cout << format("Nombre de redimensionnements : {}\n", compteurRedimensionnement);
}

void afficherVecteurParCopie(const vector<int> vecteur, const string& nom)
{
	cout << format("--- {} ---\n", nom);
	cout << format("Adresse du vecteur : {:#x}\n", (unsigned long long) & vecteur);
	cout << format("Capacity           : {}\n", vecteur.capacity());
	cout << format("Size               : {}\n", vecteur.size());

	if (vecteur.size() > 0)
	{
		cout << format("Adresse du tableau : {:#x}\n", (unsigned long long) & vecteur[0]);
		cout << format("Index [0] - [{}]  : ", vecteur.size());

		for (int i = 0; i < vecteur.size(); i++)
		{
			// Préférer [] à l'utilisation de .at() pour des performances optimales
			int valeur = vecteur[i];
			cout << format("{} ", valeur);
		}
	}

	cout << "\n\n";
}

void afficherVecteurParReference(const vector<int>& vecteur, const string& nom)
{
	cout << format("--- {} ---\n", nom);
	cout << format("Adresse du vecteur : {:#x}\n", (unsigned long long) & vecteur);
	cout << format("Capacity           : {}\n", vecteur.capacity());
	cout << format("Size               : {}\n", vecteur.size());

	if (vecteur.size() > 0)
	{
		cout << format("Adresse du tableau : {:#x}\n", (unsigned long long) & vecteur[0]);
		cout << format("Tableau [0] - [{}] : ", vecteur.size());

		for (int i = 0; i < vecteur.size(); i++)
		{
			// Préférer [] à l'utilisation de .at() pour des performances optimales
			int valeur = vecteur[i];
			cout << format("{} ", valeur);
		}
	}

	cout << "\n\n";
}

void modifierValeurParCopie(vector<int> vecteur, const int valeur)
{
	if (vecteur.size() <= 0)
		return;

	vecteur[0] = valeur;
}

void modifierValeurParReference(vector<int>& vecteur, const int valeur)
{
	if (vecteur.size() <= 0)
		return;

	vecteur[0] = valeur;
}

vector<int> retournerNouveauVecteur()
{
	vector<int> vecteur;

	for (int i = 0; i < 10; i++)
	{
		vecteur.push_back(i);
	}

	afficherVecteurParReference(vecteur, "Vecteur dans fonction");

	return vecteur;
}
#pragma endregion
