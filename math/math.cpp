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

void check_armstrong(int num)
{
    int origNum = num;
    int sum = 0;
    while(origNum>0)
    {
        int lastDigit = origNum%10;
        sum = sum+(lastDigit*lastDigit*lastDigit);
        origNum/=10;
    }
    if(sum == num){
        std::cout<<"It is armstrong number\n";
    }
    else{
        std::cout<<"It is not a armstrong number\n";
    }
    return;
}

void print_divisors(int num)
{
    for(int i = 1;i<=std::sqrt(num);i++)
    {
        if((num%i) == 0){
            std::cout<<i<<",";

            if((num/i) != i){
                std::cout<<(num/i)<<",";
            }
        }
    }
    return;
}


void check_prime(int num)
{
    int count = 0;
    for(int i = 1;i<=std::sqrt(num);i++)
    {
        if((num%i) == 0){
            count++;
            if((num/i) != i){
                count++;
            }
        }
    }
    if(count == 2){
        std::cout<<"It is prime number\n";
    }
    else{
        std::cout<<"It is not a prime number\n";
    }
}

void find_gcd(int num1,int num2)
{
    while((num1>0) and (num2>0)){
        if(num1>num2){
            num1 %= num2;
        }
        else
        {
            num2 %= num1;
        }
    }
    if(num1 == 0){
        std::cout<<"GCD is "<<num2<<std::endl;
    }
    else{
        std::cout<<"GCD is "<<num1<<std::endl;
    }
    return;
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
    NEW_LINE;
    check_armstrong(153);
    NEW_LINE;
    print_divisors(36);
    NEW_LINE;
    check_prime(11);
    NEW_LINE;
    find_gcd(11,13);
    NEW_LINE;
    return 0;
}