//This program shows the interlink class in action
//The interlink class is basically a singly linked list I programmed myself
#include<iostream>
#include"Interlink.h"
using namespace std;

int main(){
	//Instantiate object
	Interlink one;
	
	//Append list
	one.appendNode(1);
	one.appendNode(2);
	one.appendNode(4);
	one.appendNode(5);

	//Display data
	one.displayNode();

	//Insert 3 to list
	one.insertNode(3);

	//Display new data
	one.displayNode();

	//Delete node
	one.deleteNode(2);

	//Display new data
	one.displayNode();

	//Create new object
	Interlink two(one);

	cout << "\n";

	//Display copy node data
	two.displayNode();

	//Reverse
	try{ one.reverse(); }
	catch (exception) { cout << "Cannot reverse empty list.\n"; }

	//Display new data
	one.displayNode();

	cout << "\n\n\n\nARIGATO\n\n\n\n";


	return 0;
}
