#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaitymas (int &n, int &k, int masyvas[]);
void balsu_skaiciavimas (int n, int k, int masyvas[], int balsai[]);
void rasyti (int balsai[], int k);


int main()
{
    int n, k, masyvas[1000], balsai[100];
    skaitymas (n, k, masyvas);
    balsu_skaiciavimas (n, k, masyvas, balsai);
    rasyti (balsai, k);


    return 0;
}

void skaitymas (int &n, int &k, int masyvas[])
{
    ifstream fd(FV);
    fd >> n >> k;
    for (int i=0; i<n; i++)
    {
        fd >> masyvas[i];
    }
    fd.close();
}

void balsu_skaiciavimas (int n, int k, int masyvas[], int balsai[])
{
    for (int i=0; i<k; i++)
    {
       balsai[i] = 0;
    }
   for (int i=0; i<n; i++)
   {
       int x = masyvas[i] - 1;
       balsai[x]++;
   }
}

void rasyti (int balsai[], int k)
{
    ofstream fr(FVR);
    fr << "Kandidato nr.   " << "Balsu kiekis" << endl;
    for (int i=0; i<k; i++)
    {
       fr << i+1 << "               " << balsai[i] << endl;
    }
    fr.close();
}
