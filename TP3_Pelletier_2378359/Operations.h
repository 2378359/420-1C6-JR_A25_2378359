#pragma once

#include <string>
#include "Constantes.h"
using namespace std;

void AfficherMenuCalculatrice(string, string, double);

double CalculerOperationAddition(double&, double, double);

double CalculerOperationSoustraction(double&, double, double);

double CalculerOperationMultiplication(double&, double, double);

double CalculerOperationDivision(double&, double, double);

double CalculerOperationExposant(string&, double&, double&, int&, double&);

double CalculerOperationFactoriel(string&, double, double&);

double CalculerOperationTaylor(string&, double, double, double, double&, double, double);

void CalculerFormeRectangle(double, double);

void CalculerFormeTriangle(double, double, double, double);

double CalculerOperationDiviseurs(double&);

void CalculerOperationInverser(double&);

int extraireChiffre(int&);

void TransforrmerBase();

void InitialiserSeedAutomatique();

void ConfigurerLaSeed();

void LancerLesDes(int&);