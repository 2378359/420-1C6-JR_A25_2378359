
#include <iostream>
#include <format>
#include <string>
using namespace std;

double trouverMinimum(double, double);

double trouverMaximum(double, double);

double trouverMilieu(double, double, double);

bool estPositif(double);

bool estNegatif(double);

bool estMemeSigne(double, double);
bool estMemeSigne(double, double, double);

bool estMinuscule(char);

int main()
{
	setlocale(LC_ALL, "en_US");

	// MINIMUM
	double minimum1 = trouverMinimum(10.2, 5);
	cout << format("Minimum entre 10.2 et 5 : {}\n", minimum1);

	double minimum2 = trouverMinimum(-30, 45);
	cout << format("Minimum entre -30 et 45 : {}\n", minimum2);

	// MAXIMUM
	double maximum1 = trouverMaximum(10.2, 5);
	cout << format("Maximum entre 10.2 et 5 : {}\n", maximum1);

	double maximum2 = trouverMaximum(-30, 45);
	cout << format("Maximum entre -30 et 45 : {}\n", maximum2);

	// MILIEU
	double milieu1 = trouverMilieu(10.2, -30, 45); // 10.2
	cout << format("Nombre milieu parmis 10.2, -30 et 45 :  {}\n", milieu1);

	double milieu2 = trouverMilieu(-80.4, -20.5, -41.2); // -41.2
	cout << format("Nombre milieu parmis -80.4, -20.5 et -41.2:  {}\n", milieu2);

	// POSITIF
	bool estPositif1 = estPositif(100);
	cout << format("Est positif 100 : {}\n", estPositif1);

	bool estPositif2 = estPositif(-12.345);
	cout << format("Est positif -12345 : {}\n", estPositif2);

	// NÉGATIF
	bool estNegatif1 = estNegatif(100);
	cout << format("Est negatif 100 : {}\n", estNegatif1);

	bool estNegatif2 = estNegatif(-12.345);
	cout << format("Est negatif -12.345 : {}\n", estNegatif2);

	// MÊME SIGNE
	bool estMemeSigne1 = estMemeSigne(12, 1.45);
	cout << format("Meme signe 12 et 1.45 : {}\n", estMemeSigne1);
	bool estMemeSigne2 = estMemeSigne(-3.25, -25);
	cout << format("Meme signe -3.25 et -25 : {}\n", estMemeSigne2);

	bool estMemeSigne3 = estMemeSigne(10, 20, 30);
	cout << format("Meme signe 10, 20, 30 : {}\n", estMemeSigne3);
	bool estMemeSigne4 = estMemeSigne(-10, -20, -30);
	cout << format("Meme signe -10, -20, -30 : {}\n", estMemeSigne4);

	bool estMemeSigne5 = estMemeSigne(-10, 20, 30);
	cout << format("Meme signe -10, 20, 30 : {}\n", estMemeSigne5);
	bool estMemeSigne6 = estMemeSigne(-10, 20, -30);
	cout << format("Meme signe -10, 20, -30 : {}\n", estMemeSigne6);


	bool estMinuscule1 = estMinuscule('t');
	cout << format("Est minuscule 't' : {}\n", estMinuscule1);

	bool estMinuscule2 = estMinuscule('à');
	cout << format("Est minuscule 'à' : {}\n", estMinuscule2);

	bool estMinuscule3 = estMinuscule('é');
	cout << format("Est minuscule 'é' : {}\n", estMinuscule3);

	bool estMinuscule4 = estMinuscule('0');
	cout << format("Est minuscule '0' : {}\n", estMinuscule4);





}

double trouverMinimum(double nombre1, double nombre2)
{
	if (nombre1 > nombre2)
		return nombre2;
	else
		return nombre1;
}

double trouverMaximum(double nombre1, double nombre2)
{
	if (nombre1 < nombre2)
		return nombre2;
	else
		return nombre1;
}

double trouverMilieu(double nombre1, double nombre2, double nombre3)
{
	if ((nombre1 > nombre2 && nombre1 < nombre3) || (nombre1 < nombre2 && nombre1 > nombre3))
		return nombre1;

	else if ((nombre2 > nombre1 && nombre2 < nombre3) || (nombre2 < nombre1 && nombre2 > nombre3))
		return nombre2;

	else
		return nombre3;
}

bool estPositif(double nombre1)
{
	if (nombre1 >= 0)
		return true;
	else
	return false;
}

bool estNegatif(double nombre1)
{

	return !estPositif(nombre1);
}

bool estMemeSigne(double nombre1, double nombre2)
{
	if (estPositif(nombre1) == estPositif(nombre2) || estNegatif(nombre1) == estNegatif(nombre2))
		return true;
	else
		return false;
}

bool estMemeSigne(double nombre1, double nombre2, double nombre3)
{
	if (estPositif(nombre1) == estPositif(nombre2) && estPositif(nombre1) == estPositif(nombre3) && estPositif(nombre2) == estPositif(nombre3) 
		|| estNegatif(nombre1) == estNegatif(nombre2) && estNegatif(nombre1) == estNegatif(nombre3) && estNegatif(nombre2) == estNegatif(nombre3))
		return true;
	else
		return false;
}

bool estMinuscule(char lettre)
{
	if ((lettre >= 'a' && lettre <= 'z') || lettre == 'à' || lettre == 'é')
		return true;
	else
		return false;
}

