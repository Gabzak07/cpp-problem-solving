#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";
const int Cn = 53;

void skaityk (int &n, int pirkta[], int laimeta[]);
int skaiciuok (int n, int masyvas[]);
int didziausias (int n, int laimeta[]);
int biletai (int viso_isleido);
void rasyk (int viso_isleido, int viso_laimejo, int didziausias_laimejimas, int biletu_kiekis, int pelnas);

int main()
{
    int n, pirkta[Cn], laimeta[Cn], viso_isleido, viso_laimejo, didziausias_laimejimas, biletu_kiekis, pelnas;
    skaityk (n, pirkta, laimeta);
    viso_isleido = skaiciuok(n, pirkta);
    viso_laimejo = skaiciuok(n, laimeta);
    didziausias_laimejimas = didziausias (n, laimeta);
    biletu_kiekis = biletai (viso_isleido);
    pelnas = viso_laimejo - viso_isleido;
    rasyk (viso_isleido, viso_laimejo, didziausias_laimejimas, biletu_kiekis, pelnas);

    return 0;
}

void skaityk (int &n, int pirkta[], int laimeta[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> pirkta[i] >> laimeta[i];
    }
    fd.close();
}

int skaiciuok (int n, int masyvas[])
{
    int suma = 0;
    for (int i=0 ; i<n; i++)
    {
        suma = suma + masyvas[i];
    }
    return suma;
}

int didziausias (int n, int laimeta[])
{
    int maxi = 0;
    for (int i=0; i<n; i++)
    {
        if (laimeta[i] > maxi)
        {
            maxi = laimeta[i];
        }
    }
    return maxi;
}

int biletai (int viso_isleido)
{
    int kiekis;
    return kiekis = viso_isleido/2;
}

void rasyk (int viso_isleido, int viso_laimejo, int didziausias_laimejimas, int biletu_kiekis, int pelnas)
{
    ofstream fr(FVR);
    fr << viso_isleido << " Lt  " << viso_laimejo << " Lt " << endl;
    fr << "Didziausias laimejimas " << didziausias_laimejimas <<  " Lt " << endl;
    fr << "Petras pirko " << biletu_kiekis <<  " bilietus" << endl;
    fr << "Pelnas " << pelnas << " Lt " << endl;
    fr.close();
}
