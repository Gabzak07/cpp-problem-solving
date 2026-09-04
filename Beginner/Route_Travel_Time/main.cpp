#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys2.txt";
const char FVR[]= "Rezultatas2.txt";

int kelionesLaikas (int x, int y);
int sustojimuKiekis (int b, int s);

int main()
{
    int b, s1, v1, s2, v2, h1, h2, m1, m2, sustojimai_1, sustojimai_2;


    ifstream fd (FV);

    fd >> b;
    fd >> s1 >> v1;
    fd >> s2 >> v2;

    fd.close();

    m1 = kelionesLaikas (s1, v1);
    m2 = kelionesLaikas (s2, v2);

    sustojimai_1 = sustojimuKiekis (b, s1);
    sustojimai_2 = sustojimuKiekis (b, s2);

    m1 = m1 + (sustojimai_1 * 5);
    m2 = m2 + (sustojimai_2 * 5);

    h1 = m1 / 60;
    m1 = m1 % 60;
    h2= m2 / 60;
    m2 = m2 % 60;

    ofstream fr (FVR);

    fr << "Pirmu keliu: " << h1 << " h  " << m1 << " min " << endl;
    fr << "Antru keliu: " << h2 << " h  " << m2 << " min " << endl;

    if (h1 > h2) fr << " Antru keliu greiciau ";
    else if (h1<h2) fr << "Pirmu keliu greiciau";
    else if (m1 > m2) fr << " Antru keliu greiciau ";
    else if (m1 < m2) fr << "Pirmu keliu greiciau";
    else fr << "Abiem keliais";

    fr.close();

    return 0;
}

int kelionesLaikas (int x, int y)
{
    int laikas_m;
    double laikas_v;
    laikas_v = (double) x/y;
    laikas_m = (laikas_v*60);
    laikas_m = (int) (laikas_m);
    return laikas_m;
}

int sustojimuKiekis (int b, int s)
{
    int kiekis = 1;
    while (s-b>0)
    {
        kiekis++;
        s= s-b;
    }
    return kiekis;
}

