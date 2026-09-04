#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys1.txt";
const char FVR[]= "Rezultatas.txt";

struct Miestai
{
    string miestas, aps;
    int n;
};

struct Apskritys
{
    string aps;
    int maz, aps_gyv;
};

void skaityk (Miestai M[], int &k);
void atranka (Miestai M[], int k, int &b, Apskritys A[]);
int rasti (Apskritys A[], int b, string x);
void rikiavimas (Apskritys A[], int k);
void rasyk (Apskritys A[], int k);

int main()
{
    Miestai M[103];
    Apskritys A[103];
    int k, b = 0;
    skaityk (M, k);
    atranka (M, k, b, A);
    rikiavimas (A, b);
    rasyk (A, b);
    return 0;
}

void skaityk (Miestai M[], int &k)
{
    ifstream fd(FV);
    fd >> k;
    fd.ignore(256, '\n');
    for (int i=0; i<k; i++)
    {
        char eil[21], laik[14];
        fd.get(eil, 21);
        M[i].miestas = eil;
        fd.get(laik, 14);
        M[i].aps = laik;
        fd >> M[i].n;
        fd.ignore(256, '\n');

    }
    fd.close();
}

void atranka (Miestai M[], int k, int &b, Apskritys A[])
{
    int laik;
    for (int i=0; i<k; i++)
    {
        laik = rasti (A, b, M[i].aps);
        cout << laik << endl;
        if (laik == -1)
        {
            A[b].aps = M[i].aps;

            // A[b].maz = M[i].n;
            A[b].aps_gyv = M[i].n;
            b++;
        }
        else
        {
            A[laik].aps_gyv = A[laik].aps_gyv + M[i].n;
            //if (A[laik].maz > M[i].n
                  //A[laik].maz = M[i].n
        }

    }
    for (int i=0; i<b; i++)
    {
        A[i].maz = M[0].n;
        for (int j=0; j<k; j++)
        {
            if (A[i].aps == M[j].aps && M[j].n < A[i].maz)
            {
                A[i].maz = M[j].n;
            }
        }
    }
}

int rasti (Apskritys A[], int b, string x)
{
    for (int i=0; i<b; i++)
    {
        if (A[i].aps == x)
        {
            return i;
        }
    }
    return -1;
}

void rikiavimas (Apskritys A[], int k)
{
    for (int i=0; i<k-1; i++)
    {
        for (int j=i+1; j<k; j++)
        {
            if (A[i].maz > A[j].maz)
            {
                swap (A[i], A[j]);
            }
            else if (A[i].maz == A[j].maz && A[i].aps > A[j].aps)
            {
                swap (A[i], A[j]);
            }
        }
    }
}

void rasyk (Apskritys A[], int k)
{
    ofstream fr(FVR);
    fr << k << endl;
    for (int i=0; i<k; i++)
    {
        fr << A[i].aps << " " << A[i].maz << " " << A[i].aps_gyv << endl;
    }
    fr.close();
}
