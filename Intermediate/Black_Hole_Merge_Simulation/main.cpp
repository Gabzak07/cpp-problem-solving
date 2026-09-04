#include <iostream>
#include <fstream>
using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int dydz[]);
int skaiciavimas (int n, int dydz[]);
void rasyk (int rez);

int main()
{
    int n, dydz[50], rez;
    skaityk (n, dydz);
    rez = skaiciavimas(n, dydz);
    rasyk (rez);
    return 0;
}

void skaityk (int &n, int dydz[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> dydz[i];
    }
    fd.close();
}

int skaiciavimas (int n, int dydz[])
{
    while (n!=1)
    {
        if (dydz[0] < dydz[1])
        {
            for (int i=0; i<n-1; i++)
            {
                dydz[i] = dydz[i+1];
            }
            dydz[0]++;
            n--;
        }
        else if (dydz[0] == dydz[1])
        {
           for (int i=0; i<n-1; i++)
            {
                dydz[i] = dydz[i+1];
            }
            dydz[0] = dydz[0]*2;
            n--;
        }
        else
        {
            for (int i=1; i<n-1; i++)
            {
               dydz[i]= dydz[i+1];
            }
            dydz[0]++;
            n--;
        }
    }
    return dydz[0];
}

void rasyk (int rez)
{
    ofstream fr(FVR);
    fr << rez << endl;
    fr.close();
}
