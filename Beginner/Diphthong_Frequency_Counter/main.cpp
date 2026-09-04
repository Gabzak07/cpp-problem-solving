#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (char s[], int &viso_simb);
int skaiciuok (char s[], int viso_simb);
void rasyk (int au_kiekis);

int main()
{
    char s[300];
    int viso_simb = 0, au_kiekis;
    skaityk (s, viso_simb);
    au_kiekis = skaiciuok (s, viso_simb);
    rasyk (au_kiekis);
    return 0;
}

void skaityk (char s[], int &viso_simb)
{
    ifstream fd(FV);
    while (!fd.eof())
    {
        fd.get(s[viso_simb]);
        viso_simb++;
    }
    fd.close();
}

int skaiciuok (char s[], int viso_simb)
{
    int kiekis = 0;
    for (int i=0; i<viso_simb; i++)
    {
        if (s[i] == 'a' && s[i+1] == 'u')
            kiekis++;
    }
    return kiekis;
}

void rasyk (int au_kiekis)
{
    ofstream fr(FVR);
    fr << au_kiekis << endl;
    fr.close();
}
