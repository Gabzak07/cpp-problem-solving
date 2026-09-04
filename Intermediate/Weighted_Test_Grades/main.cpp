#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Mokinys
{
    string v;
    int paz[10];
    int g;
};

void skaityk (int &n, int &k, double kef[], Mokinys A[]);
void skaiciuok (int n, int k, double kef[], Mokinys A[]);
int maksimalus (int n, Mokinys A[]);
int minimalus (int n, Mokinys A[]);
void rasyk (int n, Mokinys A[], int min, int max);
int vidurkis (int n, Mokinys A[]);

int main()
{
    int n, k, min, max;
    double kef[10];
    Mokinys A[30];
    skaityk (n, k, kef, A);
    skaiciuok (n, k, kef, A);
    max= maksimalus (n, A);
    min= minimalus (n, A);
    rasyk (n, A, min, max);
    return 0;
}

void skaityk (int &n, int &k, double kef[], Mokinys A[])
{
    ifstream fd(FV);
    char eil[16];
    fd >> n >> k;
    for (int i=0; i<k; i++)
    {
        fd >> kef[i];
    }
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        fd.get(eil, 16);
        A[i].v = eil;
        for (int j=0; j<k; j++)
        {
            fd >> A[i].paz[j];
        }
        fd.ignore(256, '\n');
    }
    fd.close();
}

int maksimalus (int n, Mokinys A[])
{
    int maxi = 0;
    for (int i=0; i<n; i++)
    {
        if (A[i].g > maxi)
        {
            maxi = A[i].g;
        }
    }
    return maxi;
}

int minimalus (int n, Mokinys A[])
{
    int mini = A[0].g;
    for (int i=0; i<n; i++)
    {
        if (A[i].g < mini)
        {
            mini = A[i].g;
        }
    }
    return mini;
}

void skaiciuok (int n, int k, double kef[], Mokinys A[])
{
    double sum;
    for (int i=0; i<n; i++)
    {
        sum = 0;
        for (int j=0; j<k; j++)
        {
            sum = sum + A[i].paz[j] * kef[j];
        }
        A[i].g = round (sum);
    }
}

int vidurkis (int n, Mokinys A[])
{
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        sum = sum + A[i].g;
    }
    return round((double)sum/n);
}

void rasyk (int n, Mokinys A[], int min, int max)
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        fr << A[i].v << " " << A[i].g << endl;
    }
    fr << vidurkis (n, A) << endl;
    for (int i=0; i<n; i++)
    {
        if (A[i].g == max)
        {
            fr << A[i].v << " " << A[i].g << endl;
        }
    }
    for (int i=0; i<n; i++)
    {
        if (A[i].g == min)
        {
            fr << A[i].v << " " << A[i].g << endl;
        }
    }
    fr.close();
}
