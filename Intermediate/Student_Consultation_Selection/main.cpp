#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[] = "Rezultatas.txt";

void skaityk (int &n, int &u, int studento_num[], int val[], int minutes[]);
void laikas (int n, int u, int val[], int minutes[], int vid[]);
int vidurk (int n, int vid[]);
void rikiavimas (int n, int studento_num[], int vid[]);
int studentu_tilpo (int n, int val[], int minutes[], int m);
void rasyk (int n, int studento_num[], int vid[]);
void rasyk2(int studento_num[], int vidurkis, int k);


int main()
{
    int m, n, u, studento_num[30], val[30], minutes[30], vid[30], vidurkis, k;

    skaityk (n, u, studento_num, val, minutes);
    laikas (n, u, val, minutes, vid);
    vidurkis = vidurk (n, vid);
    rasyk (n, studento_num, vid);
    rikiavimas (n, studento_num, vid);
    cout << "Iveskite m" << endl;
    cin >> m;
    k = studentu_tilpo (n, val, minutes, m);
    rasyk2(studento_num, vidurkis, k);
    return 0;
}

void skaityk (int &n, int &u, int studento_num[], int val[], int minutes[])
{
    ifstream fd(FV);
    fd >> n >> u;
    for (int i=0; i<n; i++)
    {
        fd >> studento_num[i] >> val[i] >> minutes[i];
    }
    fd.close();
}

void laikas (int n, int u, int val[], int minutes[], int vid[])
{
    double minut, vidurkis;
    for (int i=0; i<n; i++)
    {
        minut = minutes[i] + val[i]*60;
        vidurkis = minut / u;
        vid[i] = round(vidurkis);
    }

}

int vidurk (int n, int vid[])
{
    double v = 0, vi;
    for (int i=0; i<n; i++)
    {
        v= v + vid[i];
    }
    vi = v/ n;
    return round(vi);
}

void rikiavimas (int n, int studento_num[], int vid[])
{
    for (int i=0; i<n-1; i++)
    {
      for (int y=i+1; y<n; y++)
      {
          if (vid[i] < vid[y])
          {
              swap (vid[i], vid[y]);
              swap (studento_num[i], studento_num[y]);
          }
      }
    }
}

int studentu_tilpo (int n, int val[], int minutes[], int m)
{
    int minut, kiekis = 0;
    for (int i=0; i<n; i++)
    {
       minut = minutes[i] + val[i] * 60;
       if (m > minut)
       {
           kiekis++;
       }
    }
    return kiekis;
}

void rasyk (int n, int studento_num[], int vid[])
{
    ofstream fr(FVR);
    for (int i=0 ; i<n; i++)
    {
        fr << studento_num[i] << " " <<  vid[i] << endl;
    }
    fr.close();
}

void rasyk2(int studento_num[], int vidurkis, int k)
{
    ofstream fr(FVR, ios::app);
    fr << studento_num[0] << " " << studento_num[1] << endl;
    fr << vidurkis << endl;
    fr << k << endl;
    fr.close();
}
