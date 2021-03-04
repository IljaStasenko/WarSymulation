#include "Fleet.h"
int Fleet::Size() 
{
	return this->SizeOfFleet;
}
int Fleet::SumAP() 
{
	int Sum = 0;
	for (int i = 0; i < this->SizeOfFleet; i++) 
	{
		Sum = Sum + this->List[i].GetAP();
	}
	return Sum;
}
int Fleet::SumSize() 
{
	int Sum = 0;
	for (int i = 0; i < this->SizeOfFleet; i++)
	{
		Sum = Sum + this->List[i].GetSize();
	}
	return Sum;
}
int Fleet::SumActSize()
{
	int Sum = 0;
	for (int i = 0; i < this->SizeOfFleet; i++)
	{
		if (this->List[i].GetState() == 0) 
		{
			Sum = Sum + this->List[i].GetShotPow();
		}
	}
	return Sum;
}
int Fleet::FleetShotPow() 
{
	int SUM = 0;
	for (int i = 0; i < this->SizeOfFleet; i++)
	{
		if (this->List[i].GetState() == 0)
		{
			SUM = SUM + this->List[i].GetShotPow();
		}
	}
	return SUM;
}
void Fleet::SortFleet() 
{
	Ship A;
	for (int i = 0; i < this->SizeOfFleet - 1; i++) 
	{
		for (int j = i + 1; j < this->SizeOfFleet; j++) 
		{
			if (this->List[i].GetShotPow() < this->List[j].GetShotPow()) 
			{
				A.SetShip(this->List[i]);
				this->List[i].SetShip(this->List[j]);
				this->List[j].SetShip(A);
			}
		}
	}
}
int* Fleet::GetListOfNumbers() 
{
	return this->ListOfNumbers;
};
Ship* Fleet::GetSList() 
{
	return this->SList;
};
int Fleet::NumbOfAlive() 
{
	int A = 0;
	for (int i = 0; i < this->SizeOfFleet; i++)
	{
		if (this->List[i].GetState() != 2)
		{
			A++;
		}
	}
	return A;
}
int Fleet::NumbOfActiv() 
{
	int A = 0;
	for (int i = 0; i < this->SizeOfFleet; i++)
	{
		if (this->List[i].GetState() == 0)
		{
			A++;
		}
	}
	return A;
}
