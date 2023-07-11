//This is the specification file for the interger linked list
#ifndef INTERLINK_H
#define INTERLINK_H

class Interlink
{
	//Declare Private member functions
	private:
		struct IntNode
		{
			int value;
			IntNode* next;		
		};

		IntNode* head;

	//Declare Public Members
	public:
		//Default constructor sets head as nullptr
		Interlink()
		{
			head = nullptr;
		}

		//Destructor
		~Interlink();

		//List Operations
		void appendNode(int);
		void insertNode(int);
		void deleteNode(int);
		void displayNode()const;

		
};
#endif // !INTERLINK_H
