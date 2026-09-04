#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, char d[], double t[]);
void atranka (int n, char d[], double t[], double atr_liet[], int &liet_k, char raide);
void skaiciuok (double atr_liet[], int liet_k, double &vid_liet, int &virsija_liet);
void rasyk (int liet_k, int saul_k, int aps_k, int virsija_liet, int virsija_saul, int virsija_aps, double vid_liet,
            double vid_saul, double vid_aps, double atr_liet[], double atr_saul[], double atr_aps[]);


int main()
{
    int n, liet_k = 0, saul_k = 0, aps_k = 0, virsija_liet = 0, virsija_saul = 0, virsija_aps = 0;
    char d[30];
    double t[30], vid_liet, vid_saul, vid_aps, atr_liet[30], atr_saul[30], atr_aps[30];
    skaityk (n, d, t);
    atranka (n, d, t, atr_liet, liet_k, 'L');
    atranka (n, d, t, atr_saul, saul_k, 'S');
    atranka (n, d, t, atr_aps, aps_k, 'A');
    skaiciuok (atr_liet, liet_k, vid_liet, virsija_liet);
    skaiciuok (atr_saul, saul_k, vid_saul, virsija_saul);
    skaiciuok (atr_aps, aps_k, vid_aps, virsija_aps);
    rasyk (liet_k, saul_k, aps_k, virsija_liet, virsija_saul, virsija_aps, vid_liet, vid_saul, vid_aps, atr_liet, atr_saul, atr_aps);
    return 0;
}

void skaityk (int &n, char d[], double t[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> d[i] >> t[i];
    }
    fd.close();
}

void atranka (int n, char d[], double t[], double atr_liet[], int &liet_k, char raide)
{
    for (int i=0; i<n; i++)
    {
        if (d[i] == raide)
        {
            atr_liet[liet_k] = t[i];
            liet_k++;
        }
    }
}

void skaiciuok (double atr_liet[], int liet_k, double &vid_liet, int &virsija_liet)
{
    double suma = 0;
    for (int i=0; i<liet_k; i++)
    {
       suma = suma + atr_liet[i];
    }
    vid_liet = suma / liet_k;
    for (int i=0; i<liet_k; i++)
    {
        if (atr_liet[i] > vid_liet)
        {
            virsija_liet++;
        }
    }
}

void rasyk (int liet_k, int saul_k, int aps_k, int virsija_liet, int virsija_saul, int virsija_aps, double vid_liet,
            double vid_saul, double vid_aps, double atr_liet[], double atr_saul[], double atr_aps[])
{
    ofstream fr(FVR);
    fr << " LIETINGOS: " << endl;
    fr << liet_k << " ";
    for (int i=0; i<liet_k; i++)
    {
        fr << atr_liet[i] << " ";
    }
    fr << endl;
    fr << vid_liet << endl;
    fr << virsija_liet << endl;
    fr << "SAULETOS: " << endl;
    fr << saul_k << endl;
    for (int i=0; i<saul_k; i++)
    {
        fr << atr_saul[i] << " ";
    }
    fr << endl;
    fr << vid_saul << endl;
    fr << virsija_saul << endl;
    fr << "APSINIAUKUSIOS: " << endl;
    fr << aps_k << endl;
    for (int i=0; i<aps_k; i++)
    {
        fr << atr_aps[i] << " ";
    }
    fr << vid_aps << endl;
    fr << virsija_aps << endl;
    fr.close();
}
