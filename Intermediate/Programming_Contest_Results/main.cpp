#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &u, int laiko_limitas[], int taskai[], string v[], int surinkti_taskai[], int ispresti_uzd[], int laikas[]);
int maks (int surinkti_taskai[]);
void rikiavimas (int surinkti_taskai[], string v[], int laikas[], int ispresti_uzd[]);
void rasyk (int surinkti_taskai[], string v[], int laikas[], int ispresti_uzd[], int maksimalus);

int main()
{
    int u, laiko_limitas[12], taskai[12], surinkti_taskai[5], ispresti_uzd[5], laikas[5], maksimalus;
    string v[5];
    skaityk (u, laiko_limitas, taskai, v, surinkti_taskai, ispresti_uzd, laikas);
    rikiavimas (surinkti_taskai, v, laikas, ispresti_uzd);
    maksimalus = maks(surinkti_taskai);
    rasyk (surinkti_taskai, v, laikas, ispresti_uzd, maksimalus);
    return 0;
}

void skaityk (int &u, int laiko_limitas[], int taskai[], string v[], int surinkti_taskai[], int ispresti_uzd[], int laikas[])
{
    ifstream fd(FV);
    fd >> u;
    for (int i=0; i<u; i++)
    {
        fd >> laiko_limitas[i];
    }
    for (int i=0; i<u; i++)
    {
        fd >> taskai[i];
    }
    int x;
    for (int i=0; i<5; i++)
    {
        ispresti_uzd[i]=0;
        laikas[i] = 0;
        surinkti_taskai[i] = 0;
        fd >> v[i];
        for (int j=0; j<u; j++)
        {
            fd >> x;
            if (x > 0)
            {
                ispresti_uzd[i]++;
                laikas[i] = laikas[i] + x;
                if (x<= laiko_limitas[j])
            {
                surinkti_taskai[i] = surinkti_taskai [i] + taskai[j];
            }
            else surinkti_taskai[i] = surinkti_taskai[i] + taskai[j] / 2;
            }
        }
    }
    fd.close();
}

int maks (int surinkti_taskai[])
{
    int maxi = 0;
    for (int i=0; i<5; i++)
    {
       if (surinkti_taskai[i] > maxi)
       {
           maxi = surinkti_taskai[i];
       }
    }
    return maxi;
}

void rikiavimas (int surinkti_taskai[], string v[], int laikas[], int ispresti_uzd[])
{
    for (int i=0; i<5-1; i++)
    {
        for (int j=i+1; j<5; j++)
        {
            if (ispresti_uzd[i] < ispresti_uzd[j])
            {
                swap (ispresti_uzd[i], ispresti_uzd[j]);
                swap (v[i], v[j]);
                swap (laikas[i], laikas[j]);
                swap (surinkti_taskai[i], surinkti_taskai[j]);
            }
        }
    }
}

void rasyk (int surinkti_taskai[], string v[], int laikas[], int ispresti_uzd[], int maksimalus)
{
    ofstream fr (FVR);
    fr << maksimalus << endl;
    for (int i=0; i<5; i++)
    {
        if (surinkti_taskai[i] == maksimalus)
        {
            fr << left << setw(10) << v[i] << ispresti_uzd[i] << " " << laikas[i] << endl;
        }
    }
    fr.close();
}
