#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct aut
{
    string marke;
    string mod;
    int kaina;
};
void skaityk (int &n, aut masyvas[]);
void parnesk (int n, int &b, aut masyvas[], aut masyvas_b[], char zodis[]);
int brangiausias (int b, aut masyvas_b[]);
int pigiausias (int b, aut masyvas_b[]);
void rasyk (int brangiausias_audi, int brangiausias_bmw, int pigiausias_audi, int pigiausias_bmw);

int main()
{
    int n, a = 0, b = 0, brangiausias_audi, brangiausias_bmw, pigiausias_audi, pigiausias_bmw;
    aut masyvas[30], masyvas_audi[30], masyvas_bmw[30];
    skaityk (n, masyvas);
    parnesk (n, a, masyvas, masyvas_audi, "Audi");
    parnesk (n, b, masyvas, masyvas_bmw, "BMW");
    brangiausias_audi = brangiausias (a, masyvas_audi);
    brangiausias_bmw = brangiausias (b, masyvas_bmw);
    pigiausias_audi = pigiausias (a, masyvas_audi);
    pigiausias_bmw = pigiausias (b, masyvas_bmw);
    rasyk (brangiausias_audi, brangiausias_bmw, pigiausias_audi, pigiausias_bmw);
    return 0;
}

void skaityk (int &n, aut masyvas[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> masyvas[i].marke >> masyvas[i].mod >> masyvas[i].kaina;
    }
    fd.close();
}

void parnesk (int n, int &b, aut masyvas[], aut masyvas_b[], char zodis[])
{
    for (int i=0; i<n; i++)
    {
        if (masyvas[i].marke == zodis)
        {
            masyvas_b[b].marke = masyvas[i].marke;
            masyvas_b[b].mod = masyvas[i].mod;
            masyvas_b[b].kaina = masyvas[i].kaina;
            b++;
        }
    }
}

int brangiausias (int b, aut masyvas_b[])
{
    int maxi = masyvas_b[0].kaina;
    for (int i=0; i<b; i++)
    {
        if (masyvas_b[i].kaina > maxi)
        {
            maxi = masyvas_b[i].kaina;
        }
    }
    return maxi;
}

int pigiausias (int b, aut masyvas_b[])
{
    int mini = masyvas_b[0].kaina;
    for (int i=0; i<b; i++)
    {
        if (masyvas_b[i].kaina < mini)
        {
            mini = masyvas_b[i].kaina;
        }
    }
    return mini;
}

void rasyk (int brangiausias_audi, int brangiausias_bmw, int pigiausias_audi, int pigiausias_bmw)
{
    ofstream fr(FVR);
    if (brangiausias_audi > brangiausias_bmw)
    {
        fr << "Brangiausias: Benas" << endl;
    }
    else
    {
        fr << "Brangiausias: Tomas" << endl;
    }
    if (pigiausias_audi < pigiausias_bmw)
    {
        fr << "Pigiausias: Benas" << endl;
    }
    else
    {
        fr << "Pigiausias: Tomas" << endl;
    }
    if (brangiausias_audi > brangiausias_bmw && pigiausias_audi < pigiausias_bmw)
    {
        fr << "Benas" << endl;
    }
    else if (brangiausias_audi < brangiausias_bmw && pigiausias_audi > pigiausias_bmw)
    {
        fr << "Tomas" << endl;
    }
    else
    {
        fr << "Lygiosios" << endl;
    }
    fr.close();
}
