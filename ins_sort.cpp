#include <iostream>
#include <fstream>
using namespace std;

int main()
{
        int size,i,j;
        float key;
        fstream f;
        f.open("ins.txt",ios::in);
        f>>size;
        float *A = new float[size];
        for(i=0;i<size;i++)
                f>>A[i];
        f.close();
        for(i=1;i<size;i++)
        {
                key=A[i];
                j=i-1;
                while(j>0 && A[j]>key)
                {
                        A[j+1]=A[j];
                        j--;
		}
                A[j+1]=key;
        }
        f.open("insert.txt",ios::out);
        f<<size;
        for(i=0;i<size;i++)
                f<<A[i];
        f.close();
        delete [] A;
        return 0;
}

