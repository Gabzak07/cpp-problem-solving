#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char FV[]= "Olimpines.txt";
const char FD[]= "Pasiekimai.csv";
const char FVR[]= "Rezultatas.txt";

struct Olimp
{
    string v;
    double rez;
};

struct Pasiek
{
    string v, salis;
    int data;
    double rez, skirt;
};

void skaityk (int &n, Olimp A[], Pasiek B[]);
double vidurkis_olimp (Olimp A[], int n);
double vidurkis_pasiek (Pasiek B[], int n);
void skirtumas_min_max (ofstream &fr, Olimp A[], int n);
void skirtumas_ir_rasyk(ofstream &fr, int n, Olimp A[], Pasiek B[], double vid_olimp, double vid_pasiek);
int metai (int m);
string vardas (string v);
void seniausias_rezult (ofstream &fr, Pasiek B[], int n);
void skirtumas_pasiekimu (ofstream &fr, int n, Olimp A[], Pasiek B[]);

int main()
{
    ofstream fr(FVR);
    int n;
    double vid_olimp, vid_pasiek;
    Olimp A[32];
    Pasiek B[32];
    skaityk (n, A, B);
    vid_olimp = vidurkis_olimp(A, n);
    vid_pasiek = vidurkis_pasiek(B, n);
    skirtumas_ir_rasyk(fr, n, A, B, vid_olimp, vid_pasiek);
    seniausias_rezult(fr, B, n);
    skirtumas_pasiekimu(fr, n, A, B);

    return 0;
}

void skaityk (int &n, Olimp A[], Pasiek B[])
{
    ifstream fd(FV); //islieka tas pats kaip txt, taip ir csv;
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> A[i].v >> A[i].rez;
        cout << A[i].rez << endl;
    }
    fd.close();
    ifstream fw(FD);
    string laik;
    int b = 0;
    while(!fw.eof())
    {
        getline(fw, B[b].v, ';'); //nuskaitome string'a iki ,, ; '' ;
        getline(fw, laik, ';'); // nuskaitome laikina string'a, i double negalime nuskaityti, getline veikia tik su string'ais;
        B[b].rez = stod(laik); // laikina konvertuojame i double    stod - skirtas double tipui, o stoi - int tipui.
        cout << B[b].rez << endl;
        getline(fw, laik, ';');
        B[b].data = stoi(laik);
        getline(fw, B[b].salis); // jei eilutes paskutinis kintamasis yra string, naudojame getline be kabliataskio, o jeigu skaicius, tai nuskaitome iprastai fd >> ..., bet reikia fd.ignore();
        b++;
    }
    fw.close();
}

double vidurkis_olimp (Olimp A[], int n)
{
    double sum = 0;
    for (int i=0; i<n; i++)
    {
        sum += A[i].rez;
    }
    return sum / n;
}

double vidurkis_pasiek (Pasiek B[], int n)
{
    double sum = 0;
    for (int i=0; i<n; i++)
    {
        sum += B[i].rez;
    }
    return sum / n;
}

void skirtumas_min_max (ofstream &fr, Olimp A[], int n)
{
    double max = 0, mini = A[0].rez;
    for (int i=0; i<n; i++)
    {
        if (A[i].rez > max)
        {
            max = A[i].rez;
        }
    }
    for (int i=0; i<n; i++)
    {
        if (A[i].rez < mini)
        {
            mini = A[i].rez;
        }
    }
    fr << "Skirtumas tarp didziausio ir maziausio rezultato " << max - mini << " m." << endl;
}

void skirtumas_ir_rasyk(ofstream &fr, int n, Olimp A[], Pasiek B[], double vid_olimp, double vid_pasiek)
{
    fr << "Disko metimo duomenu analizes rezultatai: " << endl;
    fr << endl;
    fr << "Olimpines zaidines: " << endl;
    fr << "Vidutiniskai diskas skriejo " << vid_olimp << " m." << endl;
    skirtumas_min_max(fr, A, n);
    fr << endl;
    fr << "Geriausi rezultatai" << endl;
    fr << "Vidutiniskai diskas skriejo " << vid_pasiek << " m." << endl;
    if (vid_pasiek > vid_olimp)
    {
        fr << "Vidurkis " << vid_pasiek - vid_olimp << " m didesnis negu olimpinese zaidynese" << endl;
    }
    else
    {
         fr << "Vidurkis " << vid_olimp - vid_pasiek << " m mazesnis negu olimpinese zaidynese" << endl;
    }
    fr << endl;
}

int metai (int m)
{
    return m/10000;
}

string vardas (string v)
{
    return v.erase(0, 1);
}

void seniausias_rezult (ofstream &fr, Pasiek B[], int n)
{
    int mini = metai(B[0].data), poz = 0;
    for (int i=0; i<n; i++)
    {
        if ( metai(B[i].data) < mini)
        {
            mini = metai(B[i].data);
            poz = i;
        }
    }
    fr << "Seniausiai pasiektas geriausias rezultatas: " << endl;
    fr << vardas(B[poz].v) << " " << B[poz].rez << " " << metai(B[poz].data) << " " << B[poz].salis << endl;
    fr << endl;
}

void skirtumas_pasiekimu (ofstream &fr, int n, Olimp A[], Pasiek B[])
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (A[i].v == B[j].v)
            {
                B[j].skirt =  B[j].rez - A[i].rez;
            }
        }
    }
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (B[i].skirt > B[j].skirt)
            {
                swap (B[i], B[j]);
            }
        }
    }
    fr << "Skirtumas tarp sportininku pasiekimu: " << endl;
    for (int i=0; i<n; i++)
    {
        fr << vardas(B[i].v) << " " << B[i].skirt << endl;
    }

}
