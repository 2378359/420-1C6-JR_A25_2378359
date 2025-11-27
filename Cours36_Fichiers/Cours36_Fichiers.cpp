#include <ctime>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma region Constantes
const string FICHIER_LIVRES_LECTURE = "livres.csv";
const string FICHIER_LIVRES_VALIDES_ECRITURE = "livres_valides.txt";

struct Livre
{
	string titre = "";
	string auteur = "";
	int anneePublication = -1;
	double prix = 0.0;
};
#pragma endregion

#pragma region DeclarationFonctions
bool tryParseInt(const string& chaine, int& entier);
bool tryParseDouble(const string& chaine, double& nombreVirgule);
void testerTryParseEntier(const string& chaine);
void testerTryParseDouble(const string& chaine);
vector<string> split(const string& chaine, char delimiteur);

vector<Livre> lireFichierLivres(const string& nomFichier);
void sauvegarderFichierLivresValides(const string& nomFichier, const vector<Livre>& livres);
#pragma endregion

int main(int argc, char* argv[])
{
	std::cout << "--- Fichiers textes ---\n";

	// *** Lecture des ligne ***
	// - Permet de lire une ligne complète depuis un flux d'entrée (console, fichier, etc.)
	// - Permet de traiter la ligne complète, y compris les espaces
	// - Délimiteur est supprimé de la chaîne de caractères lue (ex. '\n')
	// 
	// getline(stream, variable); // '\n' comme délimiteur par défaut
	// getline(stream, variable, delimiteur);

	if (false)
	{
		string ligneTexte;
		cout << "Entrer une ligne de texte ('\\n' comme delimiteur) : ";
		getline(cin, ligneTexte);
		cout << format("Texte : {}\n", ligneTexte);

		string texteAvantDelimiteur;
		cout << "Entrer une ligne de texte (',' comme delimiteur) : ";
		getline(cin, texteAvantDelimiteur, ',');
		cout << format("Texte jusqu'au delimiteur ',' : {}\n", texteAvantDelimiteur);

		string texteApresDelimiteur;
		getline(cin, texteApresDelimiteur);
		cout << format("Texte apres le delimiteur ',' jusqu'au '\\n' : {}\n", texteApresDelimiteur);
	}

	// *** Fichiers textes ***
	// - Permettent de sauvegarder des données de façon permanente sur le disque dur
	//      - #include <fstream>
	//		- ifstream : input file stream (lecture)
	// 		- ofstream : output file stream (écriture)
	// - Formats textes de base avec des séparateurs simples
	//		- .txt : Fichier texte brut
	//		- .csv : Comma-Separated Values (valeurs séparées par des virgules ',')
	// - Format de fichiers avancés qui demandent des librairies de parsing supplémentaires pour lecture et écriture
	//		- .json : JavaScript Object Notation
	//		- .xml : eXtensible Markup Language
	//		- .yaml : YAML Ain't Markup Language

	// TODO: Tenter d'ouvrir un fichier 'lecture.txt' qui n'existe pas
	// TODO: Créer le fichier 'lecture.txt' avec le contenu et l'ajouter au 'Fichiers de ressources' du projet
	// - Alice Smith,alice.smith@exemple.com,5551234567
	// - Bob Johnson,bob.j@exemple.com,5559876543
	// - Charlie Brown,charlie.b@exemple.com,5555555555
	if (false)
	{
		// Ouvrir le fichier en mode lecture seulement (ifstream, ios::in)
		// - Reserve le fichier au niveau du système d'exploitation pour la lecture seulement
		// - N'empêche pas la lecture par les autres processus
		ifstream fichierEntree;
		fichierEntree.open("lecture.txt", ios::in);

		// Vérifier si l'ouverture du fichier a réussi avant de lire le contenu avec 'is_open()'
		if (!fichierEntree.is_open())
		{
			cout << "Erreur : Impossible d'ouvrir le fichier 'lecture.txt' en lecture.\n";
		}
		else
		{
			cout << "Contenu du fichier 'lecture.txt' :\n";

			// Lire chaque ligne du fichier jusqu'à la fin avec 'getline()'
			string ligne;
			while (getline(fichierEntree, ligne))
			{
				cout << ligne << "\n";
			}

			// Fermer le fichier après la lecture afin de ne pas bloquer l'accès au fichier par d'autres processus
			fichierEntree.close();
		}
	}

	// *** Modes d'ouverture des fichiers en écriture ***
	// - fichierSortie.open("ecriture.txt", ios::out);
	// 		- Ouvrir le curseur d'écriture 'out' au début du fichier
	// 		- Supprimer le contenu entier du fichier dès l'ouverture
	// - fichierSortie.open("ecriture.txt", ios::app);
	// 		- Ouvrir le curseur d'écriture 'append' à la fin du fichier
	//		- Conserver le contenu existant du fichier

	if (false)
	{
		ofstream fichierSortie;
		fichierSortie.open("ecriture.txt", ios::app); // ios::out ou ios::app

		// TODO: Vérifier que le fichier est ouvert avant d'écrire du contenu
		if (!fichierSortie.is_open())
		{
			cout << "Erreur : Impossible d'ouvrir le fichier 'ecriture.txt' en ecriture.\n";
		}
		else
		{
			cout << "Ecriture dans le fichier 'ecriture.txt'.\n";

			// TODO: Écrire des lignes dans le fichier
			fichierSortie << "Ceci est une ligne écrite dans le fichier.\n";
			fichierSortie << "Voici une autre ligne.\n";

			// TODO: Fermer le fichier après la lecture afin de ne pas bloquer l'accès au fichier par d'autres processus
			// - Important pour les fichiers en écriture qui bloquent l'accès aux autres processus
			fichierSortie.close();
		}
	}

	// *** Convertir des string ***
	// - C++11 et plus 
	//		- Fonctions sto...() afin de convertir des string en types numériques (int, double, float, long, etc.)
	//			- int stoi(chaine) : string to int
	// 			- double stod(chaine) : string to double
	//			- etc.
	//		- Lance une exception lors de l'échec de conversion (throw) qu'il faut gérer avec un bloc try/catch
	// - C#
	//		- Fonctions TryParse() qui contiennent déjà un try/catch et retournent un bool si la conversion réussit
	//			- bool int.TryParse(chaine, out int entier)
	//			- bool double.TryParse(chaine, out double nombreVirgule)
	//			- etc.
	//		- Fonctions 'tryParseInt' et 'tryParseDouble' fournies effectuent le même travail

	if (false)
	{
		cout << "\n--- Conversion avec stoi() et stod() ---\n\n";

		string chaineEntier = "12345";
		int entier = stoi(chaineEntier);

		string chaineDouble = "3.1416";
		double nombreVirgule = stod(chaineDouble);

		cout << format("Entier converti avec 'stoi()' : {}\n", entier);
		cout << format("Double converti avec 'stod()' : {}\n", nombreVirgule);

		// TODO: Crash lors d'un échec de conversion
		// double nombreVirguleErreur = stod("abc");

		// Englober la conversion dans un bloc try/catch pour recevoir l'exception
		//try
		//{
		//	double nombreVirguleErreur = stod("abc");
		//}
		//catch (const std::exception&) { }

		// Utiliser les fonctions 'tryParseInt' et 'tryParseDouble' fournies qui contiennent déjà un try/catch
		cout << "\n--- tryParseEntier() ---\n\n";

		testerTryParseEntier("12345");
		testerTryParseEntier("3.1416");
		testerTryParseEntier("abc");
		testerTryParseEntier("abc12345");
		testerTryParseEntier("abc3.1416");
		testerTryParseEntier("12345abc");
		testerTryParseEntier("3.1416abc");

		cout << "\n--- tryParseDouble() ---\n\n";

		testerTryParseDouble("12345");
		testerTryParseDouble("3.1416");
		testerTryParseDouble("abc");
		testerTryParseDouble("abc12345");
		testerTryParseDouble("abc3.1416");
		testerTryParseDouble("12345abc");
		testerTryParseDouble("3.1416abc");

		// Utiliser 'getline()' au lieu de 'cin <<' afin de convertir la ligne complète en int
		while (true)
		{
			cout << "\nEntrez un entier (q pour quitter) : ";
			string ligne;
			getline(cin, ligne);

			if (ligne == "q" || ligne == "Q") // Utiliser toLower()
				break;

			testerTryParseEntier(ligne);
		}

		// Utiliser 'getline()' au lieu de 'cin <<' afin de convertir la ligne complète en double
		while (true)
		{
			cout << "\nEntrez un nombre a virgule (q pour quitter) : ";
			string ligne;
			getline(cin, ligne);

			if (ligne == "q" || ligne == "Q") // Utiliser toLower()
				break;

			testerTryParseDouble(ligne);
		}
	}

	// *** Lire structures depuis un fichier texte ***
	if (false)
	{
		cout << "\n--- Lire structures depuis un fichier texte ---\n\n";

		// Lire le fichier CSV et convertir les lignes en Livres
		vector<Livre> livres = lireFichierLivres("livres.csv");

		// Afficher les livres valides qui ont pu être lus depuis le fichier
		cout << format("\n{} livres valides lus depuis le fichier 'livres.csv' :\n", livres.size());

		for (size_t i = 0; i < livres.size(); i++)
		{
			cout << format("livres[{}] - Titre: {}, Auteur: {}, Annee: {}, Prix: {}\n",
				i,
				livres[i].titre,
				livres[i].auteur,
				livres[i].anneePublication,
				livres[i].prix);
		}

		// Sauvegarder un nouveau fichier texte qui contient uniquement les livres valides
		sauvegarderFichierLivresValides("livres_valides.txt", livres);
	}

	// *** Arguments de programme ***
	// - Permettent de passer des informations au programme au moment de son lancement
	//		- Exemple : monProgramme.exe argument1 argument2
	// - Configuration des arguments du programme
	//		- Dans ligne de commande (ex. cmd, Git Bash, etc.)
	//			- Ouvrir le dossier 'x64' contenant l'exécutable du programme (exe)
	//			- Taper la commande
	//				- ./monProgramme.exe argument1 argument2 ...
	//		- Dans Visual Studio (débogage)
	// 			- Explorateur de solutions => Propriétés du projet => Débogage => Arguments de la commande commande
	// - Accès aux arguments
	// 		- Modifier la signature de la fonction main pour recevoir 2 nombres en paramètres :
	//			- int main(int argc, char* argv[])
	//			- 'argc' : nombre d'arguments passés en ligne de commande
	//			- 'argv' : tableau de chaînes de caractères contenant les arguments dans l'ordre
	//				- 'argv[0]' contient le nom du programme exécuté (ex. "monProgramme.exe")
	//				- 'argv[1]' contient le premier argument (ex. "argument1")
	//				- 'argv[2]' contient le deuxième argument (ex. "argument2")
	//				- etc.
	if (false)
	{
		cout << "\n--- Arguments de la ligne de commande ---\n";

		//TODO: Ajouter des arguments de test si aucun argument n'est fourni au programme
		//if (argc == 0)
		//{
		//	argc = 3;
		//	const char* args[] = { "monProgramme.exe", "argument1", "argument2" };
		//	argv = const_cast<char**>(args);
		//}

		// Afficher les arguments reçus de la ligne de commande
		cout << format("Nombre d'arguments : {}\n", argc);
		for (int i = 0; i < argc; ++i)
		{
			cout << format("Argument {} : {}\n", i, argv[i]);
		}

		// Afficher un message d'erreur si le nombre d'arguments ne correspond pas au nombre attendu
		const int NOMBRE_ARGUMENT_ATTENDU = 3;
		if (argc != NOMBRE_ARGUMENT_ATTENDU)
		{
			cout << format("Erreur : Nombre d'arguments {} ne correspond pas au nombre attendu {}.\n", argc, NOMBRE_ARGUMENT_ATTENDU);
			cout << "Appel du programme : ./programme.exe <fichier-lecture> <fichier-ecriture>\n";
			return -1;
		}

		// TODO: Ouvrir le premier argument après le nom du programme comme un fichier en lecture 'lecture.txt'
		ifstream fichierEntree;
		fichierEntree.open(argv[1], ios::in);

		if (!fichierEntree.is_open())
		{
			cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en lecture.\n", argv[1]);
			return -1;
		}

		// TODO: Ouvrir le deuxième argument après le nom du programme comme un fichier en écriture 'ecriture.txt'
		ofstream fichierSortie;
		fichierSortie.open(argv[2], ios::app);

		if (!fichierSortie.is_open())
		{
			cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en ecriture.\n", argv[2]);
			return -1;
		}

		// TODO: Lire chaque ligne du fichier d'entrée et écrire dans le fichier de sortie
		string ligne;
		while (getline(fichierEntree, ligne))
		{
			fichierSortie << ligne << "\n";
		}

		// TOOD: Écrire une ligne de fin de programme dans le fichier de sortie avec un timestamp
		fichierSortie << format("Fin du programme : {}\n", time(0));

		cout << format("\nLecture du fichier '{}' et ecriture dans le fichier '{}'.\n", argv[1], argv[2]);
	}

	return 0;
}

#pragma region DefinitionFonctions
bool tryParseInt(const string& chaine, int& entier)
{
	try
	{
		if (!chaine.empty())
		{
			size_t indexConversion = 0;
			int entierTemporaire = stoi(chaine, &indexConversion);

			// Vérifier si toute la chaîne a été convertie
			if (indexConversion == chaine.size())
			{
				entier = entierTemporaire;
				return true;
			}
		}
	}
	catch (const exception&) {}

	return false;
}

bool tryParseDouble(const string& chaine, double& nombreVirgule)
{
	try
	{
		if (!chaine.empty())
		{
			size_t indexConversion = 0;
			double nombreVirguleTemporaire = stod(chaine, &indexConversion);

			// Vérifier si toute la chaîne a été convertie
			if (indexConversion == chaine.size())
			{
				nombreVirgule = nombreVirguleTemporaire;
				return true;
			}
		}
	}
	catch (const exception&) {}

	return false;
}

void testerTryParseEntier(const string& chaine)
{
	int entier = 0;

	if (tryParseInt(chaine, entier))
	{
		cout << format("Conversion entiere reussie de '{}' : {}\n", chaine, entier);
	}
	else
	{
		cout << format("Erreur : Echec de la conversion entiere de '{}'\n", chaine);
	}
}

void testerTryParseDouble(const string& chaine)
{
	double nombreVirgule = 0.0;

	if (tryParseDouble(chaine, nombreVirgule))
	{
		cout << format("Conversion double reussie de '{}' : {}\n", chaine, nombreVirgule);
	}
	else
	{
		cout << format("Erreur : Echec de la conversion double de '{}'\n", chaine);
	}
}

vector<string> split(const string& chaine, char delimiteur)
{
	vector<string> tokens;

	// Retourner un vecteur vide si la chaîne est vide
	if (chaine.empty())
		return tokens;

	// Ajouter les tokens jusqu'au dernier delimiteur
	size_t indexDebut = 0;
	size_t indexDelimiteur = chaine.find(delimiteur);
	while (indexDelimiteur != string::npos)
	{
		string token = chaine.substr(indexDebut, indexDelimiteur - indexDebut);
		tokens.push_back(token);

		indexDebut = indexDelimiteur + 1;
		indexDelimiteur = chaine.find(delimiteur, indexDebut);
	}

	// Ajouter le reste de la chaine apres le dernier delimiteur jusqu'à la fin
	string token = chaine.substr(indexDebut);
	tokens.push_back(token);

	return tokens;
}

vector<Livre> lireFichierLivres(const string& nomFichier)
{
	vector<Livre> livres;

	ifstream fichierLivres;
	fichierLivres.open(nomFichier, ios::in);

	if (!fichierLivres.is_open())
	{
		cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en lecture.\n", nomFichier);
		return livres;
	}

	// Lire chaque ligne du fichier et tenter de convertir le texte en une instance de la struct 'Livre'
	int compteurLigne = 0;
	string ligne;
	while (getline(fichierLivres, ligne))
	{
		++compteurLigne;

		// TODO: Séparer la ligne en tokens avec la fonction 'split()' en utilisant la virgule comme délimiteur ','
		vector<string> tokens = split(ligne, ',');

		// TODO: Vérifier le nombre de tokens attendus
		if (tokens.size() != 4)
		{
			cout << format("Erreur : Ligne {} - Nombre delimiteurs invalide: {} - {}\n", compteurLigne, tokens.size(), ligne);
			continue;
		}

		// TODO: Créer une instance de 'Livre'
		Livre livre;

		// TODO: Pour les champs 'string', vérifier qu'ils ne sont pas vides avant de les assigner
		if (tokens[0].empty())
		{
			cout << format("Erreur : Ligne {} - Titre du livre vide.\n", compteurLigne);
			continue;
		}

		livre.titre = tokens[0];

		if (tokens[1].empty())
		{
			cout << format("Erreur : Ligne {} - Auteur du livre vide.\n", compteurLigne);
			continue;
		}

		livre.auteur = tokens[1];

		// TODO: Pour les champs 'int' et 'double', utiliser les fonctions 'tryParse' pour convertir les chaînes en nombres
		if (!tryParseInt(tokens[2], livre.anneePublication))
		{
			cout << format("Erreur : Ligne {} - Annee de publication invalide : {}\n", compteurLigne, tokens[2]);
			continue;
		}

		if (!tryParseDouble(tokens[3], livre.prix))
		{
			cout << format("Erreur : Ligne {} - Prix invalide : {}\n", compteurLigne, tokens[3]);
			continue;
		}

		// TODO: Ajouter le livre au vecteur des livres valides
		livres.push_back(livre);
	}

	// Fermer le fichier après la lecture des livres
	fichierLivres.close();

	return livres;
}

void sauvegarderFichierLivresValides(const string& nomFichier, const vector<Livre>& livres)
{
	// Écrire les livres valides dans un nouveau fichier texte
	ofstream fichierLivresValides;
	fichierLivresValides.open(nomFichier, ios::out);

	if (!fichierLivresValides.is_open())
	{
		cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en ecriture.\n", nomFichier);
		return;
	}

	cout << format("\nEcriture des {} livres valides dans le fichier '{}' separes par des ';'\n", livres.size(), nomFichier);

	// Écrire dans le fichier les livres valides séparés par des points-virgules ';'
	for (size_t i = 0; i < livres.size(); i++)
	{
		if (i != 0)
			fichierLivresValides << "\n";

		fichierLivresValides << format("{};{};{};{}",
			livres[i].titre,
			livres[i].auteur,
			livres[i].anneePublication,
			livres[i].prix);
	}

	fichierLivresValides.close();
}

#pragma endregion