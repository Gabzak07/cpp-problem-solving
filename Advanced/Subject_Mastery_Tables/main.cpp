#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Mokinys
{
    string name, gerai_list[30], blogai_list[30];
    int gerai, blogai;
};

void skaityk (int &n, Mokinys A[]);
void rasyk1 (int n, Mokinys A[], string v1, string v2, string v3);
void skaiciuok(int n, int &b, Mokinys A[], Mokinys B[]);
int rask (Mokinys X[], int x, string pav);
void max (int b, Mokinys B[], int &v_s, int &v_n, int &v_skirt);
void rasyk2 (Mokinys B[], int v_s, int v_n, int v_skirt);

int main()
{
    ofstream fr(FVR);
    fr.close();
    Mokinys A[30], B[30];
    int n, b = 0, v_s, v_n, v_skirt;
    skaityk (n, A);
    rasyk1(n, A, "Mokinys", "Puikiai Moka", "Nemoka");
    skaiciuok(n, b, A, B);
    rasyk1(b, B, "Pavadinimas", "Mokantys mokiniai", "Nemokantys mokiniai");
    max(b, B, v_s, v_n, v_skirt);
    rasyk2(B, v_s, v_n, v_skirt);
    return 0;
}

void skaityk (int &n, Mokinys A[])
{
    ifstream fd(FV);
    fd >> n;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        getline(fd, A[i].name);
        fd >> A[i].gerai;
        fd.ignore(256, '\n');
        for (int j=0; j<A[i].gerai; j++)
        {
            getline(fd, A[i].gerai_list[j]);
        }
        fd >> A[i].blogai;
        fd.ignore(256, '\n');
        for (int j=0; j<A[i].blogai; j++)
        {
            getline(fd, A[i].blogai_list[j]);
        }
    }
    fd.close();
}

void rasyk1 (int n, Mokinys A[], string v1, string v2, string v3)
{
    ofstream fr(FVR, ios::app);
    fr << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    fr << "|" << setw(30) << left << v1 << " |" << setw(30) << v2 << "|" << setw(30) << v3 << "|" << endl;
    fr << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i=0; i<n; i++)
    {
        if (A[i].gerai > A[i].blogai)
        {
            for (int j=0; j<A[i].gerai; j++)
            {
                    if (j == 0)
                    {
                        fr << "|" << setw(30) << right << A[i].name << " ";
                    }
                    else
                    {
                        fr << "|" << setw(30) << " " << " ";
                    }
                    fr << "|" << setw(30) << A[i].gerai_list[j] << "|" << setw(30) << A[i].blogai_list[j] << "|" << endl;
            }
        }
        else
        {
            for (int j=0; j<A[i].blogai; j++)
            {
                if (j == 0)
                    {
                        fr << "|" << setw(30) << right << A[i].name << " ";
                    }
                    else
                    {
                        fr << "|" << setw(30) << " " << " ";
                    }
                fr << "|" << setw(30) << A[i].gerai_list[j] << "|" << setw(30) << A[i].blogai_list[j] << "|" << endl;
            }
        }
        fr << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    fr.close();
}

void skaiciuok(int n, int &b, Mokinys A[], Mokinys B[])
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<A[i].gerai; j++)
        {
            int laik = rask (B, b, A[i].gerai_list[j]);
            if (laik == -1)
            {
                B[b].name = A[i].gerai_list[j];
                B[b].gerai_list[0] = A[i].name;
                B[b].gerai = 1;
                B[b].blogai = 0;
                b++;
            }
            else
            {
                B[laik].gerai_list[B[laik].gerai] = A[i].name;
                B[laik].gerai++;
            }
        }
        for (int j=0; j<A[i].blogai; j++)
        {
            int laik = rask(B, b, A[i].blogai_list[j]);
            if (laik == -1)
            {
                B[b].gerai = 0;
                B[b].name = A[i].blogai_list[j];
                B[b].blogai_list[0] = A[i].name;
                B[b].blogai = 1;
                b++;
            }
            else
            {
                B[laik].blogai_list[B[laik].blogai] = A[i].name;
                B[laik].blogai++;
            }
        }
    }
}

void max (int b, Mokinys B[], int &v_s, int &v_n, int &v_skirt)
{
    v_s = 0;
    v_n = 0;
    v_skirt = 0;
    for (int i=0; i<b; i++)
    {
        if (B[i].gerai > B[v_s].gerai)
        {
            v_s = i;
        }
        if (B[i].blogai > B[v_n].blogai)
        {
            v_n = i;
        }
        if (abs(B[i].gerai - B[i].blogai) > abs(B[v_skirt].gerai - B[v_skirt].blogai))
        {
            v_skirt = i;
        }
    }
}
int rask (Mokinys X[], int x, string pav)
{
    for (int i=0; i<x; i++)
    {
        if (X[i].name == pav)
        {
            return i;
        }
    }
    return -1;
}

void rasyk2 (Mokinys B[], int v_s, int v_n, int v_skirt)
{
    ofstream fr(FVR, ios::app);
    fr << B[v_s].gerai << " mokiniai supranta " << B[v_s].name << endl;
    fr << B[v_n].blogai << " mokiniai nesupranta " << B[v_n].name << endl;
    fr << "Didziausias skirtumas yra: " << B[v_skirt].name << "; skirtumas " << abs(B[v_skirt].gerai - B[v_skirt].blogai) << " mokiniai" << endl;
    fr.close();
}
