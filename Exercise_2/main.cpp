#include "Utils.hpp"

#include <string>
using namespace std;

int main() {
    double S;
    int n;
    double* w = nullptr;
    double* r = nullptr;
    readData("data.csv", S, n, w, r);

    double rate_of_return = computePortfolio(S, n, w, r);
    double final_value = computeFinalValue(S, rate_of_return);

    //dichiaro la stringa per il nome del file output
    string output_filename = "result.txt";

    //stampo i risultati
    printResults(output_filename, S, n, w, r, rate_of_return, final_value);

    //deallocazione dinamica dei due array w e r
    delete[] w;
    delete[] r;

    return 0;
}

