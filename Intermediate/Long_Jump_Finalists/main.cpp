#include <iostream>
#include <fstream>
using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, double rez[]);
void salinimas (int &n, double rez[]);
void rikiavimas (int n, double rez[]);
void rasyk (int n, double rez[]);

int main()
{
    int n;
    double rez[100];
    skaityk (n, rez);
    salinimas (n, rez);
    rikiavimas (n, rez);
    rasyk (n, rez);
    return 0;
}

void skaityk (int &n, double rez[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> rez[i];
    }
    fd.close();
}

void salinimas (int &n, double rez[])
{
    double suma = 0;
    double vid;
    for (int i=0; i<n; i++)
    {
        suma = suma + rez[i];
    }
    vid = suma / n;
    for (int i=0; i<n; i++)
    {
        if (rez[i] <= vid)
        {
            for (int j=i; j<n-1; j++)
            {
                rez[j] = rez[j+1];
            }
            n--;
            i--;
        }
    }
}
void rikiavimas (int n, double rez[])
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (rez[i] > rez[j])
            {
                swap (rez[i], rez[j]);
            }
        }
    }
}
void rasyk (int n, double rez[])
{
    ofstream fr(FVR);
    fr << n << endl;
    for (int i=0; i<n; i++)
    {
        fr << rez[i] << " ";
    }
    fr.close();
}
