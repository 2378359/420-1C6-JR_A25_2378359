// TODO: Avant de cr�er le Projet, faire un 'git clone' ou un 'git pull' si dossier Git est d�j� pr�sent

// TODO: Ajouter un en-t�te


// Inclusion des librairies
// TODO: Modifier la version du Projet � C++20 pour la librairie <format>
// TODO: Compiler le code pour le tester et sauvegarder sur Git local et puis sur GitHub
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

// *** Constantes globales ***
// Nomenclature : UPPER_SNAKE_CASE
const int MON_ENTIER_CONSTANT = 10;
const double MON_DOUBLE_CONSTANT = 10.123;
const char MON_CARACTERE_CONTANT = 'a';
const string MA_CHAINE_CONSTANTE = "bonjour";

int main()
{
    // Configuration de la console en Unicode pour les accents
    setlocale(LC_ALL, "fr_CA.UTF-8");

    // Affichage de l'en-t�te
    cout << "--- Cours 07 - Switch ---\n";

#pragma region Switch
    // *** Switch ***
    // - Instruction conditionnelles afin de s�lectionner un travail � faire parmis plusieurs
    //      - V�rifie seulement une seule variable � plusieurs valeurs
    //      - �quivalent de comparer plusieurs la variable fois avec l'op�rateur d'�galit� (==)
    //      - G�n�re en arri�re-plan le code if() �quivalent lors de la compilation
    // - Par convention
    //      - Difficile avec switch de se tromper de variable ou d'op�rateur
    //      - Pr�f�rer au if() si on v�rifie une seule variable (int ou char) avec l'op�rateur d'�galit� (==)
    //      - Tr�s utile pour les menu � la Console avec un choix utilisateur
    //
    // switch (variable)
    // {
    // case 0:
    //     // Travail si la valeur est 0
    // 
    //     break; // Termine le switch � l'emplacement de l'accolade fermante 
    // 
    // case 1:
    //     // Travail si la valeur est 1
    // 
    //     break; // Termine le switch � l'emplacement de l'accolade fermante 
    // 
    // default:
    //     // Travail par d�faut si la valeur est aucun des autres cas d�finis
    //     // Toujours mettre le default � la fin par convention
    // 
    //     break; // Termine le switch � l'emplacement de l'accolade fermante 
    // }

    // *** Switch avec entier (int) ***
    // - Choix de travail � faire selon nombre entr� (ex. message)

    cout << "\n--- Entiers (int) ---\n";

    cout << "Entrer un nombre : ";
    int nombre;
    cin >> nombre;

    // Version avec if et conditions sur un entier (int)
    if (nombre == 0)
    {
        cout << "If - Message seulement pour 0\n";
    }
    else if (nombre == 1 || nombre == 2)
    {
        cout << "If - Message pour 1 ou 2\n";
    }
    else
    {
        cout << "If - Message par d�faut pour tous les autres cas\n";
    }

    // Version avec switch �quivalent sur un entier (int)
    switch (nombre)
    {
    case 0:
        cout << "Switch - Message seulement pour 0\n";
        break;

    case 1:
    case 2:
        cout << "Switch - Message pour 1 ou 2\n";
        break;

    default:
        cout << "Switch - Message par d�faut pour tous les autres cas\n";
        break;
    }


    // *** Switch avec un caract�re (char) ***
    // - Choix de travail � faire selon le caract�re entr� (ex. message)

    cout << "\n--- Caractere (char) ---\n";

    cout << "Entrer un caract�re : ";
    char caractere;
    cin >> caractere;

    // Version avec if avec choix sur un caract�re (char)
    if (caractere == 'a'
        || caractere == 'e'
        || caractere == 'i'
        || caractere == 'o'
        || caractere == 'u')
    {
        cout << format("If - {} est une voyelle\n", caractere);
    }
    else if (caractere == ' ')
    {
        cout << format("If - {} est un espace\n", caractere);
    }
    else if (caractere == '0'
        || caractere == '1'
        || caractere == '2'
        || caractere == '3'
        || caractere == '4'
        || caractere == '5'
        || caractere == '6'
        || caractere == '7'
        || caractere == '8'
        || caractere == '9')
    {
        cout << format("If - {} est un chiffre\n", caractere);

        if (caractere == '0')
        {
            cout << format("If - {} est le chiffre z�ro\n", caractere);
        }
    }
    else if (caractere >= 'a' && caractere <= 'z')
    {
        cout << format("If - {} est une consonne\n", caractere);
    }
    else
    {
        cout << format("If - {} est un caract�re sp�cial\n", caractere);
    }

    // Version avec switch �quivalent sur un caract�re (char)
    // - Plus a�r�e et facile � lire que la version if
    switch (caractere)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        cout << format("Switch - {} est une voyelle\n", caractere);
        break;

    case ' ':
        cout << format("Switch - {} est un espace\n", caractere);
        break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        cout << format("Switch - {} est un chiffre\n", caractere);

        if (caractere == '0')
        {
            cout << format("Switch - {} est le chiffre z�ro\n", caractere);
        }
        break;

    default:
        // Cases permettent seulement les op�rateurs d'�galit� (==) 
        if (caractere >= 'a' && caractere <= 'z')
        {
            cout << format("Switch - {} est une consonne\n", caractere);
        }
        else
        {
            cout << format("Switch - {} est un caract�re sp�cial\n", caractere);
        }
        break;
    }

    cout << "\n--- Erreurs ---\n";

    // *** Erreurs ***
    // 1) Switch avec string impossible en C++, mais permis en C# et JavaScript
    //string chaine = "abc";
    //switch (chaine)
    //{
    //case "abc":
    //    break;
    //default:
    //    break;
    //}

    // 2) Erreurs de syntaxe avec instruction 'case'
    //
    // E0052: ':' attendu
    //switch (nombre)
    //{
    //case 0 // Erreur, point virgule manquant
    //    break;
    //default:
    //    break;
    //}
    //
    // E0029: expression attendue
    //switch (nombre)
    //{
    //case: 0 // Erreur, deux-points mal positionn�
    //    break;
    //default:
    //    break;
    //}
    //
    // E1578: la valeur de l'�tiquette case appara�t d�j� dans ce commutateur
    //switch (nombre)
    //{
    //case 0:
    //    break;
    //case 0: // Erreur, 2 fois le m�me case
    //    break;
    //default:
    //    break;
    //}

    // 3) Erreur de logique avec 'break' manquant
    // C26819: Il existe un fallthrough non annot� entre les �tiquettes de Switch
    switch (nombre)
    {
    case 0:
        cout << "Erreur de break manquant (case 0)\n";
        // break; manquant, continue au prochain case
    case 1:
        cout << "Erreur de break manquant (case 1)\n";
        // break; manquant, continue au prochain case
    default:
        cout << "Erreur de break manquant (default)\n";
        // break; manquant, techniquement non n�cessaire car on est d�j� � la fin
    }

    // *** Exemple de switch ***
    // Afficher le menu de conversion de temp�rature
    cout << "\n --- Conversion de temp�rature ---\n\n";
    cout << "c) Celsius\n";
    cout << "f) Farenheit\n";

    // Lire le choix de conversion de l'utilisateur � la Console
    cout << "\nEntre le format de la temp�rature : ";
    char choixTemperature;
    cin >> choixTemperature;

    // TODO: Convertir la temp�rature du 'nombre' seulement selon le choix de l'utilisateur avec un switch
    cout << format("Celsius : {}\n", nombre * 9.0 / 5.0 + 32);
    cout << format("Farenheit : {}\n", (nombre - 32) * 5.0 / 9.0);


#pragma endregion

#pragma region Scope
    // *** Scope ***
    // Accolades ouvrantes et fermantes {} d�finissent un 'Scope'
    // - main() {}
    // - if () {}
    // - else if () {}
    // - else {}
    // - switch() {}
    // 
    // Scope
    // - Ensemble de variables en m�moire qui peuvent �tre utilis�es
    // - M�moire et noms des variables sont reserv�s
    // 
    // Stack (pile)
    // - Fa�on principale d'attribution de la m�moire avec le Heap (amas)
    // - Ouverture d'un scope {
    //      - R�serve l'espace m�moire pour toutes les variables comprises
    //      - R�serve les noms des variables
    // - Fermeture d'un scope }
    //      - Lib�re l'espace m�moire de toutes les variables comprises
    //      - Lib�re les noms des variables

    // TODO: Faire un dessin du Stack suivant avec Scope

    // Variable d�finie pour toute la fonction main()
    int a = 10;

    // D�but du Scope
    {
        // int a = 20; // Erreur, d�fini dans le Scope main()

        // Variables d�finies pour le Scope seulement
        int b = 20;
        int c = 30;

        // Variables du Scope main() peuvent �tre utilis�es
        b = a + 100;

        // Variables du Scope main() peuvent �tre modifi�es
        a = b + c;
    }
    // Fin du Scope

    cout << format("Valeur de 'a' apr�s le Scope\n", a);

    // Erreur, variables du Scope ont �t� lib�r�es
    //cout << format("Valeur de 'b' apres le Scope : {}\n", b);
    //cout << format("Valeur de 'c' apres le Scope : {}\n", c);

    // *** Switch avec Scope ***
    // - Attention que l'instruction switch() par d�faut ouvre un seul Scope
    //      - Variables avec le m�me ne peuvent pas �tre d�finies plusieurs fois
    // - Variable 'resultat' est d�finie 3 fois dans le m�me Scope
    //      - C2374 : 'resultat' r�d�finition
    // - De plus, C++ emp�che les d�finitions de variables directement dans un switch
    //      - C2361 : l'initialisation de 'resultat' est ignor�e par l'�tiquette 'default'
    //      - C2360 : l'initialisation de 'resultat' est ignor�e par l'�tiquette 'case'
    //      - C2361 : l'initialisation de 'bonus' est ignor�e par l'�tiquette 'default'
    //switch (nombre)
    //{
    //case 0:
    //    int resultat = nombre + 100;
    //    cout << format("Resultat pour le nombre {} : {}\n", nombre, resultat);
    //    break;
    //case 1:
    //    int resultat = nombre * 10 + 2000;
    //    int bonus = 10000;
    //    cout << format("Resultat pour le nombre {} : {}\n", nombre + bonus, resultat);
    //    break;
    //default:
    //    int resultat = nombre + 1000;
    //    cout << format("Resultat pour le nombre {} : {}\n", nombre, resultat);
    //    break;
    //}

    // TODO: Fixer l'erreur en ajoutant un Scope par case


    // TODO: Fixer l'erreur en d�clarant une variable avant le switch et message apr�s switch

#pragma endregion

#pragma region Constantes
    // *** Contantes ***
    // Dans un programme, les litt�raux sont consid�r�s comme des 'nombres magiques' � �viter
    // - Exemples
    //      - Minimum / Maximum
    //      - Montants, co�ts et taxes
    //      - Choix de l'utilisateur dans les menus
    // - Lorsque le programme doit �tre modifi�
    //      - Il faut modifier tous les nombres sans faire de faute
    //      - Difficile � v�rifier sans tester le programme au complet
    //      - Gros programme implique des efforts monumental de test
    //
    // Solution
    // - D�finir chaque nombre utilis� comme une constante
    //      - Constante est une variable en m�moire qui ne peut changer de valeur
    //      - Habituellement d�finies dans des fichiers de configuration
    //      - Pour l'instant, d�finir dans la zone de variables globales avant la fonction main() 
    // 
    // const int MON_ENTIER_CONSTANT = 10;
    // const double MON_DOUBLE_CONSTANT = 10.123;
    // const char MON_CARACTERE_CONTANT = 'a';
    // const string MA_CHAINE_CONSTANTE = "bonjour";

    // TODO: Conventir les 'nombres magiques' du code suivant en constantes globables

    // Afficher le menu
    cout << format("\n--- Menu des constantes ---\n\n");
    cout << format("p) Paiement\n");
    cout << format("r) Remboursement\n");

    // Lire le choix du menu de l'utilisateur
    cout << "\nEntrer le choix : ";
    char choixMenu;
    cin >> choixMenu;

    switch (choixMenu)
    {
    case 'p':
    case 'P':
    {
        double total = 1000 + nombre;
        double taxe = total * 0.15;
        cout << format("Total du paiment : {:.2f}\n", total);
        cout << format("Taxe : {:.2f}\n", taxe);
    }
    break;

    case 'r':
    case 'R':
    {
        double total = 1000 - nombre;

        // Afficher un message si le total est en bas du minimum et mettre au minimum
        if (total < 499.99)
        {
            cout << format("Remboursement {:.2f} a �t� fix� au minimum : {:.2f}\n", total, 499.99);
        }

        cout << format("Total du remboursement : {:.2f}\n", total);
    }
    break;

    default:
        cout << format("Erreur : '{}' n'est pas un choix valide\n", choixMenu);
        break;
    }
#pragma endregion
}