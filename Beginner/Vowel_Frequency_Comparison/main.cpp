#include <iostream>
#include <fstream>

using namespace std;

const char FV[] = "Duomenys.txt";
const char FVR[] = "Rezultatas.txt";

void skaityk (char s[], int &viso_simb);
int balsiu_kiekis (char s[], int viso_simb, char raide);
void skaiciuok (char &raide, int a_kiekis, int e_kiekis, double &proc);
void rasyk (int a_kiekis, int e_kiekis, char raide, double proc);

int main()
{
    char s[100], raide;
    int viso_simb = 0, a_kiekis = 0, e_kiekis = 0;
    double proc;
    skaityk (s, viso_simb);
    a_kiekis = balsiu_kiekis (s, viso_simb, 'a');
    e_kiekis = balsiu_kiekis (s, viso_simb, 'e');
    skaiciuok (raide, a_kiekis, e_kiekis, proc);
    rasyk (a_kiekis, e_kiekis, raide, proc);
    return 0;
}

void skaityk (char s[], int &viso_simb)
{
    ifstream fd(FV);
    while (!fd.eof())
    {
        fd.get(s[viso_simb]);
        //cout << s[viso_simb] << endl;
        viso_simb++;
    }
    fd.close();
}

int balsiu_kiekis (char s[], int viso_simb, char raide)
{
    int kiekis = 0;
    for (int i=0; i<viso_simb; i++)
    {
        if (s[i] == raide)
        {
            kiekis++;
        }
    }
    return kiekis;
}

void skaiciuok (char &raide, int a_kiekis, int e_kiekis, double &proc)
{
    if (a_kiekis > e_kiekis)
    {
        proc = (double) e_kiekis *100 /a_kiekis;
        raide = 'a';
    }
    else
    {
        proc = (double) a_kiekis *100 / e_kiekis;
        raide = 'e';
    }
}

void rasyk (int a_kiekis, int e_kiekis, char raide, double proc)
{
    ofstream fr(FVR);
    fr << "Raide a pasikartoja tekste " << a_kiekis << endl;
    fr << "Raide e pasikartoja tekste " << e_kiekis << endl;
    fr << "Raide " << raide << " pasikartoja " << proc << "% dazniau" << endl;
    fr.close();
}
