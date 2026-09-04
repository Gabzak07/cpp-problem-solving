#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

int kiek_dienu (int n, int a, int b);

int main()
{
    int n, a, b, d = 0;
    ifstream fd (FV);
    fd >> n >> a >> b;
    fd.close();
    ofstream fr (FVR);
    fr << kiek_dienu (n, a, b) << endl;
    fr.close();
    return 0;
}

int kiek_dienu (int n, int a, int b)
{
    int d = 0;
    while (n > 0)
    {
        n= n-a;
        a= a+b;
        d++;
    }
      return d;
}
