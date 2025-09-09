/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-09
	Description		: cours 07 Devoir Switch
*/
#include <format>
#include <iostream>
#include <string>

using namespace std;

const int NOTE_FINALE_A_MAX = 100;
const int NOTE_FINALE_A_MIN = 90;


const int NOTE_FINALE_B_MAX = 89;
const int NOTE_FINALE_B_MIN = 80;


const int NOTE_FINALE_C_MAX = 79;
const int NOTE_FINALE_C_MIN = 70;


const int NOTE_FINALE_D_MAX = 69;
const int NOTE_FINALE_D_MIN = 60;


const int NOTE_FINALE_F_MAX = 59;
const int NOTE_FINALE_F_MIN = 0;

const int JOUR_MAX = 31;
const int JOUR_MIN = 1;
const int MOIS_MIN = 1;
const int MOIS_MAX = 12;



int main()
{

    setlocale(LC_ALL, "");

    cout << "--- Devoir 07 – Hugo Pelletier - 2378359 ---\n\n";

    bool exercice1 = true;
    bool exercice2 = true;
    bool exercice3 = true;
    bool exercice4 = true;

    if (exercice1 == false)
    {
        // *** Exercice 01 ***
        // Écrire un programme qui demande une cote à l’utilisateur et retourne les notes possibles obtenues par l’étudiant. Permettre à l’utilisateur 
        // d’entrer la cote en majuscule ou en minuscule et utiliser une instruction switch. 
        // Ne pas oublier de déclarer les nombres magiques en tant que constantes globales.

        char noteFinale;

        cout << "Entrer une note finale [A, B, C, D, F] : ";
        cin >> noteFinale;

        switch (noteFinale)
        {
        case 'A':
        case 'a':
            cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.", NOTE_FINALE_A_MIN, NOTE_FINALE_A_MAX);
            break;

        case 'B':
        case 'b':
            cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.", NOTE_FINALE_B_MIN, NOTE_FINALE_B_MAX);
            break;

        case 'C':
        case 'c':
            cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.", NOTE_FINALE_C_MIN, NOTE_FINALE_C_MAX);
            break;

        case 'D':
        case 'd':
            cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.", NOTE_FINALE_D_MIN, NOTE_FINALE_D_MAX);

            break;

        case 'F':
        case 'f':
            cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.", NOTE_FINALE_F_MIN, NOTE_FINALE_F_MAX);

            break;

        default:
            cout << format("La note finale {} est invalide, entrer une note finale : A, B, C, D ou F.", noteFinale);
            break;
        }
    }

    if (exercice2 == false)
    {
        // *** Exercice 02 ***
        //Un programme qui valide une date(jour et mois) savoir si la combinaison de jour et mois est valide.
        //Ne pas prendre en compte les années bissextiles : 28 et 29 jours sont des valeurs valides pour le mois de février, sinon 30 ou 31 jours dépendamment du mois.

        int jour;
        int mois;

        cout << format("\nEntrer le jour ({} - {}) : ", JOUR_MIN, JOUR_MAX);
        cin >> jour;
        cout << format("\nEntrer le mois ({} - {}) : ", MOIS_MIN, MOIS_MAX);
        cin >> mois;

        if ((jour > JOUR_MAX || jour < JOUR_MIN) || (mois > MOIS_MAX || mois < MOIS_MIN))
        {
            cout << format("\nJour {} n’existe pas pour le mois {}.\n", jour, mois);
        }
        else if (jour < 28 && jour > JOUR_MIN)
        {
            cout << format("\nJour {} existe pour le mois {}.\n", jour, mois);
        }
        else
        {
            switch (jour)
            {
            case 28:
            case 29:
            case 30:
                if (mois == 3 && (jour >=28 && jour <= 29))
                {
                    cout << format("\nJour {} existe pour le mois {}.\n", jour, mois);
                }
                else if (mois == 3 && jour > 29 )
                {
                    cout << format("\nJour {} n’existe pas pour le mois {}.\n", jour, mois);

                }
                else
                {
                    cout << format("\nJour {} existe pour le mois {}.\n", jour, mois);
                }
                break;

            case 31:

                switch (mois)
                {
                case 1:
                case 2:
                case 4:
                case 5:
                case 7:
                case 8:
                case 10:
                    cout << format("\nJour {}cexiste seulement lors d’une année bissextile pour le mois {}.\n", jour, mois);

                default:
                    cout << format("\nJour {} n’existe pas pour le mois {}.\n", jour, mois);

                    break;
                }


                break;

            default:
                break;
            }
        }




    }
}