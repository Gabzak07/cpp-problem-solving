#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Islaidos.txt";
const char FVR[]= "Ataskaita.txt";

double dienpinigiu_likutis (double dienpinigiai, double m);
double maksimalus (double max, double skaicius);
double vidurkis (double suma);

int main()
{
    double m, n, max = 0, suma = 0;
    ifstream fd (FV);
    fd >> n;
    for (int i=1; i<=5; i++)
    {
        fd >> m;
        n = dienpinigiu_likutis (n, m);
        max = maksimalus (max, m);
        suma = suma + m;

    }

    fd.close();
    ofstream fr (FVR);
    fr << n << endl;
    fr << max << endl;
    fr << fixed << setprecision(2) << vidurkis (suma) << endl;
    fr.close();
    return 0;
}


double dienpinigiu_likutis (double dienpinigiai, double m)
{
    double pinigu_likutis;
    pinigu_likutis = dienpinigiai - m;
    return pinigu_likutis;
}

double maksimalus (double max, double skaicius)
{
    if (skaicius > max)
    {
        max = skaicius;
    }
    return max;
}

double vidurkis (double suma)
{
    return suma / 5;
}
