#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node(int val) : data(val) , next(nullptr){}
};

class Stack
{
    private:
        Node* top_;
        int size_;

    public:
        Stack() : top_(nullptr) , size_(0){}

        ~Stack()
        {
            while(top_)
            {
                Node* delNode=top_;
                top_=top_->next;
                delete delNode;
            }
            top_=nullptr;
        }

        Node* createNode(int val)
        {
            return new Node(val);
        }

        void push(int val)
        {
            Node* newNode = createNode(val);
            if(top_==nullptr)
            {
                top_ = newNode;
                size_++;
                return;
            }

            newNode->next=top_;
            top_=newNode;
            size_++;
        }


        int pop()
        {
            if(top_==nullptr)
            {
                std::cout<<"Stack underflow\n";
                return -1;
            }


            Node* delNode=top_;
            int val = delNode->data;
            top_=top_->next;
            size_--;
            delete delNode;
            return val;
        }


        int size()
        {
            return size_;
        }


        int peek()
        {
            if(top_==nullptr)
            {
                std::cout<<"Stack is empty\n";
                return -1;
            }

            return top_->data;
        }

        bool isEmpty()
        {
            if(top_==nullptr)
                return true;

            return false;
        }


        void show()
        {
            Node* temp=top_;
            while(temp)
            {
                std::cout<<temp->data<<",";
                temp=temp->next;
            }
            std::cout<<"\n";
        }

};
int main()
{

    Stack st;

    st.push(1);
    st.push(2);
    st.push(99);

    std::cout<<"Top of the stack is "<<st.peek()<<std::endl;
    std::cout<<"Size of the stack is "<<st.size()<<std::endl;

    st.pop();

    st.pop();

    st.pop();

    st.show();

    return 0;
}