#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys2.txt";
const char FVR[]= "Rezultatas.txt";

int main()
{
    int n, m, b = 0;
    char v; // tai vardu raides;
    string vardas;
    bool laik = true;
    ifstream fd(FV);
    ofstream fr(FVR);
    fd >> n;
    fd >> m;
    fd.ignore(256, '\n');
    for (int i=0; i<m; i++)
    {
        fd.get(v);
        switch(v)
        {
            case 'M': n = n - 2; break;
            case 'K': n = n - 5; break;
            case 'F': n = n - 3; break;
        }
        if (n <= 0)
        {
            laik = false;
            switch (v)
            {
                case 'M': n = n + 2; vardas = "Mazylis"; break;
                case 'K': n = n + 5; vardas = "Karlsonas"; break;
                case 'F': n = n + 3; vardas = "Frekenbok"; break;
            }
            break;
        }

    }
    if (laik == true)
        {
            vardas = "liko";
        }
    fr << n << " " << vardas << endl;
    fd.close();
    fr.close();
    return 0;
}

