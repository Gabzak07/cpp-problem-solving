#include <fstream>
#include <iostream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &norma, int &atl, int nuv[]);
double vidurkis (int nuv[]);
void skaiciuok (int norma, int atl, int nuv[], int &pazeidzia_k, int &galut_atl, int &virsija_kiekis, int &nepasiekia_kiekis);
int labiausiai (int norma, int nuv[]);
void rasyk (double vid, int virsija_kiekis, int nepasiekia_kiekis, int pazeidzia_k, int lab_paz, int galut_atl);

int main()
{
    int norma, atl, nuv[20], virsija_km, nepasiekia_km, pazeidzia_k, galut_atl, virsija_kiekis = 0, nepasiekia_kiekis = 0, lab_paz;
    double vid;
    skaityk (norma, atl, nuv);
    vid = vidurkis (nuv);
    skaiciuok (norma, atl, nuv, pazeidzia_k, galut_atl, virsija_kiekis, nepasiekia_kiekis);
    lab_paz = labiausiai (norma, nuv);
    rasyk (vid, virsija_kiekis, nepasiekia_kiekis, pazeidzia_k, lab_paz, galut_atl);

    return 0;
}

void skaityk (int &norma, int &atl, int nuv[])
{
    ifstream fd(FV);
    fd >> norma >> atl;
    for (int i=0; i<20; i++)
    {
        fd >> nuv[i];
    }
    fd.close();
}

double vidurkis (int nuv[])
{
    int sum = 0;
    for (int i=0; i<20; i++)
    {
       sum = sum + nuv[i];
    }
    return (double) sum / 20;
}

void skaiciuok (int norma, int atl, int nuv[], int &pazeidzia_k, int &galut_atl, int &virsija_kiekis,
                int &nepasiekia_kiekis)
{
    double virsija_km = 0, nepasiekia_km = 0;
    for (int i=0; i<20; i++)
    {
        if (nuv[i] > norma )
        {
            virsija_kiekis++;
        }
        else nepasiekia_kiekis++;
        if (nuv[i] >= norma*1.2)
        {
            pazeidzia_k++;
            virsija_km = virsija_km + (double) nuv[i] - norma*1.2;
        }
        else if (nuv[i] <= norma*0.8)
        {
            pazeidzia_k++;
            nepasiekia_km = nepasiekia_km + (double) norma*0.8 - nuv[i];
        }
    }
    galut_atl = atl - (int)virsija_km - (int)nepasiekia_km;
}

int labiausiai (int norma, int nuv[])
{
    int maxi = 0;
    double didz_skirt = 0;
    for (int i=0; i<20; i++)
    {
        if (nuv[i] >= norma*1.2 && didz_skirt < nuv[i] - norma*1.2)
        {
            didz_skirt = (double) nuv[i] - norma*1.2;
            maxi = i;
        }
        else if (nuv[i] <= norma*0.8 && didz_skirt < nuv[i] - norma*1.2)
        {
            didz_skirt = norma*0.8-(double) nuv[i];
            maxi = i;
        }
    }
    return maxi;
}

void rasyk (double vid, int virsija_kiekis, int nepasiekia_kiekis, int pazeidzia_k, int lab_paz, int galut_atl)
{
    ofstream fr(FVR);
    fr << vid << endl;
    fr << virsija_kiekis << endl;
    fr << nepasiekia_kiekis << endl;
    fr << pazeidzia_k << endl;
    fr << lab_paz << endl;
    fr << galut_atl << endl;
    fr.close();
}
