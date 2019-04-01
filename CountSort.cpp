#include<iostream>
using namespace std;
int k=0;
int *D;
void CountSort(int A[],int B[],int n)
{
	int C[30];
	D=new int[n];
	for(int i=0;i<k+1;i++)
	{
		C[i]=0;
	}
	for(int j=1;j<=n;j++)
	{
		C[A[j]]++;
	}
	for(int i=1;i<=k;i++)
	{
		C[i]=C[i]+C[i-1];
	}
	for(int j=n;j>0;j--)
	{
		B[C[A[j]]]=A[j];
		D[C[A[j]]]=j-1;
		C[A[j]]=C[A[j]]-1;
	}
}
int main()
{
	int n;
	int A[30];
	int B[30];
	cout<<"Enter size of Array :";
	cin>>n;
	cout<<"Enter Elements:";
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		if(A[i]>k)
		{
			k=A[i];
		}
	}
	cout<<endl<<"Index:\t";
	for(int i=1;i<=n;i++)
	cout<<i<<" ";
	cout<<endl<<"A:\t";
	for(int i=1;i<=n;i++)
	 {
	 	cout<<A[i]<<" ";
     }
    CountSort(A,B,n);
    cout<<endl<<endl;
	cout<<endl<<"Index:\t";
	for(int i=1;i<=n;i++)
	 { 
	 	cout<<D[i]<<" ";
     }
     cout<<endl;
     cout<<"B:\t";
	 for(int i=1;i<=n;i++)
	 {
	 	cout<<B[i]<<" ";
     }
     	cout<<endl;
}

