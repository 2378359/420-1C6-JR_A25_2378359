#include <format>
#include <iostream>
#include <string>

using namespace std;

void AfficherMenuCalculatrice(string operation, string calcul, double resultat)
{
	cout << "\n***********************************************************\n"
		<< "*                       Calculatrice TP3                  *\n"
		<< "*             Par Votre Hugo (Votre 2378359)              *\n"
		<< "***********************************************************\n\n";

	cout << operation;

	cout << calcul;

	cout << format("Résultat : {}\n\n", resultat);
	cout << "+) Addition\n" // Opérations qui utilisent le résultat dans le calcul
		<< "-) Soustraction\n"
		<< "*) Multiplication\n"
		<< "/) Division\n"
		<< "^) Exposant\n\n"
		<< "!) Factorielle\n" // Opérations qui écrasent le résultat avec le calcul
		<< "s) Série de Taylor\n\n"
		<< "r) Rectangle\n" // Opérations qui ne changent pas le résultat
		<< "t) Triangle\n\n"
		<< "d) Diviseurs\n"
		<< "p) Nombres premiers\n"
		<< "i) Inverser nombre\n"
		<< "b) Transformer base\n"
		<< "c) Configurer la seed\n"
		<< "l) Lancer de des\n"
		<< "a) Nombres aleatoires\n\n"
		<< "q) Quitter\n\n";

	operation = "";
	calcul = "";
}
