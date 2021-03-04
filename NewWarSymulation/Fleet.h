#pragma once
#include "Ship.h"
class Fleet
{
private:
	int NumberOfTypes;
	int SizeOfFleet;
	int* ListOfNumbers;
	Ship* SList;
public:
	Ship* List;
	Fleet(int a, int* A, Ship* B) 
	{
		this->NumberOfTypes = a;
		this->ListOfNumbers = A;
		this->SList = new Ship[a];
		for (int q = 0; q < a; q++) 
		{
			SList[q] = B[q];
		}
		int SUM = 0;
		for (int i = 0; i < a; i++) 
		{
			SUM = SUM + A[i];
		}
		this->SizeOfFleet = SUM;
		this->List = new Ship[SUM];
		int c = 0;
		for (int i = 0; i < a; i++) 
		{
			for (int j = c; j < c + A[i]; j++) 
			{
				List[j] = B[i];
			}
			c = c + A[i];
		}
	}
	int GetNumberOfTypes() 
	{
		return this->NumberOfTypes;
	}
	int SumAP();
	int SumSize();
	int SumActSize();
	int NumbOfActiv();
	void SortFleet();
	int Size();
	int FleetShotPow();
	int NumbOfAlive();
	int* GetListOfNumbers();
	Ship* GetSList();
};

