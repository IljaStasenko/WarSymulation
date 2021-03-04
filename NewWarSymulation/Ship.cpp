#include "Ship.h"
#include <iostream>
#include <ctime>
using namespace std;
void Ship::SetSize(int n) 
{
	this->Size = n;
}
void Ship::SetAP(int n) 
{
	this->ActiveProtect = n;
}
void Ship::Setdem(int n)
{
	this->Damage = n;
}
void Ship::Setstate(int n)
{
	this->State = n;
}
void Ship::GetDamage(double Ch, int n) 
{
	if (this->State == 0) 
	{
		for (int i = 0; i < n; i++) 
		{
			int A = rand() % 100 + 1;
			if (A > Ch) 
			{
				this->Damage++;
				if (this->Size == this->Damage)
				{
					this->State = 2;
					break;
				}
			}
		}
	}
}
void Ship::GoAway() 
{
	if (this->State == 0) 
	{
		this->State = 1;
	}
}
int Ship::GetAP() 
{
	return this->ActiveProtect;
}
int Ship::GetSize() 
{
	return this->Size;
}
int Ship::GetState() 
{
	return this->State;
}
int Ship::GetDam() 
{
	return this->Damage;
}
int Ship::GetShotPow() 
{
	int A = this->GetSize() - this->GetDam();
	return A;
}
void Ship::SetShip(Ship A) 
{
	this->SetSize(A.GetSize());
	this->SetAP(A.GetAP());
	this->Setdem(A.GetDam());
	this->Setstate(A.GetState());
}