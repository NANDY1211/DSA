#include <iostream>
#include <stack>

bool isBalanced(std::string par)
{
    std::stack<char> cStack;
    for(int i=0;i<par.size();i++)
    {
        if(par[i] == '{'|| par[i] == '(' || par[i] == '[')
        {
            cStack.push(par[i]);
            continue;
        }
        else
        {
            if(cStack.empty())
                return false;
        }
        
        char top = cStack.top();

        if((par[i] == '}' && top == '{') || (par[i] == ')' && top == '(') || (par[i] == ']' && top == '['))
        {
            cStack.pop();
            continue;
        }
        else
        {
            if(!cStack.empty())
                return false;
        }
    }

    if(cStack.empty())
        return true;
    return false;
}
int main()
{
    std::string s1 = "()";
    std::string s2 = "{[()]}";
    std::string s3 = "{[(]}";
    std::cout<<std::boolalpha<<isBalanced(s1)<<std::endl;
    std::cout<<std::boolalpha<<isBalanced(s2)<<std::endl;
    std::cout<<std::boolalpha<<isBalanced(s3)<<std::endl;
    return 0;
}