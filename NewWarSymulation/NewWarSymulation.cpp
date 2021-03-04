#include <iostream>
#include <ctime>
#include "Fleet.h"
#include "Ship.h"
using namespace std;

double ChA(Fleet A, Fleet P, int ProtBild)
{
    double ChenA;
    double X = A.SumAP();
    double Y = P.SumAP();
    if (A.SumAP() >= P.SumAP())
    {
        ChenA = (X / Y) * 10.0 /*+ 100.0*/ - ProtBild * 10.0;
        if (ChenA < 10)
        {
            ChenA = 10;
        }
        if (ChenA > 85)
        {
            ChenA = 85;
        }
    }
    else
    {
        ChenA = 0 - ((Y / X) * 10.0 /*- 100.0*/ + ProtBild * 10.0);
        if (ChenA < 10)
        {
            ChenA = 10;
        }
        if (ChenA > 85)
        {
            ChenA = 85;
        }
    }
    return ChenA;
}
double ChP(Fleet A, Fleet P, int ProtBild)
{
    double X = A.SumAP();
    double Y = P.SumAP();
    double ChenP;
    if (A.SumAP() >= P.SumAP())
    {
        ChenP = 0 - ((X / Y) * 10.0 /*+ 100.0*/ - ProtBild * 10.0);
        if (ChenP < 10)
        {
            ChenP = 10;
        }
        if (ChenP > 85)
        {
            ChenP = 85;
        }

    }
    else
    {
        ChenP = (Y / X) * 10.0 /*- 100.0*/ + ProtBild * 10.0;
        if (ChenP < 10)
        {
            ChenP = 10;
        }
        if (ChenP > 85)
        {
            ChenP = 85;
        }
    }
    return ChenP;
}
void FirstStrik(Fleet A, Fleet P, double ChP)
{
    if (A.SumSize()>=P.SumSize()) 
    {
        for (int i = 0; i < P.Size(); i++)
        {
            P.List[i].GetDamage(ChP, P.List[i].GetSize());
        }
    }
    else 
    {
        int Al = A.SumSize();
        int Be = 0;
        int Next = 0;
        bool Ch = true;
        while (Al > 0) 
        {
            if (Ch) 
            {
                Be = P.List[Next].GetSize();
                Ch = false;
            }
            else 
            {
                Be--;
                Al--;
                P.List[Next].GetDamage(ChP, 1);
                if (Be == 0)
                {
                    Next++;
                    Ch = true;
                }
            }
        }
    }
    A.SortFleet();
    P.SortFleet();
}
void Fight(Fleet A, Fleet P, double ChA, double ChP) 
{
    if (A.SumActSize()>=P.SumActSize()) 
    {
        int Al = P.SumActSize();
        int Be = 0;
        int Next = 0;
        bool Ch = true;
        int Cou = 1;
        while (Al > 0)
        {
            if (A.List[Next].GetState() == 0) 
            {
                if (Ch)
                {

                    Be = A.List[Next].GetSize();
                    if (Next != 0)
                    {
                        A.List[Next - Cou].GoAway();
                        Cou = 1;
                    }
                    Ch = false;
                }
                else
                {
                    Be--;
                    Al--;
                    A.List[Next].GetDamage(ChA, 1);
                    if (Be == 0)
                    {
                        Next++;
                        Ch = true;
                    }
                }
            }
            else 
            {
                Next++;
                Cou++;
            }
        }
        for (int i = 0; i < P.Size(); i++)
        {
            P.List[i].GetDamage(ChP, P.List[i].GetSize());
        }
        if (Ch == false)
        {
            int Last = A.List[Next].GetShotPow();
            A.List[Next].GetDamage(ChA, A.List[Next].GetShotPow());
            A.List[Next].GoAway();
            Al = Last;
            Be = 0;
            Next = 0;
            Ch = true;
            while (Al > 0)
            {
                if (Ch)
                {
                    Be = P.List[Next].GetSize();
                    Ch = false;
                }
                else
                {
                    Be--;
                    Al--;
                    P.List[Next].GetDamage(ChP, 1);
                    if (Be == 0)
                    {
                        Next++;
                        Ch = true;
                    }
                }
            }
        }
        else 
        {
            A.List[Next - Cou].GoAway();
        }
    }
    else 
    {
        int Al = A.SumActSize();
        int Be = 0;
        int Next = 0;
        bool Ch = true;
        while (Al > 0)
        {
            if (Ch)
            {
                Be = P.List[Next].GetSize();
                Ch = false;
            }
            else
            {
                Be--;
                Al--;
                P.List[Next].GetDamage(ChP, 1);
                if (Be == 0)
                {
                    Next++;
                    Ch = true;
                }
            }
        }
        for (int i = 0; i < A.Size(); i++)
        {
            A.List[i].GetDamage(ChA, A.List[i].GetSize());
        }
        if (Ch == false)
        {
            int Last = P.List[Next].GetShotPow();
            P.List[Next].GetDamage(ChP, P.List[Next].GetShotPow());
            Al = Last;
            Be = 0;
            Next = 0;
            Ch = true;
            while (Al > 0)
            {
                if (Ch)
                {
                    Be = A.List[Next].GetSize();
                    Ch = false;
                }
                else
                {
                    Be--;
                    Al--;
                    A.List[Next].GetDamage(ChA, 1);
                    if (Be == 0)
                    {
                        Next++;
                        Ch = true;
                    }
                }
            }
        }
        if (P.NumbOfAlive() != 0)
        {
            for (int i = 0; i < A.Size(); i++)
            {
                A.List[i].GoAway();
            }
        }
    }
    A.SortFleet();
    P.SortFleet();
}
void Battle(double NumbOfTrys, Fleet a, Fleet p, int ProtBild)
{
    a.SortFleet();
    p.SortFleet();
    srand(time(0));
    double NumOfWins = 0.0;
    double ASum = 0.0;
    double PSum = 0.0;
    double AAct = 0.0;
    double ChenA;
    double ChenP;
    ChenA = ChA(a, p, ProtBild);
    ChenP = ChP(a, p, ProtBild);
    cout << ChenA << " " << ChenP << endl;
    for (int i = 0; i < NumbOfTrys; i++)
    {
        Fleet A(a.GetNumberOfTypes(), a.GetListOfNumbers(), a.GetSList());
        Fleet P(p.GetNumberOfTypes(), p.GetListOfNumbers(), p.GetSList());
        //FirstStrik(A, P, ChenP);
        A.SortFleet();
        P.SortFleet();
        while (A.NumbOfActiv() > 0 && P.NumbOfActiv() > 0)
        {
            Fight(A, P, ChenA, ChenP);
        }
        if (P.NumbOfActiv() == 0 && A.NumbOfActiv() != 0)
        {
            NumOfWins++;
        }
        for (int j = 0; j < A.Size(); j++)
        {
            if (A.List[j].GetState() == 2)
            {
                if (A.List[j].GetAP() == 1 && A.List[j].GetSize() == 1)
                {
                    ASum++;
                }
                else
                {
                    ASum = ASum + A.List[j].GetAP() + A.List[j].GetSize();
                }
            }
        }
        for (int j = 0; j < P.Size(); j++)
        {
            if (P.List[j].GetState() == 2)
            {
                if (P.List[j].GetAP() == 1 && P.List[j].GetSize() == 1)
                {
                    PSum++;
                }
                else
                {
                    PSum = PSum + P.List[j].GetAP() + P.List[j].GetSize();
                }
            }
        }
        AAct = AAct + A.NumbOfActiv();
        if (i % 50 == 0) 
        {
            //cout << i / 50 << endl;
        }
    }
    double Mox = NumOfWins / NumbOfTrys;
    ASum = ASum / NumbOfTrys;
    PSum = PSum / NumbOfTrys;
    AAct = AAct / NumbOfTrys;
    cout << Mox << " " << AAct << " " << ASum << " " << PSum << " " << ASum / PSum << endl;
}
int main()
{
    srand(time(0));
    Ship A(1, 1);
    Ship B(1, 4);
    int y[2] = { 5, 1 };
    int x[1] = { 10 };
    Ship X[1] = { A };
    Fleet a(1, x, X);
    Ship Y[2] = { A, B };
    Fleet b(2, y, Y);
    Battle(20000.0, a, b, 0);
    Battle(20000.0, b, a, 0);
}
