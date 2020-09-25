/****************************************************************/
/*                Publisher Subscriber Driver File              */
/****************************************************************/
/*    Implementing menu options as described in the writeup     */
/****************************************************************/

#include "PubSub.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Publisher (Publish items to the queue)" << endl;
	cout << "2. Subscriber (Retrieve items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

// function for adding items to the queue (enqueue)
void option1(PubSub &items)
{
	string numberOfItems;
	string itemName;
	cout << "Enter the number of items to be published:" << endl;
	getline(cin, numberOfItems);
	
	for (int i = 1; i <= stoi(numberOfItems); i++)
	{
		cout << "Item" << i << ":" << endl;
		getline(cin, itemName);
		items.enqueue(itemName);
	}
	
}

// function for removing items from the queue (dequeue)
void option2(PubSub &items)
{
	string numberOfItems;
	cout << "Enter the number of items to be retrieved:" << endl;
	getline(cin, numberOfItems);
	int num = items.queueSize();


	// in case input is bigger than queue size
	if (stoi(numberOfItems) > num)
	{
		for (int i = 1; i <= num; i++)
		{
			cout << "Retrieved: " << items.peek() << endl;
			items.dequeue();
		}
		cout << "No more items to retrieve from queue" << endl;
	} else {
		for (int i = 1; i <= stoi(numberOfItems); i++)
		{
			cout << "Retrieved: " << items.peek() << endl;
			items.dequeue();
		}
	}
}

void option3 (PubSub &items)
{
	cout << "Number of items in the queue:" << items.queueSize() << endl;
}


// Use getline for reading
int main(int argc, char const *argv[])
{
	PubSub items;
	string userInput;
	
	
	while (true)
	{
		menu();
		getline(cin, userInput);
		if (userInput == "1")
		option1(items);
		else if (userInput == "2")
			option2(items);
		else if(userInput == "3")
			{option3(items); break;}
		else cout << "Invalid input" << endl;
	}
	return 0;
}
