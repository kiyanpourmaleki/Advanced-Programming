/* Author        : Kiyan Pourmaleki
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

int main() {
	cout << "****************THE MENS CLOTHING SHOP***************" << endl << endl;
	cout << "Welcome, Enter an option from the list below: " << endl;

	int choice = printMenu();
	selectChoice(choice);
	

}