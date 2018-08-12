#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	class Mail {
	public:
		string state;
		double cost;
	};

	Mail data[1000];
	int count = 0;

	ifstream inFile("C:\\Users\\Dell\\Desktop\\fedex.txt");
	if (inFile.good())
	{
		while (!inFile.eof())
		{
			inFile >> data[count].state;
			inFile >> data[count].cost;
			count++;
		}
	}
	inFile.close();

	while (true)
	{
		cout << "-----------------------------------------------" << endl;
		cout << "Welcome to FedEx in the middle of nowhere. :->" << endl;
		cout << "This tool will help you keep track of packages." << endl;
		cout << "-----------------------------------------------" << endl;
		//Menu
		cout << "1- Create New Mail" << endl;
		cout << "2- Search Mail (by State)" << endl;
		cout << "3- Search Mail (by Cost)" << endl;
		cout << "4- Grand Report" << endl;
		cout << "0- " << endl;

		//choice
		cout << "What do you want to do?" << endl;
		int choice;
		cin >> choice;

		//1- Create New Mail
		if (choice == 1)
		{
			cout << "Destination State (two letter, no space): " << endl;
			string userState;
			cin >> userState;

			cout << "Cost of this Delivery: " << endl;
			int userCost;
			cin >> userCost;

			data[count].state = userState;
			data[count].cost = userCost;
			count++;

			ofstream outFile("C:\\Users\\Dell\\Desktop\\fedex.txt");
			for (int i = 0; i < count; i++)
			{
				outFile << data[i].state << " ";
				outFile << data[i].cost << endl;
			}
			outFile.close();
		}

		//2- Search Mail (by State)
		else if (choice == 2)
		{
			cout << "Enter state you want to see (two letter, no space): " << endl;
			string userState;
			cin >> userState;
			cout << "Here are the packages to " << userState << ": " << endl;
			for (int i = 0; i < count; i++)
			{
				if (userState == data[i].state)
				{
					cout << "Package to " << data[i].state << " for $" << data[i].cost << endl;
				}
			}
		}

		//3- Search Mail (by Cost)
		else if (choice == 3)
		{
			cout << "Enter minimum package price: " << endl;
			double userPrice;
			cin >> userPrice;
			cout << "Here are the packages that are larger in value than " << userPrice << ":" << endl;
			for (int i = 0; i < count; i++)
			{
				if (userPrice < data[i].cost)
				{
					cout << "Package to " << data[i].state << " for $" << data[i].cost << endl;
				}
			}
		}

		//4- Grand Report
		else if (choice == 4)
		{
			cout << "Here are all the packages for today: " << endl;
			for (int i = 0; i < count; i++)
			{
				cout << data[i].state << data[i].cost << endl;
			}
		}

		//0- Break
		else if (choice == 0)
		{
			break;
		}
	}
	system("pause");
	return 0;
}