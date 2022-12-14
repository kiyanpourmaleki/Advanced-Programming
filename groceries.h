/*
Author        : Kiyan Pourmaleki
Class         : CSI - 240 : Advanced Programming
Assignment    : Polymorphism Lab
Date Assigned : 3/29
Due Date      : 4/5 11:59PM
*/
/*
Project Description :
Create a grocery shoppingprogram that illustrates polymorphism

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
#include <string> 
#include <vector> 

using namespace std;

class Groceries {
public:
	virtual void getDescription() = 0;
};

class Vegetable : public Groceries{
public:
	Vegetable();
	~Vegetable() {};
	Vegetable(string);
	
	void getDescription() override;

	string getName() { return vegetableName; }

 protected:
	string vegetableName;
};

class Peppers : public Vegetable{
public:
	Peppers();
	~Peppers() {};
	Peppers(string, int, string, float);

	void getDescription() override;

	string getColor() { return PepperColor; }
	float getPrice() { return pricePerPound; }
	int getQuantity() { return quantity; }

protected:
	string PepperColor;
	float pricePerPound;
	int quantity;
};