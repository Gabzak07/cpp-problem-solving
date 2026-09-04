#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[] = "Rezultatas.txt";

void skaiciuoti (int &s, int skaitmuo, int &kiekis);

int main()
{
    int s, kiekis;
    ifstream fd (FV);
    ofstream fr (FVR);
    fd >> s;
    for (int i=5; i>0; i= i-2)
    {
       skaiciuoti (s, i, kiekis);
       fr << i << " " << kiekis << endl;
    }
    fd.close();
    fr.close();
    return 0;
}

void skaiciuoti (int &s, int skaitmuo, int &kiekis)
{
    kiekis = s/skaitmuo;
    s = s - kiekis * skaitmuo;
}
