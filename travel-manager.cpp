#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

void menu();

class ManageMenu
{
protected:
	string userName;

public:
	ManageMenu()
	{
		cout << "\n\n\n\n\n\n\n\t Enter Your Name to Continue as an Admin: ";
		cin >> userName;
		system("CLS");
		menu();
	}
	~ManageMenu() {}
};

class Customers
{
public:
	string name, gender, address;
	int age, mobilenumber;
	static int cusID;
	char all[999];

	void getDetails()
	{
		ofstream out("old-customers.txt", ios::app);

		// Nhập Customer ID
		while (true)
		{
			cout << "Enter Customer ID: ";
			cin >> cusID;
			if (cin.fail())
			{
				cin.clear();										 // Xóa cờ lỗi
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua phần còn lại của dòng
				cout << "Invalid input. Please enter a valid number for Customer ID: ";
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua ký tự newline còn lại trong bộ đệm
				break;												 // Thoát khỏi vòng lặp nếu nhập hợp lệ
			}
		}

		// Nhập Name
		cout << "Enter Name: ";
		getline(cin, name);

		// Nhập Age
		while (true)
		{
			cout << "Enter Age: ";
			cin >> age;
			if (cin.fail() || age < 0)
			{
				cin.clear();										 // Xóa cờ lỗi
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua phần còn lại của dòng
				cout << "Invalid input. Please enter a positive number for Age: ";
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua ký tự newline còn lại trong bộ đệm
				break;												 // Thoát khỏi vòng lặp nếu nhập hợp lệ
			}
		}

		// Nhập Gender
		cout << "Enter Gender: ";
		getline(cin, gender);

		// Nhập Address
		cout << "Enter Address: ";
		getline(cin, address);

		// Nhập Mobile Number
		while (true)
		{
			cout << "Enter Mobile Number: ";
			cin >> mobilenumber;
			if (cin.fail() || mobilenumber <= 0)
			{
				cin.clear();										 // Xóa cờ lỗi
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua phần còn lại của dòng
				cout << "Invalid input. Please enter a valid mobile number: ";
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua ký tự newline còn lại trong bộ đệm
				break;												 // Thoát khỏi vòng lặp nếu nhập hợp lệ
			}
		}

		out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nGender: " << gender << "\nAddress: " << address << "\nMobile Number: " << mobilenumber << endl;
		out.close();
		cout << "\nSAVED \nNOTE: We save your details for future purposes\n"
			 << endl;
	}

	void showDetails()
	{
		ifstream in("old-customers.txt");
		{
			if (!in)
			{
				cout << "File Error!!!" << endl;
			}
			while (!(in.eof()))
			{
				in.getline(all, 999);
				cout << all << endl;
			}
			in.close();
		}
	}

	void searchCustomerID(int id)
	{
		ifstream in("old-customers.txt");
		bool found = false;
		string line;

		if (!in)
		{
			cout << "File opening error!!!" << endl;
			return;
		}

		cout << "Searching for Customer ID: " << id << endl;

		while (getline(in, line))
		{
			if (line.find("Customer ID: " + to_string(id)) != string::npos)
			{
				found = true;
				cout << "\n------------ Customer Details ------------\n";
				cout << line << endl;
				while (getline(in, line) && !line.empty())
				{
					cout << line << endl;
				}
				cout << "------------------------------------------\n";
				break;
			}
		}

		if (!found)
		{
			cout << "Customer with ID " << id << " not found." << endl;
		}

		in.close();
	}
};

int Customers::cusID;

class Cabs
{
public:
	int cabChoice, kilometers, hireCab;
	float cabCost;
	static float lastcabCost;

	void cabDetails()
	{
		cout << "Your hotel, our service, everywhere you go" << endl;
		cout << "------------------X Cabs------------------" << endl;
		cout << "1. Rent a Standard Cab - 1.3 dola for 1KM" << endl;
		cout << "2. Rent a Luxury Cab - 3 dola for 1KM" << endl;
		cout << "nTo calculate the cost for your jurney" << endl;
		cout << "Enter which kind of cab you need: ";
		cin >> cabChoice;
		cout << "Enter kilometer you have to travel: ";
		cin >> kilometers;

		if (cabChoice == 1)
		{
			cabCost = kilometers * 1.3;
			cout << "\nYour tour cost " << cabCost << " dola for a Standard Cab" << endl;
			cout << "Press 1 to hire this car: or";
			cout << " Press 2 to select another cab: ";
			cin >> hireCab;
			system("CLS");

			if (hireCab == 1)
			{
				lastcabCost = cabCost;
				cout << "\nYou have successfully hired a Standard Cab" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (hireCab == 2)
			{
				cabDetails();
			}
			else
			{
				cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
				Sleep(999);
				system("CLS");
				cabDetails();
			}
		}

		else if (cabChoice == 2)
		{
			cabCost = kilometers * 3;
			cout << "\nYour tour cost " << cabCost << " dola for a Luxury Cab" << endl;
			cout << "Press 1 to hire this car: or";
			cout << " Press 2 to select another cab: ";
			cin >> hireCab;
			system("CLS");

			if (hireCab == 1)
			{
				lastcabCost = cabCost;
				cout << "\nYou have successfully hired a Luxury Cab" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (hireCab == 2)
			{
				cabDetails();
			}
			else
			{
				cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
				Sleep(999);
				system("CLS");
				cabDetails();
			}
		}
		else
		{
			cout << "Invalid Input! Redirecting to Main Menu \nPlease Wait!" << endl;
			Sleep(999);
			system("CLS");
			menu();
		}

		cout << "\nPress 1 to Redirect Main Menu: ";
		cin >> hireCab;
		system("CLS");
		if (hireCab == 1)
		{
			menu();
		}
		else
		{
			menu();
		}
	}
};

float Cabs::lastcabCost;

class Booking
{
public:
	int choiceHotel, packChoice;
	static float hotelCost;
	int gotoMenu;
	void hotels()
	{
		string hotelNo[] = {"A", "B", "C"};
		for (int a = 0; a < 3; a++)
		{
			cout << (a + 1) << ". Hotel" << hotelNo[a] << endl;
		}

		cout << "\nCurrently we collaborated with above hotels!" << endl;
		cout << "Press any key to back or\nEnter number of the hotel you want to book: ";
		cin >> choiceHotel;
		system("CLS");

		if (choiceHotel == 1)
		{
			cout << "----------WELCOME TO HOTEL A-----------\n";
			cout << "Indulge in unparalleled luxury and discover a world of comfort and elegance at our exclusive hotel" << endl;
			cout << "Packages offered by A: \n"
				 << endl;

			cout << "1. Standard Pack" << endl;
			cout << "\tAll basic facilities you need just for: 200 dola" << endl;
			cout << "2. Premium Pack" << endl;
			cout << "\tEnjoy Premium: 400 dola" << endl;
			cout << "3. Luxury Pack" << endl;
			cout << "\tLive a Luxury at A: 1000 dola" << endl;
			cout << "Press any key to back or\nEnter package number you want to book: ";
			cin >> packChoice;

			if (packChoice == 1)
			{
				hotelCost = 200;
				cout << "\nYou have successfully booked Standard Pack at A" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (packChoice == 2)
			{
				hotelCost = 400;
				cout << "\nYou have successfully booked Premium Pack at A" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (packChoice == 3)
			{
				hotelCost = 1000;
				cout << "\nYou have successfully booked Luxury Pack at A" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else
			{
				cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
				Sleep(999);
				system("CLS");
				hotels();
			}

			cout << "\nPress 1 to redirect Main Menu: ";
			cin >> gotoMenu;
			if (gotoMenu == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}

		if (choiceHotel == 2)
		{
			cout << "----------WELCOME TO HOTEL B-----------\n";
			cout << "Experience the epitome of hospitality as you immerse yourself in our world of refined luxury and bespoke services." << endl;
			cout << "Packages offered by A: \n"
				 << endl;

			cout << "1. Standard Pack" << endl;
			cout << "\tAll basic facilities you need just for: 220 dola" << endl;
			cout << "2. Premium Pack" << endl;
			cout << "\tEnjoy Premium: 440 dola" << endl;
			cout << "3. Luxury Pack" << endl;
			cout << "\tLive a Luxury at B: 1200 dola" << endl;
			cout << "Press any key to back or\nEnter package number you want to book: ";
			cin >> packChoice;

			if (packChoice == 1)
			{
				hotelCost = 220;
				cout << "\nYou have successfully booked Standard Pack at B" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (packChoice == 2)
			{
				hotelCost = 440;
				cout << "\nYou have successfully booked Premium Pack at B" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (packChoice == 3)
			{
				hotelCost = 1200;
				cout << "\nYou have successfully booked Luxury Pack at B" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else
			{
				cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
				Sleep(999);
				system("CLS");
				hotels();
			}
			cout << "\nPress 1 to redirect Main Menu: ";
			cin >> gotoMenu;
			if (gotoMenu == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}

		if (choiceHotel == 3)
		{
			cout << "----------WELCOME TO HOTEL C-----------\n";
			cout << "A harmonious blend of contemporary design and timeless elegance, our hotel offers a one-of-a-kind experience for discerning travelers" << endl;
			cout << "Packages offered by A: \n"
				 << endl;

			cout << "1. Standard Pack" << endl;
			cout << "\tAll basic facilities you need just for: 250 dola" << endl;
			cout << "2. Premium Pack" << endl;
			cout << "\tEnjoy Premium: 500 dola" << endl;
			cout << "3. Luxury Pack" << endl;
			cout << "\tLive a Luxury at A: 1500 dola" << endl;
			cout << "Press any key to back or\nEnter package number you want to book: ";
			cin >> packChoice;

			if (packChoice == 1)
			{
				hotelCost = 250;
				cout << "\nYou have successfully booked Standard Pack at C" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (packChoice == 2)
			{
				hotelCost = 500;
				cout << "\nYou have successfully booked Premium Pack at C" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (packChoice == 3)
			{
				hotelCost = 1500;
				cout << "\nYou have successfully booked Luxury Pack at C" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else
			{
				cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
				Sleep(999);
				system("CLS");
				hotels();
			}

			cout << "\nPress 1 to redirect Main Menu: ";
			cin >> gotoMenu;
			if (gotoMenu == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}

		else
		{
			cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
			Sleep(999);
			system("CLS");
			menu();
		}
	}
};

float Booking::hotelCost;

class Charges : public Customers, Booking, Cabs
{
public:
	void printBill()
	{
		ofstream outf("receipt.txt", ios::app);
		{
			outf << "----------X Travel Agency----------" << endl;
			outf << "--------------Receipt--------------" << endl;
			outf << "___________________________________" << endl;

			outf << "Custommer ID: " << Customers::cusID << endl
				 << endl;
			outf << "Description\t\t Total" << endl;
			outf << "Hotel cost:\t\t" << fixed << setprecision(2) << Booking::hotelCost << endl;
			outf << "Travel (Cab) cost:\t " << fixed << setprecision(2) << Cabs::lastcabCost << endl;

			outf << "____________________________________" << endl;
			outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastcabCost << endl;
			outf << "___________________________________" << endl;
			outf << "------------THANK YOU--------------" << endl;
			outf << endl
				 << endl;
		}

		outf.close();
	}

	void showBill()
	{
		ifstream inf("receipt.txt");
		{
			if (!inf)
			{
				cout << "File opening error!!!" << endl;
			}
			while (!(inf.eof()))
			{
				inf.getline(all, 999);
				cout << all << endl;
			}
		}
		inf.close();
	}

	void searchID(int id)
	{
		ifstream inf("receipt.txt");
		bool found = false;
		string line;

		if (!inf)
		{
			cout << "File opening error!!!" << endl;
			return;
		}

		cout << "Searching for Customer ID: " << id << endl;

		while (getline(inf, line))
		{
			if (line == "___________________________________")
			{
				while (getline(inf, line) && line != "___________________________________")
				{
					if (line.find("Custommer ID: " + to_string(id)) != string::npos)
					{
						found = true;
						cout << "\n------------ Bill Found ------------\n";
						cout << line << endl;
						while (getline(inf, line) && line != "___________________________________")
						{
							cout << line << endl;
						}
						cout << "------------------------------------\n";
						break;
					}
				}

				if (found)
					break;
			}
		}

		if (!found)
		{
			cout << "Bill with Customer ID " << id << " not found." << endl;
		}

		inf.close();
	}
};

void menu()
{
	int mainChoice, inChoice, gotoMenu, searchIDInput;

	cout << "\t\t   *** X Travel ***\n"
		 << endl;
	cout << "-----------------------Main Menu--------------------" << endl;

	cout << "\t----------------------------------------" << endl;
	cout << "\t|\t\t\t\t\t|" << endl;
	cout << "\t|\tCustomer Management -> 1\t|" << endl;
	cout << "\t|\tCabs Management     -> 2\t|" << endl;
	cout << "\t|\tBookings Management -> 3\t|" << endl;
	cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
	cout << "\t|\tSearch ID           -> 5\t|" << endl;
	cout << "\t|\tExit                -> 6\t|" << endl;
	cout << "\t|\t\t\t\t\t|" << endl;
	cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

	cout << "\nEnter Your Choice: ";
	cin >> mainChoice;

	system("CLS");

	Customers a2;
	Cabs a3;
	Booking a4;
	Charges a5;

	if (mainChoice == 1)
	{
		cout << "------Customers------\n"
			 << endl;
		cout << "1. Enter New Customers" << endl;
		cout << "2. See Old Customers" << endl;

		cout << "\nEnter Choice: ";
		cin >> inChoice;
		system("CLS");

		if (inChoice == 1)
		{
			a2.getDetails();
		}
		else if (inChoice == 2)
		{
			a2.showDetails();
		}
		else
		{
			cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
			Sleep(999);
			system("CLS");
			menu();
		}

		cout << "\nPress 1 to Redirect Main Menu: ";
		cin >> gotoMenu;
		system("CLS");
		if (gotoMenu == 1)
		{
			menu();
		}
		else
		{
			menu();
		}
	}

	else if (mainChoice == 2)
	{
		a3.cabDetails();
	}

	else if (mainChoice == 3)
	{
		cout << "-------- Book a Luxuty Hotel using the system --------" << endl;
		a4.hotels();
	}

	else if (mainChoice == 4)
	{
		cout << "-------- Get your receipt--------" << endl;
		a5.printBill();

		cout << "Your receipt is already printed you can get it form file path\n"
			 << endl;
		cout << "To display the you receipt in the screen, Enter 1: or Enter another key to back Main Menu: ";

		cin >> gotoMenu;

		if (gotoMenu == 1)
		{
			system("CLS");
			a5.showBill();
			cout << "\nPress 1 to redirect Main Menu: ";
			cin >> gotoMenu;
			system("CLS");
			if (gotoMenu == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}
		else
		{
			system("CLS");
			menu();
		}
	}

	else if (mainChoice == 5)
	{
		cout << "------Search------\n"
			 << endl;
		cout << "1. Search Customers" << endl;
		cout << "2. Search Bill" << endl;

		cout << "\nEnter Choice: ";
		cin >> inChoice;
		system("CLS");

		if (inChoice == 1)
		{
			cout << "Enter Customer ID to search: ";
			cin >> searchIDInput;
			a2.searchCustomerID(searchIDInput);

			cout << "\nPress 1 to redirect Main Menu: ";
			cin >> gotoMenu;
			system("CLS");
			if (gotoMenu == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}

		else if (inChoice == 2)
		{
			cout << "Enter Customer ID to search: ";
			cin >> searchIDInput;
			a5.searchID(searchIDInput);

			cout << "\nPress 1 to redirect Main Menu: ";
			cin >> gotoMenu;
			system("CLS");
			if (gotoMenu == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}

		else
		{
			cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
			Sleep(999);
			system("CLS");
			menu();
		}
	}

	else if (mainChoice == 6)
	{
		cout << "-----GOOD BYE------" << endl;
		Sleep(999);
		system("CLS");
		menu();
	}

	else
	{
		cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
		Sleep(999);
		system("CLS");
		menu();
	}
}
int main()
{
	ManageMenu startObj;
	return 0;
}
