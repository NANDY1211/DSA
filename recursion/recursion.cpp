#include <iostream>
#define NEW_LINE std::cout<<"\n"

//print name for n times using recursion
void print_name(unsigned int times)
{
    if(times<1){
        return;
    }
    std::cout<<"Welcome Nandha Kishore!\n";
    print_name(times-1);
}

//print linearly from 1 to n using recursion
void print_asc(unsigned int times,unsigned int init=1)
{
    if(init>times){
        return;
    }
    std::cout<<"Linear values :: "<<init<<std::endl;
    print_asc(times,init+1);
}

//print linear from N to 1 using recursion
void print_desc(unsigned int times)
{
    if(times<1){
        return;
    }
    std::cout<<"Linearly descending :: "<<times<<std::endl;
    print_desc(times-1);
}

//Print 1 to N using recusrsion and backtracking
void print_asc_back_track(unsigned int times)
{
    if(times<1){
        return;
    }
    print_asc_back_track(times-1);
    std::cout<<"Backtraced Asc Values :: "<<times<<std::endl;
}

//print N to 1 using recursion and backtracking
void print_desc_back_track(unsigned int times,unsigned int init = 1)
{
    if(init>times){
        return;
    }
    print_desc_back_track(times,init+1);
    std::cout<<"Linearly desc value :: "<<init<<std::endl;
}

//Sum of n numbers using parameterized way
void sum_n_param(unsigned int limit,unsigned int sum = 0)
{
    if(limit<1){
        std::cout<<"Sum of n is :: "<<sum<<std::endl;
        return;
    }
    sum_n_param(limit-1,sum+limit);
}


//Sum of n numbers using functional way
unsigned int sum_n_func(unsigned int limit)
{
    if(limit == 1){
        return 1;
    }
    return limit + sum_n_func(limit-1);
}

//factorial numbers using recursion and parameterized way
void fact_param(unsigned int limit,unsigned fact = 1)
{
    if(limit <1){
        std::cout<<"Factorial using param way is :: "<<fact<<std::endl;
        return;
    }
    fact_param(limit-1,fact*limit);
}

//factorial numbers using recursion and functional way
unsigned int fact_func(unsigned int limit)
{
    if(limit == 1){
        return 1;
    }
    return limit * fact_func(limit-1);
}

int main()
{
    print_name(5);
    NEW_LINE;
    print_asc(5);
    NEW_LINE;
    print_desc(5);
    NEW_LINE;
    print_asc_back_track(5);
    NEW_LINE;
    print_desc_back_track(5);
    NEW_LINE;
    sum_n_param(3);
    NEW_LINE;
    std::cout << "Sum using functional :: "<<sum_n_func(6)<<std::endl;
    NEW_LINE;
    fact_param(5);
    NEW_LINE;
    std::cout<<"Factorial using functional way is :: "<<fact_func(10)<<std::endl;
    
    return 0;
}