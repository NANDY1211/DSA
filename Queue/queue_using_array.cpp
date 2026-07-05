#include <iostream>


class Queue
{
    private:
        int start;
        int end;
        int currSize;
        int capacity;
        int* arr;

    public:
        Queue(int size)
        {
            start = end = -1;
            currSize=0;
            capacity=size;
            arr=new int[size];
        }


        ~Queue()
        {
            delete[] arr;
        }

        void push(int val)
        {
            if(currSize==0)
            {
                start=end=0;
                arr[end]=val;

                std::cout<<"Pushed "<<arr[end]<<std::endl;
                currSize++;
                return;
            }

            arr[(++end)%capacity] = val;
            currSize++;

            std::cout<<"Pushed "<<arr[end]<<std::endl;
        }


        int pop()
        {
            if(currSize==0)
            {
                std::cout<<"Queue is empty\n";
                return -1;
            }

            if(currSize==1)
            {
                start=end=-1;
                currSize--;
                std::cout<<"Popped "<<arr[currSize]<<std::endl;
                return arr[currSize];
            }

            start=(start+1)%capacity;
            
            std::cout<<"Popped "<<arr[start]<<std::endl;
            currSize--;

            return arr[start];
        }

        int peek()
        {
            if(currSize==0)
            {
                std::cout<<"Queue is empty \n";
                return -1;
            }

            std::cout<<"Top of the queue is "<<arr[start]<<std::endl;
            return arr[start];
        }

        int size()
        {
            return currSize;
        }


        bool isEmpty()
        {
            if(currSize==0) return true;

            return false;
        }

        void show()
        {
            if(currSize==0)
            {
                std::cout<<"Queue is empty\n";
                return;
            }


            for(int i=0;i<currSize;i++)
            {
                std::cout<<arr[i]<<",";
            }
            std::cout<<"\n";
        }
};


int main()
{
    Queue q1(5);

    q1.push(1);
    q1.push(2);
    q1.push(3);

    q1.peek();

    std::cout << "Size of the queue "<<q1.size()<<std::endl;

    q1.pop();
    q1.pop();
    q1.pop();
    std::cout<<"Is the Queue empty "<<std::boolalpha<<q1.isEmpty()<<std::endl;

    q1.show();
    return 0;
}