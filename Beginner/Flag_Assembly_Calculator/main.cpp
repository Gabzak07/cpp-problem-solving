#include <iostream>
#include <fstream>


using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int juosteles[], char juost[]);
void skaiciuok (int n, int juosteles[], char juost[], int &zaliu_suma, int &raudonu_suma, int &geltonu_suma, int &vel_k);
void rasyk (int vel_k, int zaliu_suma, int raudonu_suma, int geltonu_suma);

int main()
{
    int n, juosteles[30], zaliu_suma = 0, raudonu_suma = 0, geltonu_suma = 0, vel_k =0;
    char juost[30];
    skaityk (n, juosteles, juost);
    skaiciuok (n, juosteles, juost, zaliu_suma, raudonu_suma, geltonu_suma, vel_k);
    rasyk (vel_k, zaliu_suma, raudonu_suma, geltonu_suma);

    return 0;
}

void skaityk (int &n, int juosteles[], char juost[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> juost[i] >> juosteles[i];
    }
    fd.close();
}

void skaiciuok (int n, int juosteles[], char juost[], int &zaliu_suma, int &raudonu_suma, int &geltonu_suma, int &vel_k)
{
    for (int i=0; i<n; i++)
    {
        if (juost[i] == 'Z')
        {
            zaliu_suma = zaliu_suma + juosteles[i];
        }
        if (juost[i] == 'R')
        {
            raudonu_suma = raudonu_suma + juosteles[i];
        }
        if (juost[i] == 'G')
        {
            geltonu_suma = geltonu_suma + juosteles[i];
        }
    }
    while (zaliu_suma >= 2 && raudonu_suma >= 2 && geltonu_suma >=2)
    {
        zaliu_suma = zaliu_suma - 2;
        raudonu_suma = raudonu_suma -2;
        geltonu_suma = geltonu_suma - 2;
        vel_k++;
    }

}

void rasyk (int vel_k, int zaliu_suma, int raudonu_suma, int geltonu_suma)
{
    ofstream fr(FVR);
    fr << vel_k << endl;
    fr << "G = " << geltonu_suma << endl;
    fr << "Z = " << zaliu_suma << endl;
    fr << "R = " << raudonu_suma << endl;
    fr.close();
}
