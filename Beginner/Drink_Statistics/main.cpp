#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

double rusis (int n, int kiekis);
double vanduo_procentais (int n, int vanduo_kiekis);
int nepilnameciu ( int cola_kiekis);

int main()
{
    int n, gerimas, cola_kiekis = 0, sprite_kiekis = 0, vanduo_kiekis = 0, nepilnameciai_cola;
    ifstream fd(FV);
    ofstream fr(FVR);
    fd >> n;
    for (int i=0; i<n; i++)
    {
      fd >> gerimas;
      if (gerimas == 1) cola_kiekis++;
      else if (gerimas ==2) sprite_kiekis++;
      else vanduo_kiekis++;
    }

    fd.close();


    nepilnameciai_cola = nepilnameciu (cola_kiekis);

    fr << fixed << setprecision(2) << rusis (n, cola_kiekis) << endl;
    fr << fixed << setprecision(2) << rusis (n, sprite_kiekis) << endl;
    fr << fixed << setprecision(2) << rusis (n, vanduo_kiekis) << endl;
    fr << fixed << setprecision(5) << vanduo_procentais (n, vanduo_kiekis) << endl;
    fr << nepilnameciai_cola << endl;

    fr.close();

    return 0;
}

double rusis (int n, int kiekis)
{
    return (double)kiekis/n;
}

double vanduo_procentais (int n, int vanduo_kiekis)
{
    return (double)vanduo_kiekis*100/n;
}

int nepilnameciu (int cola_kiekis)
{
    double laik = cola_kiekis *0.4;
    return (int) laik;
}
