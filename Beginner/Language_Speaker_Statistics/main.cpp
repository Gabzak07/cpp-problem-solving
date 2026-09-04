#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaiciuoti (int n, int kn, int &nn, double &p);

int main()
{
    int k, n, kn, nn;
    double p;
    ifstream fd(FV);
    ofstream fr(FVR);
    fd >> k >> n;
    for (int i=0; i<k; i++)
    {
        fd >> kn;
        skaiciuoti (n, kn, nn, p);
        fr << fixed << setprecision(2) << p << " " << nn << endl;
    }

    fr.close();
    fd.close();
    return 0;
}

void skaiciuoti (int n, int kn, int &nn, double &p)
{
   p =  (double) kn*100/n;
   nn = n - kn;
}
