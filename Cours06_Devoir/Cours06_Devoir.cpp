/*
    Auteur			: Hugo Pelletier
    Date			: 2025-09-04
    Description		: Devoir 06 conditions
*/

#include <iostream>
#include <format>
#include <string>

using namespace std;
int main()
{

    setlocale(LC_ALL, "");

    cout << "--- Devoir 06 – Hugo Pelletier - 2378359 ---\n\n";

    bool exercice1 = true;

    if (exercice1 = true)
    {

        bool reponseA = 10 > 5 || (45 <= 40 && "a" != "b");
        // 10 > 5 || (45 <= 40 && "a" != "b");
        //
        // 1) 10 > 5 || (45 <= 40 && "a" != "b");
        // 1) true || (45 <= 40 && "a" != "b");
        // 1) true || (false && "a" != "b");
        // 1) true || (false && true);
        // 1) true || false;
        // 1) true;

        int a = 20;
        int b = 30;
        int c = 50;
        bool reponseB = c == a + b && (b - 30 > 0 || b - 20 > 0);
        // 50 == 20 + 30 && (30 - 30 > 0 || 30 - 20 > 0);
        // 50 == 50 && (30 - 30 > 0 || 30 - 20 > 0);
        // true && (30 - 30 > 0 || 30 - 20 > 0);
        // true && (0 > 0 || 30 - 20 > 0);
        // true && (false || 30 - 20 > 0);
        // true && (false || 10 > 0);
        // true && (false || true);
        // true && true;
        // true;


        int d = -10;
        int e = 100;
        int f = -55;
        bool reponseC = (d > 0 || e > 0) && (d > e || (e > 0 || f > 0));
        // (-10 > 0 || 100 > 0) && (-10 > 100 || (100 > 0 || -55 > 0));
        // (false || 100 > 0) && (-10 > 100 || (100 > 0 || -55 > 0));
        // (false || true) && (-10 > 100 || (100 > 0 || -55 > 0));
        // (false || true && ( false || (100 > 0 || -55 > 0));
        // (false || true && ( false || (true || -55 > 0));
        // (false || true && ( false || (true || false));
        // (false || true && ( false || (true));
        // (false || true && true;
        // (false || true;
        // true;
        
        double g = -10.0;
        int h = 100;
        string i = "i";
        bool reponseD = ((g == -10.0 && h == g) || i == "I" || (h > g && i == "i"));
        // ((-10.0 == -10.0 && 100 == -10.0) || i == "I" || (100 > -10.0 && i == "i"));



        // Affichage des réponses finales pour vous aider à valider partiellement
        cout << format("Réponse finale A : {}\n", reponseA);
        //cout << format("Réponse finale B : {}\n", reponseB);
        cout << format("Réponse finale C : {}\n", reponseC);
        cout << format("Réponse finale D : {}\n", reponseD);


    }












}