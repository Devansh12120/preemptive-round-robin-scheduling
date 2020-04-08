#include<bits/stdc++.h> 
using namespace std; 
struct Process 
{ 
	int pid; 
	int bt;  
	int priority; 
}; 
// Function to sort the Process acc. to priority 
bool comparison(Process x, Process y) 
{ 
	return (x.priority > y.priority); 
} 
//waiting time 
void findWaitingTime(Process proc[], int n, int wt[]) 
{ 
	// waiting time is 0 for 1st process 
	wt[0] = 0; 

	//waiting time calculation 
	for(int i=1;i<n;i++) 
	{wt[i]=proc[i-1].bt+wt[i-1]; 
    }
} 
// TAT calculation for a process
void findTurnAroundTime( Process proc[], int n,	int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = proc[i].bt + wt[i]; 
} 
//Function to calculate average time 
void findavgTime(Process proc[], int n) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	//Function to find waiting time of all processes 
	findWaitingTime(proc, n, wt); 
	//Function to find turn around time for all processes 
	findTurnAroundTime(proc, n, wt, tat); 
	//Display processes  
	cout << "\nProcesses "<< " Burst time "<<" Priority "<< " Waiting time " << " Turn around time\n"; 
	// Calculate total waiting time and total turn around time 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << proc[i].pid << "\t\t"
			<< proc[i].bt << "\t " <<proc[i].priority<<"\t "<< wt[i] 
			<< "\t\t " << tat[i] <<endl; 
	} 
	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
} 
void priorityScheduling(Process proc[], int n) 
{ 
	// Sort processes by priority 
	sort(proc, proc + n, comparison); 
	cout<< "Order in which processes gets executed \n"; 
	for (int i = 0 ; i < n; i++) 
		cout << proc[i].pid <<" " ; 
	findavgTime(proc, n); 
} 
// Driver code 
int main() 
{ 
	Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 0},{4, 10, 2}, {5, 5, 0}, {6, 8, 3}}; 
	int n = sizeof proc / sizeof proc[0]; 
	priorityScheduling(proc, n); 
	return 0; 
} 

