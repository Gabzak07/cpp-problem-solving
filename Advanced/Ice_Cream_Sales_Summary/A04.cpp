#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.csv";
const char FVR[]= "Rezultatai.txt";

struct Ledai
{
    string pav; // pav - pavadinimas
    int k; // suvalgytu liedu kiekis
    double suma, bendra_suma; // suma - vienos porcijos kaina, o bendra_suma - bendra ledu kaina;
};


void skaityk (Ledai Duom[], int &n);
void skaiciuok (int n, Ledai Duom[], Ledai Rez[], int &b);
int rask (int b, Ledai Rez[], string ledai);
void rikiavimas (Ledai Rez[], int b);
void rasyk (Ledai Rez[], int b);


int main()
{

    Ledai Duom[30], Rez[30];
    int n = 0, b = 0;
    skaityk (Duom, n);
    skaiciuok (n, Duom, Rez, b);
    rikiavimas (Rez, b);
    rasyk (Rez, b);

    return 0;
}

void skaityk (Ledai Duom[], int &n)
{
    string laik;
    ifstream fd(FV);
    while (!fd.eof())
    {
    getline(fd, Duom[n].pav, ';');
    getline(fd, laik, ';');
    Duom[n].k = stoi (laik);
    getline(fd, laik);
    Duom[n].suma = stod (laik);
    n++;
    }
    fd.close();
}

void skaiciuok (int n, Ledai Duom[], Ledai Rez[], int &b)
{
    int laik;
    for (int i=0; i<n; i++)
    {
        laik = rask (b, Rez, Duom[i].pav);
        if (laik == -1)
        {
            Rez[b].pav = Duom[i].pav;
            Rez[b].bendra_suma = Duom[i].k * Duom[i].suma;
            b++;
        }
        else
        {
            Rez[laik].bendra_suma += Duom[i].k * Duom[i].suma;
        }
    }
}

int rask (int b, Ledai Rez[], string ledai)
{
    for (int i=0; i<b; i++)
    {
        if (Rez[i].pav == ledai)
        {
            return i;
        }
    }
    return -1;
}

void rikiavimas (Ledai Rez[], int b)
{
    for (int i=0; i<b-1; i++)
    {
        for (int j=i+1; j<b; j++)
        {
            if (Rez[i].bendra_suma < Rez[j].bendra_suma)
            {
                swap (Rez[i], Rez[j]);
            }
            else if(Rez[i].bendra_suma == Rez[j].bendra_suma && Rez[i].pav > Rez[j].pav)
            {
                swap (Rez[i], Rez[j]);
            }
        }
    }
}

void rasyk (Ledai Rez[], int b)
{
    ofstream fr(FVR);
    for (int i=0; i<b; i++)
    {
        fr << Rez[i].pav << " " << Rez[i].bendra_suma << endl;
    }
    fr.close();
}
