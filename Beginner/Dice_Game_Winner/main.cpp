#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

int main()
{   int n, k, a, suma, max = 0, vieta= 0;
    ifstream fd (FV);
    fd >> n;
    for (int i=0; i < n; i++)
    {
        suma = 0;
        fd >> k;

        for (int j=0; j<k; j++)
        {
            fd >> a;
            suma = suma + a;

        }
        if (suma > max)
        {
            max = suma;
            vieta = i;
        }


    }




    fd.close();

    ofstream fr (FVR);

    fr << vieta+1 << endl;
    fr << suma;

    fr.close();

    return 0;
}
