#include <iostream>

//Defining a Singly linked list
struct Node
{
    int data;
    Node* next; //Pointer to the next Node

    Node(int value) : data(value) , next(nullptr) {}
};

class LinkedList
{
    private:
    Node* head; //Head pointer to track the start of the node
    Node* tail; // tail pointer to track the end of the node
    int length_;

    public:
        LinkedList() : head(nullptr) , tail(nullptr) , length_(0) {}

        //CreateNode
        Node* createNode(int value)
        {
            return new Node(value);
        }

        //clearing the list
        void clear()
        {
            if(head == nullptr)
            {
                std::cout<<"Nothing to clear\n";
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
                delete delNode;
            }
            length_ = 0;
        }

        //Destructor
        ~LinkedList()
        {
            clear();
        }

        /* Insertion operation */

        //Inserting node at front

        void pushFront(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head = tail = newNode;
                length_++;
                return;
            }

            Node* newNode = createNode(value);
            newNode->next = head;
            head = newNode;
            length_++;
        }

        //Inserting node at back

        void pushBack(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head = tail = newNode;
                length_++;
                return;
            }

            Node* newNode = createNode(value);
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
            length_++;
        }

        //Inserting Node at specific position
        void pushAt(int pos, int value) {
            if (pos <= 1) { // insert at head
                pushFront(value);
                return;
            }

            Node* prev = head;
            for (int i = 1; i < pos - 1 && prev != nullptr; i++) {
                prev = prev->next;
            }

            if (prev == nullptr) {
                std::cout << "Position exceeds list length, inserting at back\n";
                pushBack(value);
                return;
            }

            Node* newNode = createNode(value);
            newNode->next = prev->next;
            prev->next = newNode;
            length_++;

            if (newNode->next == nullptr) { // update tail if inserted at end
                tail = newNode;
            }
        }

        /* Removal operation */

        //Remove at front

        void popFront()
        {
            if(head == nullptr)
            {
                std::cout<<"List is Empty\n";
                return;
            }

            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                length_--;
                return;
            }

            Node* delNode = head;
            head = head->next;
            delete delNode;
            length_--;
        }

        //Remove at back

        void popBack()
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty\n";
                return;
            }

            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                length_--;
                return;
            }

            Node* delNode = tail;
            Node* prev = head;
            while(prev->next!=tail)
            {
                prev = prev->next;
            }
            prev->next = nullptr;
            tail = prev;
            delete delNode;
            length_--;
        }

        //Remove at specific position

        void popAt(int pos)
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty\n";
                return;
            }
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                length_--;
                return;
            }
            if(pos<1)
            {
                popFront();
                return;
            }


            Node* prev = head;

            for(int i=0;i<pos-1 && prev!=nullptr;i++)
            {
                prev = prev->next;
            }
            if(prev == nullptr)
            {
                popBack();
                return;
            }
            Node* after = prev->next;
            prev->next = after->next;
            delete after;
            length_--;
        }

        //Search in the list
        void search(int value)
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty , nothing to search\n";
                return;
            }

            Node* traverse = head;
            int index = 0;
            while(traverse != nullptr && traverse->data != value)
            {
                traverse = traverse->next;
                index++;
            }
            if(traverse == nullptr)
            {
                std::cout<<"There is no such value present in list\n";
                return;
            }

            std::cout<<"Value "<<value<<" present in the index "<<index<<std::endl;
        }

        //Reverse 
        void reverse()
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty , nothing to be reversed\n";
                return;
            }

            Node* prev = nullptr;
            Node* after = nullptr;
            Node* current = head;
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

        //Display list
        void show()
        {
            if(head == nullptr)
            {
                std::cout<<"List is empty\n";
                return;
            }


            Node* traverse = head;
            while(traverse != nullptr)
            {
                std::cout<<traverse->data<<"->";
                traverse = traverse->next;
            }
            std::cout<<"NULL\n";
        }

        //Length of an list
        int length()
        {
            return length_;
        }

        //Find the middle of the list
        void mid()
        {
            if(head == nullptr || head == tail) return;

            int position = ((length()/2)+1);

            Node* current = head;

            for(int i=1;i<position;i++)
            {
                current = current->next;
            }

            std::cout<<"Middle of the list is "<<current->data<<std::endl;

        }

        //Find Occurence of the element
        void occurence(int key)
        {
            if(key == 0 || head == nullptr) return;


            int count = 0;

            Node* current = head;
            while(current)
            {
                if(current->data == key) count++;
                current = current->next;
            }

            if(count)
            {
                std::cout<<"Occurence of the element "<<key<<" is "<<count<<std::endl;
            }   
            else
            {
                std::cout<<"Sorry! there is no occurence\n";
            }
        }

        //check list is circular
        void isCircular()
        {
            if(head == nullptr) return;


            if(tail->next == head) 
            {
                std::cout<<"It is circular\n";
                return;
            }
            std::cout<<"It is not circular\n";
        }

        //Convert single linked list to circular list
        void convertToCircular()
        {
            if(head == nullptr) return;

            tail->next = head;
        }

        //Convert circular linked list to single linked list
        void CircularToSingle()
        {
            if(head == nullptr) return;
            
            if(tail->next == head)
                tail->next = nullptr;
        }


        //Pairwise swap in linked list
        void pairSwap()
        {
            if(head == nullptr || head->next == nullptr) return;


            Node* current = head;
            Node* adjacent = head->next;

            while(adjacent!=nullptr)
            {
                int temp = current->data;
                current->data = adjacent->data;
                adjacent->data = temp;

                current = adjacent->next;
                adjacent = current->next;
            }
        }


};
int main()
{
    LinkedList list;
    list.pushFront(1);
    list.pushBack(2);
    list.pushAt(3,3);
    list.pushBack(4);
    list.pushAt(5,5);



    std::cout<<"Length of the list "<<list.length()<<std::endl;


    list.mid();    

    list.occurence(1);
    list.isCircular();
    list.convertToCircular();
    list.isCircular();
    list.CircularToSingle();
    list.isCircular();

    list.pairSwap();


    list.show();
    return 0;
}