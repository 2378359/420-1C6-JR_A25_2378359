// TODO: Avant de créer le Projet, faire un 'git clone' ou un 'git pull' si dossier Git est déjà présent

// TODO: Ajouter un en-tête


// Inclusion des librairies
// TODO: Modifier la version du Projet à C++20 pour la librairie <format>
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

    // Affichage de l'en-tête
    cout << "--- Cours 07 - Switch ---\n";

#pragma region Switch
    // *** Switch ***
    // - Instruction conditionnelles afin de sélectionner un travail à faire parmis plusieurs
    //      - Vérifie seulement une seule variable à plusieurs valeurs
    //      - Équivalent de comparer plusieurs la variable fois avec l'opérateur d'égalité (==)
    //      - Génère en arrière-plan le code if() équivalent lors de la compilation
    // - Par convention
    //      - Difficile avec switch de se tromper de variable ou d'opérateur
    //      - Préférer au if() si on vérifie une seule variable (int ou char) avec l'opérateur d'égalité (==)
    //      - Très utile pour les menu à la Console avec un choix utilisateur
    //
    // switch (variable)
    // {
    // case 0:
    //     // Travail si la valeur est 0
    // 
    //     break; // Termine le switch à l'emplacement de l'accolade fermante 
    // 
    // case 1:
    //     // Travail si la valeur est 1
    // 
    //     break; // Termine le switch à l'emplacement de l'accolade fermante 
    // 
    // default:
    //     // Travail par défaut si la valeur est aucun des autres cas définis
    //     // Toujours mettre le default à la fin par convention
    // 
    //     break; // Termine le switch à l'emplacement de l'accolade fermante 
    // }

    // *** Switch avec entier (int) ***
    // - Choix de travail à faire selon nombre entré (ex. message)

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
        cout << "If - Message par défaut pour tous les autres cas\n";
    }

    // Version avec switch équivalent sur un entier (int)
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
        cout << "Switch - Message par défaut pour tous les autres cas\n";
        break;
    }


    // *** Switch avec un caractère (char) ***
    // - Choix de travail à faire selon le caractère entré (ex. message)

    cout << "\n--- Caractere (char) ---\n";

    cout << "Entrer un caractère : ";
    char caractere;
    cin >> caractere;

    // Version avec if avec choix sur un caractère (char)
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
            cout << format("If - {} est le chiffre zéro\n", caractere);
        }
    }
    else if (caractere >= 'a' && caractere <= 'z')
    {
        cout << format("If - {} est une consonne\n", caractere);
    }
    else
    {
        cout << format("If - {} est un caractère spécial\n", caractere);
    }

    // Version avec switch équivalent sur un caractère (char)
    // - Plus aérée et facile à lire que la version if
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
            cout << format("Switch - {} est le chiffre zéro\n", caractere);
        }
        break;

    default:
        // Cases permettent seulement les opérateurs d'égalité (==) 
        if (caractere >= 'a' && caractere <= 'z')
        {
            cout << format("Switch - {} est une consonne\n", caractere);
        }
        else
        {
            cout << format("Switch - {} est un caractère spécial\n", caractere);
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
    //case: 0 // Erreur, deux-points mal positionné
    //    break;
    //default:
    //    break;
    //}
    //
    // E1578: la valeur de l'étiquette case apparaît déjà dans ce commutateur
    //switch (nombre)
    //{
    //case 0:
    //    break;
    //case 0: // Erreur, 2 fois le même case
    //    break;
    //default:
    //    break;
    //}

    // 3) Erreur de logique avec 'break' manquant
    // C26819: Il existe un fallthrough non annoté entre les étiquettes de Switch
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
        // break; manquant, techniquement non nécessaire car on est déjà à la fin
    }

    // *** Exemple de switch ***
    // Afficher le menu de conversion de température
    cout << "\n --- Conversion de température ---\n\n";
    cout << "c) Celsius\n";
    cout << "f) Farenheit\n";

    // Lire le choix de conversion de l'utilisateur à la Console
    cout << "\nEntre le format de la température : ";
    char choixTemperature;
    cin >> choixTemperature;

    // TODO: Convertir la température du 'nombre' seulement selon le choix de l'utilisateur avec un switch
    cout << format("Celsius : {}\n", nombre * 9.0 / 5.0 + 32);
    cout << format("Farenheit : {}\n", (nombre - 32) * 5.0 / 9.0);


#pragma endregion

#pragma region Scope
    // *** Scope ***
    // Accolades ouvrantes et fermantes {} définissent un 'Scope'
    // - main() {}
    // - if () {}
    // - else if () {}
    // - else {}
    // - switch() {}
    // 
    // Scope
    // - Ensemble de variables en mémoire qui peuvent être utilisées
    // - Mémoire et noms des variables sont reservés
    // 
    // Stack (pile)
    // - Façon principale d'attribution de la mémoire avec le Heap (amas)
    // - Ouverture d'un scope {
    //      - Réserve l'espace mémoire pour toutes les variables comprises
    //      - Réserve les noms des variables
    // - Fermeture d'un scope }
    //      - Libère l'espace mémoire de toutes les variables comprises
    //      - Libère les noms des variables

    // TODO: Faire un dessin du Stack suivant avec Scope

    // Variable définie pour toute la fonction main()
    int a = 10;

    // Début du Scope
    {
        // int a = 20; // Erreur, défini dans le Scope main()

        // Variables définies pour le Scope seulement
        int b = 20;
        int c = 30;

        // Variables du Scope main() peuvent être utilisées
        b = a + 100;

        // Variables du Scope main() peuvent être modifiées
        a = b + c;
    }
    // Fin du Scope

    cout << format("Valeur de 'a' après le Scope\n", a);

    // Erreur, variables du Scope ont été libérées
    //cout << format("Valeur de 'b' apres le Scope : {}\n", b);
    //cout << format("Valeur de 'c' apres le Scope : {}\n", c);

    // *** Switch avec Scope ***
    // - Attention que l'instruction switch() par défaut ouvre un seul Scope
    //      - Variables avec le même ne peuvent pas être définies plusieurs fois
    // - Variable 'resultat' est définie 3 fois dans le même Scope
    //      - C2374 : 'resultat' rédéfinition
    // - De plus, C++ empêche les définitions de variables directement dans un switch
    //      - C2361 : l'initialisation de 'resultat' est ignorée par l'étiquette 'default'
    //      - C2360 : l'initialisation de 'resultat' est ignorée par l'étiquette 'case'
    //      - C2361 : l'initialisation de 'bonus' est ignorée par l'étiquette 'default'
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


    // TODO: Fixer l'erreur en déclarant une variable avant le switch et message après switch

#pragma endregion

#pragma region Constantes
    // *** Contantes ***
    // Dans un programme, les littéraux sont considérés comme des 'nombres magiques' à éviter
    // - Exemples
    //      - Minimum / Maximum
    //      - Montants, coûts et taxes
    //      - Choix de l'utilisateur dans les menus
    // - Lorsque le programme doit être modifié
    //      - Il faut modifier tous les nombres sans faire de faute
    //      - Difficile à vérifier sans tester le programme au complet
    //      - Gros programme implique des efforts monumental de test
    //
    // Solution
    // - Définir chaque nombre utilisé comme une constante
    //      - Constante est une variable en mémoire qui ne peut changer de valeur
    //      - Habituellement définies dans des fichiers de configuration
    //      - Pour l'instant, définir dans la zone de variables globales avant la fonction main() 
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
            cout << format("Remboursement {:.2f} a été fixé au minimum : {:.2f}\n", total, 499.99);
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