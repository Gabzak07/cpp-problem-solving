#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, string v[], double siluma[], double telefonas[], double vanduo[]);
void skaicuok_suma (int n, double siluma[], double telefonas[], double vanduo[], double &siluma_suma, double &telefonas_suma, double &vanduo_suma);
void atranka (int n, string v[], double telefonas[], double siluma[], double vanduo[], double suma_skola[]);
void rikiavimas (int n, string v[], double suma_skola[]);
void rasyk (int n, string v[], double suma_skola[], double siluma_suma, double telefonas_suma, double vanduo_suma);

int main()
{
    int n;
    string v[30];
    double siluma[30], telefonas[30], vanduo[30], siluma_suma = 0, telefonas_suma = 0, vanduo_suma = 0, suma_skola[30];
    skaityk (n, v, siluma, telefonas, vanduo);
    skaicuok_suma (n, siluma, telefonas, vanduo, siluma_suma, telefonas_suma, vanduo_suma);
    atranka (n, v, telefonas, siluma, vanduo, suma_skola);
    rikiavimas (n, v, suma_skola);
    rasyk (n, v, suma_skola, siluma_suma, telefonas_suma, vanduo_suma);
    return 0;
}

void skaityk (int &n, string v[], double siluma[], double telefonas[], double vanduo[])
{
    ifstream fd(FV);
    fd >> n;
    char s[16];
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        fd.get(s, 16);
        v[i] = s;
        fd >> siluma[i] >> telefonas[i] >> vanduo[i];
        fd.ignore(256, '\n');
    }
    fd.close();
}

void skaicuok_suma (int n, double siluma[], double telefonas[], double vanduo[], double &siluma_suma, double &telefonas_suma, double &vanduo_suma)
{
    for (int i=0; i<n; i++)
    {
        if (siluma[i] > 0)
        {
            siluma_suma = siluma_suma + siluma[i];
        }
        if (telefonas[i] > 0)
        {
            telefonas_suma = telefonas_suma + telefonas[i];
        }
        if (vanduo[i] > 0)
        {
            vanduo_suma = vanduo_suma + vanduo[i];
        }
    }
}

void atranka (int n, string v[], double telefonas[], double siluma[], double vanduo[], double suma_skola[])
{
    for (int i=0; i<n; i++)
    {
            suma_skola[i] = 0;
            if (siluma[i] > 0)
            {
                suma_skola[i] = suma_skola[i] + siluma[i];
            }
            if (telefonas[i] > 0)
            {
                suma_skola[i] = suma_skola[i] + telefonas[i];
            }
            if (vanduo[i] > 0)
            {
                suma_skola[i] = suma_skola[i] + vanduo[i];
            }
    }
}

void rikiavimas (int n, string v[], double suma_skola[])
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (suma_skola[i] > suma_skola[j])
            {
                swap (v[i], v[j]);
                swap (suma_skola[i], suma_skola[j]);
            }
        }
    }
}

void rasyk (int n, string v[], double suma_skola[], double siluma_suma, double telefonas_suma, double vanduo_suma)
{
    ofstream fr(FVR);
    fr << siluma_suma << endl;
    fr << telefonas_suma << endl;
    fr << vanduo_suma << endl;
    for (int i=0; i<n; i++)
    {
        if (suma_skola[i] > 0)
        {
            fr << v[i] << " " << suma_skola[i] << endl;
        }
    }
    fr.close();
}
