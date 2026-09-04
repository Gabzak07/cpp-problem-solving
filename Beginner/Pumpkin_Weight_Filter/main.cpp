#include <iostream>
#include <fstream>

using namespace std;

const char FV[] = "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaitymas (double masyvas[], int &n, double &p1, double &p2 );
double vidurkis (double masyvas[], int n );
void atrinkimas (double  masyvas[], int n, double masyvas2[], int &n2, double p1, double p2);
void isvesti (double moliugiu_vidurkis, double masyvas2[], int n2, double atrinktu_moliugiu_vidurkis);

int main()
{
    int n, n2 = 0;
    double p1, p2, moliugiu_vidurkis, atrinktu_moliugiu_vidurkis, masyvas[100], masyvas2[100];
    skaitymas (masyvas, n, p1, p2);
    moliugiu_vidurkis = vidurkis (masyvas, n);
    atrinkimas (masyvas, n, masyvas2, n2, p1, p2);
    atrinktu_moliugiu_vidurkis = vidurkis (masyvas2, n2);
    isvesti (moliugiu_vidurkis, masyvas2, n2, atrinktu_moliugiu_vidurkis);



    return 0;
}

void skaitymas (double masyvas[], int &n, double &p1, double &p2 )
{
    ifstream fd(FV);
    fd >> n >> p1 >> p2;
    for (int i=0; i<n; i++)
    {
        fd >> masyvas[i];
    }
    fd.close();
}

double vidurkis (double masyvas[], int n )
{
    double suma = 0;
    for (int i=0; i<n; i++)
    {
        suma = suma + masyvas[i];
    }
    return suma/n;
}

void atrinkimas (double masyvas[], int n, double masyvas2[], int &n2, double p1, double p2)
{
    for (int i=0; i<n; i++)
    {
        if (masyvas[i] >= p1 && masyvas[i] <= p2 )
        {
            masyvas2[n2] = masyvas [i];
            n2++;
        }
    }
}

void isvesti (double moliugiu_vidurkis, double masyvas2[], int n2, double atrinktu_moliugiu_vidurkis)
{
    ofstream fr(FVR);
    fr << "Visu moliugu vidutinis svoris: " << moliugiu_vidurkis << " kg " << endl;
    fr << "I supirkima atrinkta: " << n2 << endl;
    fr << "Vidutinis vieno atrinkto moliugo svoris: " << atrinktu_moliugiu_vidurkis << " kg " << endl;
    fr << "Atrinktu moliugu svoriu sarasas: ";
    for (int i=0; i<n2; i++)
    {
        fr << masyvas2[i] << " ";
    }
    fr.close();
}
