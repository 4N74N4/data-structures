#include <iostream>
#include <fstream>
using namespace std;

int main()
{
        int size,num,elt,index=-1,i;
        fstream f1;
        f1.open("linsearch.txt",ios::in);
        f1>>size;
        for(i=0;i<size;i++)
                f1>>num;
        f1>>num;
        f1.close();
        f1.open("linsearch.txt",ios::in);
        f1>>size;
        for(i=0;i<size;i++)
        {
                f1>>elt;
                if(elt == num)
                {
                        index=i;
                        break;
		}
        }
        cout<<index<<endl;
        return 0;
}

