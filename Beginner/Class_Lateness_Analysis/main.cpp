#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys3.txt";
const char FVR[]= "Rezultatas3.txt";

int vieno_mokinio_velavimas (int mm, int pm, int pv, int mv );
string nauja_tema (int veluotoju_kiekis, int n);


int main()
{   int n, pamokos_pradzia_val, pamokos_pradzia_min, mokinio_atejimas_val, mokinio_atejimas_min, mokinio_pavelavimas, paveluotoju_kiekis=0, atejusiu_laiku=0, mokinio_velavimas_minutemis, viso_praleista_minutemis = 0;
    double vidurkis = 1;
    ifstream fd (FV);
    ofstream fr (FVR);
    fd >> n >> pamokos_pradzia_val >> pamokos_pradzia_min;

    for (int i = 1; i <= n; i++  )
    {

        fd >> mokinio_atejimas_val >> mokinio_atejimas_min;

            mokinio_velavimas_minutemis = vieno_mokinio_velavimas ( mokinio_atejimas_min, pamokos_pradzia_min, pamokos_pradzia_val, mokinio_atejimas_val );
          viso_praleista_minutemis = viso_praleista_minutemis + mokinio_velavimas_minutemis;

        if (pamokos_pradzia_min != mokinio_atejimas_min )
        {
           paveluotoju_kiekis++;
        }
        else if (pamokos_pradzia_min == mokinio_atejimas_min)
        atejusiu_laiku++;

     vidurkis = (double) viso_praleista_minutemis / n;

     fr << mokinio_velavimas_minutemis << endl;
    }



    fr << paveluotoju_kiekis << " " << atejusiu_laiku << endl;
    fr << setprecision(2) << vidurkis <<  endl;

    fr << nauja_tema (paveluotoju_kiekis, n);

    fr.close();
    fd.close();
    return 0;

}

int vieno_mokinio_velavimas (int mm, int pm, int pv, int mv ) //x - mokinio atejimas minutemis; y - pamokos pradzia minutemis;
{
    int mokinio_velavimas_min;
    if (pv>mv)
    {
        mokinio_velavimas_min = 60 - pm + mm;
    }
    else
    {
        mokinio_velavimas_min = mm - pm;
    }
    return mokinio_velavimas_min;
}

string nauja_tema (int veluotoju_kiekis, int n)
{
    string zodis;
  if (veluotoju_kiekis < n/0.25  )
  {
      zodis = "NEGALIMA" ;
  }
    else
    {
        zodis = "GALIMA " ;
    }
    return zodis;
}



