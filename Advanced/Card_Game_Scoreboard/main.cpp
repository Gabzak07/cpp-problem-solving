#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n, int numeris[], int taskai[]);
void atrinkti (int &b, int n, int numeris[], int taskai[], int nauji_num[], int nauji_task[]);
int rask (int x, int b, int nauji_num[]);
void minimalus (int nauji_num[], int nauji_task[], int b, int minimal[], int &m, int &min);
void maksimalus (int nauji_num[], int nauji_task[], int b, int maksimal[], int &maks, int &maxi);
int parnesk_maz_tasku_max_num (int nauji_num[], int nauji_task[], int b, int min);
int parnesk_max_tasku_min_num (int nauji_num[], int nauji_task[], int b, int maxi);
void iterpimas (int nauji_num[], int nauji_task[], int &b, int maz_tasku_max_num, int &max_tasku_min_num);
void rasyk (int b, int nauji_num[], int nauji_task[]);
void rasyk2(int b, int nauji_num[], int nauji_task[], int maksimal[], int maks, int minimal[], int m);
int main()
{
    int n, numeris[100], taskai[100], nauji_num[100], nauji_task[100], b = 0, minimal[100], m = 0, maksimal[100], maks = 0,
    maz_tasku_max_num, max_tasku_min_num, min, maxi;
    skaityk (n, numeris, taskai);
    atrinkti (b, n, numeris, taskai, nauji_num, nauji_task);
    rasyk (b, nauji_num, nauji_task);
    minimalus (nauji_num, nauji_task, b, minimal, m, min);
    maksimalus (nauji_num, nauji_task, b, maksimal, maks, maxi);
    maz_tasku_max_num =  parnesk_maz_tasku_max_num (nauji_num, nauji_task, b, min);
    max_tasku_min_num = parnesk_max_tasku_min_num (nauji_num, nauji_task, b, maxi);
    iterpimas (nauji_num, nauji_task, b, maz_tasku_max_num, max_tasku_min_num);
    iterpimas (nauji_num, nauji_task, b, maz_tasku_max_num, max_tasku_min_num);
    rasyk2 (b, nauji_num, nauji_task, maksimal, maks, minimal, m);
    return 0;
}

void skaityk (int &n, int numeris[], int taskai[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> numeris[i] >> taskai[i];
    }
    fd.close();
}

void atrinkti (int &b, int n, int numeris[], int taskai[], int nauji_num[], int nauji_task[])
{
    int laik;
    for (int i=0; i<n; i++)
    {
        if (taskai[i] >= 0)
        {
            laik = rask (numeris[i], b, nauji_num);
        if (laik == -1)
        {
            nauji_num[b] = numeris[i];
            nauji_task[b] = taskai[i];
            b++;
        }
        else
        {
            nauji_task[laik] += taskai[i];

        }
        }

    }
}

int rask (int x, int b, int nauji_num[])
{
    for (int i=0; i<b; i++)
    {
        if (x == nauji_num[i])
        {
            return i;
        }
    }
    return -1;
}

void minimalus (int nauji_num[], int nauji_task[], int b, int minimal[], int &m, int &min)
{
    min = nauji_task[0];
    for (int i=0; i<b; i++)
    {
        if (nauji_task[i]  < min)
        {
            min = nauji_task[i];
        }
    }
    for (int i=0; i<b; i++)
    {
        if (nauji_task[i] == min)
        {
            minimal[m] = nauji_num[i];
            m++;
        }
    }
}

void maksimalus (int nauji_num[], int nauji_task[], int b, int maksimal[], int &maks, int &maxi)
{
    maxi = nauji_num[0];
    for (int i=0; i<b; i++)
    {
        if (nauji_task[i] > maxi)
        {
            maxi = nauji_task[i];
        }
    }
    for (int i=0; i<b; i++)
    {
        if (nauji_task[i] == maxi)
        {
            maksimal[maks] = nauji_num[i];
            maks++;
        }
    }
}

int parnesk_maz_tasku_max_num (int nauji_num[], int nauji_task[], int b, int min)
{
    int pozicija = 0;
    int numeris = 0;
    for (int i=0; i<b; i++)
    {
        if (nauji_task[i] == min && nauji_num[i] > numeris)
        {
            pozicija = i;
            numeris = nauji_num[i];
        }
    }
    return pozicija;
}

int parnesk_max_tasku_min_num (int nauji_num[], int nauji_task[], int b, int maxi)
{
    int poz = 0;
    int num = nauji_num[b-1];
    for (int i=0; i<b; i++)
    {
        if (nauji_task[i] == maxi && nauji_num[i] < num)
        {
            poz = i;
            num = nauji_num[i];
        }
    }
    return poz;
}

void iterpimas (int nauji_num[], int nauji_task[], int &b, int maz_tasku_max_num, int &max_tasku_min_num)
{
    if (max_tasku_min_num > maz_tasku_max_num)
    {
        max_tasku_min_num++;
    }
    for (int i=b-1; i>=maz_tasku_max_num; i--)
    {
        nauji_num[i+1] = nauji_num[i];
        nauji_task[i+1] = nauji_num[i];
    }
    nauji_num[maz_tasku_max_num] = nauji_num[max_tasku_min_num];
    nauji_task[maz_tasku_max_num] = nauji_task[max_tasku_min_num];
    b++;

}
void rasyk (int b, int nauji_num[], int nauji_task[])
{
    ofstream fr(FVR);
    fr << "Zaidejai ir ju surinkti taskai:" << endl;
    for (int i=0; i<b; i++)
    {
        fr << nauji_num[i] << " " << nauji_task[i] << endl;
    }
    fr.close();
}

void rasyk2(int b, int nauji_num[], int nauji_task[], int maksimal[], int maks, int minimal[], int m)
{
    ofstream fr(FVR, ios::app);
    fr << "Maziausiai tasku surinko:" << endl;
    for (int i=0; i<m; i++)
    {
        fr << minimal[i] << " ";
    }
    fr << endl;
    fr << "Daugiausiai tasku surinko:" << endl;
    for (int i=0; i<maks; i++)
    {
        fr << maksimal[i] << " ";
    }
    fr << endl;
    fr << "Po iterpimo:" << endl;
    for (int i=0; i<b; i++)
    {
        fr << nauji_num[i] << " " << nauji_task[i] << endl;
    }
    fr.close();
}
