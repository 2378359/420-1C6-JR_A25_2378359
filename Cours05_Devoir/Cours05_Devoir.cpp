

/*
    Auteur			: Hugo Pelletier
    Date			: 2025-09-02
    Description		: Devoir 05 Bool�ens et If
*/

#include <iostream>
#include <format>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    cout << "--- Devoir 05 � Hugo Pelletier - 2378359 ---\n\n";

    bool estExercice1Actif = false;
    bool estExercice2Actif = false;
    bool estExercice3Actif = false;
    bool estExercice4Actif = false;
    bool estExercice5Actif = false;

    // Exercice 01

    if (estExercice1Actif)
    {
        cout << "Entrer la largeur du rectangle : ";
        int largeurRectangle;
        cin >> largeurRectangle;

        cout << "Entrer la hauteur du rectangle : ";
        int hauteurRectangle;
        cin >> hauteurRectangle;

        if (largeurRectangle <= 0)
        {
            cout << "Erreur : largeur ne peut �tre 0 ou n�gative.";
        }
        else if (hauteurRectangle <= 0)
        {
            cout << "Erreur : hauteur ne peut �tre 0 ou n�gative.";
        }
        else if (largeurRectangle == hauteurRectangle)
        {
            cout << format("Carr� {} par {}\n", largeurRectangle, hauteurRectangle);
        }
        else if (largeurRectangle > hauteurRectangle)
        {
            cout << format("Rectangle {} par {}\n", largeurRectangle, hauteurRectangle);
            double ratioHauteur = largeurRectangle / hauteurRectangle;
            cout << format("{:.3f} % plus large que haut\n", ratioHauteur);
        }
        else
        {
            cout << format("Rectangle {} par {}\n", largeurRectangle, hauteurRectangle);
            cout << "Plus haut que large\n";
            double ratioRectangle = hauteurRectangle / largeurRectangle;
            cout << format("{:.3f} % plus haut que large\n", ratioRectangle);
        }

        double airRectangle = largeurRectangle * hauteurRectangle;
        double perimetreRectangle = 2 * (largeurRectangle + hauteurRectangle);
        cout << format("Aire : {:.2f}\n", airRectangle);
        cout << format("Perim�tre : {:.2f}\n", perimetreRectangle);

        system("pause");
        system("cls");

    }

    // Exercice 02
    if (estExercice2Actif)
    {
        cout << "--- Comparaison de 2 nombres ---\n";

        double premierNombre;
        double deuxiemeNombre;

        cout << "\nEntrer le premier nombre : ";
        cin >> premierNombre;

        cout << "\nEntrer le deuxi�me nombre : ";
        cin >> deuxiemeNombre;

        double differenceNombre = premierNombre - deuxiemeNombre;
        
        if (differenceNombre < 0)
        {
            differenceNombre = deuxiemeNombre - premierNombre;
        }

        if (premierNombre != deuxiemeNombre)
        {
            cout << format("\nLe nombre {:.3f} et {:.3f} ont une diff�rence de {:.3}\n", premierNombre, deuxiemeNombre, differenceNombre);
        }
        else
        {
            cout << format("\nLe nombre {:.3f} et {:.3f} sont �gaux\n", premierNombre, deuxiemeNombre);
        }

        system("pause");
        system("cls");
    }

    // Exercice 03
    if (estExercice3Actif)
    {
        cout << "---Cr�ation d�un nouveau compte utilisateur---\n\n";

        string courriel;
        string courrielConfirmation;
        string motDePasse;
        string motDePasseConfirmation;

        cout << "Entrer un courriel : ";
        cin >> courriel;

        cout << "Confirmer votre courriel : ";
        cin >> courrielConfirmation;

        if (courriel != courrielConfirmation)
        {
            cout << "courriels diff�rents, cr�ation du compte annul�e.\n\n";
            system("pause");
            system("cls");
        }
        else
        {
            cout << "Entrer un Mot de passe : ";
            cin >> motDePasse;

            cout << "Confirmer votre Mot de passe : ";
            cin >> motDePasseConfirmation;

            if (motDePasse == motDePasseConfirmation)
            {
                cout << "Succ�s : nouveau compte compte " << courriel << " a �t� cr�� !\n\n";

            }
            else
            {
                cout << "Erreur : mots de passe diff�rents, cr�ation du compte annul�e.\n\n";
            }
        }
    }

    // Exercice 04
    if (estExercice4Actif)
    {
        cout << "--- R�servation de billets d��v�nements ---\n\n";

        cout << "Entrer le nombre de personnes(n�gatif pour un remboursement) : ";
        int nombrePersonne;
        cin >> nombrePersonne;

        double rabais;
        double prixBillet = 29.99;
        double sousTotal = nombrePersonne * prixBillet;
        
        if (nombrePersonne >=0)
        {

       
            if (nombrePersonne >= 50)
            {
                rabais = 0.25;
            }
            else if (nombrePersonne < 20)
            {
                rabais = 0.0;
            }
            else
            {
                rabais = 0.10;
            }

        double coutTotalSeulRabais = sousTotal * rabais;
        double coutTotal = sousTotal - coutTotalSeulRabais;

        cout << format("Sous-Total\t:\t{:.2f}$\n", sousTotal);
        cout << format("Rabais\t\t:\t{}%\n", rabais * 100);
        cout << format("Sous-Total\t:\t{:.2f}$\n", coutTotal);
        }

        else
        {
        cout << "\n\nEntrer le total de la facture originale : ";
        double factureOriginale;
        cin >> factureOriginale;
        cout << "\nEntrer le nombre de jours avant l��v�nement : ";
        int nombreJourAvantEvenement;
        cin >> nombreJourAvantEvenement;

        double pourcentageRemboursement;

        if (nombreJourAvantEvenement <= 0)
        {
            cout << format("\nErreur : �v�nement a d�j� eu lieu il y a {} jours, impossible d�effectuer un remboursement.\n", nombreJourAvantEvenement *-1);
        }
        else if (nombreJourAvantEvenement >= 7)
        {
            pourcentageRemboursement = 1;
        }
        else if (nombreJourAvantEvenement < 5)
        {
            pourcentageRemboursement = 0.10;
        }
        else
        {
            pourcentageRemboursement = 0.50;
        }

        double totalRemboursementRabais = factureOriginale * pourcentageRemboursement;
        double totalRemboursement = factureOriginale - totalRemboursementRabais;
        double totalRembousementPersonne = totalRemboursementRabais / nombrePersonne;

        cout << format("\nPourcentage de remboursement\t: {}%\n\n", pourcentageRemboursement * 100);
        cout << format("Total original\t\t\t: {:.2f}$\n", factureOriginale);
        cout << format("Total du remboursement\t\t: {:.2f}$\n\n", totalRemboursementRabais);
        cout << format("Nombre de personnes\t\t: {}\n", nombrePersonne *-1);
        cout << format("Remboursement par personne\t: {:.2f}$\n", totalRembousementPersonne *-1);
            
        system("pause");
        system("cls");

        }
    }

    // Exercice 05
    if (estExercice5Actif)
    {
        cout << "--- R�servation d�un si�ge d�avion ---\n\n";

        string categorie;

        cout << "Cat�gories disponibles (affaire, premium, economie)\n\n Entrer une cat�gorie : ";
        cin >> categorie;
        int siege;
        double prixAffaire = 5000;
        double prixPremium = 2500;
        double prixEconomieArriere = 1500;
        double prixEconomieAvant = 1200;
        if (categorie == "affaire")
        {
            cout << "\n\nS�lectionner un si�ge affaire [1 � 20] : ";
            cin >> siege;
            if (siege > 20)
            {
                cout << format("\n\nErreur : pour la classe {} le num�ro de si�ge {} est invalide, r�servation annul�e.", categorie, siege);
            }
            else if (siege < 1)
            {
                cout << format("\n\nErreur : pour la classe {} le num�ro de si�ge {} est invalide, r�servation annul�e.", categorie, siege);
            }
            else
            {
                cout << format("classe\t\t\t: {}\nSi�ge\t\t\t: {}\nPrix du billet\t\t: {:.2f}$", categorie, siege, prixAffaire);
            }
        }
        else if (categorie == "premium")
        {
            cout << "\n\nS�lectionner un si�ge premium [21 � 50] : ";
            cin >> siege;

            if (siege > 50)
            {
                cout << format("\n\nErreur : pour la classe {} le num�ro de si�ge {} est invalide, r�servation annul�e.", categorie, siege);
            }
            else if (siege < 21)
            {
                cout << format("\n\nErreur : pour la classe {} le num�ro de si�ge {} est invalide, r�servation annul�e.", categorie, siege);
            }
            else
            {
                cout << format("classe\t\t\t: {}\nSi�ge\t\t\t: {}\nPrix du billet\t\t: {:.2f}$", categorie, siege, prixPremium);
            }
        }
        else if (categorie == "economie")
        {
            cout << "\n\nS�lectionner un si�ge �conomie [51 � 150] : ";
            cin >> siege;

            if (siege > 150)
            {
                cout << format("\n\nErreur : pour la classe {} le num�ro de si�ge {} est invalide, r�servation annul�e.", categorie, siege);
            }
            else if (siege < 51)
            {
                cout << format("\n\nErreur : pour la classe {} le num�ro de si�ge {} est invalide, r�servation annul�e.", categorie, siege);
            }
            else
            {
                if (siege >= 101)
                {
                    cout << format("classe\t\t\t: {}\nSi�ge\t\t\t: {}\nPrix du billet\t\t: {:.2f}$", categorie, siege, prixEconomieArriere);
                }
                else
                {
                    cout << format("classe\t\t\t: {}\nSi�ge\t\t\t: {}\nPrix du billet\t\t: {:.2f}$", categorie, siege, prixEconomieAvant);
                }
               
            }
        }
        else
        {
            cout << format("Erreur : la cat�gorie {} n�existe pas, r�servation annul�e.", categorie);
        }
    }
}
