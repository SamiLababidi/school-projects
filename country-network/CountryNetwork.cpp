/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = nullptr;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
    return (!head);
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) 
{
    Country* newCountry = new Country;
    newCountry->name = countryName;
    if (!previous)
    {
        newCountry->next = head;
        head = newCountry;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    } else
    {
        newCountry->next = previous->next;
        previous->next = newCountry;
        
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
    } 
    
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) 
{
    Country* prev = nullptr;
    Country* temp = head;
    if (temp->name == countryName)
    {
        head = temp->next;
        delete temp;
        return;
    }
    prev = head;
    temp = head->next;
    while (prev->next)
    {
        if (countryName == temp->name)
        {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Country does not exist." << endl;
    
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    Country* previous = nullptr;
    deleteEntireNetwork();
    insertCountry(previous, "United States");
    previous = head;
    insertCountry(previous, "Canada");
    previous = previous->next;
    insertCountry(previous, "Brazil");
    previous = previous->next;
    insertCountry(previous, "India");
    previous = previous->next;
    insertCountry(previous, "China");
    previous = previous->next;
    insertCountry(previous, "Australia");
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    Country* temp = head;
    while (temp != nullptr)
    {
        if (countryName == temp->name)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    Country* temp = new Country;
    while (head != nullptr)
    {
        temp = head;
        head = temp->next;
        cout << "deleting: " << temp->name << endl;
        delete temp;
    }
    //cout << "Deleted network" << endl;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    if (isEmpty())
    {
        cout << "Empty list" << endl;
        return;
    }

    Country* temp = head;
    string name = temp->name;
    bool found = false;

    while (temp != nullptr && !found)
    {
        if (temp->name == receiver)
        {
            found = true;
        }
        temp = temp->next;
    }
    temp = head;
    if (!found)
    {
        cout << "Country not found" << endl;
        return;
    }
    do
    {
        name = temp->name;
        temp->message = message;
        temp->numberMessages+=1 ;
        cout << name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
        temp = temp->next;

    } while(name != receiver);
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() 
{
    cout << "== CURRENT PATH ==" << endl;
    if (isEmpty())
    {
        cout << "nothing in path" << endl;
        cout << "===" << endl;
        return;
    }
    
    Country* temp = head;
    
    while (temp != nullptr)
    {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "===" << endl;
    
}
