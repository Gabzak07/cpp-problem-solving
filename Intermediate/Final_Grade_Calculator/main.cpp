#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const char FV[]= "U1.txt";
const char FVR[]= "U1rez.txt";

struct Mok
{
    char zyme;
    int paz[7], kiekis_daugiau_5 = 0;
    double paz_galutinis = 0; // paz_galutinis - sudauginti pazymiai su koeficentais;
};

struct Naujas
{
    int paz, kiekis = 0;
};

void skaityk (int &m, double koef[], Mok mokiniai[], Naujas naujas_sarasas[]);

//void skaiciuok (int m, double koef[], Mok mokiniai[]);

int skaiciuok_mokiniui (double koef[], Mok mokiniai);

void skaiciuok2(int m, Mok mokiniai[], int &b, Naujas naujas_sarasas[]);
int rask (int b, Naujas naujas_sarasas[], int paz);
void rasyk (int b, Naujas naujas_sarasas[]);

int main()
{
    int m, b = 0; // kintamasis b eina kartu su naujas_sarasas;
    double koef[7];
    Mok mokiniai[30];
    Naujas naujas_sarasas[30];
    skaityk (m, koef, mokiniai, naujas_sarasas);

    for (int i=0; i<m; i++)
    {
            mokiniai[i].paz_galutinis = skaiciuok_mokiniui(koef, mokiniai[i]);
    }

    //skaiciuok (m, koef, mokiniai);
    skaiciuok2(m, mokiniai, b, naujas_sarasas);
    rasyk (b, naujas_sarasas);

    return 0;
}

void skaityk (int &m, double koef[], Mok mokiniai[], Naujas naujas_sarasas[])
{
    ifstream fd(FV);
    fd >> m;
    for (int i=0; i<7; i++)
    {
        fd >> koef[i];
    }
    for (int i=0; i<m; i++)
    {
        fd >> mokiniai[i].zyme;
        for (int j=0; j<7; j++)
        {
            fd >> mokiniai[i].paz[j];
            if (mokiniai[i].paz[j] >=5)
            {
                mokiniai[i].kiekis_daugiau_5++;
            }
        }
    }
    fd.close();
}

int skaiciuok_mokiniui (double koef[], Mok mokiniai) // I VAR.
{
    double suma = 0;

    for (int i=0; i<7; i++)
    {
        suma += mokiniai.paz[i] * koef[i];
    }

    if (mokiniai.kiekis_daugiau_5 == 7 && mokiniai.zyme == 'A')
            {
                suma++;
            }

    suma = round(suma);

    if ( suma >=10)
            {
                suma = 10;
            }

    return suma;
}

//void skaiciuok (int m, double koef[], Mok mokiniai[])     // II VAR.
//{
    //for (int i=0; i<m; i++)
       // {
           // for (int j=0; j<7; j++)
            //{
               // mokiniai[i].paz_galutinis += mokiniai[i].paz[j] * koef[j];
            //}
           // if (mokiniai[i].kiekis_daugiau_5 == 7 && mokiniai[i].zyme == 'A')
            //{
              //  mokiniai[i].paz_galutinis++;
           // }

            //mokiniai[i].paz_galutinis = round(mokiniai[i].paz_galutinis);

            //if ( mokiniai[i].paz_galutinis >=10)
            //{
               // mokiniai[i].paz_galutinis = 10;
            //}
        //}
//}

void skaiciuok2(int m, Mok mokiniai[], int &b, Naujas naujas_sarasas[])
{
    naujas_sarasas[0].paz = mokiniai[0].paz_galutinis;
    naujas_sarasas[0].kiekis = 1;
    b = 1;
    int laik;
    for (int i=1; i<m; i++)
    {
        laik = rask (b, naujas_sarasas, mokiniai[i].paz_galutinis);
        if (laik == -1)
        {
            naujas_sarasas[b].paz = mokiniai[i].paz_galutinis;
            naujas_sarasas[b].kiekis = 1;
            b++;
        }
        else
        {
            naujas_sarasas[laik].kiekis++;
        }
    }
}

int rask (int b, Naujas naujas_sarasas[], int paz)
{
    for (int i=0; i<b; i++)
    {
        if (naujas_sarasas[i].paz == paz)
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
        fr << naujas_sarasas[i].paz << " " << naujas_sarasas[i].kiekis << endl;
    }
    fr.close();
}
