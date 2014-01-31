#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

int Check_Alpha(string a)
{
        for(int i=0;i<a.size();i++)
                if(!(isalpha(a[i]))||!(islower(a[i])))
                        return -1;
        return 1;
}
int main()
{
        fstream f;
        f.open("sel_sort.txt",ios::in);
        int size,j,i,index;
        string A[100],temp;
        f>>size;
        for(i=0;i<size;i++)
                f>>A[i];
        f.close();
	for(i=0;i<size;i++)
        {
                index=Check_Alpha(A[i]);
                if(index==-1)
                        break;
                for(j=i+1;j<size;j++)
                {
                        if(A[i]>A[j])
                        {
                                temp=A[i];
                                A[i]=A[j];
                                A[j]=temp;
                        }
                }
        }
        if(index==-1)
                cout<<"Invalid";
        else
        f.open("sel_sort.txt",ios::out);
        f<<size<<'\n';
        for(i=0;i<size;i++)
                f<<A[i]<<'\n';
        f.close();
	return 0;
}


