#include <iostream>


struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value) , prev(nullptr) , next(nullptr) {}
};

class CircularList
{
    private:
        Node* head;
        Node* tail;
        int size_;
    public:
        CircularList() : head(nullptr) , tail(nullptr) ,size_(0){}

        ~CircularList()
        {
            if(head == nullptr) return;

            Node* current = head->next;

            while(current!=head)
            {
                Node* next = current->next;
                delete current;
                current = next;
            }

            head = tail = nullptr;
        }

        //Creating Node
        Node* createNode(int value)
        {
            return new Node(value);
        }

        /* Insertion Operation */
        
        //Insert at front
        void insertFront(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head = tail = newNode;
                newNode->next = head;
                newNode->prev = tail;
                size_++;
                return;
            }

            Node* newNode = createNode(value);

            newNode->next = head;
            newNode->prev = tail;
            head->prev= newNode;
            tail->next = newNode;
            head = newNode;
            size_++;
        }

        //Insert at back
        void insertBack(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head = tail = newNode;
                newNode->next = head;
                newNode->prev = tail;
                size_++;
                return;
            }

            Node* newNode = createNode(value);
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
            
        }

        
};
int main()
{
    return 0;
}