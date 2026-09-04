#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (string &vardas_A, string &pavarde_A, string &vardas_B, string &pavarde_B, int &n, int A[], int B[]);
int pal (int n, int X[]);
void rikiavimas (int n, int X[]);
void rasyk (string vardas, string pavarde, int n, int X[]);


int main()
{
    string vardas_A, pavarde_A, vardas_B, pavarde_B;
    int n, A[20], B[20], suma_A, suma_B;
    skaityk (vardas_A, pavarde_A, vardas_B, pavarde_B, n, A, B);
    suma_A = pal (n, A);
    suma_B = pal (n, B);
    if (suma_A > suma_B)
    {
        rikiavimas (n, A);
        rasyk (vardas_A, pavarde_A, n, A);
    }
    else
    {
        rikiavimas (n, B);
        rasyk (vardas_B, pavarde_B, n, B);
    }

    return 0;
}

void skaityk (string &vardas_A, string &pavarde_A, string &vardas_B, string &pavarde_B, int &n, int A[], int B[])
{
    ifstream fd(FV);
    fd >> vardas_A >> pavarde_A;
    fd >> vardas_B >> pavarde_B;
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> A[i] >> B[i];
    }
    fd.close();
}

int pal (int n, int X[])
{
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        sum = sum + X[i];
    }
    return sum;
}

void rikiavimas (int n, int X[])
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (X[i] < X[j])
            {
                swap(X[i], X[j]);
            }
        }
    }
}

void rasyk (string vardas, string pavarde, int n, int X[])
{
    ofstream fr(FVR);
    fr << vardas << " " << pavarde << endl;
    for (int i=0; i<n; i++)
    {
        fr << X[i] << " ";
    }
    fr.close();
}
