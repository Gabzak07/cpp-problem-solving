#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &min, int &max, int &n, int slidziu_kaina[], int batu_kaina[]);
void kainos (int min, int max, int n, int slidziu_kaina[], int batu_kaina[], int &minimalus, int &didziausias);
int kiek (int min, int max, int n, int slidziu_kaina[], int batu_kaina[]);
void kiek_tinka (int min, int max, int n, int slidziu_kaina[], int batu_kaina[], int &m, int tinkamiausi[]);
void rasyk (int pigiausias_galimas, int brangiausias_galimas, int kiekis, int m, int tinkamiausi[]);

int main()
{
    int min, max, n, slidziu_kaina[50], batu_kaina[50], pigiausias_galimas, brangiausias_galimas, kiekis, m = 0, tinkamiausi[50];
    skaityk (min, max, n, slidziu_kaina, batu_kaina);
    kainos (min, max, n, slidziu_kaina, batu_kaina, pigiausias_galimas, brangiausias_galimas);
    kiekis = kiek (min, max, n, slidziu_kaina, batu_kaina);
    kiek_tinka (min, max, n, slidziu_kaina, batu_kaina, m, tinkamiausi);
    rasyk (pigiausias_galimas, brangiausias_galimas, kiekis, m, tinkamiausi );

    return 0;
}

void skaityk (int &min, int &max, int &n, int slidziu_kaina[], int batu_kaina[])
{
    ifstream fd(FV);
    fd >> min >> max >> n;
    for (int i=0; i<n; i++)
    {
        fd >> slidziu_kaina[i] >> batu_kaina[i];
    }
    fd.close();
}

void kainos (int min, int max, int n, int slidziu_kaina[], int batu_kaina[], int &minimalus, int &didziausias)
{
    minimalus = max;
    didziausias = min;
    for (int i=0; i<n; i++)
    {
        if (slidziu_kaina[i] + batu_kaina[i] >= min && slidziu_kaina[i] + batu_kaina[i] <=max )
        {
            if (slidziu_kaina[i] + batu_kaina[i] < minimalus)
            {
                minimalus = slidziu_kaina[i] + batu_kaina[i];
            }
            if (slidziu_kaina[i] + batu_kaina[i] > didziausias)
            {
                didziausias = slidziu_kaina[i] + batu_kaina[i];
            }
        }
    }
}

int kiek (int min, int max, int n, int slidziu_kaina[], int batu_kaina[])
{
    int kiekis = 0;
    for (int i=0; i<n; i++)
    {
        if (slidziu_kaina[i] + batu_kaina[i] >= min && slidziu_kaina[i] + batu_kaina[i] <=max )
        {
            kiekis++;
        }
    }
    return kiekis;
}

void kiek_tinka (int min, int max, int n, int slidziu_kaina[], int batu_kaina[], int &m, int tinkamiausi[])
{
    for (int i=0; i<n; i++)
    {
        if (slidziu_kaina[i] + batu_kaina[i] >= min && slidziu_kaina[i] + batu_kaina[i] <=max )
        {
            tinkamiausi[m] = slidziu_kaina[i] + batu_kaina[i];
            m = m+1;
        }
}
}
void rasyk (int pigiausias_galimas, int brangiausias_galimas, int kiekis, int m, int tinkamiausi[])
{
    ofstream fr(FVR);
    fr << pigiausias_galimas << " " << brangiausias_galimas << endl;
    fr << kiekis << endl;
    for (int i=0; i< m; i++)
    {
        fr << tinkamiausi[i] << " ";
    }
    fr.close();
}
