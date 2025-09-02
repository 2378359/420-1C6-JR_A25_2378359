

/*
    Auteur			: Hugo Pelletier
    Date			: 2025-09-02
    Description		: Devoir 05 Booléens et If
*/

#include <iostream>
#include <format>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    cout << "--- Devoir 05 – Hugo Pelletier - 2378359 ---\n\n";

    bool estExercice1Actif = false;
    bool estExercice2Actif = false;
    bool estExercice3Actif = false;
    bool estExercice4Actif = false;
    bool estExercice5Actif = true;

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
            cout << "Erreur : largeur ne peut être 0 ou négative.";
        }
        else if (hauteurRectangle <= 0)
        {
            cout << "Erreur : hauteur ne peut être 0 ou négative.";
        }
        else if (largeurRectangle == hauteurRectangle)
        {
            cout << format("Carré {} par {}\n", largeurRectangle, hauteurRectangle);
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
        cout << format("Perimètre : {:.2f}\n", perimetreRectangle);

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

        cout << "\nEntrer le deuxième nombre : ";
        cin >> deuxiemeNombre;

        double differenceNombre = premierNombre - deuxiemeNombre;
        
        if (differenceNombre < 0)
        {
            differenceNombre = deuxiemeNombre - premierNombre;
        }

        if (premierNombre != deuxiemeNombre)
        {
            cout << format("\nLe nombre {:.3f} et {:.3f} ont une différence de {:.3}\n", premierNombre, deuxiemeNombre, differenceNombre);
        }
        else
        {
            cout << format("\nLe nombre {:.3f} et {:.3f} sont égaux\n", premierNombre, deuxiemeNombre);
        }

        system("pause");
        system("cls");
    }

    // Exercice 03
    if (estExercice3Actif)
    {
        cout << "---Création d’un nouveau compte utilisateur---\n\n";

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
            cout << "courriels différents, création du compte annulée.\n\n";
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
                cout << "Succès : nouveau compte compte " << courriel << " a été créé !\n\n";

            }
            else
            {
                cout << "Erreur : mots de passe différents, création du compte annulée.\n\n";
            }
        }
    }

    // Exercice 04
    if (estExercice4Actif)
    {
        cout << "--- Réservation de billets d’événements ---\n\n";

        cout << "Entrer le nombre de personnes(négatif pour un remboursement) : ";
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
        cout << "\nEntrer le nombre de jours avant l’événement : ";
        int nombreJourAvantEvenement;
        cin >> nombreJourAvantEvenement;

        double pourcentageRemboursement;

        if (nombreJourAvantEvenement <= 0)
        {
            cout << format("\nErreur : événement a déjà eu lieu il y a {} jours, impossible d’effectuer un remboursement.\n", nombreJourAvantEvenement *-1);
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
        cout << "--- Réservation d’un siège d’avion ---\n\n";

        string categorie;

        cout << "Catégories disponibles (affaire, premium, economie)\n\n Entrer une catégorie : ";
        cin >> categorie;

        if (categorie != "affaire")
        {

        }

    }

}
