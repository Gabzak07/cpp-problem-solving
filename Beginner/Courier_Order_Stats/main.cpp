#include <iostream>
#include <fstream>
using namespace std;

    const char FV [] = "duomenys.txt";
    const char FVR [] ="rezult.txt";

    ifstream fd (FV);
    ofstream fr (FVR);

    int main()
{   int uzsakymai = 0, uzsakymu_suma = 0, suma = 1, sumos_vidurkis = 0,  uzsakymai_uz_simta = 0;

    while (suma!=0)
     {
        fd >> suma;
        if (suma > 100)
            uzsakymai_uz_simta++;
        if (suma!=0)
            uzsakymai++;

     uzsakymu_suma = uzsakymu_suma + suma;
     sumos_vidurkis = uzsakymu_suma / uzsakymai;

     }

     fr << uzsakymai_uz_simta << endl;
     fr << sumos_vidurkis << endl;
     fr << uzsakymai << endl;

    fd.close();
    fr.close();
    return 0;
}

