#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const char FV[]= "U2.txt";
const char FVR[]= "U2rez.txt";

struct Dalyviai
{
    string v;
    int k, pradzia_val[5], pradzia_min[5], pabaiga_val[5], pabaiga_min[5], pradzia_min_T, pabaiga_min_T, sugaista_laiko_T, kiekis_T, proc_T;
    char ivert[5];
};

void skaityk (int &d, int &u, Dalyviai dalyviai[]);
void skaiciuok (int d, int u, Dalyviai dalyviai[], int &maxi);
void rikiavimas (int d, Dalyviai dalyviai[]);
void rasyk (int n, int maxi, Dalyviai dalyviai[]);

int main()
{
    int d, u, maxi = 0;
    Dalyviai dalyviai[15];
    skaityk (d, u, dalyviai);
    skaiciuok(d, u, dalyviai, maxi);
    rikiavimas (d, dalyviai);
    rasyk (d, maxi, dalyviai);
    for (int i=0; i<d; i++)
    {
        cout << dalyviai[i].kiekis_T << " ";
    }
    return 0;
}

void skaityk (int &d, int &u, Dalyviai dalyviai[])
{
    ifstream fd(FV);
    char eil[13];
    fd >> d >> u;
    fd.ignore(256, '\n');
    for (int i=0; i<d; i++)
    {
        fd.get(eil, 13);
        dalyviai[i].v = eil;
        fd >> dalyviai[i].k;
        for (int j=0; j<dalyviai[i].k; j++)
        {
            fd >> dalyviai[i].pradzia_val[j] >> dalyviai[i].pradzia_min[j] >> dalyviai[i].pabaiga_val[j] >> dalyviai[i].pabaiga_min[j] >> dalyviai[i].ivert[j];
            //cout << dalyviai[i].pradzia_val[j] << " " << dalyviai[i].pradzia_min[j] << " " << dalyviai[i].pabaiga_val[j] << " " << dalyviai[i].pabaiga_min[j] << " "
            //<< dalyviai[i].ivert[j] << endl;
        }
        fd.ignore(256, '\n');
    }
    fd.close();
}

void skaiciuok (int d, int u, Dalyviai dalyviai[], int &maxi)
{
    for (int i=0; i<d; i++)
    {
        dalyviai[i].kiekis_T = 0;
        //cout << dalyviai[i].kiekis_T << endl;
        dalyviai[i].sugaista_laiko_T = 0;
        //dalyviai[i].pradzia_min_T = 0;
        //dalyviai[i].pabaiga_min_T = 0;
    }

    for (int i=0; i<d; i++)
    {
        for (int j=0; j<dalyviai[i].k; j++)
        {
            if (dalyviai[i].ivert[j] == 'T')
            {
                dalyviai[i].kiekis_T++;
                //cout << dalyviai[i].kiekis_T << endl;
                dalyviai[i].sugaista_laiko_T += (dalyviai[i].pabaiga_val[j] * 60 + dalyviai[i].pabaiga_min[j]) - (dalyviai[i].pradzia_val[j] * 60 + dalyviai[i].pradzia_min[j]);
                //dalyviai[i].pradzia_min_T += dalyviai[i].pradzia_val[j] * 60 + dalyviai[i].pradzia_min[j];
                //dalyviai[i].pabaiga_min_T += dalyviai[i].pabaiga_val[j] * 60 + dalyviai[i].pabaiga_min[j];
            }
        }
    }

    for (int i=0; i<d; i++)
    {
        dalyviai[i].proc_T = round ( (double) dalyviai[i].kiekis_T / u * 100); // 1. proc t - int or double? 2. cia geriau proc_T skaiciuoti negu tame virsutiniame?
        if (dalyviai[i].kiekis_T > maxi)
        {
            maxi = dalyviai[i].kiekis_T;
        }
    }
}

void rikiavimas (int d, Dalyviai dalyviai[])
{
    for (int i=0; i<d-1; i++)
    {
        for (int j=i+1; j<d; j++)
        {
            if (dalyviai[i].proc_T < dalyviai[j].proc_T )
            {
                swap (dalyviai[i], dalyviai[j]);
            }
            else if (dalyviai[i].proc_T == dalyviai[j].proc_T && dalyviai[i].sugaista_laiko_T > dalyviai[j].sugaista_laiko_T)
            {
                swap (dalyviai[i], dalyviai[j]);
            }
        }
    }
}

void rasyk (int d, int maxi, Dalyviai dalyviai[])
{
    ofstream fr(FVR);
    fr << maxi << endl;
    for (int i=0; i<d; i++)
    {
        if (dalyviai[i].kiekis_T > 0)
        {
            fr << dalyviai[i].v << " " << dalyviai[i].proc_T << " % " << dalyviai[i].sugaista_laiko_T << endl;
        }
    }
    fr.close();
}

