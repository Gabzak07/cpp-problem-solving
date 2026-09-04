#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (string &z1, string &z2);
bool tikrinti (string z1, string z2);

int main()
{
    string z1, z2;
    bool h;
    skaityk (z1, z2);
    h= tikrinti (z1, z2);
    ofstream fr(FVR);
    if (h) fr << "Ne heteroliteralas" << endl;
    else fr << "heteroliteralas " << endl;
    fr.close();
    return 0;
}

void skaityk (string &z1, string &z2)
{
    ifstream fd(FV);
    fd >> z1 >> z2;
    fd.close();
}

bool tikrinti (string z1, string z2)
{
    for (int i=0; i<z1.length(); i++)
    {
        for (int j=0; j<z2.length(); j++)
        {
            if (z1[i] == z2[j])
            {
                return true;
            }
        }
    }
    return false;
}
