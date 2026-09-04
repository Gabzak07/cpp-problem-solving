#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";
const int Cn = 50;

void skaityti (int &n, int t[], int k[]);
int suma (int n, int x[]);
double vidurkis (int n, int suma);
int dvigubi (int n, int t[], int k[]);
void rasyti (int sumT, int sumK, double vidT, double vidK, int dd);

int main()
{
    int n, sumT, sumK, t[Cn], k[Cn], dd;
    double vidT, vidK;
    skaityti (n, t, k);
    sumT = suma (n, t);
    sumK = suma (n, k);
    vidT = vidurkis (n, sumT);
    vidK = vidurkis (n, sumK);
    dd = dvigubi (n, t, k);
    rasyti (sumT, sumK, vidT, vidK, dd);

    return 0;
}

void skaityti (int &n, int t[], int k[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> t[i] >> k[i];
    }
    fd.close();
}

int suma (int n, int x[])
{
    int sum = 0;
    for (int i=0; i<n; i++)
    {
      sum = sum + x[i];
    }
    return sum;
}

double vidurkis (int n, int suma)
{
    return (double) suma / n;
}

int dvigubi (int n, int t[], int k[])
{
    int kiekis = 0;
    for (int i=0; i<n; i++)
    {
        if (t[i]>= 10 && k[i] >=10)
        {
            kiekis++;
        }
    }
    return kiekis;
}

void rasyti (int sumT, int sumK, double vidT, double vidK, int dd)
{
    ofstream fr (FVR);
    fr << sumT << " " << sumK << endl;
    fr << fixed << setprecision (1) << vidT << " " << fixed << setprecision (1) << vidK << endl;
    fr << dd << endl;
    fr.close();
}
