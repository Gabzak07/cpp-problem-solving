#include <iostream>
#include <fstream>

using namespace std;

const char FD[]= "Mokytojai.txt";
const char FV[]= "Mokiniai.txt";
const char FVR[]= "Rezultatas.txt";

struct Mokytojai
{
    string v, pav, dalykas; // v - vardas; pav - pavarde
    int mok_k; //mok_k - mokiniu kiekis, kuri turi mokytojas;
    double vid; //vid - vidurkis;
};

struct Mokiniai
{
    string v, dalykas, pav; // v - vardas; pav - pavarde
    int p; // p - pazymys
};

void skaityk1 (int &n, Mokytojai N[]);
void skaityk2 (int &m, Mokiniai M[]);
void skaiciuok (int n, int m, Mokiniai M[], Mokytojai N[]);
void max (int n, Mokytojai N[], string &v_ger, string &pav_ger);
Mokytojai geriausias (int n, Mokytojai N[]);
void rasyk (int n, Mokytojai N[], Mokytojai Geriausias, string v_ger, string pav_ger);

int main()
{
    int n, m; //n - mokytoju kiekis; m- mokiniu kiekis;
    Mokytojai N[30], Geriausias;
    Mokiniai M[30];
    string v_ger, pav_ger; //vardas ir pavarde mokytojo, kuris turi daugiausia mokiniu
    skaityk1 (n, N);
    skaityk2 (m, M);
    skaiciuok (n, m, M, N);
    max (n, N, v_ger, pav_ger);
    Geriausias = geriausias (n, N);
    rasyk (n, N, Geriausias, v_ger, pav_ger);
    return 0;
}

void skaityk1 (int &n, Mokytojai N[])
{
    ifstream fd(FD);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> N[i].v >> N[i].pav >> N[i].dalykas;
    }
    fd.close();
}

void skaityk2 (int &m, Mokiniai M[])
{
    ifstream fd(FV);
    fd >> m;
    for (int i=0; i<m; i++)
    {
        fd >> M[i].v >> M[i].pav >> M[i].dalykas >> M[i].p;
    }
    fd.close();
}

void skaiciuok (int n, int m, Mokiniai M[], Mokytojai N[])
{
    for (int i=0; i<n; i++)
    {
        N[i].mok_k = 0;
        N[i].vid = 0; //Kol kas naudosiu vid kaip sumai, o tik to po paskaiciuosiu kaip vidurki;
        for (int j=0; j<m; j++)
        {
            if (M[j].dalykas == N[i].dalykas)
            {
                N[i].mok_k++;
                N[i].vid = N[i].vid + M[j].p; // naudoju dabar vid kaip suma;
            }
        }
        N[i].vid = N[i].vid / N[i].mok_k; // dabar jau ieskau kaip vidurki;
    }
}

void max (int n, Mokytojai N[], string &v_ger, string &pav_ger)
{
    int maxi = 0;
    for (int i=0; i<n; i++)
    {
        if (N[i].mok_k > maxi)
        {
            maxi = N[i].mok_k;
            v_ger = N[i].v;
            pav_ger = N[i].pav;
        }
    }
}

Mokytojai geriausias (int n, Mokytojai N[])
{
    Mokytojai laik = N[0];
    for (int i=0; i<n; i++)
    {
        if (laik.vid < N[i].vid)
        {
            laik = N[i];
        }
    }
    return laik;
}

void rasyk (int n, Mokytojai N[], Mokytojai Geriausias, string v_ger, string pav_ger)
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        fr << N[i].pav << " " << N[i].mok_k << endl;
    }
    fr << "Daugiausia mokiniu turi: " << v_ger << " " << pav_ger << endl;
    fr << "Geriausiai mokiniai mokosi pas: " << Geriausias.v << " " << Geriausias.pav << endl;
    fr.close();
}
