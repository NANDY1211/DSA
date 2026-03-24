#include <iostream>

#define NEW_LINE std::cout<<"\n";

void pattern1(int p_input)
{
    for(int row= 0; row < p_input ; row++)
    {
        for(int col=0;col<p_input ; col++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    return;
}

void pattern2(int p_input)
{
    for(int row= 0; row < p_input ; row++)
    {
        for(int col=0;col<=row ; col++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    return;
}

void pattern3(int p_input)
{
    for(int row= 0; row < p_input ; row++)
    {
        for(int col=1;col<=row+1 ; col++)
        {
            std::cout<<col;
        }
        std::cout<<"\n";
    }
    return;
}

void pattern4(int p_input)
{
    for(int row= 1; row <= p_input ; row++)
    {
        for(int col=1;col<=row ; col++)
        {
            std::cout<<row;
        }
        std::cout<<"\n";
    }
    return;
}

void pattern5(int p_input)
{
    for(int row= 1; row <= p_input ; row++)
    {
        for(int col=1;col<=(p_input-row+1) ; col++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    return;
}

void pattern6(int p_input)
{
    for(int row= 1; row <= p_input ; row++)
    {
        for(int col = 1;col<=row;col++)
        {
            std::cout<<" ";
        }
        for(int col=1;col<=(p_input-row+1) ; col++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    return;
}

void pattern7(int p_input)
{
    for(int row= 1; row <= p_input ; row++)
    {
        for(int col = 1;col<=(p_input-row);col++)
        {
            std::cout<<" ";
        }
        for(int col=1;col<=row ; col++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    return;
}

void pattern8(int p_input)
{
    for(int row= 1; row <= p_input ; row++)
    {
        for(int col = 1;col<=row;col++)
        {
            std::cout<<" ";
        }
        for(int col=1;col<=(p_input-row+1) ; col++)
        {
            std::cout<<col;
        }
        std::cout<<"\n";
    }
    return;
}

void pattern9(int p_input)
{
    for(int row = 0; row<p_input;row++)
    {
        //space
        for(int col = 0;col<(p_input-row-1);col++)
        {
            std::cout<<" ";
        }

        //star

        for(int col = 0 ; col<((2*row)+1);col++)
        {
            std::cout<<"*";
        }

        //space
        for(int col = 0;col<(p_input-row-1);col++)
        {
            std::cout<<" ";
        }

        std::cout<<"\n";
    }
    return;
}

void pattern10(int p_input)
{
    for(int row= 1; row <= p_input ; row++)
    {
        for(int col = 1;col<=(p_input-row);col++)
        {
            std::cout<<" ";
        }
        for(int col=1;col<=row ; col++)
        {
            std::cout<<col;
        }
        std::cout<<"\n";
    }
    return;
}

void pattern11(int size)
{
    for(int row=0;row<size;row++)
    {
        //space
        for(int col = 0 ; col<row;col++)
        {
            std::cout<<" ";
        }

        //star
        for(int col=0;col<((2*size)-(2*row)-1);col++)
        {
            std::cout<<"*";
        }

        //space
        for(int col = 0 ; col<row;col++)
        {
            std::cout<<" ";
        }
        std::cout<<"\n";
    }
}


void pattern12(int size)
{
    for(int row=0;row<=(2*size - 1);row++)
    {
        int star = row;
        if(row+1>size)
            star = 2*size-row-2;
        for(int col = 0 ; col<=star;col++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
}


void pattern13(int size)
{
    int state=1;
    for(int row=0;row<=size;row++)
    {
        if(row&1)
            state = 1;
        for(int col=0;col<row;col++)
        {
            std::cout<<state;
            state = 1-state; //state flip
        }
        std::cout<<"\n";
    }
    return;
}


void pattern14(int size)
{
    for(int row = 1;row<=size;row++)
    {
        //num
        for(int col=1;col<=row;col++)
        {
            std::cout<<col;
        }

        //space
        for(int col=0;col<(2*(size-row));col++)
        {
            std::cout<<" ";
        }

        //number
        for(int col=row;col>=1;col--)
        {
            std::cout<<col;
        }
        std::cout<<"\n";
    }
    return;
}


void pattern15(int size)
{
    for(int row=0;row<size;row++)
    {
        int ascii = 65;
        for(int col = 0;col<row;col++)
        {
            std::cout<<(char)ascii;
            ascii++;
        }
        std::cout<<"\n";
    }
}

void pattern16(int size)
{
    for(int row=0;row<size;row++)
    {
        int ascii=65;
        for(int col=0;col<(size-row-1);col++)
        {
            std::cout<<(char)ascii;
            ascii++;
        }
        std::cout<<"\n";
    }
}

void pattern17(int size)
{
    int ascii=65;
    for(int row=0;row<size;row++)
    {
        for(int col=0;col<=row;col++)
        {
            std::cout<<(char)ascii;
        }
        ascii++;
        std::cout<<"\n";
    }
}

void pattern18(int p_input)
{
    for(int row = 0; row<p_input;row++)
    {
        //space
        for(int col = 0;col<(p_input-row-1);col++)
        {
            std::cout<<" ";
        }

        //star
        int start = 65;
        int breakpoint = (((2*row)+1)/2)-1;
        for(int col = 0 ; col<((2*row)+1);col++)
        {
            std::cout<<(char)start;
            if(col<=breakpoint)
                start++;
            else
                start--;
        }

        //space
        for(int col = 0;col<(p_input-row-1);col++)
        {
            std::cout<<" ";
        }

        std::cout<<"\n";
    }
    return;
}

void pattern19(int size)
{
    for(int row=0;row<size;row++)
    {

        //star
        for(int col=0;col<(size-row);col++)
        {
            std::cout<<"*";
        }

        //space
        for(int col=0;col<(2*row);col++)
        {
            std::cout<<" ";
        }

        //star
        for(int col=0;col<(size-row);col++)
        {
            std::cout<<"*";
        }

        std::cout<<"\n";
    }
}

void pattern20(int size)
{
    for(int row=1;row<=size;row++)
    {

        //star
        for(int col=1;col<=row;col++)
        {
            std::cout<<"*";
        }

        //space
        for(int col=0;col<2*(size-row);col++)
        {
            std::cout<<" ";
        }

        //star
        for(int col=1;col<=row;col++)
        {
            std::cout<<"*";
        }

        std::cout<<"\n";
    }
    return;
}

void pattern21(int size)
{
    for(int row=1;row<=(2*size)-1;row++)
    {
        int star=row;
        int space=2*(size-row);


        if(row>=size)
        {
            star = 2*(size) -row;
            space = ((size+row) - (2*size))*2;
        }

        //star
        for(int col=1;col<=star;col++)
        {
            std::cout<<"*";
        }

        //space
        for(int col=1;col<=space;col++)
        {
            std::cout<<" ";
        }

        //star
        for(int col=1;col<=star;col++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
}

void pattern22(int size)
{
    int rowcount = 0;
    int colcount = 0;
    int num=size;
    for(int row=rowcount;row<size;row++)
    {

        for(int col=colcount;col<size;col++)
        {
            if(row == 0 || row == size-1 || col == 0 || col == size-1 )
            {
                std::cout<<num;
            }
            else
            {
                std::cout<<" ";
            }

        }
        std::cout<<"\n";
    }
    return;
}


int main()
{
    pattern1(8);
    NEW_LINE
    pattern2(8);
    NEW_LINE
    pattern3(8);
    NEW_LINE
    pattern4(8);
    NEW_LINE
    pattern5(8);
    NEW_LINE
    pattern6(8);
    NEW_LINE
    pattern7(8);
    NEW_LINE
    pattern8(8);
    NEW_LINE
    pattern9(8);
    NEW_LINE
    pattern10(8);
    NEW_LINE
    pattern11(8);
    NEW_LINE
    pattern12(8);
    NEW_LINE
    pattern13(4);
    NEW_LINE
    pattern14(4);
    NEW_LINE
    pattern15(5);
    NEW_LINE
    pattern16(5);
    NEW_LINE
    pattern17(5);
    NEW_LINE
    pattern18(5);
    NEW_LINE
    pattern19(5);
    NEW_LINE
    pattern20(5);
    NEW_LINE
    pattern21(5);
    NEW_LINE
    pattern22(5);
    return 0;

}