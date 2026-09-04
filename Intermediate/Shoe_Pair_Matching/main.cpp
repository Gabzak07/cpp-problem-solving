#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &n,  int lytis[], int koja[], int dydis[]);
int skaiciavimas (int lyt, int &n, int lytis[], int koja[], int dydis[]);
void salinimas (int &n, int lytis[], int koja[], int dydis[], int vieta);
void rasyk (int m_poru, int v_poru);

int main()
{
    int n, lytis[100] , koja[100] , dydis[100] = {0}, m_poru, v_poru;
    skaityk (n, lytis, koja, dydis);
    m_poru = skaiciavimas (4, n, lytis, koja, dydis);
    v_poru = skaiciavimas (3, n, lytis, koja, dydis);
    rasyk (m_poru, v_poru);
    return 0;
}

void skaityk (int &n, int lytis[], int koja[], int dydis[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> lytis[i] >> koja[i] >> dydis[i];
    }
    fd.close();
}

int skaiciavimas (int lyt, int &n, int lytis[], int koja[], int dydis[])
{
    int poru_k=0;
    for (int i=0; i<n; i++)
    {
        if (lytis[i] == lyt)
        {
            for (int j=i+1; j<n; j++)
            {
                if (lytis[j] == lyt && koja[j] != koja[i] && dydis[j] == dydis[i])
                {
                   poru_k++;
                salinimas (n, lytis, koja, dydis, j);
                salinimas (n, lytis, koja, dydis, i);
                i--;
                break;
                }
            }
        }
    }
    return poru_k;
}

void salinimas (int &n, int lytis[], int koja[], int dydis[], int vieta)
{
    for (int i=vieta; i<n-1; i++)
    {
       lytis[i]=lytis[i+1];
       koja[i]=koja[i+1];
       dydis[i]=dydis[i+1];
    }
    n--;
}

void rasyk (int m_poru, int v_poru)
{
    ofstream fr(FVR);
    fr << m_poru << endl;
    fr << v_poru << endl;
    fr.close();
}
