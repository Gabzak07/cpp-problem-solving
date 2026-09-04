#include <iostream>
#include <fstream>


using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

int main()
{
    int n, k, t, suma_t, maxi = 0, max;
    ifstream fd(FV);
    ofstream fr(FVR);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        suma_t = 0;
        fd >> k;
        for (int i=0; i<k; i++)
        {
            fd >> t;
            suma_t = suma_t + t;
        }
        fr << i+1 << " Zaidejas surinko " << suma_t << " tasku " << endl;
        if (suma_t > maxi)
        {
            maxi = suma_t;
            max = i+1;
        }
    }
    fr << max << " " << maxi << endl;
    fr.close();
    fd.close();

    return 0;
}
