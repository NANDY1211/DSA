#include <iostream>


//Defining a node structure

struct Node
{
    //Default Access specifier is public for struct
    int data;
    Node* next;

    //constructor
    Node(int value) : data(value) , next(nullptr){}
};

//Define Linked List class
class LinkedList
{
    private:
    //head and tail to easily access linked list
        Node* head;
        Node* tail;
    public:
        //Default constructor
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        //Clearing linked list
        void clear()
        {
            while(head != nullptr)
            {
                delete_head();
            }
        }

        //Destructor
        ~LinkedList()
        {
            clear();
        }

        //Creating a Node
        Node* createNode(int val)
        {
            return new Node(val);
        }


        /* Insert operations */
        
        // Head insert - O(1)
        void insert_head(int val)
        {
            //If initial insertion
            if(head == nullptr)
            {
                Node* newNode = createNode(val);
                head = newNode;
                tail = newNode;
                return;
            }

            //If already node are there
            Node* newNode = createNode(val); //create a node
            newNode->next = head; // link new node next to head node 
            head = newNode; // move the head to new node
        }

        //tail insert - O(1)
        void insert_tail(int val)
        {
            //if no node are present already
            if(head == nullptr)
            {
                Node* newNode = createNode(val);
                head = newNode;
                tail = newNode;
                return;
            }

            //If node already present
            Node* newNode = createNode(val); //create a node
            tail->next = newNode; // link new node after tail node
            tail = newNode; //move the tail pointer to new node
        }

        //Insert at position - O(n)
        void insertAt(int pos,int val)
        {
            //if no node is present or position is initial
            if(head == nullptr || pos < 1)
            {
                Node* newNode = createNode(val);
                head = tail = newNode;
                return;
            }

            Node* temp = head; // create a temp pointer to traverse
            Node* newNode = createNode(val); // create a new node
            //Traverse through the position
            for(int i=0;i<pos-1;i++)
            {
                //while traversing if position exceeds the Node present
                if(temp == nullptr || temp-> next == nullptr)
                {
                    insert_tail(val);
                    return;
                }
                //If not exceeds the nodes present
                temp = temp->next; //this is the node before position
            }
            newNode->next = temp->next; //new node points to the node after position
            temp->next = newNode; // previous node to position should points to the new node
        }


        /* Delete Operation*/

        //Delete at head - O(1)
        void delete_head()
        {
            //If no Nodes are there
            if(head == nullptr)
            {
                std::cout<<"No Nodes to delete\n";
                return;
            }

            //If nodes are there
            Node* temp = head; // store head in temp
            head = head->next; // move the head pointer to next Node
            delete temp; // delete the previous head node
        }

        //Delete at tail - O(n)
        void delete_tail()
        {
            //If no Nodes are there
            if(head == nullptr)
            {
                std::cout<<"No Nodes to delete\n";
                return;
            }

            //If nodes present
            Node* temp = head; //create a temp node to traverse

            while(temp->next != tail)
            {
                temp = temp->next; // traverse through the node before tail node
            }

            delete tail; // delete the tail node
            tail = temp; // make before node to tail as tail 
            temp->next = nullptr; // make next to tail as nullptr
        }

        //Delete node in specific position
        void delete_value(int val)
        {
            //If no Nodes are there
            if(head == nullptr)
            {
                std::cout<<"No Nodes to delete\n";
                return;
            }

            Node* prev = nullptr;
            Node* current = head;

            while(current != nullptr && (current->data != val))
            {
                prev = current; // points to the previous node
                current = current->next; //points to the current node
            }

            //If value not found
            if(current == nullptr)
            {
                std::cout<<"Value not found\n";
                return;
            }

            //Bypass and delete
            prev->next = current-> next;
            if(current == tail)
            {
                tail = prev;
            }
            delete current;
            
        }

        /* Searching an Value - O(n) */

        int search(int val) const
        {
            // if no node is present
            if(head == nullptr)
            {
                std::cout<<"No Node to search \n";
                return -1;
            }

            //if node present
            Node* traverse = head; // create a pointer to traverse
            int index = 0;
            while(traverse != nullptr) // traverse and match the value
            {
                if(traverse->data == val)
                {
                    return index;
                }

                traverse = traverse->next;
                index++;
            }
            //if value not found
            if(traverse == nullptr)
            {
                std::cout<<"Value is not present in the list\n";
                return -1;
            }

            return -1;

        }

        /* Reverse a linked list - O(n) */

        void reverse()
        {
            //If no node present
            if(head == nullptr)
            {
                std::cout<<"No node is present\n";
                return;
            }

            //taking three pointer to track previous , current and next node
            Node* prev = nullptr;
            Node* current = head;
            Node* next = nullptr;

            //Traversing through the linked list
            while(current != nullptr)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;

        }

        /* Find and replace an element - O(n)*/

        void findAndReplace(int findElement,int replaceElement)
        {

            //If no node present
            if(head == nullptr)
            {
                std::cout<<"No node is present\n";
                return;
            }

            Node* traverse = head; // creating a pointer to traverse through linked list

            while(traverse != nullptr)
            {
                if(traverse->data == findElement) // if the find element matched
                {
                    traverse->data = replaceElement;
                    return;
                }
                traverse = traverse->next;
            }
            //If find element not found
            if(traverse == nullptr)
            {
                std::cout<<"Can't find the element . So can't be replaced\n";
            }

        }


        //Display nodes present
        void display()
        {
            Node* traverse = head;

            if(head == nullptr)
            {
                std::cout<<"There is no element to traverse\n";
                return;
            }

            while(traverse != nullptr)
            {
                std::cout<<traverse->data<<"->";
                traverse = traverse->next;
            }
            std::cout<<"NULL";
        }

};
int main()
{

    LinkedList llObj;
    llObj.insert_head(1);
    llObj.insert_head(11);
    llObj.insert_tail(2);
    llObj.insert_tail(3);
    llObj.insert_tail(4);
    llObj.insertAt(2,22);
    llObj.insertAt(4,33);
    llObj.insertAt(6,44);
    llObj.delete_head();
    llObj.delete_tail();
    llObj.delete_value(33);


    std::cout<<"Searching element in linked list - Position : "<<llObj.search(99)<<std::endl;

    llObj.display();

    std::cout <<"\nAfter reversing the linked list\n";
    llObj.reverse();
    llObj.display();

    std::cout<<"\nAfter finding and replacing linked list element\n";
    llObj.findAndReplace(3,33);
    llObj.display();
    return 0;

}