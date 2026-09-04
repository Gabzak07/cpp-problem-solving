#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Stoteles
{
    string pav;
    int b;
    int st[100];
};

void skaityk (int &n, Stoteles S[]);
void ilgis (int n, Stoteles S[], int ilg[]);
int maksimalus (int ilg[]);
void rasyk (int max, Stoteles S[], int n);

int main()
{
    int n, ilg[100] = {0}, max;
    Stoteles S[100];
    skaityk (n, S);
    ilgis (n, S, ilg);
    max = maksimalus (ilg);
    rasyk (max, S, n);
    return 0;
}

void skaityk (int &n, Stoteles S[])
{
    ifstream fd(FV);
    char eil[21];
    fd >> n;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        fd.get(eil, 21);
        S[i].pav = eil;
        fd >> S[i].b;
        for (int j=0; j<S[i].b; j++)
        {
            fd >> S[i].st[j];
        }
        fd.ignore(256, '\n');
    }
    fd.close();
}

void ilgis (int n, Stoteles S[], int ilg[])
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<S[i].b; j++)
        {
            ilg[S[i].st[j]]++;
        }
    }
}

int maksimalus (int ilg[])
{
    int maxi = 0, v;
    for (int i=0; i<100; i++)
    {
        if (ilg[i] > maxi)
        {
            maxi = ilg[i];
            v = i;
        }
    }
    return v;
}

void rasyk (int max, Stoteles S[], int n)
{
    ofstream fr(FVR);
    fr << max << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<S[i].b; j++)
        {
            if (S[i].st[j] == max)
            {
                fr << S[i].pav << endl;
            }
        }
    }
    fr.close();
}
