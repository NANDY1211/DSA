#include <iostream>
#include <cstring>


//Class to Compute number frequency using array . Hashing method
class NumFreq
{
    private:
        int m_size;
        int* m_hashArr;

    public:
        NumFreq(){};
        ~NumFreq()
        {
            delete[] m_hashArr;
            m_size = 0;
        }
        void precompute(int arr[],int size)
        {
            m_size = size;
            m_hashArr = new int[m_size+1];
            memset(m_hashArr,0,sizeof(m_size+1));
            for(int i=0;i<m_size;i++)
            {
                m_hashArr[arr[i]]++;
            }
        }

        void getFreq(int val)
        {
            std::cout<<"Frequency of "<<val<<" is "<<m_hashArr[val];
        }
};


//Class to compute character frequency using array . Hashing method

#define ALPHA_SIZE 26

class CharFreq
{
    private:
        int* m_lowerHash;
        int* m_upperHash;

    public:
        CharFreq() :m_lowerHash(nullptr) , m_upperHash(nullptr){};
        ~CharFreq()
        {
            delete[] m_lowerHash;
            delete[] m_upperHash;
        }

        void precompute(char arr[],int p_size)
        {
            m_lowerHash = new int[ALPHA_SIZE+1];
            m_upperHash = new int[ALPHA_SIZE+1];

            memset(m_lowerHash, 0, (ALPHA_SIZE+1) * sizeof(char));
            memset(m_upperHash, 0, (ALPHA_SIZE+1) * sizeof(char));


            for(int ch=0;ch<p_size;ch++)
            {
                if(arr[ch] >= 'A' and arr[ch] <= 'Z')
                {
                    m_upperHash[arr[ch] - 'A']++;
                }
                else if(arr[ch] >= 'a' and arr[ch] <= 'z')
                {
                    m_lowerHash[arr[ch] - 'a']++;
                }
                else
                {
                    std::cout<<"Invalid Input\n";
                    return;
                }
            }
        }


        void getFreq(char ch)
        {
                if(ch >= 'A' and ch <= 'Z')
                {
                    std::cout<<"Frequency of "<<ch<<" is "<<m_upperHash[ch - 'A']<<std::endl;
                }
                else if(ch >= 'a' and ch <= 'z')
                {
                    std::cout<<"Frequency of "<<ch<<" is "<<m_lowerHash[ch - 'a']<<std::endl;
                }          
                else
                {
                    std::cout<<"Provide Valid Input \n";
                    return;
                }
            
        }

};

//Hash map using unordered map

#include <unordered_map>
#include <climits>

std::unordered_map<int,int> g_hashMap;


void precompute(int arr[],int size)
{
    for(int i = 0 ;i < size; i++)
    {
        g_hashMap[arr[i]]++;
    }
}

void getFrequency(int val)
{
    std::cout<<"Frequency of "<<val<<" is "<<g_hashMap[val]<<std::endl;
}

void minAndMaxFreq()
{
    int high = 0;
    int low = INT_MAX;
    for(auto it = g_hashMap.begin();it!=g_hashMap.end();it++)
    {
        if(it->second > high)
        {
            high = it->second;
        }

        if(it->second<low)
        {
            low = it->second;
        }
    }

        std::cout<<"Min Frequency "<<low<<std::endl;
        std::cout<<"Max Frequency "<<high<<std::endl;
}

int main()
{
    char arr[10] = {'a','a','A','A','C','a','v','v','x','z'};
    int iArr[10] = {1,2,3,4,4,4,4,3,2,2};
    precompute(iArr,10);

    getFrequency(4);
    
    minAndMaxFreq();

    return 0;
}