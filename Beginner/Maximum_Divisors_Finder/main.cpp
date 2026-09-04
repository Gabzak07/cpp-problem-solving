#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

int dalikliai (int skaicius);

int main()
{
    int a, b, dalikliu_kiekis, didziausias = 0, didziausio_skaicius;
    ifstream fd(FV);
    fd >> a >> b;
    fd.close();
    for (int i=a; i<=b; i++)
    {
       dalikliu_kiekis = dalikliai (i);
       if (dalikliu_kiekis > didziausias)
       {
           didziausias = dalikliu_kiekis;
           didziausio_skaicius = i;
       }
    }
    ofstream fr (FVR);
    fr <<  didziausio_skaicius << " " << didziausias << endl;
    for (int i=1; i<=didziausio_skaicius; i++)
    {
        if (didziausio_skaicius % i == 0)
        {
            fr << i << " ";
        }
    }
    fr.close();
    return 0;
}

int dalikliai (int skaicius)
{
   int kiekis = 0;
   for (int i=1; i<=skaicius; i++)
   {
       if (skaicius % i ==0)
       {
           kiekis++;
       }
   }
   return kiekis;
}
