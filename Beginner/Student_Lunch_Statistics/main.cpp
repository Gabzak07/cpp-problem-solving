#include <iostream>
#include <fstream>

using namespace std;

const char FV[] = "Duomenys1.txt";
const char FVR [] = "Rezultatai.txt";

int main()
{
    ifstream fd (FV);
    ofstream fr (FVR);

    int n, k, p, k_p = 0, gerimas = 0, antrasis= 0, sriuba = 0, desertas = 0;
    fd >> n;
    for ( int i = 0; i < n; i++)
    {
        fd >> k;
        switch (k)
        {
            case 0: k_p+=1; break;
        }
        for (int j=0; j<k; j++)
        {
          fd >> p;
          switch (p)
          {
              case 1: gerimas+=1; break;
              case 2: antrasis+=1; break;
              case 3: sriuba+=1; break;
              default: desertas++; break;
          }
        }
    }
    fr<<k_p << "moksleiviai valge kompleksinius pietus"<< endl;
    fr<<gerimas << "moksleiviai gere gerima"<<endl;
    fr<<antrasis << "moksleiviai valge antraji patiekala"<<endl;
    fr<<sriuba << "moksleiviai valge sriuba"<<endl;
    fr<<desertas << "moksleiviai valge deserta"<<endl;



    return 0;
}
