#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaitymas (int &n, int numeris[], double &m, double naud[]);
double maksimalus (int n, double naud[]);
double minimalus (int n, double naud[]);
void atranka (int n, int numeris[], int atrinkt[], int &b, double m, double naud[]);
void rasyk (double min, double max, int b, int atrinkt[]);

int main()
{
    int n, numeris[50], atrinkt[50], b = 0;
    double m, naud[50], min, max;
    skaitymas (n, numeris, m, naud);
    max = maksimalus (n, naud);
    min = minimalus (n, naud);
    atranka (n, numeris, atrinkt, b, m, naud);
    rasyk (min, max, b, atrinkt);
    return 0;
}

void skaitymas (int &n, int numeris[], double &m, double naud[])
{
    ifstream fd(FV);
    fd >> n >> m;
    for (int i=0; i<n; i++)
    {
        fd >> numeris[i] >> naud[i];
    }
    fd.close();
}

double maksimalus (int n, double naud[])
{
    double maxi = 0;
    for (int i=0; i<n; i++)
    {
        if (naud[i] > maxi)
        maxi = naud[i];
    }
    return maxi;
}

double minimalus (int n, double naud[])
{
    double mini = naud[0];
    for (int i=0; i<n; i++)
    {
        if (mini > naud[i])
            mini = naud[i];
    }
    return mini;
}

void atranka (int n, int numeris[], int atrinkt[], int &b, double m, double naud[])
{
    for (int i=0; i<n; i++)
    {
        if (naud[i] >= m)
        {
            atrinkt[b] = numeris[i];
            b++;
        }
    }
}

void rasyk (double min, double max, int b, int atrinkt[])
{
    ofstream fr(FVR);
    fr << min << " " << max << endl;
    for (int i=0; i<b; i++)
    {
        fr << atrinkt[i] << " ";
    }
    fr.close();
}
