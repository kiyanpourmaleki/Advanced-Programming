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

using namespace std;

int main() {
	
    cout << "The groceries in my basket are:" << endl;

    vector<Groceries*> basket;
    basket.push_back(new Vegetable("Fresh Green Beans"));
    basket.push_back(new Vegetable("Bell Peppers"));
    basket.push_back(new Peppers("Bell Peppers", 3, "Orange", 2.99));
    basket.push_back(new Peppers("Bell Peppers", 5, "Red", 2.99));

    for (int i = 0; i < basket.size(); i++)
    {
        basket[i]->getDescription();
    }

    cout << "Size of basket: " << basket.size() << endl;

    for (int i = 0; i < basket.size(); i++)
    {
        delete basket[i];
        basket[i] = nullptr;
    }

    basket.clear();

    cout << "Basket Cleared" << endl;
    cout << "Size of Basket: " << basket.size() << endl;


}