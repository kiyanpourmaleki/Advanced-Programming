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

#include "groceries.h"

Vegetable::Vegetable(string name) {
	vegetableName = name;
}

Vegetable::Vegetable() {
	vegetableName = "Unset";
}

void Vegetable::getDescription() {
	cout << vegetableName << endl;
}

Peppers::Peppers() {
	pricePerPound = 0;
	PepperColor = "Unset";
	quantity = 0;
}

Peppers::Peppers(string vegetableName, int quantity, string color, float pricePerPound):Vegetable(vegetableName) {
	PepperColor = color;
	this->pricePerPound = pricePerPound;
	this->quantity = quantity;
}

void Peppers::getDescription() {
	cout << getColor() << " " << getName() << ", Count: " << getQuantity() << ", $" << getPrice() << " per pound" << endl;
}