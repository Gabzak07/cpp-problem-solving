#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Zaidejai
{
    int g, min[50], sek[50];
    string v[50];
};

void skaityk (int &k, Zaidejai A[]);
void skaiciuok (int k, Zaidejai A[], Zaidejai &B);
void rikiavimas (Zaidejai &A);
void rasyk (Zaidejai B);

int main()
{
    Zaidejai A[50], B;
    int k;
    skaityk (k, A);
    skaiciuok (k, A, B);
    rikiavimas (B);
    rasyk (B);
    return 0;
}

void skaityk (int &k, Zaidejai A[])
{
    ifstream fd(FV);
    fd >> k;
    for (int i=0; i<k; i++)
    {
        char eil[21];
        fd >> A[i].g;
        fd.ignore(256, '\n');
        for (int j=0; j<A[i].g; j++)
        {
            fd.get(eil, 21);
            A[i].v[j] = eil;
            fd >> A[i].min[j] >> A[i].sek[j];
            fd.ignore(256, '\n');
        }
    }
    fd.close();
}

void skaiciuok (int k, Zaidejai A[], Zaidejai &B)
{
    B.g = 0;
    for (int i=0; i<k; i++)
    {
        rikiavimas (A[i]);
            for (int j=0; j< A[i].g / 2; j++)
            {
                B.v[B.g] = A[i].v[j];
                B.min[B.g] = A[i].min[j];
                B.sek[B.g] = A[i].sek[j];
                B.g++;
            }
    }
}

void rikiavimas (Zaidejai &A)
{
    for (int i=0; i<A.g-1; i++)
    {
        for (int j=i+1; j<A.g; j++)
        {
            if (A.min[i]*60 + A.sek[i] > A.min[j]*60 + A.sek[j])
            {
                swap (A.v[i], A.v[j]);
                swap (A.min[i], A.min[j]);
                swap (A.sek[i], A.sek[j]);
            }
        }
    }
}

void rasyk (Zaidejai B)
{
    ofstream fr(FVR);
    for (int i=0; i<B.g; i++)
    {
        fr << B.v << " " << B.min << " " << B.sek << endl;
    }
    fr.close();
}
