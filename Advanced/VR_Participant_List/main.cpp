#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, string v[], int atsisake[], int &nauji_k, string naujas[], int &ats);
void rasyk (int n, string v[], string zodis);
void rikiavimas (int n, string v[]);
void salinimas (int &n, string v[], int ats, int atsisake[]);
void iterpimas (int &n, string v[], int nauji_k, string naujas[]);

int main()
{
    ofstream fr(FVR);
    fr.close();
    int n, atsisake[30], nauji_k, ats = 0;
    string v[30], naujas[30];
    skaityk (n, v, atsisake, nauji_k, naujas, ats);
    rikiavimas (n, v);
    rasyk (n, v, "Pradinis sarasas: ");
    salinimas (n, v, ats, atsisake);
    rasyk (n, v, "Sarasas pasalinus atsisakiusius salyvauti: ");
    iterpimas (n, v, nauji_k, naujas);
    rasyk (n, v, "Atnaujintas sarasas: ");
    return 0;
}

void skaityk (int &n, string v[], int atsisake[], int &nauji_k, string naujas[], int &ats)
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> v[i];
    }
    fd >> atsisake[ats];
    while (atsisake[ats] != 0)
    {
        ats++;
        fd >> atsisake[ats];
    }
    fd >> nauji_k;
    for (int i=0; i<nauji_k; i++)
    {
        fd >> naujas[i];
    }
    fd.close();
}

void rasyk (int n, string v[], string zodis)
{
    ofstream fr(FVR, ios::app);
    fr << zodis << endl;
    for (int i=0; i<n; i++)
    {
        fr << v[i] << endl;
    }
    fr.close();
}

void rikiavimas (int n, string v[])
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (v[i] > v[j])
            {
                swap (v[i], v[j]);
            }
        }
    }
}
void salinimas (int &n, string v[], int ats, int atsisake[])
{
    int laik[30];
    for (int i=0; i<n; i++)
    {
        laik[i] = i+1;
    }
    for (int i=0; i<ats; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (laik[j] == atsisake[i])
            {
                for (int k=j; k<n-1; k++)
                {
                    laik[k] = laik[k+1];
                    v[k] = v[k+1];
                }
                n--;
                j--;
            }
        }
    }
}

void iterpimas (int &n, string v[], int nauji_k, string naujas[])
{
    for (int i=0; i<nauji_k; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (naujas[i] < v[j])
            {
                cout << j << endl;
                for (int k=n-1; k>=j; k--)
                {
                    v[k+1] = v[k];
                }
                v[j] = naujas[i];
                n++;
                break;
            }
        }
    }
}
