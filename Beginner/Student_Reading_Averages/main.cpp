#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaiciuoti (int &suma, int masyvas[], int n );
void vidurkis (int suma, double &vid, int n);
double m_vid (double vid);

int main()
{
    int masyvas[30], n, suma = 0;
    double vid;
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
       fd >> masyvas[i];
    }
    fd.close();
    skaiciuoti (suma, masyvas, n);
    vidurkis (suma, vid, n);

    ofstream fr (FVR);
    fr << suma << endl;
    fr << vid << endl;
    fr << m_vid (vid) << endl;
    fr.close();
    return 0;
}

void skaiciuoti (int &suma, int masyvas[], int n )
{
    for (int i=0; i<n; i++)
    {
        suma = suma + masyvas[i];
    }
}

void vidurkis (int suma, double &vid, int n)
{
    vid = (double) suma / n;
}

double m_vid (double vid)
{
    return vid/10;
}
