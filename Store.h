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
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

enum ClothingType {
	SHOE = 1, 
	SHIRT,
	PANTS
};

int printMenu();
void selectChoice(int);
void readItems();
void adminLogin();

class Items {
public:
	virtual void getDescription() = 0;
};

class Clothing : public Items {
public:
	Clothing();
	~Clothing() {};
	Clothing(float price, string color, string model);
	Clothing(float price, int sku, string color, string model);

	int getSKU() { return sku; }
	float getPrice() { return price; }
	string getColor() { return color; }
	string getModel() { return model; }

protected:
	int sku;
	float price;
	string color;
	string model;
}; 

class Shoes : public Clothing {
public:
	Shoes();
	~Shoes() {};
	Shoes(float price, char size, string color, string model);
	Shoes(float price, int sku, int size, string color, string model);
	void getDescription() override;

	int getSize() { return size; }

protected:
	friend istream& operator>>(istream& input, Shoes& shoe);
	friend ostream& operator<<(ostream& output, Shoes& shoe);
	int size;
};


class Shirt : public Clothing {
public:
	Shirt();
	~Shirt() {};
	Shirt(float price, char size, string color, string model);
	Shirt(float price, int sku, char size, string color, string model);
	void getDescription() override;

	char getSize() { return size; }

protected:
	friend istream& operator>>(istream& input, Shirt& shirt);
	friend ostream& operator<<(ostream& output, Shirt& shirt);
	char size;
};

class Pants : public Clothing {
public:
	Pants();
	~Pants() {};
	Pants(float price, char size, string color, string model);
	Pants(float price, int sku, char size, string color, string model);
	void getDescription() override;

	char getSize() { return size; }
protected:
	friend istream& operator>>(istream& input, Pants& pants);
	friend ostream& operator<<(ostream& output, Pants& pants);
	char size;
};