#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>


using namespace std;

bool readData(const string& filename, double& S, int& n, double*& w, double*& r)
{
    ifstream infile(filename);//apro il file
    if (infile.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    string line; //dichiaro la var 'line' di tipo string, che sarà utilizzata per contenere la riga letta dal file di input
    getline(infile, line); //leggo la prima riga e la memorizzo in 'line'
    istringstream ssS(line); //creo una stringstream per S che permtte di estrarre i valori dalla riga letta
    string token; //dichiaro la var 'token' di tipo string, che sarà utilizzata per contenere il valore estratto dalla riga
    getline(ssS, token, ';'); //estraggo la parte, token, dopo il delimitatore ';', che è il valore di S.
    ssS >> S; //estraggo il valore di S dallo stream di input ssS e lo memorizzo nella variabile S

    getline(infile, line); //leggo la seconda linea
    istringstream ssN(line); //creo una stringstream per n
    getline(ssN, token, ';'); //ottengo il valore di n
    ssN >> n; //memorizzo il valore di n nella variabile n

    getline(infile, line); //leggo la terza linea

    //allocazione dinamica dei due array w e r
    w = new double[n];
    r = new double[n];

    for (int i = 0; i < n; ++i) {
        getline(infile, line); //leggo una nuova riga dal file
        istringstream ss(line); //creo una stringstream dalla riga letta
        string token1, token2;

        //divido la riga in due parti utilizzando il delimitatore ';'
        getline(ss, token1, ';'); //token1 contiene la prima parte della stringa fino al delimitatore ';'
        getline(ss, token2, ';');//token2 contiene la seconda parte della stringa fino al delimitatore ';'

        //converto le stringhe token in double e li assegno a w[i] e r[i]
        //creo un oggetto istringstream da token1 e token2 e utilizzo l'operatore di estrazione (>>) per estrarre il valore in w[i] e r[i]
        istringstream iss1(token1);
        iss1 >> w[i];

        istringstream iss2(token2);
        iss2 >> r[i];

        //oppure uso la funzione stod
        //w[i] = stod(token1);
        //r[i] = stod(token2);
    }

    infile.close(); //chiudo il file
}


double computePortfolio(double S, int n, const double* w, const double* r)
{
    double rate_of_return = 0.0;
    for (int i = 0; i < n; ++i) {
        rate_of_return += w[i] * r[i];
    }
    return rate_of_return;
}

double computeFinalValue(double S, double rate_of_return)
{
    return S * (1 + rate_of_return);
}

bool printResults(const string& filename, double S, int n, const double* w, const double* r, double rate_of_return, double final_value)
{
    ofstream outfile(filename);
    if (outfile.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    outfile << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    outfile << "w = [ ";
    for (int i = 0; i < n; ++i)
    {
        outfile << fixed << setprecision(2) << w[i];
        if (i < n - 1)
            outfile << " ";
    }
    outfile << " ]" << endl;

    outfile << "r = [ ";
    for (int i = 0; i < n; ++i) {
        outfile << fixed << setprecision(2) << r[i];
        if (i < n - 1)
            outfile << " ";
    }
    outfile << " ]" << endl;

    outfile << "Rate of return of the portfolio : " << fixed << setprecision(4) << rate_of_return << endl;
    outfile << "V : " << fixed << setprecision(2) << final_value << endl;

    outfile.close();
}




