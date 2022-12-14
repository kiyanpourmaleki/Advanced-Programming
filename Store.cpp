/* Author: Kiyan Pourmaleki
Class : CSI - 240 : Advanced Programming
Assignment : Final Project
Date Assigned : 4 / 15
Due Date : 4 / 25 at 11 : 59PM
* /
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

//Clothing constructors

Clothing::Clothing() {
	price = 0.00;
	sku = 0000;
	color = "Unknown";
	model = "Unknown";
}

Clothing::Clothing(float price, string color, string model) {
	this->price = price;
	this->sku = 0000;
	this->color = color;
	this->model = model;
}

Clothing::Clothing(float price, int sku, string color, string model) {
	this->price = price;
	this->sku = sku;
	this->color = color;
	this->model = model;

}

//Shoe constructors

Shoes::Shoes() : Clothing() {
	size = 0;
}

Shoes::Shoes(float price, char size, string color, string model) : Clothing(price, color, model) {
	this->size = size;
};

Shoes::Shoes(float price, int sku, int size, string color, string model) : Clothing(price, sku, color, model) {
	this->size = size;
}

//Shoe functions

void Shoes::getDescription() {
	cout << setw(20) << getModel() << setw(15) << getColor() << "\t" << "Size: " << getSize() << setw(8) << "$" << getPrice() << endl;
}

ostream& operator<<(ostream& output, Shoes& shoe) {
	output << "1" << endl;
	output << shoe.sku << endl;
	output << shoe.price << endl;
	output << shoe.model << endl;
	output << shoe.color << endl;
	output << shoe.size << endl;
	return output;
}

istream& operator>>(istream& input, Shoes& shoe) {
	input >> shoe.sku;
	input >> shoe.price;
	input.ignore();
	getline(input, shoe.model);
	getline(input, shoe.color);
	input >> shoe.size;
	return input;
}

//Shirt Constructors

Shirt::Shirt() : Clothing() {
	size = 'N';
}

Shirt::Shirt(float price, char size, string color, string model) : Clothing(price, color, model) {
	this->size = size;
};

Shirt::Shirt(float price, int sku, char size, string color, string model) : Clothing(price, sku, color, model) {
	this->size = size;
}

//shirt functions

void Shirt::getDescription() {
	cout << setw(20) << getModel() << setw(15) << getColor() << "\t" << "Size: " << getSize() << setw(8) << "$" << getPrice() << endl;
}

ostream& operator<<(ostream& output, Shirt& shirt) {
	output << "2" << endl;
	output << shirt.sku << endl;
	output << shirt.price << endl;
	output << shirt.model << endl;
	output << shirt.color << endl;
	output << shirt.size << endl;
	return output;
}

istream& operator>>(istream& input, Shirt& shirt) {
	input >> shirt.sku;
	input >> shirt.price;
	input.ignore();
	getline(input, shirt.model);
	getline(input, shirt.color);
	input >> shirt.size;
	return input;
}

//Pants Constructors

Pants::Pants() : Clothing() {
	size = 'N';
}

Pants::Pants(float price, char size, string color, string model) : Clothing(price, color, model) {
	this->size = size;
};

Pants::Pants(float price, int sku, char size, string color, string model) : Clothing(price, sku, color, model) {
	this->size = size;
}

//Pants functions

void Pants::getDescription() {
	cout << setw(20) << getModel() << setw(15) << getColor() << "\t" << "Size: " << getSize() << setw(8) << "$" << getPrice() << endl;
}

ostream& operator<<(ostream& output, Pants& pants) {
	output << "3" << endl;
	output << pants.sku << endl;
	output << pants.price << endl;
	output << pants.model << endl;
	output << pants.color << endl;
	output << pants.size << endl;
	return output;
}

istream& operator>>(istream& input, Pants& pants) {
	input >> pants.sku;
	input >> pants.price;
	input.ignore();
	getline(input, pants.model);
	getline(input, pants.color);
	input >> pants.size;
	return input;
}

//Main store functions

vector<Clothing*> cart;
vector<Clothing*> inventory;

int printMenu() {
	int choice;

	cout << endl << "1. Display Store Items" << endl;
	cout << "2. Add Items to cart" << endl;
	cout << "3. Check out" << endl;
	cout << "4. Login as an Admin" << endl;
	cout << "5. Exit program" << endl;
	cout << "Enter your choice number here: ";

	cin >> choice;
	return choice;
}

void selectChoice(int choice) {
	float total = 0.00;
	int loop = 1;
	ofstream reciept;

	switch (choice) {
	case 1:
		readItems();
		break;
	case 2:		
		//adds items to the cart
		int i;

		while (loop == 1) {
		
			cout << "Enter the Item number you are adding to cart: ";
			cin >> i;
			
			if (inventory[i - 1]->getSKU() < 2000) {
				cart.push_back(inventory[i-1]);
			}
			else if (2000 < inventory[i-1]->getSKU() < 3000) {
				cart.push_back(inventory[i - 1]);
			}
			else if(inventory[i - 1]->getSKU() > 3000) {
				cart.push_back(inventory[i - 1]);
			}
			
			cout << endl << "Would you like to add another item to your cart? (1 to add, 0 to return to menu) : ";
			cin >> loop;
		}

		int newchoice;
		newchoice = printMenu();
		selectChoice(newchoice);		
		break;
	case 3:
		reciept.open("reciept.txt");

		//prints the reciept for the customer

		for (int i = 0; i < cart.size(); i++) {
			cart[i]->getDescription();
			reciept << "$" << cart[i]->getPrice() << "\t\t" << cart[i]->getModel() << endl;
			total += cart[i]->getPrice();
		}

		cout << endl << endl << "\t\tTotal: \t\t" << "$" << total;
		reciept << endl << "\t\tTotal: \t\t" << "$" << total << endl << endl;

		reciept.close();

		//deletes the items in the cart and inventory vector
		
		for (int i = 0; i < cart.size(); i++) {
			delete cart[i];
			cart[i] = nullptr;
		}
		break;
	case 4:
		try {
			adminLogin();
		}
		catch (const char* message) { cout << endl << message << endl; }
		break;
	case 5:
		exit(0);
		break;
	default:
		cout << "Warning: No choice entered" << endl;
		break;

	}
}

//prints the merchandise for the store

void readItems() {
	int type;
	int count = 1;

	ifstream clothingFile;
	clothingFile.open("clothes.txt");

	cout << endl << "\nSTORE MERCHANDISE\n" << endl;

	while (!clothingFile.eof()) {
		clothingFile >> type;
		
		if (type == SHOE) {
			Shoes thisShoe;
			clothingFile >> thisShoe;
			cout << count << ". ";
			thisShoe.getDescription();
			inventory.push_back(new Shoes(thisShoe.getPrice(),thisShoe.getSize(), thisShoe.getColor(), thisShoe.getModel()));
		}
		else if (type == SHIRT) {
			Shirt thisShirt;
			clothingFile >> thisShirt;
			cout << count << ". ";
			thisShirt.getDescription();
			inventory.push_back(new Shirt(thisShirt.getPrice(), thisShirt.getSize(), thisShirt.getColor(), thisShirt.getModel()));
		}
		else if (type == PANTS) {
			Pants thesePants;
			clothingFile >> thesePants;
			cout << count << ". ";
			thesePants.getDescription();
			inventory.push_back(new Pants(thesePants.getPrice(), thesePants.getSize(), thesePants.getColor(), thesePants.getModel()));

		}
		count++;
		type = NULL;
	}

	cout << endl;

	clothingFile.close();

	int newchoice;
	newchoice = printMenu();
	selectChoice(newchoice);
}
