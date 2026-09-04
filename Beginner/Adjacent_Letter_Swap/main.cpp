#include <iostream>
#include <fstream>

using namespace std;

const char FV[] = "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (char s[], int &k);
void skaiciuok (char s[], int k);
void rasyk (int k, char s[]);

int main()
{
    char s[100];
    int k=0;
    skaityk (s, k);
    skaiciuok (s, k);
    rasyk (k, s);

    return 0;
}

void skaityk (char s[], int &k)
{
    ifstream fd(FV);
    while (! fd.eof())
    {
        fd.get (s[k]);
        k++;
    }

    fd.close();
}

void skaiciuok (char s[], int k)
{
    for (int i=0; i<k-1; i= i+2)
    {
        swap (s[i], s[i+1]);
    }
}

void rasyk (int k, char s[])
{
    ofstream fr(FVR);
    for (int i=0; i<k; i++)
    {
        fr << s[i];
    }
    fr.close();
}
