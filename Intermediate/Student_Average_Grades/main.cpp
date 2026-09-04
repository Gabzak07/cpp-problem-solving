#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[]= "Duomenys.txt";
const char FVR[]= "Rezultatas.txt";

struct Grades
{
    double math;
    double physics;
    double programming;
};

struct Student
{
    string name;
    int age;
    Grades grades;
    double vid;
};

void skaityk (int &n, Student A[]);
void skaiciuok (int n, Student A[], double &vid_math, double &vid_physics, double &vid_programming);
void geriausias (int n, Student A[], Student &Geriausias);
void rasyk (double vid_math, double vid_physics, double vid_programming, Student Geriausias);

int main()
{
    int n;
    double vid_math = 0, vid_physics = 0, vid_programming = 0;
    Student A[30], Geriausias;
    skaityk (n, A);
    skaiciuok (n, A, vid_math, vid_physics, vid_programming);
    geriausias (n, A, Geriausias);
    rasyk (vid_math, vid_physics, vid_programming, Geriausias);
    return 0;
}

void skaityk (int &n, Student A[])
{
    ifstream fd(FV);
    fd >> n;
    fd.ignore(256, '\n');
    for (int i=0; i<n; i++)
    {
        char eil[21];
        fd.get(eil, 21);
        A[i].name = eil;
        fd >> A[i].age >> A[i].grades.math >> A[i].grades.physics >> A[i].grades.programming;
        fd.ignore(256, '\n');
    }
    fd.close();
}

void skaiciuok (int n, Student A[], double &vid_math, double &vid_physics, double &vid_programming)
{
    for (int i=0; i<n; i++)
    {
        vid_math = vid_math + A[i].grades.math;
        vid_physics =  vid_physics + A[i].grades.physics;
        vid_programming = vid_programming + A[i].grades.programming; //dabar naudoju vid_ kaip skaicuojant sumai;
    }
    vid_math = vid_math / n;
    vid_physics = vid_physics / n;
    vid_programming = vid_programming / n; //dabar vid_ apskaiciuoju kaip vidurki;
}

void geriausias (int n, Student A[], Student &Geriausias)
{
    Geriausias.vid = 0;
    for (int i=0; i<n; i++)
    {
        A[i].vid = (A[i].grades.math + A[i].grades.physics + A[i].grades.programming) / n;
        if (A[i].vid > Geriausias.vid)
        {
            Geriausias.vid = A[i].vid;
            Geriausias.name = A[i].name;
        }
    }
}

void rasyk (double vid_math, double vid_physics, double vid_programming, Student Geriausias)
{
    ofstream fr(FVR);
    fr << "Vidurkiai pagal dalykus: " << endl;
    fr << endl;
    fr << "Matematika: " << fixed << setprecision(1) << vid_math << ";  Fizika: " << vid_physics << ";  Programavimas: " << vid_programming << endl;
    fr <<  endl;
    fr << "Geriausias studentas: " << Geriausias.name << " - vidurkis: " << fixed << setprecision(2) << Geriausias.vid << endl;
    fr.close();
}
