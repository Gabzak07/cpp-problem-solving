#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";


void skaityk (long long biudzetas[], int &n, double reitingas[]);
int reit (int n, double reitingas[]);
int surasti_biudzeta (int n, long long biudzetas[]);
void surasti_biudzeta_ir_reitinga (int n, long long biudzetas[], double reitingas[], int &m, int atrinkti_filmai[] );
void rasyk (int did_reitingas, int maz_biudzetas, int m, int atrinkti_filmai[]);


int main()
{
    long long biudzetas[100], maz_biudzetas;
    int n, did_reitingas, m = 0, atrinkti_filmai[100];
    double reitingas[100];
    skaityk (biudzetas, n, reitingas);
    did_reitingas = reit (n, reitingas);
    maz_biudzetas = surasti_biudzeta (n, biudzetas);
    surasti_biudzeta_ir_reitinga (n, biudzetas, reitingas, m, atrinkti_filmai);
    rasyk (did_reitingas, maz_biudzetas, m, atrinkti_filmai);
    return 0;
}

void skaityk (long long biudzetas[], int &n, double reitingas[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> biudzetas[i] >> reitingas[i];
    }
    fd.close();
}

int reit (int n, double reitingas[])
{
    double maxi = reitingas[0];
    int vieta = 1;
    for (int i=0; i<n; i++)
    {
        if (reitingas[i] > maxi)
        {
            maxi = reitingas[i];
            vieta = i + 1;
        }
    }
    return vieta;
}

int surasti_biudzeta (int n, long long biudzetas[])
{
    long long mini = biudzetas[0];
    int vieta = 1;
    for (int i=0; i<n; i++)
    {
        if (biudzetas[i] <= mini )
        {
            mini = biudzetas[i];
            vieta = i + 1;
        }
    }
    return vieta;
}

void surasti_biudzeta_ir_reitinga (int n, long long biudzetas[], double reitingas[], int &m, int atrinkti_filmai[] )
{
    for (int i=0; i<n; i++)
    {
        if (biudzetas[i] < 100000000 && reitingas[i] > 8.5)
        {
            atrinkti_filmai[m] = i + 1;
            m = m + 1;
        }
    }
}

void rasyk (int did_reitingas, int maz_biudzetas, int m, int atrinkti_filmai[])
{
    ofstream fr(FVR);
    fr << did_reitingas << endl;
    fr << maz_biudzetas << endl;
    for (int i=0; i<m; i++)
    {
        fr << atrinkti_filmai[i] << " ";
    }
    fr.close();
}
