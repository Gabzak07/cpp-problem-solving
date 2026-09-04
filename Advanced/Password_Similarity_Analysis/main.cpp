#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Slapt
{
    string v, lygis, sarasas[25];
    int ilg, d_r, m_r, sk_k, spec_k, reiksme, b, ilgis[25];
};

void skaityk (int &n, int &s, Slapt S[], Slapt D[]);
int skaiciuok (Slapt S, Slapt D);
void rikiavimas (int n, Slapt D[]);
void rasyk (int n, Slapt D[]);

int main()
{
    int n, s;
    Slapt S[25], D[5];
    skaityk (n, s, S, D);

    for (int i=0; i<n; i++)
    {
        D[i].b = 0;
        D[i].lygis = S[0].lygis;
        D[i].reiksme = skaiciuok (S[0], D[i]);
        for (int j=1; j<s; j++)
        {
            if (skaiciuok (S[j], D[i]) < D[i].reiksme)
            {
                D[i].reiksme = skaiciuok (S[j], D[i]);
                D[i].lygis = S[j].lygis;
            }
        }

        for (int j=0; j<s; j++)
        {
            if (skaiciuok (S[j], D[i]) == D[i].reiksme)
            {
                D[i].sarasas[D[i].b] = S[j].v;
                D[i].ilgis[D[i].b] = S[j].ilg;
                D[i].b++;
            }
        }
    }

    rikiavimas(n, D);
    rasyk (n, D);
    return 0;
}

void skaityk (int &n, int &s, Slapt S[], Slapt D[])
{
    ifstream fd(FV);
    char eil[16], eil2[10];
    fd >> n >> s;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        fd.get(eil, 16);
        D[i].v = eil;
        fd >> D[i].ilg >> D[i].d_r >> D[i].m_r >> D[i].sk_k >> D[i].spec_k;
        fd.ignore(256, '\n');
    }
    for (int i=0; i<s; i++)
    {
        fd.get(eil, 16);
        S[i].v = eil;
        fd >> S[i].ilg >> S[i].d_r >> S[i].m_r >> S[i].sk_k >> S[i].spec_k;
        fd.get(eil2, 10);
        S[i].lygis = eil2;
        fd.ignore(256, '\n');
    }
    fd.close();
}

int skaiciuok (Slapt S, Slapt D)
{
    return abs(S.ilg - D.ilg) + abs(S.d_r - D.d_r) + abs(S.m_r - D.m_r) + abs(S.spec_k - D.spec_k) + abs(S.sk_k - D.sk_k);
}

void rikiavimas (int n, Slapt D[])
{

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<D[i].b-1; j++)
        {
            for (int k=j+1; k<D[i].b; k++)
            {

                if ( D[i].ilgis[j] < D[i].ilgis[k] )
                    {
                        swap (D[i].sarasas[j], D[i].sarasas[k]);
                        swap (D[i].ilgis[j], D[i].ilgis[k]);
                    }
            }
        }
    }
}


void rasyk (int n, Slapt D[])
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        fr << D[i].v << " " << D[i].lygis << " " << D[i].reiksme << endl;
        for (int j=0; j<D[i].b; j++)
        {
            fr << D[i].sarasas[j] << endl;
        }
    }
    fr.close();
}
