#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char FV[]= "duomenys1.txt";
const char FVR[] = "rezultatas1.txt";

int main()
{   int p, n, nr;
    double k, sum, vkd, viso=0;

    ifstream fd(FV);
    ofstream fr (FVR);
    fd>>p;

    for (int i=1; i<=p; i++)
    {
      fd>> n; sum=0;
      for (int j=1; j<=n; j++)
      {   fd>> k;
          sum= sum+k;
      }
      vkd= sum/n;
      viso = viso +sum;
      fr << i << setw(6) << fixed <<setprecision(2) << vkd << endl;
    }
    fr << fixed << setprecision(2) << viso << endl;
    return 0;
}
