#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int rusis[]);
void rikiavimas (int rusis[]);
int skirtumas (int rusis[]);
void rasyk (int rusis[], int skirt);

int main()
{
    int rusis[2], skirt;
    skaityk (rusis);
    rikiavimas (rusis);
    skirt = skirtumas (rusis);
    rasyk (rusis, skirt);
    return 0;
}

void skaityk (int rusis[])
{
    ifstream fd(FV);
    for (int i=0; i<3; i++)
    {
        fd >> rusis[i];
    }
    fd.close();
}

void rikiavimas (int rusis[])
{
    for (int i=0; i<3-1; i++)
    {
        for (int j=i+1; j<3; j++)
        {
            if (rusis[i]<rusis[j])
            {
                swap(rusis[i], rusis[j]);
            }
        }
    }
}

int skirtumas (int rusis[])
{
    cout << rusis[0] << " " << rusis[2];
    return rusis[0] - rusis[2];
}

void rasyk (int rusis[], int skirt)
{
    ofstream fr(FVR);
    for (int i=0; i<3; i++)
    {
        fr << rusis[i] << endl;
    }
    fr << skirt << endl;
    fr.close();
}
