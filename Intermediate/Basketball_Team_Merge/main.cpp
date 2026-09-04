#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "senbuviai.txt";
const char FG[]= "naujokai.txt";
const char FVR[]= "komanda.txt";

void skaityk (const char FD[], int &n, int s[]);
void iterpimas (int &n, int s[], int k, int naujokai[]);
void rasyk (int n, int s[]);
int main()
{
    int n, s[20], k, naujokai[20];
    skaityk (FV, n, s);
    skaityk (FG, k, naujokai);
    cout << k << endl;
    iterpimas (n, s, k, naujokai);
    rasyk (n, s);
    return 0;
}

void skaityk (const char FD[], int &n, int s[])
{
    ifstream fd(FD);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> s[i];
    }
    fd.close();
}

void iterpimas (int &n, int s[], int k, int naujokai[])
{
    for (int i=0; i<k; i++)
    {
        if (naujokai[i] <= s[n-1])
        {
            s[n]= naujokai[i];
            n++;
        }
        else
        {
           for (int j=0; j<n; j++)
           {
               if (s[j] < naujokai [i])
               {
                   for (int u=n-1; u>=j; u--)
                   {
                       s[u+1] = s[u];
                   }
                   s[j] = naujokai[i];
                   n++;
                   break;
               }
           }
        }
    }
}

void rasyk (int n, int s[])
{
    ofstream fr(FVR);
    for (int i=0; i<n; i++)
    {
        fr << s[i] << " ";
    }
    fr.close();
}
