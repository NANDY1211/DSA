#include <iostream>


struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value) , next(nullptr){}
};


class SinglyLinkedList
{
    private:
        Node* head;
        Node* tail;
        int size_;
    public:
        SinglyLinkedList() : head(nullptr) , tail(nullptr) , size_(0) {}

        void clear()
        {
            if(head == nullptr) return;

            if(head == tail) 
            {
                delete head;
                head = tail = nullptr;
                size_--;
                return;
            }

            Node* traverse = head;
            while(traverse)
            {
                Node* delNode = traverse;
                traverse = traverse->next;
                delete delNode;
                size_--;
            }
            head=tail=nullptr;
        }


        ~SinglyLinkedList(){clear();}


        Node* createNode(int value) {return new Node(value);}


        void show()
        {
            if(head == nullptr) return;

            Node* traverse = head;

            while(traverse)
            {
                std::cout<<traverse->data<<"->";
                traverse = traverse->next;
            }
            std::cout<<"null";
        }



        void pushFront(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head=tail=newNode;
                size_++;
                return;
            }

            Node* newNode = createNode(value);
            newNode->next = head;
            head = newNode;
            size_++;
        }

        void pushBack(int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head=tail=newNode;
                size_++;
                return;
            }

            Node* newNode = createNode(value);
            tail->next=newNode;
            tail = newNode;
            size_++;
        }

        void pushAt(int pos,int value)
        {
            if(head == nullptr)
            {
                Node* newNode = createNode(value);
                head=tail=newNode;
                size_++;
                return;
            }

            if(pos<1)
            {
                pushFront(value);
                return;
            } 

            if(pos>size_)
            {
                pushBack(value);
                return;
            }

            Node* prev = head;
            for(int i=1;i<pos and prev;i++)
            {
                prev = prev->next;
            }

            Node* newNode = createNode(value);
            newNode->next = prev->next;
            prev->next = newNode; 
            if(prev==tail)
                tail=newNode;
            size_++;
        }

        void pushBeforeValue(int value,int data)
        {
            if(head==nullptr) return;

            if(head->data==value)
            {
                pushFront(data);
                return;
            }
            Node*prev=head;
            Node*current=head->next;
            while(current and prev)
            {
                if(current->data==value)
                {
                    Node* newNode=createNode(data);
                    prev->next=newNode;
                    newNode->next=current;
                    size_++;
                    return;
                }
                prev=prev->next;
                current=current->next;
            }
            if(current==nullptr)
            {
                std::cout<<"Value not found"<<std::endl;
                return;
            }
        }

        void pushAfterValue(int value,int data)
        {
            if(head == nullptr) return;

            Node* current=head;
            while(current)
            {
                if(current->data==value)
                {
                    Node* newNode=createNode(data);
                    newNode->next=current->next;
                    current->next=newNode;
                    size_++;
                    return;
                }
                current=current->next;
            }
            if(current==nullptr)
            {
                std::cout<<"Value not found"<<std::endl;
            }
        }

        void size()
        {
            std::cout<<"Size of the list is "<<size_<<std::endl;
        }


        void popFront()
        {
            if(head == nullptr) return;

            if(head==tail)
            {
                delete head;
                head=tail=nullptr;
                size_--;
                return;
            }

            Node* delNode = head;
            head=head->next;
            delete delNode;
            size_--;
        }

        void popBack()
        {
            if (head == nullptr) return;

            if (head == tail) {
                delete head;
                head = tail = nullptr;
                size_--;
                return;
            }

            Node* prev = head;
            Node* delNode = tail;
            while (prev->next != tail) {
                prev = prev->next;
            }

            prev->next = nullptr;   // disconnect old tail first
            tail = prev;            // update tail
            delete delNode;
            size_--;                // decrement size
        }

        void popAt(int pos)
        {
            if(head == nullptr) return;

            if(head==tail || pos<1)
            {
                popFront();
                return;
            }
            if(pos>size_)
            {
                popBack();
                return;
            }

            Node* prev = head;

            for(int i=1;i<pos and prev;i++)
            {
                prev=prev->next;
            }
            Node* current = prev->next;
            prev->next=current->next;
            delete current;
            size_--;
        }

        void popByValue(int value)
        {
            if(head==nullptr) return;

            if(head->data==value)
            {
                popFront();
                return;
            }

            Node* prev=head;
            while(prev)
            {
                if(prev->next->data==value)
                {
                    Node* delNode=prev->next;
                    prev->next=prev->next->next;
                    delete delNode;
                    size_--;
                    return;
                }
                prev=prev->next;
            }
            if(prev==nullptr)
            {
                std::cout<<"Unable to find the value \n";
            }
        }


        void findPosition(int value)
        {
            if(head==nullptr) return;

            Node* traverse=head;
            int pos=0;
            while(traverse)
            {
                if(traverse->data==value)
                {
                    std::cout<<"Element found at position "<<pos<<std::endl;
                    return;
                }
                pos++;
                traverse=traverse->next;
            }
            std::cout<<"Element is not found in the list"<<std::endl;
        }

        void reverse()
        {
            if(head==nullptr or head==tail) return;

            Node* prev=nullptr;
            Node* current=head;
            Node* after=head->next;

            do
            {
                after=current->next;
                current->next=prev;
                prev=current;
                current = head =after;
            }while(current!=nullptr);

            head=prev;

            
        }


        void addList(Node* listHead1,Node* listHead2)
        {
            if(listHead1 == nullptr || listHead2 == nullptr) return;

            Node* traverse1 = listHead1;
            Node* traverse2 = listHead2;

            Node* dummy = createNode(-1);
            Node* current=dummy;

            int carry=0;
            while(traverse1!=nullptr || traverse2!=nullptr)
            {
                int sum=carry;
                if(traverse1)
                {
                    sum = sum+traverse1->data;
                }
                if(traverse2)
                {
                    sum = sum+traverse2->data;
                }

                Node* newNode = createNode(sum%10);
                carry = sum/10;

                current->next=newNode;
                current=newNode;

                if(traverse1)
                {
                    traverse1=traverse1->next;
                }
                if(traverse2)
                {
                    traverse2=traverse2->next; 
                }

                if(carry)
                {
                    Node* newNode = createNode(carry);
                    current->next=newNode;
                }   
            }

            head = dummy->next;
        }

        Node* getHead()
        {
            return head;
        }

        void segregateOddAndEvenNodes(Node* list)
        {
            if(list==nullptr || list->next==nullptr) return;


            Node* odd=head;
            Node* even=head->next;
            Node* evenHead=head->next;

            while(even!=nullptr and even->next!=nullptr)
            {
                odd->next=odd->next->next;
                even->next=even->next->next;


                odd=odd->next;
                even=even->next;
            }

            odd->next=evenHead;
        }

        void createList(int limit)
        {
            for(int i=1;i<=limit;i++)
            {
                this->pushBack(i);
            }
        }


        void createList(int limit,int recurrence)
        {
            for(int i=1;i<=recurrence;i++)
            {
                int reset=limit;
                while(reset!=-1)
                {
                    this->pushBack(reset);
                    reset--;
                }
            }
        }

        void sort(Node* list)
        {
            if(list==nullptr || list->next==nullptr) return;

            Node* dummyZero=createNode(-1);
            Node* dummyOne=createNode(-1);
            Node* dummyTwo=createNode(-1);

            Node* zero=dummyZero;
            Node* one=dummyOne;
            Node* two=dummyTwo;

            Node* temp=list;

            while(temp!=nullptr)
            {
                if(temp->data==0)
                {
                    zero->next=temp;
                    zero=temp;
                }
                else if(temp->data==1)
                {
                    one->next=temp;
                    one=temp;
                }
                else if(temp->data==2)
                {
                    two->next=temp;
                    two=temp;
                }
                temp=temp->next;
            }

            zero->next=(dummyOne->next)?dummyOne->next:dummyOne->next;
            one->next=(dummyTwo->next)?dummyTwo->next:nullptr;
            two->next=nullptr;

            this->head=dummyZero->next;

            delete dummyZero;
            delete dummyOne;
            delete dummyTwo;

        }

        void removeKthFromEnd(Node* head,int k)
        {
            if(head==nullptr) return;

            Node* fast=head;
            Node* slow=head;

            for(int i=0;i<k;i++)
            {
                fast=fast->next;
            }
            if(fast==nullptr) return;

            while(fast->next!=nullptr)
            {
                slow=slow->next;
                fast=fast->next;
            }

            Node* delNode=slow->next;
            slow->next=slow->next->next;
            delete delNode;
        }

};
int main()
{
    SinglyLinkedList list1;

    list1.createList(8);
    list1.show();
    std::cout<<"\n";
    list1.removeKthFromEnd(list1.getHead(),3);
    list1.show();

    return 0;
}