#include<bits/stdc++.h>
using namespace std;
int main () {
	srand(time(NULL));
	ofstream myfile("Bubble.csv");
	myfile<<"DataSet,Execution_Time,No_Of_Iterations,No_Of_Comparisons,,Data Set,Execution_Time,B_Iteration,B_Comparison\n";	
	int d[]={100,200,300,500,1000,2000,3000,5000,10000,20000,30000,50000,100000};
	int t=0;	
	while(t<10)
	{		
	int *arr=new int[d[t]];	
	for(int i=0;i<d[t];i++)
	{
		arr[i]=rand()%d[t];
	}
	double countI=0;
	double countC=0;		
	std::chrono::time_point<std::chrono::system_clock> start, end;	
    start =std::chrono::system_clock::now(); 
	for(int i=0;i<d[t];i++)
	{
	for(int j=d[t]-1;j>=i+1;j--)
	{	countI++;
		if(arr[j]<arr[j-1])
		{
			countC++;
			swap(arr[j],arr[j-1]);
		}
	}
	}
	end = std::chrono::system_clock::now(); 	
    std::chrono::duration<double> elapsed_seconds = end - start;
	myfile<<d[t]<<",";	
	myfile<<elapsed_seconds.count()<<","<<countI<<","<<countC<<",,";
	 start =std::chrono::system_clock::now(); 
	countI=0;
	 countC=0;
	for(int i=0;i<d[t];i++)
	{
	for(int j=d[t]-1;j>=i+1;j--)
	{	countI++;
		if(arr[j]<arr[j-1])
		{
			countC++;
			swap(arr[j],arr[j-1]);
		}
	}
	}
	end = std::chrono::system_clock::now(); 	
    std::chrono::duration<double> elapsed_seconds1 = end - start;
	myfile<<d[t]<<",";	
	myfile<<elapsed_seconds1.count()<<","<<countI<<","<<countC<<"\n";
	t++;
	}
}

