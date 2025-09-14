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

#pragma region Constante
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
	// TODO	: En-tête du programme.
	cout << "***********************************************************" 
		 << "\n*\t\t\tImprimerie CSTJ\t\t\t  *"
		 << "\n*\t\t\tPar Hugo (2378359)\t\t  *"
		 << "\n***********************************************************\n\n";
#pragma endregion

#pragma region TypeClient
	// TODO : Afficher la demande du matricule ou nombre d'employé de l'utilisateur pour le type de client.
	cout << "--- Numéro client ---\n\n"
		 << "Entrer votre matricule ou numéro d'employé : ";
	int matriculeNumeroEmploye;
	cin >> matriculeNumeroEmploye;
	// TODO : Déterminer type de client 
	// TODO : Si ... entre ... alors --> .....
	// TODO : Étudiant = 100000 et 9999999
	// TODO : Enseignant = 10000 et 20000
	// TODO : Administration = 3000 et 5000
	string typeClient;
	if (matriculeNumeroEmploye >= 100000 && matriculeNumeroEmploye <= 9999999)
	{
		typeClient = "étudiant";
	}
	else if (matriculeNumeroEmploye >= 10000 && matriculeNumeroEmploye <= 20000)
	{
		typeClient = "enseignant";
	}
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
	cout << "--- Pages ---\n\n";
	// TODO : Demande de nombre de pages à imprimer
	// TODO : Entrer le nombre de pages :
	cout << "Entrer le nombre de pages : ";
	double nombrePages;
	cin >> nombrePages;
	// TODO : Si numéro de pages invalide : ERREUR
	if (nombrePages < 1)
	{
		cout << format("\nErreur : {} n’est pas un nombre de pages valide, impression annulée.\n", nombrePages);
		return 0;
	}
#pragma endregion

#pragma region Exemplaires
	cout << "\n--- Exemplaires ---\n\n";
	// TODO : Demande le nombre d'exemplaire à imprimer
	// TODO : Entrer le nombre d'exemplaire
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
	cout << "\n--- Papier ---\n";
	// TODO : Demande le format de paiper pour impression
	// TODO : Afficher les trois type de format (Lettre, Légal, Photo)
	cout << format("\n1) Lettre (8 1/2 x 11)\t({}$ par page)\n2) Légal (8 1 / 2 x 14) ({}$ par page)\n3) Photo\t\t({}$ par page)\n\n", COUT_PAPIER_LETTRE, COUT_PAPIER_LEGAL, COUT_PAPIER_PHOTO);
	// TODO : demande un choix
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
		return 0;
		break;
	}
	
#pragma endregion

#pragma region ModeImpression
	cout << "\n--- Mode d'impression ---\n\n";
	// TODO : Demande le mode d'impression (Recto en noir et blanc, Recto-verso en noir et blanc, recto en couleur, recto-verso en couleur) avec les prix
	cout << format("1) Recto en noir et blanc\t\t({} %)\n", RECTO_NOIR * 100);
	cout << format("2) Recto-verso en noir et blanc\t\t({} %, moitié des pages)\n", RECTO_VERSO_NOIR * 100);
	cout << format("3) Recto en couleur\t\t\t({} %)\n", RECTO_COULEUR * 100);
	cout << format("4) Recto-verso en couleur\t\t({} %, moitié des pages)\n\n", RECTO_VERSO_COULEUR * 100);
	// TODO : Demande un choix
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

	
	// TODO : calculer la multiplication du coût initial
	double prixParExemplaire = (prixPapierMode * ratioImpression) * nombrePages;
	// TODO : Calcul Sous-Total
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
	double rabais;

	// TODO : Si étudiant alors pas de rabais
	// TODO : si enseignant alors 25% coût d'impression
	// TODO : calcul du 25%
	// TODO : Rabais 50% enseigant si 20 pages ou moins, 50 exemplaires ou moins, recto-verso en noir et blanc seulement.

	// TODO : Rabais de 50% pour administration 
	// TODO : Calculer le rabais
	// TODO : Rabais de 75% pour administration si 1 page seulement en couleur recto-verso
	bool rabaisAfficher = true;

	if (typeClient == "enseigant")
	{
		rabais = 0.25;
	}
	else if (typeClient == "enseignant" && nombrePages <= 20 && nombreExemplaire <= 50 && ratioImpression == RECTO_VERSO_NOIR)
	{
		rabais = 0.50;
	}
	else if (typeClient == "administrateur")
	{
		rabais = 0.50;
	}
	else if (typeClient == "administrateur" && nombrePages == 1 && (ratioImpression == RECTO_VERSO_COULEUR || ratioImpression == RECTO_COULEUR))
	{
		rabais = 0.75;
	}
	else
	{
		rabaisAfficher = false;
	}
	// TODO : Calculer le rabais


	// TODO : Si Rabais, alors affichage du rabais et le sous total
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
	// TODO : Afficher chaque type de paiement
	// TODO : Monnaie,  Crédit, Débit
	cout << "--- Paiement ---\n\n"
		<< "m) Monnaie\n"
		<< "c) Crédit (Visa, Mastercard)\n"
		<< "d) Débit\n\n";
	// TODO : Demande le choix
	cout << "Entrer le choix de paiement : ";
	char choixPaiement;
	cin >> choixPaiement;
	bool monnaieAfficher = false;
	bool cerditAfficher = false;
	bool debitAfficher = false;
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
	// TODO : Faire la validation du choix paiement
	bool afficherTransaction = false;
	// TODO : Si demande invalide : ERREUR
#pragma endregion

#pragma region Monnaie
	// TODO : Si la monnaie affiche le montant de la monnaie du client
	if (monnaieAfficher == true)
	{
		cout << "\n\n--- Monnaie ---\n\n";
		cout << "Entrer le montant d'argent du client : ";
		double montantMonnaie;
		cin >> montantMonnaie;
		if (montantMonnaie < calculSousTotal)
		{
	// TODO : Si monnaie invalide : ERREUR
			cout << format("\nErreur : {:.2f} $ n’est pas assez d’argent pour payer la facture de {:.2f} $, impression annulée.\n", montantMonnaie, calculSousTotal);
			return 0;
		}
	// TODO : Faire le calcul du total contre la monaie
		else
		{
		montantMonnaie = calculSousTotal - montantMonnaie;
		montantMonnaie *=-1;
		}
		//bool estInferieurEpsilon = montantMonnaie < EPSILON;		
		//cout << format("Doubles avec epsilon : ({} - {}) < {} = {}\n", calculSousTotal, montantMonnaie, EPSILON, estInferieurEpsilon);
	// TODO : Afficher la monnaie total à rendre
		cout << format("Monnaie à rendre au client\t\t: {:.2f} $", montantMonnaie);
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
	cout << format("\nTransaction pour le client {} de {:.2f} $\n", typeClient, calculSousTotal);
	}
#pragma endregion

}