#include <iostream>

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value) , prev(nullptr) , next(nullptr){}
};


class DoublyLinkedList
{
    private:
        Node* head;
        Node* tail;
        int size_;

    public:
        DoublyLinkedList() : head(nullptr),tail(nullptr),size_(0){}

        Node* createNode(int value)
        {
            return new Node(value);
        }

        void clear()
        {
            if(head==nullptr) return;

            if(head==tail)
            {
                delete head;
                size_--;
                head=tail=nullptr;
                return;
            }

            Node* traverse=head;
            while(traverse)
            {
                Node* delNode=traverse;
                traverse=traverse->next;
                delete delNode;
                size_--;
            }
            head=tail=nullptr;
        }

        ~DoublyLinkedList(){clear();}


        void pushFront(int value)
        {
            if(head==nullptr)
            {
                Node* newNode=createNode(value);
                head=tail=newNode;
                newNode->prev=nullptr;
                newNode->next=nullptr;
                size_++;
                return;
            }

            Node* newNode=createNode(value);

            newNode->next=head;
            head->prev=newNode;
            newNode->prev=nullptr;
            head=newNode; 
            size_++;           
        }

        void pushBack(int value)
        {
            if(head==nullptr)
            {
                Node* newNode=createNode(value);
                head=tail=newNode;
                newNode->prev=nullptr;
                newNode->next=nullptr;
                size_++;
                return;
            }

            Node* newNode=createNode(value);
            newNode->prev=tail;
            newNode->next=nullptr;
            tail->next=newNode;
            tail=newNode;
            size_++;
        }

        void pushAt(int pos,int value)
        {
            if(head==nullptr)
            {
                Node* newNode=createNode(value);
                head=tail=newNode;
                size_++;
                return;
            }

            if(pos<1)
            {
                pushFront(value);
                return;
            }
            if(pos>=size_)
            {
                pushBack(value);
                return;
            }

            Node* prev=head;

            for(int i=0;i<pos and prev;i++)
            {
                prev=prev->next;
            }

            Node* newNode=createNode(value);
            Node* after=prev->next;
            newNode->prev=prev;
            newNode->next=after;
            prev->next=newNode;
            if(after)
                after->prev=newNode;

            size_++;

        }

        void popFront()
        {
            if(head==nullptr) return;

            if(head==tail)
            {
                delete head;
                size_--;
                head=tail=nullptr;
                return;
            }

            Node* delNode=head;
            head=head->next;
            head->prev=nullptr;
            delete delNode;
            size_--;
        }


        void popBack()
        {
            if(head==nullptr) return;

            if(head==tail)
            {
                delete head;
                size_--;
                head=tail=nullptr;
                return;
            }

            Node* delNode=tail;
            tail=tail->prev;
            tail->next=nullptr;
            delete delNode;
            size_--;
        }

        void popAt(int pos)
        {
            if(head==nullptr) return;

            if(pos<1)
            {
                popFront();
                return;
            }

            if(pos>=size_)
            {
                popBack();
                return;
            }

            Node* current=head;

            for(int i=0;i<pos and current;i++)
            {
                current=current->next;
            }
            if(!current) return;
            Node* before=current->prev;
            Node* after=current->next;

            before->next=after;
            after->prev=before;
            delete current;
            size_--;
        }

        void findPosition(int value)
        {
            if(head==nullptr) return;
            if(head->data==value)
            {
                std::cout<<"Element found at 0\n";
                return;
            }

            Node* fTraverse=head;
            Node* lTraverse=tail;
            int fPos=0;
            int lPos=size_-1;
            while(fTraverse and lTraverse)
            {
                if(fTraverse->data==value)
                {
                    std::cout<<"Element found at "<<fPos<<std::endl;
                    return;
                }
                else if(lTraverse->data==value)
                {
                    std::cout<<"Element found at "<<lPos<<std::endl;
                    return;
                }
                fTraverse=fTraverse->next;
                lTraverse=lTraverse->prev;
                fPos++;
                lPos--;
            }

            std::cout<<"Element is not present in the list\n";
        }

        void show()
        {
            if(head==nullptr) return;

            Node* traverse=head;
            while(traverse)
            {
                std::cout<<traverse->data<<"<->";
                traverse=traverse->next;
            }
            std::cout<<"NULL";
        }

        void size()
        {
            std::cout<<"Size of the Doubly Linked List "<<size_<<std::endl;
        }
};
int main()
{
    DoublyLinkedList list;

    list.pushFront(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(7);
    list.pushAt(4,5);
    list.pushAt(5,6);

    list.popAt(3);

    list.size();


    list.findPosition(5);
    list.show();

    return 0;
}