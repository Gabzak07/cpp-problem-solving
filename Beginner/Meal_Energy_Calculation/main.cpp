#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaiciuoti (int r1, int b1, int a1, double r, double b, double a, double gr, double &r2, double &b2, double &a2 );
void viso (double r2, double b2, double a2, double &pp);

int main()
{
    int n, r1, b1, a1;
    double r, b, a, pp = 0, r2, b2, a2, gr;
    ifstream fd (FV);
    ofstream fr (FVR);
    fd >> r1 >> b1 >> a1;
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> r >> b >> a >> gr;
        skaiciuoti (r1, b1, a1, r, b, a, gr, r2, b2, a2);
        fr << fixed << setprecision(2) << r2  << " " << fixed << setprecision(2) << b2 << " " << fixed << setprecision(2) << a2 << endl;
        viso (r2, b2, a2, pp);
    }
    fr << pp;

    fr.close();
    fd.close();
    return 0;
}

void skaiciuoti (int r1, int b1, int a1, double r, double b, double a, double gr, double &r2, double &b2, double &a2 )
{
    r2 = gr/100* r1* r;
    b2 = gr/100* b1*b;
    a2 = gr/100* a1 * a;
}

void viso (double r2, double b2, double a2, double &pp)
{
    pp = pp + r2 + b2 + a2;
}
