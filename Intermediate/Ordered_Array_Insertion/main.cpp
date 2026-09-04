#include <iostream>
#include <fstream>
using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int p[], int &k, int s[]);
void iterpimas (int &n, int p[], int k, int s[]);
void rasyk (int n, int p[]);

int main()
{
    int n, p[100], k, s[100];
    skaityk (n, p, k, s);
    iterpimas (n, p, k, s);
    rasyk (n, p);
    return 0;
}

void skaityk (int &n, int p[], int &k, int s[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> p[i];
    }
    fd >> k;
    for (int i=0; i<k; i++)
    {
        fd >> s[i];
    }
    fd.close();
}

void iterpimas (int &n, int p[], int k, int s[])
{
    for (int i=0; i<k; i++)
    {
        //cout << s[i] << " ";
        if (s[i] >= p[n-1])
        {
            cout << p[n-1] << " ";
           p[n] = s[i];
           n++;
        }
        else
        {
            for (int j=0; j<n; j++)
        {
            if (p[j] > s[i])
            {
                for (int u=n-1; u>=j; u--)
                {
                    p[u+1]=p[u];
                }
                p[j]=s[i];
                //cout << p[j] << " ";
                n++;
                break;
            }
        }
    }
    }
}

void rasyk (int n, int p[])
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        fr << p[i] << endl;
    }
    fr.close();
}
