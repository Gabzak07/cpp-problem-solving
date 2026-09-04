#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Menul
{
    int k, seka[30], kv, x1, y1; // x1; y1 - jei nepasieke, tai kokioj vietoj sustojo
    bool av;
};

void skaityk (Menul M[], int &x0, int &y0, int &n);
void skaiciuok (Menul M[], int x0, int y0, int n);
void rasyk (int n, Menul M[]);

int main()
{
    int x0, y0, n;
    Menul M[10];
    skaityk (M, x0, y0, n);
    skaiciuok (M, x0, y0, n);
    rasyk (n, M);
    return 0;
}

void skaityk (Menul M[], int &x0, int &y0, int &n)
{
    ifstream fd(FV);
    fd >> x0 >> y0;
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> M[i].k;
        for (int j=0; j<M[i].k; j++)
        {
            fd >> M[i].seka[j];
        }
    }
    fd.close();
}

void skaiciuok (Menul M[], int x0, int y0, int n)
{
    for (int i=0; i<n; i++)
    {
        M[i].kv = 0;
        M[i].av = false;
        int x = x0, y = y0;
        for (int j=0; j<M[i].k; j++)
        {
            M[i].kv++;
            switch (M[i].seka[j])
            {
                case 1: x++; y++; break;
                case 2: x++; y--; break;
                case 3: x--; y--; break;
                case 4: x--; y++; break;
            }
            if (x == x0 && y == y0)
            {
                M[i].av = true;
                break;
            }
        }
        if (M[i].av == false)
        {
            M[i].x1 = x;
            M[i].y1 = y;
        }
    }
}

void rasyk (int n, Menul M[])
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        if (M[i].av == true)
        {
            fr << setw(20) << left << "pasiektas tikslas  ";
        }
        else
        {
            fr << setw(20) << left << "sekos pabaiga  ";
        }
        for (int j=0; j<M[i].kv; j++)
        {
            fr << M[i].seka[j] << " ";
        }
        fr << M[i].kv << " ";
        if (M[i].av == false)
        {
            fr << M[i].x1 << " " << M[i].y1;
        }
        fr << endl;
    }
    fr.close();
}
