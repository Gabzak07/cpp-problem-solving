#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Mok
{
    string v, p;
    int paz[7];
    int g; //galutinis pazymys
};

void skaityk (int &n, int &k, double koef[], Mok M[]);
void skaiciuok (int n, int k, double koef[], Mok M[]);
int geriausias_pazymys (int n, Mok M[]);
int blogiausias_pazymys (int n, Mok M[]);
void rasyk (int n, Mok M[], int best_grade, int worst_grade);

int main()
{
    int n, k, best_grade, worst_grade;
    double koef[7];
    Mok M[30];
    skaityk (n, k, koef, M);
    skaiciuok (n, k, koef, M);
    best_grade = geriausias_pazymys (n, M);
    worst_grade = blogiausias_pazymys (n, M);
    rasyk (n, M, best_grade, worst_grade);

    return 0;
}

void skaityk (int &n, int &k, double koef[], Mok M[])
{
    ifstream fd(FV);
    fd >> n >> k;
    for (int i=0; i<k; i++)
    {
        fd >> koef[i];
    }
    for (int i=0; i<n; i++)
    {
        fd >> M[i].v >> M[i].p;
        for (int j=0; j<k; j++)
        {
            fd >> M[i].paz[j];
        }
    }
    fd.close();
}

void skaiciuok (int n, int k, double koef[], Mok M[])
{
    for (int i=0; i<n; i++)
    {
        double suma = 0;
        for (int j=0; j<k; j++)
        {
            suma = suma + M[i].paz[j] * koef[j];
        }
        M[i].g = round(suma);
    }
}

int geriausias_pazymys (int n, Mok M[])
{
    int maxi = 0;
    for (int i=0; i<n; i++)
    {
        if (M[i].g > maxi)
        {
            maxi = M[i].g;
        }
    }
    return maxi;
}

int blogiausias_pazymys (int n, Mok M[])
{
    int mini = 10;
    for (int i=0; i<n; i++)
    {
        if (M[i].g < mini)
        {
            mini = M[i].g;
        }
    }
    return mini;
}

void rasyk (int n, Mok M[], int best_grade, int worst_grade)
{
    ofstream fr(FVR);
    fr << "VISI" << endl;
    for (int i=0; i<n; i++)
    {
        fr << M[i].v << " " << M[i].p << " " << M[i].g << endl;
    }
    fr << "GERIAUSI" << endl;
    for (int i=0; i<n; i++)
    {
        if (M[i].g == best_grade)
        {
            fr << M[i].v << " " << M[i].p << " " << M[i].g << endl;
        }
    }
    fr << "BLOGIAUSI" << endl;
    for (int i=n-1; i>=0; i--)
    {
        if (M[i].g == worst_grade)
        {
            fr << M[i].v << " " << M[i].p << " " << M[i].g << endl;
        }
    }
    fr.close();
}
