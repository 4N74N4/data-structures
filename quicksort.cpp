#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int Quick_Sort(int A[100],int start,int end)
{
        if((end-start)<1)
                return A[start];
        else
        {
                int mid=(start+end)/2;
                int pivot=A[mid];
        cout<<A[mid]<<'\t';
                A[mid]=A[end-1];
                A[end-1]=pivot;
                int pivot_index=end-1;
                int i=0,temp,j;
                while(i<pivot_index)
                {
                        if(A[pivot_index]<A[i])
                        {
                                temp=A[i];
				for(j=i;j<end-1;j++)
                                        A[j]=A[j+1];
                                A[j]=temp;
                                pivot_index--;
                        }
                        else
                        i++;
                }
                Quick_Sort(A,start,pivot_index);
                Quick_Sort(A,pivot_index+1,end);
        }
}
int main()
{
        clock_t start=clock();
        fstream f;
        f.open("quick.txt",ios::in);
        int size,A[100];
        f>>size;
        for(int i=0;i<size;i++)
                f>>A[i];
        f.close();
	Quick_Sort(A,0,size);
        f.open("quick.txt",ios::out);
        f<<size<<'\n';
        for(int i=0;i<size;i++)
                f<<A[i]<<'\n';
        f.close();
        cout<<"\nRunning Time: "<<(clock()-start)/double(CLOCKS_PER_SEC)*1000<<" seconds"<<endl;
        return 0;
}

