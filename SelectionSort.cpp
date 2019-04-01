#include<bits/stdc++.h>
using namespace std;
int main()
{
	int key,i,min;
	srand(time(NULL));
	ofstream myfile("selection.csv");
	myfile<<"DataSet,Execution Time,No_Of_Comparisons,,,B_Execution_Time,B_Comparison\n";	
	int d[]={100,200,300,500,1000,2000,3000,5000,10000,20000,30000,50000,100000};
	int t=0;	
	while(t<13)
	{		
	int*arr=new int[d[t]];	
	for(int i=0;i<d[t];i++)
	{
		arr[i]=rand()%d[t];
	}
	double countI=0;
	double countC=0;
	chrono::time_point<chrono::system_clock> start, end; 
    start =std::chrono::system_clock::now();
	for(int j=1;j<d[t]-1;j++){
		min =j;
		for(i=j+1;i<d[t];i++){
			countI++;
			if(arr[i]<arr[min])
			{
				countC++;
				min=i;
				key=arr[i];
				arr[i]=arr[j];
				arr[j]=key;
			}
		}
	}
	end = std::chrono::system_clock::now(); 	
    std::chrono::duration<double> elapsed_seconds = end-start;
  
	myfile<<d[t]<<","<<elapsed_seconds.count()<<","<<countC<<","<<",";
	start =std::chrono::system_clock::now();
	  countI=0;
    countC=0;
	for(int j=1;j<d[t]-1;j++){
		min =j;
		for(i=j+1;i<d[t];i++){
			countI++;
			if(arr[i]<arr[min]){
				countC++;
				min=i;
				key=arr[i];
				arr[i]=arr[j];
				arr[j]=key;
			}
		}
	}
	end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds1 = end - start;
		myfile<<d[t]<<","<<elapsed_seconds1.count()<<","<<countC<<","<<"\n"; 
	t++;
}
}
