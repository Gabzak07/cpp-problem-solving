#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Koord //kliuciu koordinates
{
    int x, y;
};

struct Komanda //seka, kuria eina
{
    char k; // k - kryptis, pvz ,,V'' arba ,,A'' ir tt.
    int k_sk; // k_sk - kiekis zingsniu tos krypties.
};

void skaityk (int &n, Koord A[], Komanda B[], int &b);
void skaiciuok (int n, Koord A[], Komanda B[], int b, int &x_g, int &y_g);
void rasyk (int x_g, int y_g);

int main()
{
    int n, b = 0, x_g, y_g; // kintamasis b eis kartu su struktura Komanda B; x_g - x galutinis; y_g - y_galutinis
    Koord A[30];
    Komanda B[30];
    skaityk (n, A, B, b);
    skaiciuok(n, A, B, b, x_g, y_g);
    rasyk(x_g, y_g);
    return 0;
}

void skaityk (int &n, Koord A[], Komanda B[], int &b)
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> A[i].x >> A[i].y;
    }
    while(!fd.eof())
    {
        fd >> B[b].k >> B[b].k_sk;
        b++;
    }
    fd.close();
}

void skaiciuok (int n, Koord A[], Komanda B[], int b, int &x_g, int &y_g)
{
    x_g = 0, y_g = 0;
    for (int i=0; i<b; i++)
    {
        for (int v=0; v<B[i].k_sk; v++) // po viena zingsni analizuojame;
        {
            int x_laik = x_g, y_laik = y_g; // ivedam kintamuosius x_laik ir y_laik kad nenumusti reiksmes x_g yr y_g;
            bool laik = false;
            switch(B[i].k)
            {
                case 'V': y_laik++; break;
                case 'A': y_laik--; break;
                case 'K': x_laik--; break;
                case 'D': x_laik++; break;
            }
            for (int j=0; j<n; j++)
            {
                if (x_laik == A[j].x && y_laik == A[j].y)
                {
                   laik = true;
                }
            }
            if (laik == false)
            {
                x_g = x_laik;
                y_g = y_laik;
            }
        }
    }
}

void rasyk (int x_g, int y_g)
{
    ofstream fr(FVR);
    fr << x_g << " " << y_g << endl;
    fr.close();
}
