#pragma once
class Ship
{
private:
	int ActiveProtect;
	int Size;
	int State;
	int Damage;
public:
	Ship() 
	{
		this->ActiveProtect = 1;
		this->Size = 1;
		this->State = 0;
		this->Damage = 0;
	}
	Ship(int a, int b) 
	{
		this->ActiveProtect = a;
		this->Size = b;
		this->State = 0;
		this->Damage = 0;
	}
	void GetDamage(double Ch, int n);
	void GoAway();
	int GetAP();
	int GetSize();
	int GetState();
	int GetDam();
	int GetShotPow();
	void SetSize(int a);
	void SetAP(int a);
	void Setdem(int a);
	void Setstate(int a);
	void SetShip(Ship A);
};

