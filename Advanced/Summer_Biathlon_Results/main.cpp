#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Zaidejas
{
    string v;
    int id, h, min, sek, bauda, g_sek; // id numeris, valanda, minutes, sekundes, baudos minutes;
};

void skaityk (int &n, int &m, Zaidejas A[], Zaidejas B[]);
void skaiciuok (int n, int m, Zaidejas A[], Zaidejas B[], Zaidejas Vaikinai[], Zaidejas Merginos[], int &v, int &me);
void rikiavimas (int x, Zaidejas X[]);
void rasyk (int x, Zaidejas X[], string zodis);

int main()
{
    ofstream fr(FVR);
    fr.close();
    Zaidejas A[30], B[30], Vaikinai[30], Merginos[30];
    int n, m, v =0, me=0; //v -vaikinai, me - merginos;
    skaityk (n, m, A, B);
    skaiciuok (n, m, A, B, Vaikinai, Merginos, v, me);
    rikiavimas (v, Vaikinai);
    rikiavimas (me, Merginos);
    rasyk (me, Merginos, "Merginos");
    rasyk (v, Vaikinai, "Vaikinai");
    return 0;
}

void skaityk (int &n, int &m, Zaidejas A[], Zaidejas B[])
{
    ifstream fd(FV);
    int suma_suviai, suviai;
    char eil[21];
    fd >> n;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        fd.get(eil, 21);
        A[i].v = eil;
        fd >> A[i].id >> A[i].h >> A[i].min >> A[i].sek;
        fd.ignore(256, '\n');
    }
    fd >> m;
    for (int i=0; i<m; i++)
    {
        suma_suviai = 0;
        fd >> B[i].id >> B[i].h >> B[i].min >> B[i].sek;
        if (B[i].id / 100 == 2)
        {
            for (int j=0; j<4; j++)
            {
                fd >> suviai;
                suma_suviai += suviai;
            }
            B[i].bauda = 20 - suma_suviai;
        }
        else
        {
            for (int j=0; j<2; j++)
            {
                fd >> suviai;
                suma_suviai += suviai;
            }
            B[i].bauda = 10 - suma_suviai;
        }
    }
    fd.close();
}

void skaiciuok (int n, int m, Zaidejas A[], Zaidejas B[], Zaidejas Vaikinai[], Zaidejas Merginos[], int &v, int &me)
{

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (B[i].id == A[j].id)
            {
                B[i].g_sek = (B[i].h* 3600 + B[i].min * 60 + B[i].sek) - (A[j].h*3600 + A[j].min * 60 + A[j].sek);

           if (B[i].id / 100 == 1)
           {
               Merginos[me].v = A[j].v;
               Merginos[me].id = B[i].id;

               Merginos[me].h = B[i].g_sek / 3600;
               Merginos[me].min = (B[i].g_sek % 3600) / 60 + B[i].bauda;
               Merginos[me].sek = (B[i].g_sek % 3600) % 60;
                me++;
           }

           else
           {
               Vaikinai[v].v = A[j].v;
               Vaikinai[v].id = B[i].id;
               Vaikinai[v].h = B[i].g_sek / 3600;
               Vaikinai[v].min = (B[i].g_sek % 3600) / 60 + B[i].bauda;
               Vaikinai[v].sek = (B[i].g_sek % 3600) % 60;
               v++;
           }

            }
        }
    }
}

void rikiavimas (int x, Zaidejas X[])
{
    for (int i=0; i<x-1; i++)
    {
        for (int j=x+1; j<x; j++)
        {
            if (X[i].g_sek > X[j].g_sek)
            {
                swap (X[i], X[j]);
            }
            else if (X[i].g_sek == X[j].g_sek && X[i].v > X[j].v)
            {
                swap (X[i], X[j]);
            }
        }
    }
}

void rasyk (int x, Zaidejas X[], string zodis)
{
    ofstream fr(FVR, ios::app);
    fr << zodis << endl;
    for (int i=0; i<x; i++)
    {
        fr << X[i].id << " " << X[i].v << " " << X[i].h << " " << X[i].min << " " << X[i].sek << endl;
    }
    fr.close();
}
