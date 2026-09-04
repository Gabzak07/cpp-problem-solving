#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, string m[]);
void tikrinti (int n, string m[], string atrinkti_m[], int &b);
void rasyk (string atrinkti_m[], int b);

int main()
{
    ofstream fr(FVR);
    fr.close();
    int n, b = 0;
    string m[30], atrinkti_m[30];
    skaityk (n, m);
    tikrinti (n, m, atrinkti_m, b);
    rasyk (m, n);
    rasyk (atrinkti_m, b);
    return 0;
}

void skaityk (int &n, string m[])
{
    ifstream fd(FV);
    fd >> n;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        getline(fd, m[i]);
    }
    fd.close();
}

void tikrinti (int n, string m[], string atrinkti_m[], int &b)
{
    for (int i=0; i<n; i++)
    {
        string laik = m[i];
        for (int j=0; j<laik.length(); j++)
        {
            if (laik[j] == ' ')
            {
                atrinkti_m[b] = m[i];
                b++;
            }
        }
    }
}

void rasyk (string atrinkti_m[], int b)
{
    ofstream fr(FVR, ios::app);
    for (int i=0; i<b; i++)
    {
        fr << atrinkti_m[i] << endl;
    }
    fr << endl;
    fr.close();

}
