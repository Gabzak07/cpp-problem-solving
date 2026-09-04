#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int &m, int seka[]);
void iterpimas (int &n, int m, int seka[]);
void rasyk (int n, int seka[]);
int rask (int n, int m, int seka[]);

int main()
{
    int n, m, seka[30];
    skaityk (n, m, seka);
    iterpimas (n, m, seka);
    rasyk (n, seka);
    return 0;
}

void skaityk (int &n, int &m, int seka[])
{
    ifstream fd(FV);
    fd >> n >> m;
    for (int i=0; i<n; i++)
    {
        fd >> seka[i];
    }
    fd.close();
}

void iterpimas (int &n, int m, int seka[])
{
    int  t;
    t = rask (n, m, seka);
    if (t == -1)
    {
        seka[n] = m;
        n++;
    }

    else
    {
        for (int j=n-1; j>=t; j--)
            {
                seka[j+1] = seka[j];
            }
            seka[t] = m;
            n++;
    }
}

int rask (int n, int m, int seka[])
{
    for (int i=0; i<n; i++)
    {
       if (seka[i] == m)
       {
           return i;
       }
    }
    return -1;
}
void rasyk (int n, int seka[])
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        fr << seka[i] << " ";
    }
    fr.close();
}
