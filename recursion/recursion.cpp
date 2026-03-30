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
    return 0;
}