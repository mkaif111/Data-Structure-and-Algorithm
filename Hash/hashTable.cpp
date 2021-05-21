#include <bits/stdc++.h>
#include "hashing.h"
using namespace std;

int main()
{

    HashTable<int> priceMenu;
    priceMenu.insert("Burger", 135);
    priceMenu.insert("Tea", 135);
    priceMenu.insert("Coffee", 35);
    priceMenu.insert("Chicken", 335);
    priceMenu.insert("Chai", 5);
    priceMenu.insert("Egg", 13);
    priceMenu.insert("Noodles", 15);
    priceMenu["Pizza"] = 50;
    priceMenu.erase("Pizza");

    priceMenu.print();
    if (priceMenu.search("Chai") != NULL)
        cout << "Price of Chai is " << *priceMenu.search("Chai") << endl;
    else
        cout << "Not found Chai!" << endl;

    return 0;
}