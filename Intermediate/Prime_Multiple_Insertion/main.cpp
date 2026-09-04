#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

void skaityk (int &A, int A_seka[], int &B, int B_seka[]);
void iterpimas (int &A, int A_seka[], int B, int B_seka[]);
void rasyk (int A, int A_seka[]);

int main()
{
    int A, A_seka[10], B, B_seka[10];
    skaityk (A, A_seka, B, B_seka);
    iterpimas (A, A_seka, B, B_seka);
    rasyk (A, A_seka);
    return 0;
}

void skaityk (int &A, int A_seka[], int &B, int B_seka[])
{
    ifstream fd(FV);
    fd >> A;
    for (int i=0; i<A; i++)
    {
        fd >> A_seka[i];
    }
    fd >> B;
    for (int i=0; i<B; i++)
    {
        fd >> B_seka[i];
    }
    fd.close();
}

void iterpimas (int &A, int A_seka[], int B, int B_seka[])
{
    for (int i=0; i<B; i++)
    {
        for (int j=0; j<A; j++)
        {
            if (B_seka[i] > A_seka[j] && B_seka[i]%A_seka[j]==0)
            {
                for (int k= A-1; k>j; k--)
                {
                    A_seka[k+1] = A_seka[k];
                }
                A_seka[j+1] = B_seka[i];
                A++;
            }
        }
    }
}

void rasyk (int A, int A_seka[])
{
    ofstream fr(FVR);
    for (int i=0; i<A; i++)
    {
        fr << A_seka[i] << " ";
    }
    fr.close();
}
