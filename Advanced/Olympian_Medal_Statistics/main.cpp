#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char FV[]= "U1.csv";
const char FVR[]= "U1rez.txt";

struct Olimp
{
    string vieta, v, miestas, rung;
    int metai;

};

struct Naujas
{
    int metai, b_k, gold, silver, bronze;
};

struct Atletai
{
    string v;
    int k, metai[10];
};



void skaityk (Olimp S[], int &n);
void rikiavimas (int n, Olimp S[]);
void skaiciuok (int n, int &b, Olimp S[], Naujas N[], double &vid);
int rask (Naujas N[], int b, int v);
void skaiciuok2(int n, Olimp S[], Atletai A[], int &c, int &maxi);
int rask2 (Atletai A[], int c, string v);
void rasyk (Olimp S[], int n, Naujas N[], int b, int c, int maxi, Atletai A[], double vid);


int main()
{
    int n = 0, b = 0, c = 0, maxi = 0;
    double vid;
    Olimp S[50];
    Naujas N[50];
    Atletai A[50];
    skaityk (S, n);
    rikiavimas (n, S);
    skaiciuok (n, b, S, N, vid);
    skaiciuok2(n, S, A, c, maxi);
    rasyk (S, n, N, b, c, maxi, A, vid);

    return 0;
}

void skaityk (Olimp S[], int &n)
{
    ifstream fd(FV);
    string laik;
    fd.ignore(256, '\n');
    while (!fd.eof())
    {
       getline(fd, S[n].vieta, ',');
       getline(fd, S[n].v, ',');
       getline(fd, laik, ',');
       S[n].metai = stoi(laik);
       getline(fd, S[n].miestas, ',');
       getline(fd, S[n].rung);
       n++;
    }
    fd.close();
}

void rikiavimas (int n, Olimp S[])
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (S[i].metai > S[j].metai)
            {
                swap (S[i], S[j]);
            }
            else if (S[i].metai == S[j].metai && S[i].vieta > S[j].vieta)
            {
                swap (S[i], S[j]);
            }
            else if (S[i].metai == S[j].metai && S[i].vieta == S[j].vieta && S[i].v > S[j].v)
            {
                swap (S[i], S[j]);
            }
        }
    }
}

void skaiciuok (int n, int &b, Olimp S[], Naujas N[], double &vid)
{
    int laik, suma = 0;
    for (int i=0; i<n; i++)
    {
        laik = rask (N, b, S[i].metai);
        if (laik == -1)
        {
            N[b].metai = S[i].metai;
            if (S[i].vieta == "1 Auksas")
            {
                N[b].gold = 1; N[b].silver = 0; N[b].bronze = 0;
            }
                else if (S[i].vieta == "2 Sidabras")
                {
                    N[b].silver = 1; N[b].gold = 0; N[b].bronze = 0;
                }
                    else
                    {
                        N[b].bronze = 1;  N[b].silver = 0; N[b].gold = 0;
                    }
            N[b].b_k = 1;
            b++;
        }
        else
        {
            if (S[i].vieta == "1 Auksas")
            {
                N[laik].gold++;
            }
                else if (S[i].vieta == "2 Sidabras")
                {
                    N[laik].silver++;
                }
                    else
                    {
                        N[laik].bronze++;
                    }
            N[laik].b_k++;
        }
    }

    for (int i=0; i<b; i++)
    {
        suma += N[i].b_k;
    }
    vid = (double) suma / b;

}

int rask (Naujas N[], int b, int v)
{
    for (int i=0; i<b; i++)
    {
        if (N[i].metai == v)
        {
            return i;
        }
    }
    return -1;
}

void skaiciuok2(int n, Olimp S[], Atletai A[], int &c, int &maxi)
{
    int laik;
    for (int i=0; i<n; i++)
    {
        laik = rask2 (A, c, S[i].v);
        {
            if (laik == -1)
            {
                A[c].k = 1;
                A[c].metai[0] = S[i].metai;
                A[c].v = S[i].v;
                c++;
            }
            else
            {
                A[laik].metai[A[laik].k] = S[i].metai;
                A[laik].k++;
            }
        }
    }

    for (int i=0; i<c; i++)
    {
        if (A[i].k > maxi)
        {
            maxi = A[i].k;
        }
    }
}

int rask2 (Atletai A[], int c, string v)
{
    for (int i=0; i<c; i++)
    {
        if (A[i].v == v)
        {
            return i;
        }
    }
    return -1;
}

void rasyk (Olimp S[], int n, Naujas N[], int b, int c, int maxi, Atletai A[], double vid)
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        fr << S[i].metai << " " << S[i].vieta << " " << S[i].v << " " << endl;
    }
    fr << endl;
    for (int i=0; i<b; i++)
    {
        fr << N[i].metai << " " << N[i].b_k << " (" << N[i].gold << ", " << N[i].silver << ", " << N[i].bronze << ")" << endl;
    }
    fr << "Vidutinis medaliu skaicius per olimpiada: " << fixed << setprecision(1) << vid << endl;
    fr << endl;
    fr << "Daugiausia medaliu laimejo" << endl;
    for (int i=0; i<c; i++)
    {
        if (A[i].k == maxi)
        {
            fr << A[i].v << " ";
            for (int j=0; j<A[i].k; j++)
            {
                fr << A[i].metai[j] << " ";
            }
            fr << endl;
        }
    }
    fr.close();
}
