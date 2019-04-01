#include<bits/stdc++.h>
using namespace std;
int main(){
	int key,i;
	srand(time(NULL));
	ofstream myfile("inerstion.csv");
	myfile<<"DataSet,Execution Time,No_of_Iteration,No_Of_Comparisons,,,data Set,Exec_B,Iteration_B,B_Comparison\n";	
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
	std::chrono::time_point<std::chrono::system_clock> start, end;	
    start =std::chrono::system_clock::now(); 
    for(int j=2;j<d[t];j++){
    	key =arr[j];
    	i=j-1;
    	countI++;
    	while(i>0&&arr[i]>key){
    		countC++;
    		arr[i+1]=arr[i];
    		i=i-1;
		}
		arr[i+1]=key;
	}
	end = std::chrono::system_clock::now(); 	
    std::chrono::duration<double> elapsed_seconds = end - start;
	myfile<<d[t]<<","<<elapsed_seconds.count()<<","<<countI<<","<<countC<<","<<",";
	start =std::chrono::system_clock::now(); 
	 countI=0;
	 countC=0;
    for(int j=2;j<d[t];j++){
    	key =arr[j];
    	i=j-1;
    	countI++;
    	while(i>0&&arr[i]>key){
    		countC++;
    		arr[i+1]=arr[i];
    		i=i-1;
		}
		arr[i+1]=key;
	}
	end = std::chrono::system_clock::now(); 	
    std::chrono::duration<double> elapsed_seconds1 = end - start;
	myfile<<","<<d[t]<<","<<elapsed_seconds1.count()<<","<<countI<<","<<countC<<","<<"\n";
	t++;
}
}
