#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Geles
{
    int num, start_m, start_d, finish_m, finish_d;
};

void skaityk (Geles G[], int &n);
void skaiciuok (Geles G[], int n, int dienos[], int &kiekis);
void skaiciuok1 (int dienos[], int kiekis, int &maxi_start_m, int &maxi_start_d, int &maxi_finish_m, int &maxi_finish_d);
void rasyk (int kiekis, int maxi_start_m, int maxi_start_d, int maxi_finish_m, int maxi_finish_d);

int main()
{
    Geles G[30];
    int n, kiekis = 0, dienos[92] = {0}, maxi_start_m, maxi_start_d, maxi_finish_m, maxi_finish_d; // visi kintamieji ''maxi'' - tai rezultatai, intervalas, kuriame zydi daugiausia geliu
    skaityk (G, n);
    skaiciuok (G, n, dienos, kiekis);
    skaiciuok1 (dienos, kiekis, maxi_start_m, maxi_start_d, maxi_finish_m, maxi_finish_d);
    rasyk (kiekis, maxi_start_m, maxi_start_d, maxi_finish_m, maxi_finish_d);

    return 0;
}

void skaityk (Geles G[], int &n)
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> G[i].num >> G[i].start_m >> G[i].start_d >> G[i].finish_m >> G[i].finish_d;
    }
    fd.close();
}

void skaiciuok (Geles G[], int n, int dienos[], int &kiekis)
{
    int menuo, laik, pabaigos_d;
    for (int i=0; i<n; i++)
    {
        switch (G[i].start_m)
        {
            case 6: laik = 0; break;
            case 7: laik = 30; break;
            case 8: laik = 61; break; // laik dar prideda praeitus menesius (dienomis) tolimesniuose skaiciavimuose
        }
        switch (G[i].finish_m)
        {
            case 8: pabaigos_d = 61; break; //taip pat kompensuoju ziurint i pabaiga
            case 7: pabaigos_d = 30; break;
            case 6: pabaigos_d = 0; break;
        }
        for (int j= G[i].start_d + laik; j<= pabaigos_d + G[i].finish_d; j++)
        {
            dienos[j]++;
        }
    }
    for (int i=0; i<92; i++)
    {
       if (dienos[i] > kiekis)
       {
           kiekis = dienos[i];
       }
    }
}

void skaiciuok1 (int dienos[], int kiekis, int &maxi_start_m, int &maxi_start_d, int &maxi_finish_m, int &maxi_finish_d)
{
    int start, finish;
    for (int i=0; i<92; i++)
    {
        if (dienos[i] == kiekis)
        {
            start = i;
            break;
        }
    }
    for (int i=92; i>=0; i--)
    {
        if (dienos[i] == kiekis)
        {
            finish = i;
            break;
        }
    }
    for (int i= 0; i< 92; i++) //cia maxi_start_m, maxi_start_d, maxi_finish_m, maxi_finish_d galu gale taps periodu, kada zydi daugiausia
    {
        if (start < 31)
        {
            maxi_start_m = 6;
            maxi_start_d = start;
        }
        else if (start > 30 && start < 62)
        {
            maxi_start_m = 7;
            maxi_start_d = start - 30;
        }
        else
        {
            maxi_start_m = 8;
            maxi_start_d = start - 61;
        }
        if (finish < 31)
        {
            maxi_finish_m = 6;
            maxi_finish_d = finish;
        }
        else if (finish > 30 && finish < 62)
        {
            maxi_finish_m = 7;
            maxi_finish_d = finish - 30;
        }
        else
        {
            maxi_finish_m = 8;
            maxi_finish_d = finish - 61;
        }
    }
}

void rasyk (int kiekis, int maxi_start_m, int maxi_start_d, int maxi_finish_m, int maxi_finish_d)
{
    ofstream fr(FVR);
    fr << kiekis << endl;
    fr << maxi_start_m << " " << maxi_start_d << endl;
    fr << maxi_finish_m << " " << maxi_finish_d << endl;
    fr.close();
}
