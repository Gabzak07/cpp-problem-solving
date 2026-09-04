#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int ob_k[], int k_k[], double miltai_g[], double cukrus_g[], double laikas_val[], double temp[], double &v, double &t);
int sum (int n, int kiekis[]);
double vidurkis (int n, double kiekis[]);
int keli (int n, double k[], double v);
void salinimas (int &n, int ob_k[], int k_k[], double miltai_g[], double cukrus_g[], double laikas_val[], double temp[]);
void rasyk (int n, int ob_k[], int k_k[], double miltai_g[], double cukrus_g[], double laikas_val[], double temp[], int suma_o,
            int suma_k, double vidurkis_m, double vidurkis_c, int daugiau_nei_v, int daugiau_nei_t);
int main()
{
    int n, ob_k[30], k_k[30], daugiau_nei_v, daugiau_nei_t, suma_o, suma_k;
    double miltai_g[30], cukrus_g[30], laikas_val[30], temp[30], v, t, vidurkis_m, vidurkis_c;
    skaityk (n, ob_k, k_k, miltai_g, cukrus_g, laikas_val, temp, v, t);
    suma_o = sum (n, ob_k);
    suma_k = sum (n, k_k);
    //cout << suma_o << " " << suma_k << endl;
    vidurkis_m = vidurkis (n, miltai_g);
    vidurkis_c = vidurkis (n, cukrus_g);
    daugiau_nei_v = keli (n, laikas_val, v);
    daugiau_nei_t = keli (n, temp, t);
    salinimas (n, ob_k, k_k, miltai_g, cukrus_g, laikas_val, temp);
    rasyk (n, ob_k, k_k, miltai_g, cukrus_g, laikas_val, temp, suma_o, suma_k, vidurkis_m, vidurkis_c, daugiau_nei_v, daugiau_nei_t);
    return 0;
}

void skaityk (int &n, int ob_k[], int k_k[], double miltai_g[], double cukrus_g[], double laikas_val[], double temp[], double &v, double &t)
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> ob_k[i] >> k_k[i] >> miltai_g[i] >> cukrus_g[i] >> laikas_val[i] >> temp[i];
    }
    cin >> v >> t;
    fd.close();
}

int sum (int n, int kiekis[])
{
    int suma = 0;
    for (int i=0; i<n; i++)
    {
        suma = suma + kiekis[i];
        cout << kiekis[i] << endl;
    }
    //cout << suma << endl;
    return suma;
}

double vidurkis (int n, double kiekis[])
{
    double sum = 0;
    for (int i=0; i<n; i++)
    {
        sum = sum + kiekis[i];
    }
    return sum / n;
}

int keli (int n, double k[], double v)
{
    int kiekis = 0;
    for (int i=0; i<n; i++)
    {
        if (k[i] >= v)
        {
            kiekis++;
        }
    }
    return kiekis;
}

void salinimas (int &n, int ob_k[], int k_k[], double miltai_g[], double cukrus_g[], double laikas_val[], double temp[])
{
    for (int i=0; i<n; i++)
    {
        if (temp[i] >= 200)
        {
            for (int j=i; j<n-1; j++)
            {
                temp[j] = temp[j+1];
                laikas_val[j] = laikas_val[j+1];
                cukrus_g[j] = cukrus_g[j+1];
                miltai_g[j] = miltai_g[j+1];
                k_k[j] = k_k[j+1];
                ob_k[j] = ob_k[j+1];
            }
            n--;
            i--;
        }
    }
}

void rasyk (int n, int ob_k[], int k_k[], double miltai_g[], double cukrus_g[], double laikas_val[], double temp[], int suma_o,
            int suma_k, double vidurkis_m, double vidurkis_c, int daugiau_nei_v, int daugiau_nei_t)
{
    ofstream fr(FVR);
    fr << suma_o << " " << suma_k << endl;
    fr << fixed << setprecision (1) << vidurkis_m << " " << fixed << setprecision (1) << vidurkis_c << endl;
    fr << daugiau_nei_v << endl;
    fr << daugiau_nei_t << endl;
    for (int i=0; i<n; i++)
    {
        fr << ob_k[i] << " " << k_k[i] << " " << fixed << setprecision (1) << miltai_g[i] << " " << fixed << setprecision (1) << cukrus_g[i] << " " << laikas_val[i] << " " << fixed << setprecision (1) << temp[i] << endl;

    }
    fr.close();
}
