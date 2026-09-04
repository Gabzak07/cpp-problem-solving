#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "U1.txt";
const char FVR[]= "U1rez.txt";

struct Dalyviai
{
    int klase, z_ilgis, z_skaicius[7], kiekis_t = 0; //z_ilgis - zingsnio ilgis; z_skaicius - zingsniu skaicius; kiekis_t - kiek dienu is 7 buvo ivesti duomenys;

};

struct Naujas
{
    int klase, kiekis_mok_viso_7; //kiekis_viso_7 - reiskia, kiek mokiniu vienos klases buvo ivede duomenis visas 7 dienas;
    double nueitas_ats_km = 0;
};

void skaityk (int &m, Dalyviai sarasas[]);
int rask (int b, Naujas naujas_sarasas[], int klase);
void skaiciuok (int m, Dalyviai sarasas[], Naujas naujas_sarasas[], int &b);
void rasyk (int b, Naujas naujas_sarasas[]);

int main()
{
    int m, b = 0; //kintamasis ,,b'' eina kartu su ,,naujas_sarasas''
    Dalyviai sarasas[50];
    Naujas naujas_sarasas[50];
    skaityk (m, sarasas);
    skaiciuok (m, sarasas, naujas_sarasas, b);
    rasyk (b, naujas_sarasas);

    return 0;
}

void skaityk (int &m, Dalyviai sarasas[])
{
    ifstream fd(FV);
    fd >> m;
    for (int i=0; i<m; i++)
    {
        fd >> sarasas[i].klase >> sarasas[i].z_ilgis;
        for (int j=0; j<7; j++)
        {
            fd >> sarasas[i].z_skaicius[j];
            if (sarasas[i].z_skaicius[j] > 0)
            {
                sarasas[i].kiekis_t++;
            }
        }
    }
    fd.close();
}

void skaiciuok (int m, Dalyviai sarasas[], Naujas naujas_sarasas[], int &b)
{
    int laik;
    for (int i=0; i<m; i++)
    {
            if (sarasas[i].kiekis_t == 7)
            {
                laik = rask (b, naujas_sarasas, sarasas[i].klase);
                if (laik == -1)
                {
                    for (int j=0; j<7; j++)
                    {
                        naujas_sarasas[b].nueitas_ats_km += ((double) sarasas[i].z_ilgis * sarasas[i].z_skaicius[j]) / 100000;
                    }
                    naujas_sarasas[b].klase = sarasas[i].klase;
                    naujas_sarasas[b].kiekis_mok_viso_7 = 1;
                    b++;
                }
                else
                {
                    for (int j=0; j<7; j++)
                    {
                        naujas_sarasas[laik].nueitas_ats_km += ((double) sarasas[i].z_ilgis * sarasas[i].z_skaicius[j]) / 100000;
                    }
                    naujas_sarasas[laik].kiekis_mok_viso_7++;
                }
            }
    }
}

int rask (int b, Naujas naujas_sarasas[], int klase)
{
    for (int i=0; i<b; i++)
    {
        if (naujas_sarasas[i].klase == klase)
        {
            return i;
        }
    }
    return -1;
}

void rasyk (int b, Naujas naujas_sarasas[])
{
    ofstream fr(FVR);
    for (int i=0; i<b; i++)
    {
        fr << fixed << naujas_sarasas[i].klase << " " << naujas_sarasas[i].kiekis_mok_viso_7 << " " << setprecision(2) << naujas_sarasas[i].nueitas_ats_km << endl;
    }
    fr.close();
}
