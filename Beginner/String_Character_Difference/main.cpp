#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (string &e1, string &e2);
void tikrinti (string e1, string e2, char s[], int &b);
void rasyk (int b, char s[]);

int main()
{
    string e1, e2;
    char s[100];
    int b = 0;
    skaityk (e1, e2);
    tikrinti (e1, e2, s, b);
    rasyk (b, s);
    return 0;
}

void skaityk (string &e1, string &e2)
{
    ifstream fd(FV);
    fd >> e1;
    fd.ignore(256, '\n');
    fd >> e2;
    fd.close();
}

void tikrinti (string e1, string e2, char s[], int &b)
{
    int laik;
    for (int i=0; i<e1.length(); i++)
    {
        laik =0;
        for (int j=0; j<e2.length(); j++)
        {
            if (e1[i] == e2[j])
            {
                laik = 1;

            }
        }
        if (laik == 0)
        {
            s[b] = e1[i];
            b++;
        }
    }
}

void rasyk (int b, char s[])
{
    ofstream fr(FVR);
    if (b==0) fr << " Taip " << endl;
    for (int i=0; i<b; i++)
    {
        fr << s[i] << " ";
    }
    fr.close();
}
