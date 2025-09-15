/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-11
	Description		: TP1 (5%) - IMPRIMERIE
*/
#pragma region Bibliotheque
#include <format>
#include <iostream>
#include <string>
using namespace std;
#pragma endregion

#pragma region ConstanteVariables
const double COUT_PAPIER_LETTRE = 0.11;
const double COUT_PAPIER_LEGAL = 0.13;
const double COUT_PAPIER_PHOTO = 1.24;

const double RECTO_NOIR = 1.0;
const double RECTO_VERSO_NOIR = 1.50;
const double RECTO_COULEUR = 3.0;
const double RECTO_VERSO_COULEUR = 4.25;

const double VISA_MIN = 4530000000000000;
const double VISA_MAX = 4530999999999999;
const double MASTERCARD_MIN = 5400000000000000;
const double MASTERCARD_MAX = 5499999999999999;

const double EPSILON = 0.001;
#pragma endregion


#pragma region Enum
enum Raccourci
{
	choix1 = 1,
	choix2 = 2,
	choix3 = 3,
	choix4 = 4,
	choixMonnaieMinuscule = 'm',
	choixMonnaieMajuscule = 'M',
	choixCreditMinuscule = 'c',
	choixCreditMajuscule = 'C',
	choixDebitMinuscule = 'd',
	choixDebitMajuscule = 'D',
	choixValidationDebitMinsucule = 'o',
	choixValidationDebitMajuscule = 'O',
};
#pragma endregion

int main()
{
	setlocale(LC_ALL, "");
#pragma region EnTete
	// TODO	: Afficher en-tête.
	cout << "***********************************************************" 
		 << "\n*\t\t\tImprimerie CSTJ\t\t\t  *"
		 << "\n*\t\t\tPar Hugo (2378359)\t\t  *"
		 << "\n***********************************************************\n\n";
#pragma endregion

#pragma region TypeClient
	// TODO : Affiche et demande matricule
	cout << "--- Numéro client ---\n\n"
		 << "Entrer votre matricule ou numéro d'employé : ";

	int matriculeNumeroEmploye;
	cin >> matriculeNumeroEmploye;

	// TODO : Déterminer type de client 
	string typeClient;
	// TODO : Étudiant = 100000 et 9999999
	if (matriculeNumeroEmploye >= 100000 && matriculeNumeroEmploye <= 9999999)
	{
		typeClient = "étudiant";
	}
	// TODO : Enseignant = 10000 et 20000
	else if (matriculeNumeroEmploye >= 10000 && matriculeNumeroEmploye <= 20000)
	{
		typeClient = "enseignant";
	}
	// TODO : Administration = 3000 et 5000
	else if (matriculeNumeroEmploye >= 3000 && matriculeNumeroEmploye <= 5000)
	{
		typeClient = "administrateur";
	}
	// TODO : Si numéro invalide
	else
	{
		cout << format("\nErreur : {} est un matricule ou numéro d’employé invalide, impression annulée.\n\n", matriculeNumeroEmploye);
		return 0;
	}

	// TODO : affiche messages type d'employé avec numéro de l'utilisateur
	cout << format("\nCommande pour l'{} {}\n\n", typeClient, matriculeNumeroEmploye);
#pragma endregion
	
#pragma region NombrePages

	// TODO : Afficher et demande nombre page
	cout << "--- Pages ---\n\n";
	cout << "Entrer le nombre de pages : ";

	double nombrePages;
	cin >> nombrePages;
	int nombrePagesInitial = nombrePages;

	// TODO : Si numéro de pages invalide : ERREUR
	if (nombrePages < 1)
	{
		cout << format("\nErreur : {} n’est pas un nombre de pages valide, impression annulée.\n", nombrePages);
		return 0;
	}
#pragma endregion

#pragma region Exemplaires
	// TODO : Demander le nombre d'exemplaire à imprimer
	cout << "\n--- Exemplaires ---\n\n";
	cout << "Entrer le nombre d’exemplaires : ";

	double nombreExemplaire;
	cin >> nombreExemplaire;

	// TODO : Si demande invalide : ERREUR
	if (nombreExemplaire < 1)
	{
		cout << format("\nErreur : {} n’est pas un nombre d’exemplaire valide, impression annulée.\n", nombreExemplaire);
		return 0;
	}

	// TODO :Calcule pour le nombre de page avec exemplaire
	double nombrePageTotal;
	nombrePageTotal = nombrePages * nombreExemplaire;
#pragma endregion

#pragma region Papier
	// TODO : Demande le format de paiper pour impression
	cout << "\n--- Papier ---\n";
	cout << format("\n1) Lettre (8 1/2 x 11)\t({}$ par page)\n2) Légal (8 1 / 2 x 14) ({}$ par page)\n3) Photo\t\t({}$ par page)\n\n", COUT_PAPIER_LETTRE, COUT_PAPIER_LEGAL, COUT_PAPIER_PHOTO);

	cout << "Entrer le choix de papier : ";

	int choixModePapier;
	cin >> choixModePapier;
	double prixPapierMode;


	switch (choixModePapier)
	{
	case Raccourci::choix1:
		prixPapierMode = COUT_PAPIER_LETTRE;
		break;

	case Raccourci::choix2:
		prixPapierMode = COUT_PAPIER_LEGAL;
		break;

	case Raccourci::choix3:
		prixPapierMode = COUT_PAPIER_PHOTO;
		break;

	// TODO : Si demande invalide : ERREUR
	default:
		cout << format("\nErreur : {} n’est pas un choix de papier valide, impression annulée.\n", choixModePapier);
		break;
	}
#pragma endregion

#pragma region ModeImpression
	cout << "\n--- Mode d'impression ---\n\n";
	// TODO : Demande le mode d'impression
	cout << format("1) Recto en noir et blanc\t\t({} %)\n", RECTO_NOIR * 100);
	cout << format("2) Recto-verso en noir et blanc\t\t({} %, moitié des pages)\n", RECTO_VERSO_NOIR * 100);
	cout << format("3) Recto en couleur\t\t\t({} %)\n", RECTO_COULEUR * 100);
	cout << format("4) Recto-verso en couleur\t\t({} %, moitié des pages)\n\n", RECTO_VERSO_COULEUR * 100);

	int choixImpression;
	cin >> choixImpression;
	double ratioImpression;

	switch (choixImpression)
	{
	case Raccourci::choix1:
		ratioImpression = RECTO_NOIR;
		break;

	case Raccourci::choix2:
		ratioImpression = RECTO_VERSO_NOIR;
		nombrePages = nombrePages / 2;
		break;

	case Raccourci::choix3:
		ratioImpression = RECTO_COULEUR;
		break;

	case Raccourci::choix4:
		ratioImpression = RECTO_VERSO_COULEUR;
		nombrePages = nombrePages / 2;
		break;

	// TODO : Si demande invalide = ERREUR
	default:
		cout << format("Erreur : {} n’est pas un choix de papier valide, impression annulée.", choixImpression);
		break;
	}

	// TODO : Calcul Sous-Total
	double prixParExemplaire = (prixPapierMode * ratioImpression) * nombrePages;
	double calculSousTotal = prixParExemplaire * nombreExemplaire;
#pragma endregion

#pragma region SousTotal
	cout << "\n--- Sous-Total ---\n\n";
	// TODO : Calculer/afficher les pages par exemplaire
	cout << format("Pages par exemplaire\t: {} pages", nombrePages);
	cout << format("\nPrix par page\t\t: {:.2f} $", prixPapierMode);
	cout << format("\nRatio mode impression\t: {} %\n", ratioImpression * 100);

	cout << format("\nCalcul par exemplaire\t: {} pages x {:.2f} $ par page x {} % mode impression", nombrePages, prixPapierMode, ratioImpression * 100);
	cout << format("\nPrix par exemplaire\t: {:.2f} $\n", prixParExemplaire);

	cout << format("\nCalcul du sous-total\t: {:.2f} $ par exemplaire x {} exemplaires\n", prixParExemplaire, nombreExemplaire);
	cout << format("Sous-total\t\t: {:.2f} $\n\n", calculSousTotal);
#pragma endregion

#pragma region Rabais
	// TODO : Attribuer les rabais au type de client
	bool rabaisAfficher = true;
	double rabais;

	if (typeClient == "enseignant" && nombrePagesInitial <= 20 && nombreExemplaire <= 50 && ratioImpression == RECTO_VERSO_NOIR)
	{
		rabais = 0.50;
	}
	else if (typeClient == "enseignant")
	{
		rabais = 0.25;
	}
	else if (typeClient == "administrateur" && nombrePagesInitial == 1 && (ratioImpression == RECTO_VERSO_COULEUR || ratioImpression == RECTO_COULEUR))
	{
		rabais = 0.75;
	}
	else if (typeClient == "administrateur")
	{
		rabais = 0.40;
	}
	else
	{
		rabaisAfficher = false;
	}

	// TODO : Si Rabais vrai, alors affichage du rabais et le sous total
	if (rabaisAfficher == true)
	{
		double sousTotalAvecRabais;
		sousTotalAvecRabais = calculSousTotal * rabais;
		calculSousTotal = calculSousTotal - sousTotalAvecRabais;
		cout << format("--- Rabais {} % ---\n\n", rabais * 100);
		cout << format("Sous-total\t\t: {:.2f} $\n\n", sousTotalAvecRabais);
	}
#pragma endregion

#pragma region Total
	double tps = 0.05;
	double tvq = 0.09975;

	cout << "--- Total ---\n\n";
	cout << format("Sous-total\t\t: {:.2f} $\n\n", calculSousTotal);

	// TODO : calculer la TPS et TVQ
	tps = calculSousTotal * tps;
	tvq = calculSousTotal * tvq;

	cout << format("TPS\t\t\t: {:.2f} $", tps);
	cout << format("\nTVQ\t\t\t: {:.2f} $\n\n", tvq);

	// TODO : Afficher le total de la facture
	calculSousTotal = calculSousTotal + tps + tvq;

	cout << format("Total\t\t\t: {:.2f} $\n\n", calculSousTotal);
#pragma endregion

#pragma region TypePaiement
	// TODO : Affiche et demande choix paiement
	cout << "--- Paiement ---\n\n"
		<< "m) Monnaie\n"
		<< "c) Crédit (Visa, Mastercard)\n"
		<< "d) Débit\n\n";
	cout << "Entrer le choix de paiement : ";

	char choixPaiement;
	cin >> choixPaiement;

	bool monnaieAfficher = false;
	bool cerditAfficher = false;
	bool debitAfficher = false;

	// TODO : Valide le choix
	switch (choixPaiement)
	{
	case Raccourci::choixMonnaieMajuscule:
	case Raccourci::choixMonnaieMinuscule:

		monnaieAfficher = true;
		break;

	case Raccourci::choixCreditMajuscule:
	case Raccourci::choixCreditMinuscule:

		cerditAfficher = true;
		break;

	case Raccourci::choixDebitMajuscule:
	case Raccourci::choixDebitMinuscule:
		debitAfficher = true;

		break;

	default:

		cout << format("\nErreur : {} n’est pas un type de paiement valide, impression annulée.\n", choixPaiement);
		break;
	}

	bool afficherTransaction = false;
#pragma endregion

#pragma region Monnaie
	// TODO : Si la monnaie affiche le montant de la monnaie du client
	if (monnaieAfficher == true)
	{
		cout << "\n\n--- Monnaie ---\n\n";
		cout << "Entrer le montant d'argent du client : ";
		double montantMonnaie;
		cin >> montantMonnaie;

		double difference = calculSousTotal - montantMonnaie;
		if (difference < 0)
		{
			difference *= -1;
		}

		bool estInferieurEpsilon = difference < EPSILON;

		if (estInferieurEpsilon == true)
		{
	// TODO : Si monnaie invalide : ERREUR
			cout << format("\nErreur : {:.2f} $ n’est pas assez d’argent pour payer la facture de {:.2f} $, impression annulée.\n", montantMonnaie, calculSousTotal);
			return 0;
		}
		else
		{
	// TODO : Faire le calcul du total contre la monaie
		montantMonnaie = calculSousTotal - montantMonnaie;
			if (montantMonnaie < 0)
			{
				montantMonnaie *= -1;

			}
	    }

	// TODO : Afficher la monnaie total à rendre
		cout << format("\nMonnaie à rendre au client\t: {:.2f} $\n", montantMonnaie);
		afficherTransaction = true;
	}
#pragma endregion

#pragma region Credit
	// TODO : Demande numéro de carte de crédit, MASTERCARD, VISA
	if (cerditAfficher == true)
	{
		cout << "\n--- Crédit ---\n\n";
		cout << "Entrer le numéro de carte de crédit (Visa, Mastercard) : ";

	// TODO : Utiliser plus grand qu'un entier pour numéro
		double numeroCarte;
		cin >> numeroCarte;

	// TODO : Valider la carte, VISA commence par 4530 puis 12 chiffre et Mastercard commence par 54 puis 14 chiffres
		if (numeroCarte >= VISA_MIN && numeroCarte <= VISA_MAX)
		{
			cout << format("\nCarte de crédit Visa {} acceptée.\n", numeroCarte);
			afficherTransaction = true;
		}
		else if (numeroCarte >= MASTERCARD_MIN && numeroCarte <= MASTERCARD_MAX)
		{
			cout << format("\nCarte de crédit Mastercard {} acceptée.\n", numeroCarte);
			afficherTransaction = true;
		}
	// TODO : Si entrer invalide alors ERREUR
		else
		{
			cout << format("\nErreur : {} n'est pas un numéro de carte de crédit valide, impression annulée.\n", numeroCarte);
		}
	}
#pragma endregion

#pragma region Debit
	if (debitAfficher == true)
	{
		cout << "\n--- Débit ---\n\n";
		cout << "Est-ce la transaction débit est un succès (O/N) : ";
		char validationDebit;
		cin >> validationDebit;

	// TODO : Afficher la confirmation de la transaction
		switch (validationDebit)
		{
	// TODO : 'O' ou 'o'
		case Raccourci::choixValidationDebitMinsucule:
		case Raccourci::choixValidationDebitMajuscule:
			cout << "\nTransaction reussie\n";
			afficherTransaction = true;
			break;
	// TODO : Si autre lettre alors Transaction refusée
		default:
			cout << "\nErreur : la transaction débit a échouée, impression annulée.\n";
			break;
		}
	}
#pragma endregion

#pragma region Transaction
	// TODO : Afficher le client et le total de la facture suivie "est confirmée."
	if (afficherTransaction == true)
	{
	cout << format("\nTransaction pour le client {} de {:.2f} $ est confirmée\n", matriculeNumeroEmploye, calculSousTotal);
	}
#pragma endregion
}