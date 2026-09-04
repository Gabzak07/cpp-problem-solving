#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaiciuoti (int masyvas[], int n, double &mokiniu_vid, double &m_vid, double &v_vid );
void reikalavimai (int masyvas[], int n, int &m_kiekis, int &v_kiekis);

int main()
{
    int masyvas[30], n, m_kiekis = 0, v_kiekis = 0;
    double mokiniu_vid, m_vid, v_vid;
    ifstream fd (FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> masyvas[i];

    }
    fd.close();
    skaiciuoti (masyvas, n, mokiniu_vid, m_vid, v_vid);
    reikalavimai (masyvas, n, m_kiekis, v_kiekis);
    ofstream fr(FVR);
    fr << fixed << setprecision(1) << mokiniu_vid << endl;
    fr << fixed << setprecision(2) << m_vid << endl;
    fr << fixed << setprecision(2) << v_vid << endl;
    if (m_kiekis >= 7) fr << "Merginu komandos sudaryti galima" << endl;
    else fr << "Merginu komandos sudaryti negalima" << endl;
    if (v_kiekis >=7) fr << "Vaikinu komandos sudaryti galima" << endl;
    else fr << "Vaikinu komandos sudaryti negalima" << endl;
    fr.close();

    return 0;
}

void skaiciuoti (int masyvas[], int n, double &mokiniu_vid, double &m_vid, double &v_vid )
{
    int suma = 0;
    int m_kiekis = 0, v_kiekis = 0, m_suma = 0, v_suma = 0;
    for (int i=0; i<n; i++)
    {
        suma = suma + abs(masyvas[i]);

        if (masyvas[i] > 0)
        {
          m_kiekis++;
          m_suma = m_suma + masyvas[i];
        }
        else
        {
          v_kiekis++;
          v_suma = v_suma - masyvas[i];
        }

    }
    mokiniu_vid = (double) suma / n;
    m_vid = (double) m_suma / m_kiekis;
    v_vid = (double) v_suma / v_kiekis;


}

void reikalavimai (int masyvas[], int n, int &m_kiekis, int &v_kiekis)
{

    for (int i=0; i<n; i++)
    {
        if (masyvas[i] >= 175)
    {
        m_kiekis++;
    }
    else if (masyvas[i] <= -175)
    {
        v_kiekis++;
    }
}
}

//2. abs(masyvas[i])
