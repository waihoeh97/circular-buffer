#include <iostream>
#include <limits>

#include "circularBuffer.h"

using namespace std;

CircularBuffer cb;

void Ring()
{
	for (int i = 0; i < cb.getSize(); i++)
	{
		cout << cb.getValue(i) << ",";
	}
	cout << endl << endl;
	cout << "1. Enter a number" << endl;
	cout << "2. Pop number" << endl;
	cout << "3. Get Value" << endl;
	cout << "4. Exit" << endl;
}

void ClearInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Invalid Input, try again" << endl;
}

int main(void)
{
	int choice = 0;
	int index = 0;
	float input = 0.0f;
	float indexSelected = 0.0f;

	bool isLoop = true;

	do
	{
		Ring();

		cin >> choice;

		if (choice == 1)
		{
			cout << endl << "Number: ";
			
			while (!(cin >> input))
			{
				ClearInput();
			}
			cb.Push(input);
		}
		else if (choice == 2)
		{
			cb.Pop();
		}
		else if (choice == 3)
		{
			if (cb.getSize() <= 0)
			{
				cout << "No index to get value" << endl;
			}
			else 
			{
				cout << "Index: ";
				while (!(cin >> index) || index >= 5)
				{
					ClearInput();
				}
				indexSelected = cb.getRelativeValue(index);
				cout << "Value: " << indexSelected << endl;
			}
		}
		else if (choice == 4)
		{
			isLoop = false;
		}
		else
		{
			ClearInput();
		}

		system("pause");
		system("cls");
	} while (isLoop);

	return 0;
}