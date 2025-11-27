#include <string>
#include <vector>

using namespace std;

string toLower(string chaine)
{
	for (size_t i = 0; i < chaine.size(); i++)
	{
		chaine[i] = tolower(chaine[i]);
	}

	return chaine;
}

string toUpper(string chaine)
{
	for (size_t i = 0; i < chaine.size(); i++)
	{
		chaine[i] = toupper(chaine[i]);
	}

	return chaine;
}

string trim(const string& chaine)
{
	size_t indexDebut = 0;
	while (isspace(chaine[indexDebut]))
	{
		indexDebut++;
	}

	if (indexDebut == chaine.size())
		return "";

	size_t indexFin = chaine.size() - 1;
	while (indexFin > indexDebut && isspace(chaine[indexFin]))
	{
		indexFin--;
	}

	return chaine.substr(indexDebut, indexFin - indexDebut + 1);
}

vector<string> split(const string& chaine, char delimiteur)
{
	vector<string> tokens;

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
		indexDelimiteur = chaine.find(delimiteur, indexDelimiteur + 1);
	}

	// Ajouter le reste de la chaine apres le dernier delimiteur jusqu'à la fin
	string token = chaine.substr(indexDebut);
	tokens.push_back(token);

	return tokens;
}

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

bool tryParseLongLong(const string& chaine, long long& nombreLong)
{
	try
	{
		if (!chaine.empty())
		{
			size_t indexConversion = 0;
			long long nombreLongTemporaire = stoll(chaine, &indexConversion);

			// Vérifier si toute la chaîne a été convertie
			if (indexConversion == chaine.size())
			{
				nombreLong = nombreLongTemporaire;
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