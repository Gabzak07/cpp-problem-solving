#include <iostream>
#include <fstream>
using namespace std;

const char FV [] = "duomenys.txt";
const char FVR [] = "rezultatai.txt";

ifstream fd(FV);
ofstream fr (FVR);

int main()
{   int  n, visi_uzdaviniai = 0;
    fd >> n;

    for (int i=0; i <n; i++)
    {
        int dienu, kasdien_uzdaviniu = 0;
        fd >> dienu;
        for (int j=0; j<dienu; j++)
        {
            int uzdaviniu;
            fd >> uzdaviniu;
            kasdien_uzdaviniu = kasdien_uzdaviniu + uzdaviniu;
        }
        visi_uzdaviniai = visi_uzdaviniai + kasdien_uzdaviniu;
        fr << kasdien_uzdaviniu << endl;
    }
    fr << visi_uzdaviniai << endl;
    fr.close ();
    fd.close();
    return 0;
}
