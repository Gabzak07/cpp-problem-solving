#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int &m, int L_k[], int J_k[]);
void rikiavimas (int n, int L_k[]);
int patikrinti (int m, int J_k[], int x);
void skaiciuok (int n, int L_k[], int Linos_mainai[], int &b, int J_k[], int m);
void bendr (int L_k[], int m, int J_k[], int n, int bendru_kiekis[], int &b_k);
void rasyk (int Linos_mainai[], int Jurgio_mainai[], int b, int c, int bendru_kiekis[], int b_k);

int main()
{
    int n, m, L_k[500], J_k[500], Linos_mainai[500], b, Jurgio_mainai[500], c, bendru_kiekis[500], b_k = 0;
    skaityk (n, m, L_k, J_k);
    rikiavimas (n, L_k);
    skaiciuok (n, L_k, Linos_mainai, b, J_k, m);
    rikiavimas (m, J_k);
    skaiciuok (m, J_k, Jurgio_mainai, c, L_k, n);
    bendr (L_k, m, J_k, n, bendru_kiekis, b_k);
    bendr (J_k, n, L_k, m, bendru_kiekis, b_k);
    rikiavimas (b_k, bendru_kiekis);
    rasyk (Linos_mainai, Jurgio_mainai, b, c, bendru_kiekis, b_k);
    return 0;
}

void skaityk (int &n, int &m, int L_k[], int J_k[])
{
    ifstream fd(FV);
    fd >> n >> m;
    for (int i=0; i<n; i++)
    {
        fd >> L_k[i];
    }
    for (int j=0; j<m; j++)
    {
        fd >> J_k[j];
    }
    fd.close();
}

void rikiavimas (int n, int L_k[])
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (L_k[i] > L_k[j])
            {
                swap (L_k[i], L_k[j]);
            }
        }
    }
}

int patikrinti (int m, int J_k[], int x)
{
    for (int i=0; i<m; i++)
    {
        if (J_k[i] == x)
        {
            return 1;
        }
    }
    return 0;
}
void skaiciuok (int n, int L_k[], int Linos_mainai[], int &b, int J_k[], int m)
{
    b = 0;
    for (int i=0; i<n; i++)
    {
        if (L_k[i] == L_k[i+1] && L_k[i+1] != L_k[i+2] && patikrinti (m, J_k, L_k[i]) == 0)
        {
            Linos_mainai[b] = L_k[i];
            b++;
        }
    }
}

void bendr (int L_k[], int m, int J_k[], int n, int bendru_kiekis[], int &b_k)
{
    for (int i=0; i<n; i++)
    {
        if (patikrinti (b_k, bendru_kiekis, L_k[i])==0)
        {
            bendru_kiekis[b_k] = L_k[i];
            b_k++;
        }
    }
}

void rasyk (int Linos_mainai[], int Jurgio_mainai[], int b, int c, int bendru_kiekis[], int b_k)
{
    ofstream fr(FVR);
    if (b==0)
    {
        fr << 0 << endl;
    }
    else
    {
    for (int i=0; i<b; i++)
    {
      fr << Linos_mainai[i] << " ";
    }
    fr << endl;
    }
    if (c==0)
    {
        fr << 0 << endl;
    }
    else
    {
        for (int i=0; i<c; i++)
        {
            fr << Jurgio_mainai[i] << " ";
        }
        fr << endl;
    }

    for (int i=0; i<b_k; i++)
    {
        fr << bendru_kiekis[i] << " ";
    }
    fr.close();
}
