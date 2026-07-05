#include <iostream>
#include <climits>


class Stack
{
    private:
        int top;
        int capacity;
        int* arr;
    
    public:
        Stack(int size = 0)
        {
            top=-1;
            if(size>0)
            {
                capacity=size;
                arr = new int[size];  
            }
        }

        ~Stack()
        {
            delete[] arr;
        }

        void push(int val)
        {
            if(top>=capacity)
            {
                std::cout<<"Stack Overflow\n";
                return;
            }
            arr[++top] = val;
            std::cout<<"Pushed "<<arr[top]<<std::endl;
        }


        int pop()
        {
            if(top==-1)
            {
                std::cout<<"Stack underflow\n";
                return -1;
            }

            std::cout<<"Popped "<<arr[--top]<<std::endl;
            return arr[top];
        }


        int size()
        {
            return (top+1);
        }

        int peek()
        {
            if(top==-1)
            {
                std::cout<<"Stack is empty\n";
                return -1;
            }

            return arr[top];
        }


        bool isEmpty()
        {
            if(top==-1)
            {
                std::cout<<"Stack is Empty\n";
                return true;
            }
            return false;
        }


        void show()
        {
            for(int i=0;i<=top;i++)
            {
                std::cout<<arr[i]<<",";
            }
            std::cout<<"\n";
        }
};
int main()
{

    Stack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.pop();

    std::cout<<"Top of the stack "<<st.peek()<<std::endl;
    st.isEmpty();
    st.show();
    return 0;
}