// Inventory_Records.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constants 
const int DESC_SIZE = 31;	// Description size
const int NUM_RECORDS = 5;	// Number of records

// Declaration of InventoryItem structure
struct InventoryItem
{
	char desc[DESC_SIZE];
	int qty;
	double price;
};

int main()
{
	// Create an empty InventoryItem structure
	InventoryItem record = { "", 0, 0.0 };

	// Open the file for binary output
	fstream inventory;
	inventory.open("Inventory.dat", ios::in | ios::out | ios::binary);

	// Write the blank record
	for (int i = 0; i < NUM_RECORDS; i++)
	{
		cout << "Now writing record " << i << endl;
		inventory.write(reinterpret_cast<char *>(&record),
						sizeof(record));
	}

	// Close the file
	inventory.close();
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
