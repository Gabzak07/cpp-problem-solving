#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";


void skaityk (int &n, string v[], double ugis[], int t[], int &p, int &k);
void daugiausias (int n, double ugis[], int t[], int &daug_t, double &daug_ugis);
void atranka (int n, int t[], int p, int k, int atr_t[], int &b, int daug_t, double ugis[], double atr_ugis[], double daug_ugis, string v[], string atr_v[]);
void rasyk (int b, string atr_v[], int atr_t[], double atr_ugis[]);

int main()
{
    int n, t[30], p, k, atr_t[30], b = 0, daug_t;
    double ugis[30], atr_ugis[30], daug_ugis;
    string v[30], atr_v[30];
    skaityk (n, v, ugis, t, p, k);
    daugiausias (n, ugis, t, daug_t, daug_ugis);
    atranka (n, t, p, k, atr_t, b, daug_t, ugis, atr_ugis, daug_ugis, v, atr_v);
    rasyk(b, atr_v, atr_t, atr_ugis);
    return 0;
}

void skaityk (int &n, string v[], double ugis[], int t[], int &p, int &k)
{
    ifstream fd(FV);
    fd >> n;
    char s[16];
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        fd.get(s, 16);
        v[i] = s;
        fd >> ugis[i] >> t[i];
        fd.ignore(256, '\n');
    }
    fd >> p >> k;
    fd.close();
}

void daugiausias (int n, double ugis[], int t[], int &daug_t, double &daug_ugis)
{
    daug_t = t[0];
    daug_ugis  = ugis[0];
    for (int i=0; i<n; i++)
    {
        if (daug_t < t[i])
        {
            daug_t = t[i];
        }
        if (daug_ugis < ugis[i])
        {
            daug_ugis = ugis[i];
        }
    }

}

void atranka (int n, int t[], int p, int k, int atr_t[], int &b, int daug_t, double ugis[], double atr_ugis[], double daug_ugis, string v[], string atr_v[])
{
    for (int i=0; i<n; i++)
    {
        if (ugis[i] >= daug_ugis*(100-p)/100 || t[i] >= (double)daug_t*(100-p)/100)
        {
            atr_ugis[b] = ugis[i];
            atr_v[b] = v[i];
            atr_t[b] = t[i];
            b++;
        }
    }
}

void rasyk (int b, string atr_v[], int atr_t[], double atr_ugis[])
{
    ofstream fr(FVR);
    fr << "-----------------------------" << endl;
    fr << "Vardas          Ugis     Taskai" << endl;
    fr << "------------------------------" << endl;
    for (int i=0; i<b; i++)
    {
        fr << atr_v[i] << " " << atr_ugis[i] << " " << atr_t[i] << endl;
    }
    fr.close();
}







