#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int &siandien, int kiekis[], int laikas[], double kaina[]);
void skaiciuok (int &n, int siandien, int kiekis[], int laikas[], double kaina[], int &rusiu_pasibaige, int &prekiu_isimti, double &nuostolis);
void rasyk (int n, int kiekis[], int laikas[], double kaina[], int rusiu_pasibaige, int prekiu_isimti, double nuostolis);

int main()
{
    int n, siandien, kiekis[200], laikas[200], rusiu_pasibaige = 0, prekiu_isimti = 0;
    double kaina[200], nuostolis = 0;
    skaityk (n, siandien, kiekis, laikas, kaina);
    skaiciuok (n, siandien, kiekis, laikas, kaina, rusiu_pasibaige, prekiu_isimti, nuostolis);
    rasyk (n, kiekis, laikas, kaina, rusiu_pasibaige, prekiu_isimti, nuostolis);
    return 0;
}

void skaityk (int &n, int &siandien, int kiekis[], int laikas[], double kaina[])
{
    ifstream fd(FV);
    fd >> n >> siandien;
    for (int i=0; i<n; i++)
    {
        fd >> kiekis[i] >> kaina[i] >> laikas[i];
    }
    fd.close();
}

void skaiciuok (int &n, int siandien, int kiekis[], int laikas[], double kaina[], int &rusiu_pasibaige, int &prekiu_isimti, double &nuostolis)
{
    for (int i=0; i<n; i++)
    {
        if (laikas[i] <= siandien)
        {
            rusiu_pasibaige++;
            prekiu_isimti = prekiu_isimti + kiekis[i];
            nuostolis = nuostolis + kiekis[i] * kaina[i];
           for (int j=i; j<n-1; j++)
           {
               laikas[j] = laikas[j+1];
               kiekis[j] = kiekis[j+1];
               kaina[j] = kaina[j+1];
           }
           n--;
           i--;
        }
    }
}

void rasyk (int n, int kiekis[], int laikas[], double kaina[], int rusiu_pasibaige, int prekiu_isimti, double nuostolis)
{
    ofstream fr(FVR);
    fr << "Prekes prekyboje" << endl;
    for (int i=0; i<70; i++)
    {
        fr << "-";
    }
    fr << endl;
    fr << setw(20) << left << "| Prekiu kiekis" << setw(20) << left << "| Prekes kaina " << setw(29) << left << "| Prekes galiojimo laikas" << "|" << endl;
    for (int i=0; i<70; i++)
    {
        fr << "-";
    }
    fr << endl;
    for (int i=0; i<n; i++)
    {
        fr << "|" << setw(19) << left << kiekis[i] << "|" << setw(19) << right << kaina[i] << "|" << setw(29) << right << laikas[i] << "|" << endl;
    }
    for (int i=0; i<70; i++)
    {
        fr << "-";
    }
    fr << endl;
    fr << rusiu_pasibaige << endl;
    fr << prekiu_isimti << endl;
    fr << nuostolis << endl;
    fr.close();
}
