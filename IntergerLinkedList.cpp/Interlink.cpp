//This is the implementation file for the Interlink class
#include<iostream>
#include"Interlink.h"
using namespace std;

void Interlink::appendNode(int newValue){
	//Create nodeptrs
	IntNode* newNode;//To store new values
	IntNode* nodeptr;//To transverse through list

	//Initialize New nodes
	newNode = new IntNode;
	newNode->value = newValue;
	newNode->next = nullptr;

	//Check if node is empty
	if (!head)
		head = newNode;
	else{
		//initialize nodeptr to head
		nodeptr = head;
		
		//Go through array checking for last value
		while (nodeptr->next)
			nodeptr = nodeptr->next;

		//Set newNode as last val
		nodeptr->next = newNode;
	}
}

void Interlink::insertNode(int newValue) {
	//Create nodeptrs
	IntNode* newNode;//To store new values
	IntNode* previousNode;
	IntNode* nodeptr;//To transverse through list

	//Initialize New nodes
	newNode = new IntNode;
	newNode->value = newValue;
	newNode->next = nullptr;

	//Check if node is empty
	if (!head)
		head = newNode;
	else if(!head){//Check if first value is greater and insert there
		head = newNode;
		newNode->next = nullptr;
	}
	else  {

		//initialize nodeptr to head
		nodeptr = head;
		previousNode = nullptr;

		//Go through array checking for position
		while (nodeptr->next != nullptr && nodeptr->value < newValue) {
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
		if(previousNode == nullptr){
			head = newNode;
			newNode->next = nodeptr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodeptr;
		}
	}
}

void Interlink::displayNode()const{
	//Create nodeptr to transverse through list
	IntNode* nodeptr;
	nodeptr = head;
	
	while(nodeptr){
		cout << nodeptr->value <<" ";
		nodeptr = nodeptr->next;
	}
}

void Interlink::deleteNode(int newValue) {
	//Create nodeptrs
	IntNode* previousNode;
	IntNode* nodeptr;//To transverse through list

	//Check if node is empty
	if (!head)
		return;
	else if (head->value == newValue) {//Check if value to delete is in head
		nodeptr = head;
		head = nodeptr->next;
		delete nodeptr;
	}
	else {

		//initialize nodeptr to head
		nodeptr = head;
		previousNode = nullptr;

		//Go through array checking for position
		while (nodeptr->next != nullptr && nodeptr->value != newValue) {
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
		if (nodeptr->next) {
			previousNode->next = nodeptr->next;
			delete nodeptr;
		}
		else
			delete nodeptr;
	}
}

Interlink::~Interlink(){
	//Declare nodes
	IntNode* nextNode;
	IntNode* nodeptr;

	if (!head)
		return;
	if (head->next == nullptr) {
		delete head;		
	}
	nodeptr = head;
	while(nodeptr != nullptr)
	{
		nextNode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextNode;
	}
}

/*
We cannot just copy the node from one list to the others next, we can copy the value however,
So we need to create a new node for every element we want to copy and copy the other list's value only
*/
Interlink::Interlink(const Interlink &obj){
	//create nodeptrs to iterate through both lists
	IntNode* nodeptr;
	IntNode* nodeptr1;
	
	if (!obj.head)
		head = nullptr;
	else {
		head = new IntNode;
		head->value = obj.head->value;

		
		nodeptr = obj.head -> next;
		nodeptr1 = head;

		while (nodeptr) {
			nodeptr1->next = new IntNode;
			nodeptr1 = nodeptr1->next;
			nodeptr1->value= nodeptr->value;	
			nodeptr = nodeptr->next;
		}
		nodeptr1->next = nullptr;
	}
	


	
}
