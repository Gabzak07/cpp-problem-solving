#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Komanda.csv";
const char FVR[]= "Rezultatai.txt";

struct Zaidejas
{
    string v, p;
    double n;
};

void skaityk (int &np, int &na, double &naud, Zaidejas Zaid[], Zaidejas K[]);
void salinimas (int &np, double naud, Zaidejas Zaid[]);
void rasyk (int n, string s, Zaidejas N[]);
void rikiavimas (int np, Zaidejas Zaid[]);
void iterpk (int &np, int &na, Zaidejas Zaid[], Zaidejas K[], double naud);


int main()
{
    ofstream fr(FVR);
    fr.close();

    Zaidejas Zaid[30], K[30];
    double naud;
    int np, na;
    skaityk (np, na, naud, Zaid, K);
    salinimas (np, naud, Zaid);
    rasyk (np, "Be pasalintu zaideju:", Zaid);
    rikiavimas (np, Zaid);
    rasyk (np, "Surikiuota:", Zaid);
    iterpk (np, na, Zaid, K, naud);
    rasyk (np, "Su papildytais zaidejais", Zaid);
    rasyk (na, "Nepateke", K);

    return 0;
}

void skaityk (int &np, int &na, double &naud, Zaidejas Zaid[], Zaidejas K[])
{
    ifstream fd(FV);
    fd >> naud;
    fd >> np;
    fd.ignore(256, '\n');
    for (int i=0; i<np; i++)
    {
        getline (fd, Zaid[i].v, ',');
        getline (fd, Zaid[i].p, ',');
        fd >> Zaid[i].n;
        fd.ignore(256, '\n');
    }
    fd >> na;
    for (int i=0; i<na; i++)
    {
        getline(fd, K[i].v, ',');
        getline (fd, K[i].p, ',');
        fd >> K[i].n;
        fd.ignore(256, '\n');
    }
    fd.close();
}

void salinimas (int &np, double naud, Zaidejas Zaid[])
{
    for (int i=0; i<np; i++)
    {
        if (Zaid[i].n < naud)
        {
            for (int j=i; j<np; j++)
            {
                Zaid[j] = Zaid[j+1];
            }
            np--;
            i--;
        }
    }
}

void rasyk (int n, string s, Zaidejas N[])
{
    ofstream fr(FVR, ios::app);
    fr << s << endl;
    fr << "-----------------------" << endl;
    fr << left << setw(15) << "|Vardas" << setw(20) << "|Pavarde" << setw(15) << "|Naudingumas|" << endl;
    fr << "-----------------------" << endl;
    for (int i=0; i<n; i++)
    {
        fr << "|" << setw(15) << N[i].v << "|" << setw(20) << N[i].p << "|" << setw(15) << N[i].n << "|" << endl;
    }
    fr << "-----------------------" << endl;
    fr.close();
}

void rikiavimas (int np, Zaidejas Zaid[])
{
    for (int i=0; i<np-1; i++)
    {
        for (int j=i+1; j<np; j++)
        {
            if (Zaid[i].n < Zaid[j].n)
            {
                swap (Zaid[i], Zaid[j]);
            }
            else if (Zaid[i].n == Zaid[j].n && Zaid[i].v > Zaid[j].v)
            {
                swap (Zaid[i], Zaid[j]);
            }
            else if (Zaid[i].n == Zaid[j].n && Zaid[i].v == Zaid[j].v && Zaid[i].p > Zaid[j].p)
            {
                swap (Zaid[i], Zaid[j]);
            }
        }
    }
}


void iterpk (int &np, int &na, Zaidejas Zaid[], Zaidejas K[], double naud)
{
    int s = 0;
    for (int i=na-1; i>0; i--)
    {
        if (K[i].n > naud && np < 15)
        {
            if (K[i].n < Zaid[np-1].n)
            {
                Zaid[np] = K[i];
                np++;
            }
            for (int j=0; j<np; j++)
            {
                if (K[i].n > Zaid[j].n)
                {
                    for (int k=np-1; k>=j; k--)
                    {
                        Zaid[k+1] = Zaid[k];
                    }
                    Zaid[j] = K[i];
                    np++;
                    s++;
                    break;
                }
            }
        }
    }
    na = na - s;
}
