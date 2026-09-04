#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityti (int &n, int y[], double k[]);
double kaina (double k, int y);
double priedas (int n, int y[], double k[]);
double didziausias_priedas (int n, int y[], double k[]);
void rasyk (double suma, double did_kaina);

int main()
{
    int n, y[30];
    double k[30], suma, did_kaina;
    skaityti (n, y, k);
    suma = priedas (n, y, k);
    did_kaina = didziausias_priedas (n, y, k);
    rasyk (suma, did_kaina);
    return 0;
}

void skaityti (int &n, int y[], double k[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> k[i] >> y[i];
    }
    fd.close();
}

double kaina (double k, int y)
{
    return k*y*0.1;
}

double priedas (int n, int y[], double k[])
{
    double suma = 0;
    for (int i=0; i<n; i++)
    {
        suma = suma + kaina (k[i], y[i]);
    }
    return suma;
}

double didziausias_priedas (int n, int y[], double k[])
{
    double maxi = y[0]*k[0];
    for (int i=0; i<n; i++)
    {
        if (y[i]*k[i] > maxi)
        {
            maxi = y[i]*k[i];
        }

    }
    return maxi;
}

void rasyk (double suma, double did_kaina)
{
    ofstream fr(FVR);
    fr << fixed << setprecision (2) << suma << endl;
    fr << fixed << setprecision (2) << did_kaina << endl;
    fr.close();
}
