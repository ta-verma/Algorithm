#include<bits/stdc++.h>
using namespace std;
int partion(int *arr,int low,int high);
void quickSort(int *arr,int low,int high){
	int part;
	if(low<high){
		part=partion(arr,low,high);
		quickSort(arr,low,part-1);
		quickSort(arr,part+1,high);
	}
}
int C=0;
int partion(int *arr,int low,int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		++C;
		if(arr[j]<=pivot)
		i++;
		swap(arr[i],arr[j]);
	}
	swap(arr[i+1],arr[high]);
	return i+1;	
}
int main()
{
	ofstream mfile("quicksort.csv");
	
	srand(time(NULL));
	
	mfile<<"Data set,Execution Time,No. of Comparisons,,B_Exec_T,B_Comparison\n";
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
        
		quickSort(left,0,ds[t]);
        
		end = chrono::system_clock::now(); 
		chrono::duration<double> elapsed_seconds = end - start; 	  
		
		mfile<<elapsed_seconds.count()<<","<<C<<","<<",";
		
		  start = chrono::system_clock::now(); 
		  C=0;
        
		quickSort(left,0,ds[t]);
        
		end = chrono::system_clock::now(); 
		chrono::duration<double> elapsed_seconds1 = end - start; 	  
		
		mfile<<elapsed_seconds1.count()<<","<<C<<","<<"\n";
		t++;
	}
	
return 0;
}
