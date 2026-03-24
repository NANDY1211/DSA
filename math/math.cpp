#include <iostream>
#include <bits/stdc++.h>

#define NEW_LINE std::cout<<"\n" 
#define LOG(x) std::cout<<x

//Approach1
int count(int n)
{
    int cnt = (int)(log10(n)+1);
    return cnt;
}

//Approach2
int get_count(int num)
{
    if(num == 0)
    {
        return 1;
    }
    int counter = 0;
    while(num>0)
    {
        num/=10;
        counter++;
    }
    return counter;
}


//Reverse a number
int reverse(int num){
    int reversedNum = 0;
    while(num>0){
        int lastDigit = (num%10);
        reversedNum = (reversedNum*10)+lastDigit;
        num/=10;
    }
    return reversedNum;
}

//check palindrome

void check_palindrome(int origNum){
    int num = origNum;
    int reversedNum=0;
    while(num>0)
    {
        int lastDigit = (num%10);
        reversedNum = (reversedNum*10)+lastDigit;
        num/=10;
    }
    if(origNum == reversedNum)
    {
        std::cout<<"It is palindrome\n";
    }
    else
    {
        std::cout<<"It is not a palindrome\n";
    }

}

int main()
{
    LOG(count(123));
    LOG("Count of digit is \n");
    LOG(get_count(0));
    NEW_LINE;
    LOG(reverse(1234));
    NEW_LINE;
    check_palindrome(121);
    return 0;
}