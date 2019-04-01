#include<bits/stdc++.h>
using namespace std;

void MAX_HEAPIFY(int *arr,int i,int n,int& comparisons)
{
	int l = 2*i+1 ;
	int r = 2*i +2 ;
	int max;
	if(++comparisons && l<=n && arr[l] > arr[i] )
		max=l;
	else
		max=i;
	if(++comparisons && r<=n && arr[r] > arr[max])
		max=r;
	if(max != i)
	{
		swap(arr[i],arr[max]);
		MAX_HEAPIFY(arr,max,n,comparisons);
	}
}

BUILD_MAX_HEAPIFY(int *arr,int n,int& comparisons)
{
	for(int i=(n-1)/2 ; i>=0 ; i--)
	MAX_HEAPIFY(arr,i,n,comparisons);
}

HEAP_SORT(int *arr,int n,int& comparisons)
{
	BUILD_MAX_HEAPIFY(arr,n,comparisons);
	
	for(int i=n; i>0 ; i--)
	{
		swap(arr[0],arr[i]);
		MAX_HEAPIFY(arr,0,i-1,comparisons);
	
	}
}

int main()
{
	ofstream mfile("Heap.csv");
	srand(time(NULL));
	mfile<<"Data set,Execution Time,Comparisons,,BestTime,BestComparisons\n";
	int ds[]={10,100,200,300,500,1000,2000,3000,5000,10000,20000,30000,50000,100000};
	int t=0;
	while(t<10)
	{   
		int *arr=new int[ds[t]];
		mfile<<ds[t]<<",";
		for(int i=0;i<ds[t];i++)
		{
			arr[i] =rand()%ds[t];
		}
	    int comparisons=0;
    	chrono::time_point<chrono::system_clock> start, end; 
        start = chrono::system_clock::now(); 
        
		HEAP_SORT(arr,ds[t]-1,comparisons);
        
		end = chrono::system_clock::now(); 
		chrono::duration<double> elapsed_seconds = end - start; 	  
		
		mfile<<elapsed_seconds.count()<<","<<comparisons<<",,";
		
		comparisons=0;
		start = chrono::system_clock::now(); 
		HEAP_SORT(arr,ds[t]-1,comparisons);
		end = chrono::system_clock::now(); 
		elapsed_seconds = end - start; 	  
		
		mfile<<elapsed_seconds.count()<<","<<comparisons<<",\n";
		
		
		t++;
	}
	
return 0;
}
