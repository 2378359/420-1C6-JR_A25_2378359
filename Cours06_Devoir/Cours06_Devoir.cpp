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

    bool exercice1 = false;
    bool exercice2 = false;
    bool exercice3 = false;
    bool exercice4 = false;

    if (exercice1 == true)
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
        // ((true && 100 == -10.0) || i == "I" || (100 > -10.0 && i == "i"));
        // ((true && false) || i == "I" || (100 > -10.0 && i == "i"));
        // false ||  false || (100 > -10.0 && i == "i"));
        // false ||  false || true && i == "i"));
        // false ||  false || true && true));
        // false ||  false || true));
        // false ||  true));
        // true;



        // Affichage des réponses finales pour vous aider à valider partiellement
        cout << format("Réponse finale A : {}\n", reponseA);
        cout << format("Réponse finale B : {}\n", reponseB);
        cout << format("Réponse finale C : {}\n", reponseC);
        cout << format("Réponse finale D : {}\n", reponseD);


    }

    if (exercice2 == true)
    {

        double totalFacture;
        int nombreProduitsAchetes;
        string typeMembre;
        double totalApresRabais;
        double rabais25Pourcent;
        double rabais = 0.25;
      

        cout << "\nEntrer le total de la facture : ";
        cin >> totalFacture;
        cout << "\nEntrer le nombre de produits achetés : ";
        cin >> nombreProduitsAchetes;
        cout << "\nEntrer le type de membre (Or, Argent, Bronze) : ";
        cin >> typeMembre;

        bool estOrRabais = typeMembre == "Or" && totalFacture >= 30;
        bool estArgentRabais = typeMembre == "Argent" && (totalFacture >= 50 || nombreProduitsAchetes >= 5);
        bool estBronzeRabais = typeMembre == "Bronze" && totalFacture >= 100 && nombreProduitsAchetes >= 10;

        if (estOrRabais || estArgentRabais || estBronzeRabais)
        {
            cout << "\n*** Rabais ***";
            rabais25Pourcent = totalFacture * rabais;
            totalApresRabais = totalFacture - rabais25Pourcent;

        cout << format("\nMembre\t\t\t : {}", typeMembre);
        cout << format("\nNombre de produits\t : {}", nombreProduitsAchetes);
        cout << format("\nSous - total\t\t : {:.2f}$\n", totalFacture);
        cout << format("\nRabais(25 %)\t\t : {:.2f}$", rabais25Pourcent);
        cout << format("\nTotal\t\t\t : {:.2f}$\n", totalApresRabais);

        }
        else
        {
            cout << "\n*** Facture sans rabais ***";
            cout << format("\nTotal\t\t : {:.2f}$\n", totalFacture);
        }


    }

    if (exercice3 == true)
    {

        int numeroBillet1;
        int numeroBillet2;
        int numeroBillet3;


        cout << "--- Achat de billets 3/49 ---\n";

        cout << "Entrer le numéro 1 : ";
        cin >> numeroBillet1;

        if (numeroBillet1 < 1 || numeroBillet1 > 49)
        {
            cout << format("\nle nombre {} n'est pas entre 1 et 49, achat annulé", numeroBillet1);

        }
        else
        {

            cout << "\nEntrer le numéro 2 : ";
            cin >> numeroBillet2;

            if (numeroBillet2 == numeroBillet1)
            {
                cout << format("\nle nombre {} a déjà été sélectionné, achat annulé", numeroBillet2);
            }
            else if (numeroBillet2 < 1 || numeroBillet2 > 49)
            {
                cout << format("\nle nombre {} n'est pas entre 1 et 49, achat annulé", numeroBillet2);
            }
            else
            {
                cout << "\nEntrer le numéro 3 : ";
                cin >> numeroBillet3;
                if (numeroBillet3 == numeroBillet1 || numeroBillet3 == numeroBillet2)
                {
                cout << format("\nle nombre {} a déjà été sélectionné, achat annulé", numeroBillet3);
                }
                else if (numeroBillet3 < 1 || numeroBillet3 > 49)
                {
                cout << format("\nle nombre {} n'est pas entre 1 et 49, achat annulé", numeroBillet3);
                }
                else
                {
                    
                    if (numeroBillet1 < numeroBillet2 && numeroBillet2 < numeroBillet3)
                    {
                        cout << format("Numéros croissant du billet : {}, {}, {}", numeroBillet1, numeroBillet2, numeroBillet3);
                    }
                    else if (numeroBillet1 < numeroBillet3 && numeroBillet3 < numeroBillet2)
                    {
                        cout << format("Numéros croissant du billet : {}, {}, {}", numeroBillet1, numeroBillet3, numeroBillet2);
                    }
                    else if (numeroBillet2 < numeroBillet1 && numeroBillet1 < numeroBillet3)
                    {
                        cout << format("Numéros croissant du billet : {}, {}, {}", numeroBillet2, numeroBillet1, numeroBillet3);
                    }
                    else if (numeroBillet2 < numeroBillet3 && numeroBillet3 < numeroBillet1)
                    {
                        cout << format("Numéros croissant du billet : {}, {}, {}", numeroBillet2, numeroBillet3, numeroBillet1);
                    }
                    else if (numeroBillet3 < numeroBillet1 && numeroBillet1 < numeroBillet2)
                    {
                        cout << format("Numéros croissant du billet : {}, {}, {}", numeroBillet3, numeroBillet1, numeroBillet2);
                    }
                    else
                    {
                        cout << format("Numéros croissant du billet : {}, {}, {}", numeroBillet3, numeroBillet2, numeroBillet1);
                    }
                }
            }
        
        }






    }

    if (exercice4 == true)
    {
        string etatLumiere;
        int vitesse;
        double contravention = 0.0;
        int feu1 = 1;
        int feu2 = 2;
        int feu3 = 3;

        cout << "\n\n ____ FEU 1 ____\n\n";

        cout << "Entrer l'état de la lumière (vert, jaune, rouge) : ";
        cin >> etatLumiere;
        cout << "\nEntrer la vitesse de l'automobile (- pour sens inverse) : ";
        cin >> vitesse;

        if (etatLumiere == "rouge" && vitesse != 0)
        {
            contravention = 75;

            if (vitesse > 80)
            {
                contravention += 3.5 * (vitesse - 80);
            }
            else if (vitesse < -80)
            {
                contravention += (3.5 * (-vitesse - 80));
            }

            cout << format("\nFeu {} ({} km/h) : contravention de {:.2f}$", feu1, vitesse, contravention);

        }
        else if ((etatLumiere == "vert" || etatLumiere == "jaune") && (vitesse > 80 || vitesse < -80))
        {

            if (vitesse > 80)
            {
                contravention += 3.5 * (vitesse - 80);
            }
            else if (vitesse < -80)
            {
                contravention += (3.5 * (-vitesse - 80));
            }
            cout << format("\nFeu {} ({} km/h) : contravention de {:.2f}$", feu1, vitesse, contravention);

        }
        else
        {
            cout << format("\nFeu {} ({} km/h) : aucune contravention", feu1, vitesse);
        }


        cout << "\n\n ____ FEU 2 ____\n\n";
        cout << "Entrer l'état de la lumière (vert, jaune, rouge) : ";
        cin >> etatLumiere;
        cout << "\nEntrer la vitesse de l'automobile (- pour sens inverse) : ";
        cin >> vitesse;

        if (etatLumiere == "rouge" && vitesse != 0)
        {
            contravention = 175;

            if (vitesse > 50)
            {
                contravention += 8.5 * (vitesse - 50);
            }
            else if (vitesse < -50)
            {
                contravention += (8.5 * (-vitesse - 50));
            }

            cout << format("\nFeu {} ({} km/h) : contravention de {:.2f}$", feu2, vitesse, contravention);

        }
        else if (etatLumiere == "jaune" && (vitesse > 30 || vitesse < -30))
        {

            if (vitesse > 30)
            {
                contravention += 8.5 * (vitesse - 30);
            }
            else if (vitesse < -30)
            {
                contravention += (8.5 * (-vitesse - 30));
            }
            cout << format("\nFeu {} ({} km/h) : contravention de {:.2f}$", feu2, vitesse, contravention);

        }
        else if (etatLumiere == "vert" && (vitesse > 50 || vitesse < -50))
        {

            if (vitesse > 50)
            {
                contravention += 8.5 * (vitesse - 50);
            }
            else if (vitesse < -50)
            {
                contravention += (8.5 * (-vitesse - 50));
            }
            cout << format("\nFeu {} ({} km/h) : contravention de {:.2f}$", feu2, vitesse, contravention);

        }
        else
        {
            cout << format("\nFeu {} ({} km/h) : aucune contravention\n", feu2, vitesse);
        }

        cout << "\n\n ____ FEU 3 ____\n\n";
        cout << "Entrer l'état de la lumière (vert, jaune, rouge) : ";
        cin >> etatLumiere;
        cout << "\nEntrer la vitesse de l'automobile (- pour sens inverse) : ";
        cin >> vitesse;

        if (vitesse < 0)
        {
            contravention = 325;
        }
        else if (etatLumiere == "rouge" && vitesse != 0)
        {
            contravention = 325;
        }
        else if (etatLumiere == "vert" && vitesse > 30)
        {
            contravention = 325;
        }
        else if (etatLumiere == "jaune" && (vitesse < 5 || vitesse > 25))
        {
            contravention = 325;
        }
        else if (etatLumiere == "vert" && vitesse == 0)
        {
            contravention = 325;
        }

        if (contravention > 0)
        {
            cout << format("\nFeu {} ({} km/h) : contravention de {:.2f}$", feu3, vitesse, contravention);
        }
        else
        {
            cout << format("\nFeu {} ({} km/h) : aucune contravention\n", feu3, vitesse);
        }



    }







}