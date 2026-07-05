#include <iostream>


class Stack
{
    private:
        int top;
        int capacity;
        int* arr;

    public:
        Stack(int size) : top(-1)
        {
            capacity=size;
            arr = new int[size];
        }

        ~Stack(){delete[] arr;}


        //Pushing an element
        void push(int val)
        {
            if(top==capacity-1)
            {
                std::cout<<"Stack Overflow!!!"<<std::endl;
                return;
            }
            arr[++top] = val;
        }

        int pop()
        {
            if(top==-1) 
            {
                std::cout<<"Stack underflow\n";
                return -1;
            }


            std::cout<<"Popped element \t"<<arr[--top]<<std::endl;
            return arr[top];

        }

        int size()
        {
            return top+1;
        }

        int peek()
        {
            if(top==-1) return -1;
            return arr[top];
        }

        void show()
        {
            if(top==-1)
            {
                std::cout<<"Stack is empty\n";
                return;
            }
            for(int i=0;i<=top;i++)
            {
                std::cout<<arr[i]<<",";
            }
            std::cout<<"\n";
        }
    
};

int main()
{
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    std::cout<<"Top element is "<<st.peek()<<std::endl;
    st.pop();
    std::cout<<"Top element is "<<st.peek()<<std::endl;

    std::cout<<"Size of the stack is "<<st.size()<<std::endl;

    st.show();
    return 0;
}