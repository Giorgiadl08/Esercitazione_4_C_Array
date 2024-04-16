#pragma once
#include "iostream"
#include <string>


using namespace std;

//readData legge i dati dal file input in un modo specifico e li memorizza in variabili passate come parametri
bool readData(const string& filename, double& S, int& n, double*& w, double*& r);

//computePorfolio calcola il tasso di rendimento
double computePortfolio(double S, int n, const double* w, const double* r);

//computeFinalValue calcola il valore dell'intero portafoglio
double computeFinalValue(double S, double rate_of_return);

//printResult inserisce i risultati nel file output
bool printResults(const string& filename, double S, int n, const double* w, const double* r, double rate_of_return, double final_value);



