#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, string v[]);
void tikrink (int n, string v[], string atrinktu_v[], int &b);
void rasyk (string atrinktu_v[], int b);

int main()
{
    int n, b = 0;
    string v[30], atrinktu_v[30];
    skaityk (n, v);
    tikrink (n, v, atrinktu_v, b);
    rasyk (atrinktu_v, b);
    return 0;
}

void skaityk (int &n, string v[])
{
    ifstream fd(FV);
    fd >> n;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        getline(fd, v[i]);
    }
    fd.close();
}

void tikrink (int n, string v[], string atrinktu_v[], int &b)
{
    for (int i=0; i<n; i++)
    {
        int laik = v[i].length();
        string laikinas = v[i];
        if (laikinas[laik-1] != 's')
        {
            atrinktu_v[b] = v[i];
            b++;
            }
    }
}

void rasyk (string atrinktu_v[], int b)
{
    ofstream fr(FVR);
    fr << b << endl;
    for (int i=0; i<b; i++)
    {
        fr << atrinktu_v[i] << endl;
    }
    fr.close();
}
