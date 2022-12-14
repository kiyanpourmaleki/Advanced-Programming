/*
Author        : Kiyan Pourmaleki
Class         : CSI - 240 : Advanced Programming
Assignment    : Final Project
Date Assigned : 4/15
Due Date      : 4/25 at 11:59PM
*/
/*
Project Description :
Customers can shop and recieve a total or admins can login and add or remove merchandise

Certification of Authenticity :

I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/
#include "Store.h"

//Admin Function prototypes
void filePrint();
void adminChoice(int);
int printAdminMenu();
void selectItem();
void removeItem(int);

//Admin functions
void adminLogin() {
	string adminId;
	int adminPin;
	string testId;
	int testPin;
	int choice;

	ifstream adminFile;
	adminFile.open("admin.txt");

	cout << endl <<"Enter your Admin information below" << endl;
	cout << "Admin ID: ";
	cin >> adminId;
	cout << "\nAdmin Pin: ";
	cin >> adminPin;

	while (!adminFile.eof()) {
		adminFile >> testId;
		adminFile >> testPin;

		if (adminId == testId && adminPin == testPin) {
			cout <<endl << endl << "Welcome to the admin controls" << endl;
			try {
				choice = printAdminMenu(); 
				adminChoice(choice);
			}
			catch (const char* message) {
				cout << message; 
			}
		}
	}
	throw "The pin or id entered was incorrect";
}

int printAdminMenu() {
	int choice;
	cout << "1. Add an item to the merchandise list" << endl;
	cout << "2. Remove an item from the merchandise list" << endl;
	cout << "3. Return to user menu" << endl;
	cout << "4. Shut down program" << endl;
	cout << "Enter your choice : ";
	cin >> choice;

	if (choice > 4) {
		throw "Error: Choice was invalid";
	}
	return choice;
}

void adminChoice(int choice) {
	switch (choice) {
	case 1:
		filePrint();
		break;
	case 2:
		selectItem();
		break;
	case 3:
		int newchoice;
		newchoice = printMenu();
		selectChoice(newchoice);
	case 4:
		exit(0);
		break;
	}
}

//Prints new item to the merchandise file
void filePrint() {
	float price;
	int type;
	string name;
	string color;
	int shoeSize;
	char size;
	int sku;

	cout << endl << "Enter the type of clothing you are adding (1 = shoe, 2 = shirts, 3 = pants) :";
	cin >> type;

	if (type == SHOE) {
		cout << "Enter the sku of the item: ";
		cin >> sku;
		cout << "\nEnter the price of the Shoes:";
		cin >> price;
		cout << "\nEnter the name of the item: ";
		cin.ignore();
		getline(cin, name);
		cout << "\nEnter the color: ";
		cin >> color;
		cout << "\nEnter the shoe size: ";
		cin >> shoeSize;
		
		Shoes newShoe(price, sku, shoeSize, color, name);

		ofstream clothingFile;
		clothingFile.open("clothes.txt", ios::app);
		clothingFile << newShoe;
		clothingFile.close();
	}
	else if (type == SHIRT) {
		cout << "Enter the sku of the item: ";
		cin >> sku;
		cout << "\nEnter the price of the shirt:";
		cin >> price;
		cout << "\nEnter the name of the item: ";
		cin.ignore();
		getline(cin, name);
		cout << "\nEnter the color: ";
		cin >> color;
		cout << "\nEnter the shirt size(S,M,L): ";
		cin >> size;
		
		Shirt newShirt(price, sku, size, color, name);

		ofstream clothingFile;
		clothingFile.open("clothes.txt", ios::app);
		clothingFile << newShirt;
		clothingFile.close();
	}
	else if (type == PANTS) {
		cout << "Enter the sku of the item: ";
		cin >> sku;
		cout << "\nEnter the price of the pants:";
		cin >> price;
		cout << "\nEnter the name of the pants: ";
		cin.ignore();
		getline(cin, name);
		cout << "\nEnter the color: ";
		cin >> color;
		cout << "\nEnter the pants size(S,M,L): ";
		cin >> size;

		Pants newPants(price, sku, size, color, name);

		ofstream clothingFile;
		clothingFile.open("clothes.txt", ios::app);
		clothingFile << newPants;
		clothingFile.close();
	}

	try { 
		int choice = printAdminMenu();
		adminChoice(choice);
	}
	catch (const char* message) { 
		cout << message;
	}
}

//Removes item from file
void selectItem() {
	int sku;

	cout << endl << "Enter the SKU of the item you want to remove: ";
	cin >> sku;

	removeItem(sku);
}

//Pass the item's sku and then remove it from the file
void removeItem(int sku) {
	int typeOfItem;
	int thisSKU;
	float price;
	string itemName;
	string color;
	int shoeSize;
	char clothingSize;

	ifstream fin;
	fin.open("clothes.txt");
	ofstream fout;
	fout.open("temp.txt");

	while (!fin.eof()) {
		fin >> typeOfItem;
		fin >> thisSKU;
		fin >> price;
		fin.ignore();
		getline(fin, itemName);
		getline(fin, color);

		if (typeOfItem == SHOE) {
			fin >> shoeSize;
			if (thisSKU == sku) {
				continue;
			}
			else {
				fout << typeOfItem << endl << thisSKU << endl << price << endl << itemName << endl << color << endl << shoeSize << endl;
			}
		}
		else if (typeOfItem == SHIRT || typeOfItem == PANTS) {
			fin >> clothingSize;
			if (thisSKU == sku) {
				continue;
			}
			else {
				fout << typeOfItem << endl << thisSKU << endl << price << endl << itemName << endl << color << endl << clothingSize << endl;
			}
		}
		typeOfItem = NULL;
	}

	fin.close();
	fout.close();
	remove("clothes.txt");
	rename("temp.txt", "clothes.txt");

	cout << endl << endl << "Item removed" << endl << endl;

	try { 
		int choice = printAdminMenu();
		adminChoice(choice);
	}
	catch (const char* message) { 
		cout << message;
	}
}