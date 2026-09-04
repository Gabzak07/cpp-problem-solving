#include <iostream>
#include <fstream>

using namespace std;

const char FV[]= "duom.csv";
const char FVR[]= "rez.txt";

struct Miestai
{
    string m, s, s_n[30];
    int sk, sk_n[30], sum, k;
};

void skaityk (int &n, Miestai M[]);
int rask (int b, Miestai N[], string s);
void skaiciuok (int n, Miestai M[], int &b, Miestai N[]);
void rikiavimas (int b, Miestai N[]);
void rasyk (int b, Miestai N[]);


int main()
{
    int n, b = 0; // naujo saraso kiekio kintamasis;
    Miestai M[30], N[30];
    skaityk (n, M);
    cout << n << endl;
    skaiciuok (n, M, b, N);
    rikiavimas (b, N);
    rasyk (b, N);

    return 0;
}

void skaityk (int &n, Miestai M[])
{
    ifstream fd(FV);
    fd >> n;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        getline(fd, M[i].m, ';');
        getline(fd, M[i].s, ';');
        fd >> M[i].sk;
        fd.ignore(256, '\n');
    }
    fd.close();
}

void skaiciuok (int n, Miestai M[], int &b, Miestai N[])
{
    int laik;
    for (int i=0; i<n; i++)
    {
        laik = rask (b, N, M[i].s);
        cout << laik << endl;
        if (laik == -1)
        {
            N[b].s = M[i].s;
            N[b].s_n[0] = M[i].m;
            N[b].sk_n[0] = M[i].sk;
            N[b].sum = M[i].sk;
            N[b].k = 1;
            b++;
        }
        else
        {
            N[laik].s_n[N[laik].k] = M[i].m;
            N[laik].sk_n[N[laik].k] = M[i].sk;
            N[laik].sum += M[i].sk;
            N[laik].k++;
        }
    }
}

int rask (int b, Miestai N[], string s)
{
    for (int i=0; i<b; i++)
    {
        if (N[i].s == s)
        {
            return i;
        }
    }
    return -1;
}

void rikiavimas (int b, Miestai N[])
{
    for (int i=0; i<b-1; i++)
    {
        for (int j=i+1; j<b; j++)
        {
            if (N[i].s_n > N[j].s_n)
            {
                swap (N[i], N[j]);
            }
        }
    }
}

void rasyk (int b, Miestai N[])
{
    ofstream fr(FVR);
    for (int i=0; i<b; i++)
    {
        fr << N[i].s << " " << N[i].k << " " << N[i].sum << endl;
        for (int j=0; j<N[i].k; j++)
        {
            fr << N[i].s_n[j] << " " << N[i].sk_n[j] << endl;
        }
    }
    fr.close();
}
