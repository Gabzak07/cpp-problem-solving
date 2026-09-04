#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "U1.txt";
const char FVR[]= "U1rez.txt";

struct Mokiniai
{
    string var; // var - variantas;
    int taskai[10], suma_t = 0;
};

struct Naujas
{
    string var;
    int mok_k = 0, suma_vieno[30], islaike_k = 0, maxi_sk = 0; // islaike_k - kiek mokniu islaike; maxi_sk- maksimalus, mok_k - mokiniu kiekis
};

void skaityk (int &m, Mokiniai Mok[]);
int rask (Naujas Sarasas[], int b, string var);
void skaiciuok (int m, Mokiniai Mok[], Naujas Sarasas[], int &b);
void rikiavimas (int b, Naujas Sarasas[]);
void rasyk (int b, Naujas Sarasas[], string sakinys);


int main()
{
    ofstream fr(FVR);
    fr.close();
    int m, b = 0; // kintamasis b eina kartu su ,,Naujas Sarasas''
    Mokiniai Mok[30];
    Naujas Sarasas[30];
    skaityk(m, Mok);
    skaiciuok (m, Mok, Sarasas, b);
    for (int i=0; i<b; i++)
    {
        cout << Sarasas[i].var << " " << Sarasas[i].mok_k << " " << Sarasas[i].islaike_k << " " << Sarasas[i].maxi_sk << endl;
    }
    rasyk (b, Sarasas, "Gautas sarasas:");
    rikiavimas(b, Sarasas);
    rasyk (b, Sarasas, "Surikiuotas sarasas:");

    return 0;
}

void skaityk (int &m, Mokiniai Mok[])
{
    ifstream fd(FV);
    char eil[7];
    fd >> m;
    fd.ignore(256, '\n');
    for (int i=0; i<m; i++)
    {
        fd.get(eil, 7);
        Mok[i].var = eil;
        for (int j=0; j<10; j++)
        {
            fd >> Mok[i].taskai[j];
            //cout << Mok[i].taskai[j] << " ";
        }
        //cout << endl;
        fd.ignore(256, '\n');
    }
    fd.close();
}

void skaiciuok (int m, Mokiniai Mok[], Naujas Sarasas[], int &b)
{
    int laik;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<10; j++)
        {
            Mok[i].suma_t += Mok[i].taskai[j];

        }
       // cout << Mok[i].suma_t << endl;
    }

    for (int i=0; i<m; i++)
    {
        laik = rask (Sarasas, b, Mok[i].var);
        if (laik == -1)
        {
            Sarasas[b].var = Mok[i].var;
            Sarasas[b].suma_vieno[Sarasas[b].mok_k] = Mok[i].suma_t;
            //cout << Sarasas[b].suma_vieno[Sarasas[b].mok_k] << endl;
            Sarasas[b].mok_k++;
            b++;
        }
        else
        {
            Sarasas[laik].suma_vieno[Sarasas[laik].mok_k] = Mok[i].suma_t;

            //cout << Sarasas[laik].suma_vieno[Sarasas[laik].mok_k] << endl;
            //cout << Sarasas[laik].mok_k << endl;
            //cout << Mok[i].suma_t << endl;
            Sarasas[laik].mok_k++;
        }
    }


    for (int i=0; i<b; i++)
    {
        int maxi = 0;
        for (int j=0; j<Sarasas[i].mok_k; j++)
        {
            //cout << Sarasas[i].suma_vieno[j] << endl;
            if (Sarasas[i].suma_vieno[j] >= 15)
            {
                Sarasas[i].islaike_k++;
            }

            if (Sarasas[i].suma_vieno[j] > maxi)
            {
                maxi = Sarasas[i].suma_vieno[j];
                //cout << maxi << endl;
                Sarasas[i].maxi_sk = maxi;
            }
        }

    }
}

int rask (Naujas Sarasas[], int b, string var)
{
    for (int i=0; i<b; i++)
    {
        if (Sarasas[i].var == var)
        {
            return i;
        }
    }
    return -1;
}

void rikiavimas (int b, Naujas Sarasas[])
{
    for (int i=0; i<b-1; i++)
    {
        for (int j=i+1; j<b; j++)
        {
            if (Sarasas[i].islaike_k > Sarasas[j].islaike_k)
            {
                swap (Sarasas[i], Sarasas[j]);
            }
            else if (Sarasas[i].islaike_k == Sarasas[j].islaike_k && Sarasas[i].maxi_sk < Sarasas[j].maxi_sk)
            {
                swap (Sarasas[i], Sarasas[j]);
            }
        }
    }
}

void rasyk (int b, Naujas Sarasas[], string sakinys)
{
    ofstream fr(FVR, ios::app);
    fr << sakinys << endl;
    for (int i=0; i<b; i++)
    {
        fr << Sarasas[i].var << " " << Sarasas[i].mok_k << " " << ((double)Sarasas[i].islaike_k / Sarasas[i].mok_k) * 100 << "% " << Sarasas[i].maxi_sk << endl;
    }
    fr.close();
}
