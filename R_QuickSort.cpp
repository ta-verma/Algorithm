#include<bits/stdc++.h>
using namespace std;

double C=0;
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1);  
  	for (int j = low; j <= high - 1; j++) 
	{ 
  		if (arr[j] <= pivot) 
		{ 	C++;
  			i++;
           	swap(arr[i], arr[j]); 
		} 
   	}	 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
 
int partition_r(int arr[], int low, int high) 
{ 
    
	srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  	swap(arr[random], arr[high]); 
  	return partition(arr, low, high); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
	{ 

        int pi = partition_r(arr, low, high); 
  		quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
int main()
{
	ofstream mfile("R_QuickSort.csv");
	
	srand(time(NULL));
	mfile<<"Data set,Execution Time,No. of Comparisons,,B_Exec_T,B_Comparison\n";
	int ds[]={100,200,300,500,1000,2000,3000,5000,10000,20000,30000,50000,100000};
	int t=0;
	while(t<13)
	{   
		int *arr=new int[ds[t]];
		mfile<<ds[t]<<",";
		for(int i=0;i<ds[t];i++)
		{
			arr[i] =rand()%ds[t];
		}
	 
    	chrono::time_point<chrono::system_clock> start, end; 
        start = chrono::system_clock::now(); 
        
		quickSort(arr,0,ds[t]);
        end = chrono::system_clock::now(); 
		chrono::duration<double> elapsed_seconds = end - start; 	  
		mfile<<elapsed_seconds.count()<<","<<C<<","<<",";
		
		start = chrono::system_clock::now(); 
		C=0;
        quickSort(arr,0,ds[t]);
        end = chrono::system_clock::now(); 
		chrono::duration<double> elapsed_seconds1 = end - start; 	  
		mfile<<elapsed_seconds1.count()<<","<<C<<","<<"\n";
		t++;
	}
	
return 0;
}
