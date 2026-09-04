#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int &m, int &num, string vardas[], string ats[]);
void lyginimas (string ats[], int sut[], int n, int num, int m);
void rikiavimas (string vardas[], int sut[], int n, int num);
void rasyk (string vardas[], int sut[], int n, int num);


int main()
{
    int n, m, num, sut[10];
    string vardas[10], ats[10];
    skaityk (n, m, num, vardas, ats);
    lyginimas (ats, sut, n, num, m);
    rikiavimas (vardas, sut, n, num);
    rasyk (vardas, sut, n, num);
    return 0;
}

void skaityk (int &n, int &m, int &num, string vardas[], string ats[])
{
    ifstream fd(FV);
    fd >> n >> m;
    fd >> num;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        char eil[11];
        fd.get(eil, 11);
        vardas[i] = eil;
        fd >> ats[i];
        fd.ignore(256, '\n');
    }
    fd.close();
}

void lyginimas (string ats[], int sut[], int n, int num, int m)
{
    string laik2= ats[num-1];
    for (int i=0; i<n; i++)
    {
        if (i != num-1)
        {
            sut[i] = 0;
            string laik = ats[i];
            for (int j=0; j<m; j++)
            {
                if (laik[j] == laik2[j])
                {
                    sut[i]++;
                }
            }
        }
    }
}

void rikiavimas (string vardas[], int sut[], int n, int num)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (i!=num-1 && j!=num-1)
            {
                if (sut[i] > sut[j])
            {
                swap (vardas[i], vardas[j]);
                swap (sut[i], sut[j]);
            }
            else if (sut[i] == sut[j] && vardas[i] > vardas[j])
            {
               swap (vardas[i], vardas[j]);
                swap (sut[i], sut[j]);
            }
            }

        }
    }
}

void rasyk (string vardas[], int sut[], int n, int num)
{
    ofstream fr(FVR);
    fr << vardas[num-1] << endl;
    for (int i=0; i<n; i++)
    {
        if (i != num-1)
        {
            fr << vardas[i] << " " << sut[i] << endl;
        }
    }
    fr.close();
}
