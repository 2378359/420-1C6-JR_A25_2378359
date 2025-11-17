#pragma once

#include <string>
#include "Constantes.h"
using namespace std;

double calculerAfficherRabais(double, double, bool, string = "");
bool estNombreEgal(int, int, int = INT_MIN);
int calculerResultat(int, int);
int calculerResultatReference(int, int&);
int calculerResultatConstantes(int, string&, string&);
double calculerEfficaciteEnergie(double, double, string&);
int calculerFibonacci(int);
