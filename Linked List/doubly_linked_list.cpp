#include <iostream>

//Defining a doubly linked list structure

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value) , prev(nullptr), next(nullptr) {}

};


//Defining Doubly Linked list functionality
class LinkedList
{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() : head(nullptr) , tail(nullptr) {}

        //clearing Doubly linked list
        void clear()
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty , Nothing to be clear\n";
                return;
            }

            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                return;
            }

            Node* traverse = head;
            while(traverse != nullptr)
            {
                Node* delNode = traverse;
                traverse = traverse->next;
            }
            head = tail = nullptr;
        }

        ~LinkedList()
        {
            clear();
        }


        //Create node
        Node* createNode(int value)
        {
            return new Node(value);
        }

        /* Insertion operation */

        //Insert at front
        void pushFront(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head = tail = newNode;
                return;
            }

            Node* newNode = createNode(value);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        //Insert at back
        void pushBack(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head = tail = newNode;
                return;
            }

            Node* newNode = createNode(value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        //Insert at specific position
        void pushAt(int pos,int value)
        {
            if(head == nullptr || pos<1)
            {
                pushFront(value);
                return;
            }

            Node* prev = head;
            for(int i=1;i<pos-1 && prev!=nullptr;i++)
            {
                prev = prev->next; 
            }
            if(prev->next == nullptr)
            {
                pushBack(value);
                return;
            }
            Node* newNode = createNode(value);
            Node* after = prev->next;
            newNode->prev = prev;
            newNode->next = after;
            after->prev = newNode;
            prev->next = newNode;
        }

        //Remove from front
        void removeFront()
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty . nothing to remove\n";
                return;
            }
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            Node* delNode = head;
            head = head->next;
            delete delNode;
        }

        //Remove from back
        void removeBack()
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty . nothing to remove from back\n";
                return;
            }
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            Node* delNode = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete delNode;

        }

        void removeAt(int pos)
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty . nothing to remove\n";
                return;
            }
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            if(pos<1)
            {
                removeFront();
                return;
            }
            Node* prev = head;
            for(int i=0;i<pos-1 && prev!=nullptr;i++)
            {
                prev = prev->next;
            }
            if(prev == nullptr)
            {
                removeBack();
                return;
            }
            Node* delNode = prev->next;
            prev->next = delNode->next;
            delNode->next->prev = prev;
            delete delNode;
        }

        void find(int value)
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty , nothing to search\n";
                return;
            }


            Node* traverse = head;
            int index = 0;
            while(traverse!=nullptr && traverse->data != value)
            {
                traverse = traverse->next;
                index++;
            }
            if(traverse == nullptr)
            {
                std::cout<<"Value is not present in list\n";
                return;
            }
            std::cout<<"Value "<<value<<" is present at "<<index<<" index\n";

        }

        void reverse()
        {
            if(head == nullptr || head == tail)
            {
                std::cout<<"List is empty/one element , can't reverse\n";
                return;
            }

            Node* prev = nullptr;
            Node* current = head;
            Node* after = nullptr;
            tail = head;

            while(current!=nullptr)
            {
                after = current->next;
                current->next = prev;
                prev = current;
                current = after;
            }
            head = prev;
        }


        void show()
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty nothing to be displayed\n";
                return;
            }

            Node* traverse = head;
            while(traverse != nullptr)
            {
                std::cout<<traverse->data<<"<->";
                traverse = traverse->next;
            }
            std::cout<<"NULL\n";
        }


};
int main()
{

    LinkedList list;
    list.pushFront(1);
    list.pushBack(2);
    list.pushBack(4);
    list.pushAt(3,3);
    list.pushAt(5,5);

    list.reverse();
    list.reverse();
    list.find(4);

    list.show();
    return 0;
}