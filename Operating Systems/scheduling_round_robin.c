#include <stdio.h>
#include <stdlib.h>

// Assign 10 characters of memory to each process name
#define PROCESS_NAME_SIZE 10

// Structure of each Process 
struct process
{
    char process_name[PROCESS_NAME_SIZE];
    int burst_time;
    int remaining_burst_time;
    int waiting_time;
    int turnaround_time;
};
typedef struct process Process;

// Function to schedule processes in round robin manner with allocating waiting and turnaround times to each process
void schedule_round_robin(Process*, int, int);

// Function to compute and display average waiting and turnaround time with each scheduled process information
void display_average_waiting_and_turnaround_time(Process*, int);
  
// Main driver code 
int main() 
{ 
    int total_number_of_processes, time_quantum, i;
    Process *processes;
    
    printf("\n ***** Round Robin Scheduling *****\n");
    
    // Input total number of processes
    printf("\n Enter number of processes: ");
    scanf("%d",&total_number_of_processes);
    
    processes = (Process*) malloc (total_number_of_processes * sizeof(Process));
    
    for (i = 0; i < total_number_of_processes; i++) 
    {
        // Input each process name
        printf("\n Enter the name of process: ");
        scanf("%s", processes[i].process_name);

        // Input each process burst time and assign remaining burst time to burst time entered
        printf(" Enter the burst time: ");
        scanf("%d",&processes[i].burst_time);        
        processes[i].remaining_burst_time = processes[i].burst_time;        

    }
    
    // Input the time quantum
    printf("\n Enter the time quantum: ");
    scanf("%d",&time_quantum);
    
    // Schedule processes in round robin manner with allocating waiting and turnaround times to each process
    schedule_round_robin(processes, total_number_of_processes, time_quantum);
    
    // Compute and display average waiting and turnaround time with each scheduled process information
    display_average_waiting_and_turnaround_time(processes, total_number_of_processes);  
    
    return 0; 
}

// Function to schedule processes in round robin manner with allocating waiting and turnaround times to each process
void schedule_round_robin(Process *processes, int total_number_of_processes, int time_quantum) 
{ 
    // Assign time_elapsed assumed to start at 0 
    // Initialize process_completed flag to keep track if process
    int time_elapsed = 0, process_completed, i; 
  
    // Traverse all processes in round robin manner until all of the processes are not completed
    while (1) 
    { 
        process_completed = 1; 
  
        // Traverse all processes one by one repeatedly 
        for (i = 0 ; i < total_number_of_processes; i++) 
        { 
            // Proceed further only if a process burst time is greater than 0 
            if (processes[i].remaining_burst_time > 0) 
            { 
                // Assign process_completed flag as 0 i.e. process is still pending
                process_completed = 0; 
  
                // If a process remaining time is greater than time quantum
                if (processes[i].remaining_burst_time > time_quantum) 
                { 
                    // Increase the value of time elapsed by a quantum time 
                    time_elapsed += time_quantum; 
  
                    // Decrease the remaining burst time of current process by time quantum 
                    processes[i].remaining_burst_time -= time_quantum; 
                } 
  
                // Else, if a remaining process burst time is smaller than or equal to time quantum
                else
                { 
                    // Increase the value of time elapsed by remaining burst time it has been completed 
                    time_elapsed += processes[i].remaining_burst_time;
  
                    // Assign its waiting time as time elapsed subtracted by its burst time of this process
                    processes[i].waiting_time = time_elapsed - processes[i].burst_time; 
                    
                    // Assign its turnaround time as waiting time added to its burst time
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;                   
  
                    // Assign its remaining burst time = 0, since the process is completed 
                    processes[i].remaining_burst_time = 0; 
                } 
            } 
        }   
        // If all processes are completed, exit
        if (process_completed == 1) 
          break; 
    } 
} 
  
// Function to compute and display average waiting and turnaround time with each scheduled process information
void display_average_waiting_and_turnaround_time(Process* processes, int total_number_of_processes)
{ 
    // Initialize total waiting time and turnaround time to 0
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    // Display each process information header
    printf("\n Process name\tBurst Time\tWaiting Time\tTurn Around Time\n");
    
    for (int i = 0; i < total_number_of_processes; i++)
    {
        // Display each processes information
        printf(" %s\t\t%d\t\t%d\t\t%d\n", 
        processes[i].process_name,
        processes[i].burst_time,
        processes[i].waiting_time,
        processes[i].turnaround_time);
        
        // Accumulate each process waiting time into total waiting time
        // Accumulate each process turnaround time into total waiting time
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    // Display average waiting time and average turnaround time
    printf("\n Average Waiting Time is %f\n", (float)total_waiting_time / (float)total_number_of_processes);
    printf("\n Average Turn Around Time is %f\n\n", (float)total_turnaround_time / (float)total_number_of_processes);    
} 
