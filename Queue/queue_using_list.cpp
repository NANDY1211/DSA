#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node(int val) : data(val) , next(nullptr) {}
};


class Queue
{
    private:
        Node* start_;
        Node* end_;
        int size_;

    public:
        Queue() : start_(nullptr) , end_(nullptr) , size_(0) {}


        ~Queue()
        {
            while(start_)
            {
                Node* delNode = start_;
                start_ = start_->next;

                delete delNode;
            }

            start_ = end_ = nullptr;
        }


        Node* createNode(int val)
        {
            return new Node(val);
        }


        void push(int val)
        {
            Node* newNode = createNode(val);
            if(start_==nullptr)
            {
                start_ = end_ = newNode;
                ++size_;
                return;
            }


            end_->next = newNode;
            end_ = newNode;
            ++size_;
        }


        int pop()
        {
            if(start_==nullptr)
            {
                std::cout<<"Queue is empty\n";
                return -1;
            }

            Node* delNode = start_;
            int val = delNode->data;

            start_ = start_->next;
            delete delNode;
            size_--;
            return val;
        }


        int peek()
        {
            return (start_)?start_->data:-1;
        }

        int size()
        {
            return size_;
        }

        void show()
        {
            Node* temp = start_;
            while(temp)
            {
                std::cout<<temp->data<<",";
                temp = temp->next;
            }

            std::cout<<"\n";
        }
};


int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    std::cout<<"Top of queue is "<<q.peek()<<std::endl;
    std::cout<<"size of queue is "<<q.size()<<std::endl;

    q.pop();
    q.pop();
    q.pop();
    
    q.show();
    return 0;
}