#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Kreps
{
    int num, p_b, m_b, p_dv, m_dv, p_tr, m_tr;
};

struct Naujas
{
    int k, num, sum_t, sum_m, pat_k;
    double vid, proc;
};

void skaityk (int &n, Kreps A[]);
void skaiciuok_atranka (int n, Kreps A[], int &b, Naujas B[], int &max);
int rask (int b, Naujas B[], int num);
void rasyk (int b, Naujas B[], int max);

int main()
{
    int n, b = 0, max;
    Kreps A[100];
    Naujas B[100];
    skaityk(n, A);
    skaiciuok_atranka(n, A, b, B, max);
    rasyk (b, B, max);
    return 0;
}

void skaityk (int &n, Kreps A[])
{
    ifstream fd(FV);
    fd >> n;
    for (int i=0; i<n; i++)
    {
        fd >> A[i].num >> A[i].p_b >> A[i].m_b >> A[i].p_dv >> A[i].m_dv >> A[i].p_tr >> A[i].m_tr;
    }
    fd.close();
}

void skaiciuok_atranka (int n, Kreps A[], int &b, Naujas B[], int &max)
{
    int laik;
    max = 0;
    B[0].num = A[0].num;
    B[0].sum_t = A[0].p_b * 1 + A[0].p_dv * 2 + A[0].p_tr * 3;
    B[0].sum_m = A[0].m_b + A[0].m_dv + A[0].m_tr;
    B[0].pat_k = A[0].p_b + A[0].p_dv + A[0].p_tr;
    B[0].k = 1;
    b = 1;
    for (int i=1; i<n; i++)
    {
        laik = rask (b, B, A[i].num);
        if (laik == -1)
        {
            B[b].num = A[i].num;
            //cout << B[b].num << endl;
            B[b].sum_t = A[i].p_b * 1 + A[i].p_dv * 2 + A[i].p_tr * 3;
            B[b].sum_m = A[i].m_b + A[i].m_dv + A[i].m_tr;
            B[b].pat_k = A[i].p_b + A[i].p_dv + A[i].p_tr;
            B[b].k = 1;
            b++;
        }
        else
        {
            B[laik].sum_t += A[i].p_b * 1 + A[i].p_dv * 2 + A[i].p_tr * 3;
            B[laik].sum_m += A[i].m_b + A[i].m_dv + A[i].m_tr;
            B[laik].pat_k += A[i].p_b + A[i].p_dv + A[i].p_tr;
            B[laik].k++;
        }
    }
    for (int i=0; i<b; i++)
    {
        if (B[i].k > max)
        {
            max = B[i].k;
        }
        B[i].vid = (double)B[i].sum_t / B[i].k;
        B[i].proc = B[i].pat_k / (double)B[i].sum_m  * 100;
    }
}

int rask (int b, Naujas B[], int num)
{
    for (int i=0; i<b; i++)
    {
        if (B[i].num == num)
        {
            return i;
        }
    }
    return -1;
}

void rasyk (int b, Naujas B[], int max)
{
    ofstream fr(FVR);
    fr << max << endl;
    for (int i=0; i<b; i++)
    {
        if (B[i].k == max)
        {
            fr << B[i].num << " " << fixed << setprecision(1) << B[i].vid << " " << setprecision(0) << B[i].proc << " %" << endl;
        }
    }
    fr.close();
}
