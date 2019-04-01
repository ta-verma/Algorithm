#include<bits/stdc++.h>
using namespace std;

int *D;
void countSort(int A[],int n,int exp)
{
    int B[n];
    int i,C[10]={0};
    D=new int[10];
    for (i= 0;i<n;i++)
    {
    	C[(A[i]/exp)%10]++;
	}
    for (i=1;i<10;i++)
	{
		C[i]+=C[i-1];
	}
    for (i= n-1;i>=0;i--)
    {
        B[C[(A[i]/exp)%10]-1]=A[i];
        D[C[(A[i]/exp)%10]-1]=i-1; 
        C[(A[i]/exp)%10]--;
    }
    for (i=0;i<n;i++)
        A[i]=B[i];
}
void radixsort(int A[], int n)
{
    int max=A[0];
    for (int i=1;i<n;i++)
    if (A[i]>max)
    max=A[i];
    for (int i=1; max/i >0; i*=10)
    countSort(A, n, i);
}
int main()
{
    
    int n;
    cout<<"\nEnter the size of array :";
    cin>>n;
    int *A=new int[n];
      
    cout<<"\nEnter Elements :";
	for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"Index:\t";
    for(int i=0;i<n;i++) cout<<i<<" ";
    cout<<endl;
    cout<<"Array:\t";
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
	radixsort(A, n);
    cout<<"\nAfter Sorting  :\n";
    cout<<"Index:\t";
    for(int i=0;i<n;i++)
    cout<<D[i]+1<<" ";cout<<endl;
    cout<<"Array:\t";
	for (int i = 0; i < n; i++)
    cout << A[i] << " ";
	return 0;
}

