#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Dalyvis
{
    string name, zuvys[30];
    int kiekis, mase[30];
};

struct Zuvys
{
    string z_pav;
    int taskai;
};

struct Rezult
{
    string name;
    int sum;
};

void skaityk (int &n, int &k, Dalyvis A[], Zuvys B[]);
void skaiciuok (int n, int k, Dalyvis A[], Zuvys B[], Rezult C[], Rezult D[]);
void rikiavimas (int x, Rezult X[]);
void rasyk (int n, int k, Rezult C[], Rezult D[]);

int main()
{
    Dalyvis A[30];
    Zuvys B[30];
    Rezult C[30], D[30]; // C- dalyviai rezult; D - zuvu rezult;
    int n, k; //n - dalyviu skaicius; k - zuvu skaicius;
    skaityk (n, k, A, B);
    skaiciuok (n, k, A, B, C, D);
    rikiavimas (n, C);
    rikiavimas (k, D);
    rasyk (n, k, C, D);

    return 0;
}

void skaityk (int &n, int &k, Dalyvis A[], Zuvys B[])
{
    ifstream fd(FV);
    fd >> n;
    char eil[21];
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        fd.get(eil, 21);
        A[i].name = eil;
        fd >> A[i].kiekis;
        fd.ignore(256, '\n');
        for (int j=0; j<A[i].kiekis; j++)
        {
            fd.get(eil, 21);
            A[i].zuvys[j] = eil;
            fd >> A[i].mase[j];
            fd.ignore(256, '\n');
        }
    }
    fd >> k;
    fd.ignore(256, '\n');
    for (int i=0; i<k; i++)
    {
        fd.get(eil, 21);
        B[i].z_pav = eil;
        fd >> B[i].taskai;
        fd.ignore(256, '\n');
    }
    fd.close();
}

void skaiciuok (int n, int k, Dalyvis A[], Zuvys B[], Rezult C[], Rezult D[])
{
    for (int i=0; i<k; i++)
    {
        D[i].sum = 0;
        D[i].name = B[i].z_pav;
    }
    for (int i=0; i<n; i++)
    {
        C[i].name = A[i].name;
        C[i].sum = 0;
        for (int j=0; j<A[i].kiekis; j++)
        {
            if (A[i].mase[j] < 200)
            {
                C[i].sum += 10;
            }
            else
            {
                C[i].sum += 30;
            }
            for (int p=0; p<k; p++)
            {
                if (A[i].zuvys[j] == B[p].z_pav)
                {
                    C[i].sum += B[p].taskai;
                }
                if (D[p].name == A[i].zuvys[j])
                {
                    D[p].sum += A[i].mase[j];
                }
            }

        }
    }
}

void rikiavimas (int x, Rezult X[])
{
    for (int i=0; i<x-1; i++)
    {
        for (int j=i+1; j<x; j++)
        {
            if (X[i].sum < X[j].sum)
            {
                swap (X[i], X[j]);
            }
            else if (X[i].sum == X[j].sum && X[i].name > X[j].name)
            {
                swap (X[i], X[j]);
            }
        }
    }
}

void rasyk (int n, int k, Rezult C[], Rezult D[])
{
    ofstream fr(FVR);
    fr << "Dalyviai" << endl;
    for (int i=0; i<n; i++)
    {
        fr << C[i].name << " " << C[i].sum << endl;
    }
    fr << "Laimikis" << endl;
    for (int i=0; i<k; i++)
    {
        fr << D[i].name << " " << D[i].sum << endl;
    }
    fr.close();
}
