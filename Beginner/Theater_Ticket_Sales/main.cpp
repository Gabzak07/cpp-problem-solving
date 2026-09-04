#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";


void skaityk (int &n, int vietu[]);
void skaiciuok (int n, int vietu[], int &pinigu_suma, double &vidurkis);
void rasyk (int pinigu_suma, double vidurkis);

int main()
{
    int n, vietu[20], pinigu_suma = 0;
    double vidurkis;
    skaityk (n, vietu);
    skaiciuok (n, vietu, pinigu_suma, vidurkis);
    rasyk (pinigu_suma, vidurkis);
    return 0;
}

void skaityk (int &n, int vietu[])
{
    ifstream fd(FV);
    int v, k;
    fd >> n >> v;
    for (int i=0; i<n; i++)
    {
        vietu[i] = 0;
        for (int j=0; j<v; j++)
        {
            fd >> k;
            if (k==1)
            {
                vietu[i]++;
            }
        }
    }
    fd.close();
}

void skaiciuok (int n, int vietu[], int &pinigu_suma, double &vidurkis)
{
    int kiekis = 0;
    for (int i=0; i<n; i++)
    {
        kiekis = kiekis + vietu[i];
        if (i==0 || i==1)
        {
           pinigu_suma = pinigu_suma + vietu[i]*100;
        }
        else if (i==2 || i==3)
        {
           pinigu_suma = pinigu_suma + vietu[i]*70;
        }
        else pinigu_suma = pinigu_suma + vietu[i]*40;
    }
    vidurkis = (double) pinigu_suma / kiekis;
}

void rasyk (int pinigu_suma, double vidurkis)
{
    ofstream fr(FVR);
    fr << pinigu_suma << " " << fixed << setprecision(2) << vidurkis << endl;
    fr.close();
}
