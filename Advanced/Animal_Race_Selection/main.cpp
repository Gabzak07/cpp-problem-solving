#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Gyvunai
{
    string v[50];
    int n, min[50], sek[50];
};


void skaityk (Gyvunai G[], int &k);
void rikiavimas (Gyvunai &G);
void atranka (Gyvunai G[], int k, Gyvunai &B);
void rasyk (Gyvunai B);


int main()
{
    int k;
    Gyvunai G[100], B;
    skaityk (G, k);
    for (int i=0; i<k; i++)
    {
        rikiavimas (G[i]);
    }
    atranka (G, k, B);
    rikiavimas (B);
    rasyk (B);
    return 0;
}

void skaityk (Gyvunai G[], int &k)
{
    ifstream fd(FV);
    char eil[21];
    fd >> k;
    for (int i=0; i<k; i++)
    {
        fd >> G[i].n;
        fd.ignore(256, '\n');
        for (int j=0; j<G[i].n; j++)
        {
            fd.get(eil, 21);
            G[i].v[j] = eil;
            fd >> G[i].min[j] >> G[i].sek[j];
            fd.ignore(256, '\n');
        }
    }
    fd.close();
}

void rikiavimas (Gyvunai &G)
{
    for (int i=0; i<G.n - 1; i++)
    {
        for (int j=i+1; j<G.n; j++)
        {
            if (G.min[i] > G.min[j])
            {
                swap (G.min[i], G.min[j]);
                swap (G.sek[i], G.sek[j]);
                swap (G.v[i], G.v[j]);
            }
            else if (G.min[i] == G.min[j] && G.sek[i] > G.sek[j])
            {
                swap (G.min[i], G.min[j]);
                swap (G.sek[i], G.sek[j]);
                swap (G.v[i], G.v[j]);
            }
        }
    }
}

void atranka (Gyvunai G[], int k, Gyvunai &B)
{
    B.n = 0;
    for (int i=0; i<k; i++)
    {
        for (int j=0; j<G[i].n / 2; j++)
        {
            B.v[B.n] = G[i].v[j];
            B.min[B.n] = G[i].min[j];
            B.sek[B.n] = G[i].sek[j];
            B.n++;
        }
    }
}

void rasyk (Gyvunai B)
{
    ofstream fr(FVR);
    for (int i=0; i<B.n; i++)
    {
        fr << B.v[i] << " " << B.min[i] << " " << B.sek[i] << endl;
    }
    fr.close();
}
