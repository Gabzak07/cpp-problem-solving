#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Albumas
{
    string pav;
    int metai;
    int val;
    int min;
    int kiekis;
};

void skaityk (int &n, Albumas A[]);
void skaiciuok (int n, Albumas A[], int &minutes, int &valandos, double &vid);
void rikiavimas (int n, Albumas A[]);
void rasyk (int n, Albumas A[], int minutes, int valandos, double vid);

int main()
{
    int n, valandos, minutes;
    double vid;
    Albumas A[500];
    skaityk (n, A);
    skaiciuok (n, A, minutes, valandos, vid);
    rikiavimas (n, A);
    rasyk (n, A, minutes, valandos, vid);
    return 0;
}

void skaityk (int &n, Albumas A[])
{
    ifstream fd(FV);
    char eil[21];
    fd >> n;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        fd.get(eil, 21);
        A[i].pav = eil;
        fd >> A[i].metai >> A[i].val >> A[i].min >> A[i].kiekis;
        fd.ignore(256, '\n');
    }
    fd.close();
}

void skaiciuok (int n, Albumas A[], int &minutes, int &valandos, double &vid)
{
    int m = 0, k = 0;
    for (int i=0; i<n; i++)
    {
        m = m+ A[i].val * 60 + A[i].min;
        k = k + A[i].kiekis;
    }
    valandos = m/60;
    minutes = m%60;
    vid = (double) k / n;
}

void rikiavimas (int n, Albumas A[])
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (A[i].kiekis > A[j].kiekis)
            {
                swap (A[i], A[j]);
            }
        }
    }
}

void rasyk (int n, Albumas A[], int minutes, int valandos, double vid)
{
    ofstream fr(FVR);
    fr << valandos << " " << minutes << endl;
    fr << fixed << setprecision(2) << vid << endl;
    for (int i=0; i<n; i++)
    {
        fr << A[i].pav << " " << A[i].metai << endl;
    }
    fr.close();
}
