#include <iostream>

//Defining a structure
struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value) , next(nullptr) {}
};

class CircularList
{
    private:
        Node* head;
        Node* tail;
        int size_;
    public:
        CircularList() : head(nullptr) , tail(nullptr) , size_(0) {}

        ~CircularList()
        {
            if(head == nullptr) return;

            Node* current = head;

            do
            {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
                size_--;
            }while(current!=head);

            head = tail = nullptr;
        }

        //Creating a Node
        Node* createNode(int value)
        {
            return new Node(value);
        }

        /* Insertion operation */

        //Insert at front
        void insertFront(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head = tail = newNode;
                newNode->next = head;
                size_++;
                return;
            }

            Node* newNode = createNode(value);
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
            size_++;
        }

        //Insert at the end
        void insertBack(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head = tail = newNode;
                newNode->next = head;
                size_++;
                return;
            }


            Node* newNode = createNode(value);
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
            size_++;
        }

        //Insert at a specific position

        void insertAt(int pos,int value)
        {
            if(head == nullptr || pos<1)
            {
                insertFront(value);
                return;
            }

            if(pos>size_+1)
            {
                insertBack(value);
                return;

            }

            Node* current = head;

            for(int i = 0 ; i < pos-1; i++)
            {
                current = current->next;
            }


            Node* newNode = createNode(value);

            newNode->next = current->next;
            current->next = newNode;
            size_++;
        }

        /* Removal operations */

        //Remove from the front
        void removeFront()
        {
            if(head == nullptr) return;

            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                size_--;
                return;
            }


            Node* delNode = head;
            head = head->next;
            tail->next = head;
            delete delNode;
            size_--;
        }

        //Remove from the back

        void removeBack()
        {
            if(head == nullptr) return;

            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
                size_--;
                return;
            }

            Node* current = head;


            while(current->next != tail)
            {
                current = current->next;
            }

            delete tail;
            tail = current;
            tail->next = head;
            size_--;
        }

        //Remove using an element

        void remove(int value)
        {
            if(head == nullptr) return;

            if(value == head->data)
            {
                removeFront();
                return;
            }

            Node* prev = head;
            Node* current = head->next;

            while(current!=head)
            {
                if(current->data == value)
                {
                    if(current == tail)
                    {
                        removeBack();
                        return;
                    }
                    else
                    {
                        prev->next = current->next;
                        delete current;
                        size_--;
                        return;
                    }
                }

            
                prev = current;
                current = current->next;
            }

        }

        //searching element
        void find(int value)
        {
            if(head == nullptr) return;

            Node* current = head;
            int position = 0;
            do
            {
                if(current->data == value)
                {
                    std::cout<<"Value "<<value<<" found at the position "<<position<<std::endl;
                    return;
                }
                current = current->next;
                position++;
            }while(current != head);
            std::cout<<"Element not found in the list\n";
        }

        /* Detecting loop in a linked list using Flyod's cycle detection algorithm */
        bool detectCycle()
        {
            if(head == nullptr || head == tail) return false;

            Node* slow = head;
            Node* fast = head;

            while(slow and fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(fast == slow)
                {
                    std::cout<<"Meeting point "<<slow->data<<std::endl;
                    return true;
                }
            }
            return false;

        }

        //Finding the length of the loop
        int loopLength()
        {
            if(head == nullptr) return 0;

            Node* slow = head;
            Node* fast = head;

            while(slow and fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast)
                {
                    int count=0;
                    do
                    {
                        fast = fast->next;
                        count++;
                    }while(slow!=fast);
                    return count;
                }
            }
            return 0;
        }

        int startOfCycle()
        {
            if(head == nullptr || head == tail) return 0;

            Node* slow = head;
            Node* fast = head;

            while(slow and fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast)
                {
                    slow = head;
                    while(slow->next and fast->next)
                    {
                        slow = slow->next;
                        fast = fast->next;
                        if(slow == fast)
                        {
                            return fast->data;
                        }
                    }

                }
            }

            return 0;
        }

        //Display List

        void show()
        {
            if(head == nullptr) return;

            Node* current = head;

            do
            {
                std::cout<<current->data<<"->";
                current = current->next;
            }while(current!=head);
            std::cout<<head->data<<std::endl;
            
        }

        //To get the size
        int getSize()
        {
            return size_;
        }
        
};
int main()
{
    CircularList list;
    list.insertFront(5);
    list.insertFront(4);
    list.insertFront(3);
    list.insertBack(6);
    list.insertBack(7);
    list.insertBack(8);
    list.insertAt(0,1);
    list.insertAt(1,2);

    list.removeFront();
    list.removeBack();

    list.remove(4);

    list.find(5);

    list.show();
    std::cout<<"Size of the list is "<<list.getSize()<<std::endl;
    
    std::cout<<"Does the list contains the loop "<<std::boolalpha<<list.detectCycle()<<std::endl;
    std::cout<<"Loop length is "<<list.loopLength()<<std::endl;
    std::cout<<"Starting Node of the loop is "<<list.startOfCycle()<<std::endl;
    return 0;
}