/*
	Auteur			: Hugo Pelletier
	Date			: 2025-09-11
	Description		: cours 07 Devoir Switch
*/
#include <format>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	/*if (false)
	{
		cout << "Erreur";
		return 0;
	}*/
	// TODO	: En-tête du programme.
	cout << "***********************************************************" 
		 << "\n*\t\t\tImprimerie CSTJ\t\t\t  *"
		 << "\n*\t\t\tPar Hugo (2378359)\t\t  *"
		 << "\n***********************************************************\n\n";
#pragma region TypeClient
	int matriculeNumeroEmploye;
	string typeClient;
	// TODO : Afficher la demande du matricule ou nombre d'employé de l'utilisateur pour le type de client.
	cout << "--- Numéro client ---\n\n"
		 << "Entrer votre matricule ou numéro d'employé : ";
	cin >> matriculeNumeroEmploye;
	// TODO : Déterminer type de client 
	// TODO : Si ... entre ... alors --> .....
	// TODO : Étudiant = 100000 et 9999999
	// TODO : Enseignant = 10000 et 20000
	// TODO : Administration = 3000 et 5000
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
		typeClient = "administration";
	}
	// TODO : Si numéro invalide
	else
	{
		cout << format("\nErreur : {} est un matricule ou numéro d’employé invalide, impression annulée.\n", matriculeNumeroEmploye);
		return 0;
	}

	// TODO : affiche messages type d'employé avec numéro de l'utilisateur
	cout << format("Commande pour l'{} {}\n", typeClient, matriculeNumeroEmploye);
#pragma endregion
	
#pragma region NombrePages
	// TODO : Demande de nombre de pages à imprimer 
	// TODO : Entrer le nombre de pages :
	// TODO : Si numéro de pages invalide : ERREUR
#pragma endregion

#pragma region Exemplaires
	// TODO : Demande le nombre d'exemplaire à imprimer
	// TODO : Entrer le nombre d'exemplaire
	// TODO : Si demande invalide : ERREUR
	// TODO :Calcule pour le nombre de page avec exemplaire
#pragma endregion

#pragma region Papier
	// TODO : Demande le format de paiper pour impression
	// TODO : Afficher les trois type de format (Lettre, Légal, Photo)
	// TODO : demande un choix
	// TODO : Si demande invalide : ERREUR
#pragma endregion

#pragma region ModeImpression
	// TODO : calculer la multiplication du coût initial
	// TODO : Demande le mode d'impression (Recto en noir et blanc, Recto-verso en noir et blanc, recto en couleur, recto-verso en couleur) avec les prix
	// TODO : Demande un choix
	// TODO : Si demande invalide = ERREUR
#pragma endregion

#pragma region SousTotal
	// TODO : Calculer/afficher les pages par exemplaire
	// TODO : Calculer/afficher le prix par pages
	// TODO : Calculer/afficher le ratio du mode impression
	// TODO : Calculer/afficher par exemplaire
	// TODO : Calculer/afficher prix par exemplaire
	// TODO : Calculer/afficher calcul du sous-total
	// TODO : Calculer/afficher sous-total
	// TODO : Afficher les coût totaux.
#pragma endregion


#pragma region Rabais
	// TODO : Si étudiant alors pas de rabais
	// TODO : si enseignant alors 25% coût d'impression
	// TODO : calcul du 25%
	// TODO : Rabais 50% enseigant si 20 pages ou moins, 50 exemplaires ou moins, recto-verso en noir et blanc seulement.

	// TODO : Rabais de 50% pour administration 
	// TODO : Calculer le rabais
	// TODO : Rabais de 75% pour administration si 1 page seulement en couleur recto-verso
	// TODO : Calculer le rabais

	// TODO : Si Rabais, alors affichage du rabais et le sous total
#pragma endregion

#pragma region Total
	// TODO : calculer la TPS et TVQ
	// TODO : Afficher le total de la facture et rabais si possible
#pragma endregion

#pragma region TypePaiement
	// TODO : Afficher chaque type de paiement
	// TODO : Monnaie,  Crédit, Débit
	// TODO : Demande le choix
	// TODO : Faire la validation du choix paiement
	// TODO : Si demande invalide : ERREUR
#pragma endregion

#pragma region Monnaie
	// TODO : Si la monnaie affiche le montant de la monnaie du client
	// TODO : Faire le calcul du total contre la monaie
	// TODO : Afficher la monnaie total à rendre
	// TODO : Afficher la monnaie total à rendre
	// TODO : Si monnaie invalide : ERREUR
#pragma endregion

#pragma region Credit
	// TODO : Demande numéro de carte de crédit, MASTERCARD, VISA
	// TODO : Valider la carte, VISA commence par 4530 puis 12 chiffre et Mastercard commence par 54 puis 14 chiffres
	// TODO : Utiliser plus grand qu'un entier pour numéro
	// TODO : Si entrer invalide alors ERREUR
#pragma endregion

#pragma region Debit
	// TODO : Afficher la confirmation de la transaction
	// TODO : 'O' ou 'o'
	// TODO : Si autre lettre alors Transaction refusée
#pragma endregion

#pragma region Transaction
	// TODO : Afficher le client et le total de la facture suivie "est confirmée."
#pragma endregion

}