// TODO: V�rifier les devoirs et retour sur les devoirs
// - Fichier zip, nomenclature de variables, espaces vides, alignement du code

// TODO: Avant de cr�er le Projet, faire un 'git clone' ou un 'git pull' si dossier Git est d�j� pr�sent

// TODO: Ajouter un en-t�te
/*
    Auteur			: Hugo Pelletier
    Date			: 2025-09-02
    Description		: Bool�ens et conditions if
*/

// Inclusion des librairies
// TODO: Modifier la version du Projet � C++20 pour la librairie <format>
// TODO: Compiler le code pour le tester et sauvegarder sur Git local et puis sur GitHub
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
    // Configuration de la console en Unicode pour les accents
    setlocale(LC_ALL, "");

    // Affichage de l'en-t�te
    cout << "--- Cours 05 - If ---\n";

#pragma region Theorie

#pragma region Booleens
    cout << "\n--- Bool�ens ---\n";

    // *** Bool�ens ***
    // - Type de donn�es qui permettent d'enregistrer une valeur logique vrai ou fausse
    // - Dans la plupart des langages de programmation
    //		- valeur 0 vaut faux (false)
    //		- reste des valeurs (1, -1, 1234566) valent vrai (true)

    // bool : type de donn�es 8 bits (1 octet)
    bool conditionFausse = false;
    bool conditionVraie = true;

    // Avertissement) 'initialisation': troncation de 'int' � 'bool'
    // - �viter les valeurs enti�res, par convention toujours utiliser true ou false
    bool conditionAussiVraie;

    cout << format("Valeurs des bool�ens : {}, {}, {}\n", conditionFausse, conditionVraie, conditionAussiVraie);

    // *** Nomenclature des variables bool�enes ***
    // Utiliser un pr�fixe afin de distinguer des variables contenant des valeurs (int, double, char, string)
    // - "est..." ("is..." en anglais)
    // - "peut.." ("can..." en anglais)
    bool estNombreVirgule = false;
    bool nombreVirgule = false; // �viter

    bool peutQuitter = true;
    bool quitter = false;       // �viter9

    // Inscrire des noms sans double n�gations
    bool estErreur = false;
    bool estPasErreur = true;   // �viter

    bool estValide = true;
    bool estPasValide = false;  // �viter

#pragma endregion

#pragma region OperateursComparaison
    cout << "\n--- Op�rateurs comparaison ---\n";

    // *** Op�rateurs de comparaison ***
    // Expression qui retourne une valeur bool�ene (true/false)
    // >  : Plus grand
    // <  : Plus petit
    // >= : Plus grand ou �gal
    // �<= : Plus petit ou �gal
    // == : �gal (Ne pas confondre avec op�rateur d'affectation =)
    // != : N'�gale pas, diff�rent de
    int entier = 15;
    bool estPlusGrand10 = entier > 10;
    bool estPlusGrandOuEgal15 = entier >= 15;
    bool estPlusPetit0 = entier < 0;
    bool estPlusPetitOuEgal15 = entier <= 15;
    bool estEgal10 = entier == 10;
    bool estEgal15 = entier == 15;
    bool estDifferent10 = entier != 10;
    bool estDifferent15 = entier != 15;

    cout << format("{} est plus grand que (>) 10          : {}\n", entier, estPlusGrand10);
    cout << format("{} est plus grand ou �gal � (>=) 15   : {}\n", entier, estPlusGrandOuEgal15);
    cout << format("{} est plus petit que (<) 0           : {}\n", entier, estPlusPetit0);
    cout << format("{} est plus petit que (<=) 15         : {}\n", entier, estPlusPetitOuEgal15);
    cout << format("{} est �gal � (==) 10                 : {}\n", entier, estEgal10);
    cout << format("{} est �gal � (==) 15                 : {}\n", entier, estEgal15);
    cout << format("{} n'�gale pas / diff�rent de (!=) 10 : {}\n", entier, estDifferent10);
    cout << format("{} n'�gale pas / diff�rent de (!=) 15 : {}\n", entier, estDifferent15);

    // Op�rateur d'affectation (=) au lieu de l'op�rateur d'�galit� (==)
    // - Avertissement) Assignation '=' utilis�e alors que l'�galit� ' == ' est probablement souhait�e.
    // - �crase la valeur en m�moire de la variable au lieu de comparer les valeurs

    // entier = 0
    //	- Retour toujours faux (false) peu importe la valeur de la variable 'entier'
    //  - Valeur de la variable 'entier' est perdue et assign�e � 0
    //  - 0 en bool�en vaut faux (false)
    bool estErreurMauvaisOperateurEgal1 = entier == 0;
    cout << format("\n{} est �gal � mauvais op�rateur (=) 0 : {}\n", entier, estErreurMauvaisOperateurEgal1);
    cout << format("Erreur : variable 'entier' a maintenant la valeur {}\n", entier);

    // entier = 15
    //  - Retour toujours vrai (true) peu importe la valeur de la variable 'entier'
    //  - Valeur de la variable 'entier' est perdue et assign�e � 15
    //  - 15 en bool�en vaut vrai (true)
    bool estErreurMauvaisOperateurEgal2 = entier == 15;
    cout << format("\n{} est �gal � mauvais op�rateur (=) 15 : {}\n", entier, estErreurMauvaisOperateurEgal2);
    cout << format("Erreur : variable 'entier' a maintenant la valeur {}\n", entier);

    // 10 = 15
    //  - Erreur, impossible changer de la constante 10 pour qu'elle valle 15
    //bool erreurMauvaisOperateurEgal3 = 10 = 15;

    // TODO: Exemples variables bool�enes avec op�rateurs de comparaison (>, >=, <, <=, ==, !=)
    int jour = 20;
    int mois = 8;
    int annee = 2025;
    double montant = 19.99;

    bool estMoisFevrier = mois == 2;
    bool estApresAnne2020 = annee > 2020;
    bool estJour = jour;

    bool estMontantPlusGrand10 = montant > 10;
    bool estMontantPlusPetit100 = montant < 100;

    char caractere = 'c';
    string nom = "Paul";

    bool estPaul = nom == "Paul";
    bool estUtilisateurAdmin = nom == "Admin";
    bool estUtilisateurNormal = nom != "Admin";

    // *** Comparaison de types diff�rents ***
    // - Comparer des types de donn�es diff�rents en m�moire compare des valeur encod�es diff�remment
    // - Entier (32 bits) n'est pas enregistr� comme un double (64 bits) ou un char (8 bits)
    // - Conversion implicite d'un type � l'autre afin d'effectuer la comparaison
    cout << "\n--- Comparaison types diff�rents ---\n";

    // (int) == (int)
    // - M�me type de donn�es donc m�me encodage en m�moire
    // - Bits sont identiques et peuvent �tre compar�s directement sans conversion
    cout << format("5 == 5 = {}\n", 5 == 5); // true

    // (int) == (double)
    // - 5 (int) converti en 5.0 (double) 
    // - 5.0 == 5.0
    cout << format("5 == 5.0 = {}\n", 5 == 5.0); // true

    // (int) == (char)
    // - 5 == 53 ('5')
    cout << format("5 == '5' ({}) = {}\n", (int)'5', 5 == '5'); // false

    // (int) == (string)
    // - Erreur 0042) : les types d'op�randes sont incompatibles ("int" et "const char *")
    // - Conversion implicite d'un (int) en (string) non permis en C++
    //cout << format("5 == '5' = {}\n", 5 == "5"); 
    // 
    // - Utiliser la fonction to_string() pour convertir l'entier en cha�ne de caract�res
    // - to_string(5) converti en "5" ('5' '\0')
    // - "5" ('5' '\0') == "5" ('5' '\0')
    cout << format("to_string(5) == \"5\" = {}\n", to_string(5) == "5"); // true

    // (char) == (string)
    // - Erreur 0042) les types d'op�randes sont incompatibles ("char" et "const char *")
    // - Conversion implicite d'un (char) en (string) non permis en C++
    //cout << format("'5' == \"5\"", '5' == "5");
    //
    // - Utiliser la fonction to_string() pour convertir le caract�re en cha�ne de caract�res
    // - to_string('5') converti en "5" ('5' '\0')
    // - '5' '\0' == '5' '\0'
    cout << format("to_string('5') == \"5\" : {}\n\n", to_string('5') == "5");

    // Cha�nes de caract�res doivent �tre exactes afin d'�tre consid�r�es �gales (==)
    // - V�rifie les cha�nes � partir de la gauche caract�re par caract�rs jusqu'� la fin de la cha�ne ('\0')
    // - D�s qu'une diff�rence est trouv�e, les cha�nes ne sont pas consid�r�es �gales (identiques)
    //      - Ex. minuscules, majuscules, espaces, etc.
    string message = "bonjour";

    cout << format("\"{}\" == \"bonjour\"  : {}\n", message, message == "bonjour");  // true
    cout << format("\"{}\" == \"Bonjour\"  : {}\n", message, message == "Bonjour");  // false : majuscule             'b'  == 'B'
    cout << format("\"{}\" == \"bonjouR\"  : {}\n", message, message == "bonjouR");  // false : majuscule             'r'  == 'R'
    cout << format("\"{}\" == \"bonjour \" : {}\n", message, message == "bonjour "); // false : espace apr�s          '\0' == ' '
    cout << format("\"{}\" == \" bonjour\" : {}\n", message, message == " bonjour"); // false : espace avant          'b'  == ' '
    cout << format("\"{}\" == \"bon jour\" : {}\n", message, message == "bon jour"); // false : espace au milieu      'n'  == ' '
    cout << format("\"{}\" == \"bonjou\"   : {}\n", message, message == "bonjou");   // false : caract�re manquant    'r' == '\0'
#pragma endregion

#pragma region If
    cout << "\n--- If ---\n";

    // *** If ***
    // S�lectionner un seul travail � faire (branchement) parmis plusieurs selon des conditions bool�enes
    // - Conditions
    //      - �valu�es dans l'ordre � partir du if() et ensuite chaque else if() 
    //      - Premi�re condition vrai (true) sera le travail � effectuer
    //      - Autres conditions ne seront pas v�rifi�es et les autre Travaux ne seront pas effectu�s
    // - Programme continue son ex�cution apr�s le bloc complet if () else if () else
    //
    // if (condition) 
    // {
    //      // Travail 1 � effectuer si la condition est vraie (true)
    // } 
    // else if (condition) // Optionnel
    // {
    //      // Travail 2 � effectuer si la condition est vraie (true)
    // } 
    // else if (condition) // Optionnel
    // {
    //      // Travail 3 � effectuer si la condition est vraie (true)
    // } 
    // ...
    // else // Optionnel, il doit y avoir un seul else
    // {
    //      // Travail par d�faut � effectuer si aucune des conditions est vrai (true)
    // }

    // Lire un nombre au clavier et �crire un message selon le nombre saisi par l'utilisateur
    int nombre = 60;
    cout << "Entrer un nombre � �valuer : ";
    cin >> nombre;

    if (nombre > 100)
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }
    else if (nombre < 0)
    {
        cout << format("Nombre {} est n�gatif\n", nombre);
    }
    else if (nombre == 0)
    {
        cout << format("Nombre {} est 0\n", nombre);
    }
    else
    {
        cout << format("Nombre {} ne rempli aucune des conditions\n", nombre);
    }

    // �criture minimale
    // - Instructions else if() et else sont optionnelles
    if (nombre > 100)
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }

    // *** Erreurs de compilation ***

    // Erreur 1) Parenth�se manquantes
    if (nombre > 100)
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }

    // *** Erreurs de logique ***
    // Erreur 1) Teste sans op�rateur de comparaison
    // - Op�rateur de comparaison manquant (>, >= , <, <=, ==, !=)
    // - Transforme implicite le nombre entier (int) en bool�en (bool)
    // - N'importe quel nombre entre dans la condition (true) sauf nombre 0 (false)

    // TODO: Entrer 10 comme nombre afin de voir un message bizarre

    cout << "\n--- Erreur 1 : Op�rateur comparaison ---\n";
    if (nombre)
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }

    // Erreur 3) Plusieurs if() de suite
    // - Plusieurs actions seront effectu�e : 1 action par if()
    // - Conditions sont habituellement �crite avec else if() afin de choisir un seul travail effectu�

    // TODO: Entrer 101 comme nombre afin de voir 3 message au lieu d'un seul
    cout << "\n--- Erreur 3 : if() multiples ---\n";

    if (nombre > 100)
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }
    if (nombre > 50)
    {
        cout << format("Nombre {} est sup�rieur � 50\n", nombre);
    }
    if (nombre > 0)
    {
        cout << format("Nombre {} est sup�rieur � 0\n", nombre);
    }

    // Erreur 3) Accolades manquantes {}
    // - Accolade ne sont pas strictement n�cessaires dans l'�criture d'une instruction if()
    // - Si les accolades ne sont pas pr�sentes, if() ou else ex�cute uniquement la prochaine instruction
    // - Fortement recommand�es de toujours les �crire pour le cours

    // TODO: Entrer -10 comme nombre afin de voir des messages bizarres du aux accolades manquantes

    // Exemple erreur if() sans accolades {}
    cout << "\n--- Erreur 3 : if() sans accolades {}---\n";
    if (nombre > 100)
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    cout << format("Nombre {} est tr�s grand!\n", nombre); // Erreur, Toujours ex�cut�

    // �quivalent au code pr�c�dent
    if (nombre > 100)
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }

    cout << format("Nombre {} est tr�s grand!\n", nombre); // Erreur, Toujours ex�cut�

    // Exemple erreur else sans accolades {}
    cout << "\n--- Erreur 3 : else sans accolades {} ---\n";
    if (nombre > 100)
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    else
        cout << format("Nombre {} est inf�rieur � 100\n", nombre);
    cout << format("Nombre {} est tr�s petit!\n", nombre); // Erreur, Toujours ex�cut�

    // �quivalent au code pr�c�dent
    if (nombre > 100)
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }
    else
    {
        cout << format("Nombre {} est inf�rieur � 100\n", nombre);
    }

    cout << format("Nombre {} est tr�s petit!\n", nombre); // Erreur, Toujours ex�cut�

    // Erreur 4) Op�rateur affectation
    //cout << "\n--- Erreur 4 : Op�rateur affectation (=) ---\n";
    //if (nombre = 10)
    //{
    //    cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    //}

    // Erreur 5) Ordre des conditions
    // - Important car les conditions sont �valu�es de haut vers le bas
    // - Seule le code contenu dans la premi�re condition vraie (true) est ex�cut�

    // TODO: Entrer 101 comme nombre afin de voir un mauvais message

    // 1) Mauvais ordre des conditions
    // - Condition #1 du if() emp�che toujours d'arriver � la la Condition #2 du else if()
    // - Nombre plus grand que 100 est forc�ment plus grand que 0
    // - Entre toujours dans le bloc du if(), impossible de rentrer dans le bloc du else if()

    cout << "\n--- Erreur 5 : Mauvais ordre des conditions ---\n";

    if (nombre > 0) // nombre 101 > 0 = true
    {
        cout << format("Nombre {} est sup�rieur � 0\n", nombre);
    }
    else if (nombre > 100) // nombre 101 : impossible d'arriver ici
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }
    else
    {
        cout << format("Nombre {} est n�gatif\n", nombre);
    }

    // 2) Bon ordre des conditions
    // - Condition #1 est un sous-ensemble plus sp�cifique de la Condition #2
    // - Nombre peut �tre plus sp�cifiquement plus grand que 100
    cout << "\n--- Erreur 5 : Bon ordre des conditions ---\n";

    if (nombre > 100) // nombre 101 > 100
    {
        cout << format("Nombre {} est sup�rieur � 100\n", nombre);
    }
    else if (nombre > 0)
    {
        cout << format("Nombre {} est sup�rieur � 0\n", nombre);
    }
    else
    {
        cout << format("Nombre {} est n�gatif\n", nombre);
    }

    // TODO : Exemple avec notes �tudiant
    // - Lire une note au clavier
    // - 90% et plus : "A"
    // - 75% et plus : "B"
    // - 60% et plus : "C"
    // - 59%         : "D"
    // - Moins que 59% : "�chec"

    cout << "\nEntrer votre note [0 - 100] : ";
    int note;
    cin >> note;


    if (note >= 90)
    {
        cout << format("Votre {}% est un : A \n\n", note);

        if (note >= 95)
        {
            cout << "WOWOOOW !!!";
        }
        else
        {
            cout << "Ouin proche";
        }
    }
    else if (note >= 75)
    {
        cout << format("Votre {}% est un : B \n\n", note);
    }
    else if (note >= 60)
    {
        cout << format("Votre {}% est un : C \n\n", note);
    }
    else if (note == 59)
    {
        cout << format("Votre {}% est un : D \n\n", note);
    }
    else
    {
        cout << format("Votre {}% est un : E \n\n", note);
    }

    // *** Imbrication de conditions ***
    // - Peut imbriquer un conditions if dans une autre condition if
    // - Faire un travail uniquement si certaines conditions suppl�mentaires sont respect�es
    double resultat = 0;
    if (nombre > 0)
    {
        resultat = 10 * nombre;

        if (nombre == 1000)
        {
            resultat *= 777;
        }
        else if (nombre <= 10000)
        {
            resultat += 10;
            resultat /= 8;
        }
        else
        {
            resultat += 12345;
            resultat *= nombre;
        }
    }
    else
    {
        resultat = -nombre;

        if (nombre < -5000)
        {
            resultat /= 555;
        }
    }

    cout << format("Pour le nombre {}, le r�sultat est : {:.2f}\n", nombre, resultat);

#pragma endregion

#pragma endregion
}

// TODO: Faire le Devoir dans un nouveau Projet et remettre avant la date de remise sur L�a
