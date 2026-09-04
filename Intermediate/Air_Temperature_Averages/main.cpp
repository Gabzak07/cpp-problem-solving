#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Temp
{
    string m;
    double t[31], vid = 0;
};

void skaityk (int &n, int &k, Temp T[]);
void skaiciuok (int n, int k, Temp T[], double &bendras_vid);
void rasyk (int n, Temp T[], double bendras_vid);

int main()
{
    int n, k;
    double bendras_vid = 0;
    Temp T[12];
    skaityk (n, k, T);
    skaiciuok (n, k, T, bendras_vid);
    rasyk (n, T, bendras_vid);

    return 0;
}

void skaityk (int &n, int &k, Temp T[])
{
    ifstream fd(FV);
    fd >> n >> k;
    for (int i=0; i<n; i++)
    {
        fd >> T[i].m;
        cout << T[i].m << endl;
        for (int j=0; j<k; j++)
        {
            fd >> T[i].t[j];
        }
    }
    fd.close();
}

void skaiciuok (int n, int k, Temp T[], double &bendras_vid)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<k; j++)
        {
            T[i].vid = T[i].vid + T[i].t[j]; //dabar vid naudoju sumai rasti;
        }
        bendras_vid = bendras_vid + T[i].vid;
        T[i].vid = T[i].vid / k; //dabar jau ieskau vidurkio;

    }
    bendras_vid = bendras_vid / (n*k);

}

void rasyk (int n, Temp T[], double bendras_vid)
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        fr << fixed << setprecision(2) << T[i].m << " " << T[i].vid << endl;
    }
    fr << "Bendras matavimu vidurkis: " << bendras_vid << endl;
    fr.close();
}
