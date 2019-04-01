#include<bits/stdc++.h>
using namespace std;

void merge(int* A,int,int,int);
void merge_sort(int* A,int s,int e)
{  
    
	if(s<e)
	{
		int mid=(s+e)/2;
		merge_sort(A,s,mid);
		merge_sort(A,mid+1,e);
		merge(A,s,mid,e);
	}
}
int C=0;
void merge(int* A,int s,int mid,int e)
{
   
	int m=mid-s+1,n=e-mid;
	int *left=new int [m];
	int *right=new int[n];
	for(int i=0;i<m;i++)
	{
		left[i]=A[i+s];
	}
	for(int i=0;i<n;i++)
	{
		right[i]=A[i+mid+1];
	}
    int i=0,j=0,k=s;
	while(i<n && j<m)
    {
    	++C;
        if(left[i]  <= right[j])
            A[k++]=left[i++];
        else 
            A[k++]=right[j++];
    }
    while(i<n)
        A[k++]=left[i++];
    while(j<m)
        A[k++]=right[j++];
}    
    
int main()
{
	ofstream mfile("merge.csv");
	
	srand(time(NULL));
	
	mfile<<"Data set,Execution Time,No. of Comparisons,,B_Time,B_Comparisons\n";
	int ds[]={100,200,300,500,1000,2000,3000,5000,10000,20000,30000,50000,100000};
	int t=0;
	while(t<13)
	{   
		int *left=new int[ds[t]];
		mfile<<ds[t]<<",";
		for(int i=0;i<ds[t];i++)
		{
			left[i] =rand()%ds[t];
		}
	 
    	chrono::time_point<chrono::system_clock> start, end; 
        start = chrono::system_clock::now(); 
    
        
		merge_sort(left,0,ds[t]);
        
		end = chrono::system_clock::now(); 
		chrono::duration<double> elapsed_seconds = end - start; 	  
		
		mfile<<elapsed_seconds.count()<<","<<C<<","<<",";
		
		
		start = chrono::system_clock::now(); 
        C=0;
        
		merge_sort(left,0,ds[t]);
        
		end = chrono::system_clock::now(); 
		chrono::duration<double> elapsed_seconds1 = end - start; 	  
		
		mfile<<elapsed_seconds1.count()<<","<<C<<","<<"\n";
		t++;
	}
	
return 0;
}
