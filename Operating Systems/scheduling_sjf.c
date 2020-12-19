#include <stdio.h>
#include <stdlib.h>

// Shortest Job First Scheduling Process Structure
struct process {
        int job_num;            // Job ID
        int burst_time;         // Priority based on Burst Time, low burst_time is given higher priority
        struct process* next;   // Pointer to the next process
};
typedef struct process Process;

// Create new Process, returns a Process structure pointing to NULL
Process* new_process (int job_num, int burst_time);

// Create new Process with job_num & burst_time and inserts into Process Queue with priority based on Burst Time
void insert_process(Process** head, int job_num, int burst_time);

// Traverse through Process Queue and calculate & display average and each processes Waiting Time and Turnaround Time
void calculate_process(Process** head, int total_num_of_jobs); 

// Traverse Process Queue and free memory and its pointers
void finish_process (Process** head);

// Main Driver
int main() 
{
        // Declare input variables
        int job_num, burst_time, total_num_of_jobs; 
        
        // Initialize of Process Queue
        Process* ps; 
        
        printf("\n **** Shortest Job First Scheduling ****\n");        
          
        // Input total number of jobs         
        printf("\n Enter no of jobs: ");
        scanf("%d", &total_num_of_jobs);
        
        // If total number of jobs entered is lesser than zero, exit the program
        if (total_num_of_jobs < 1)
                return 0;       

        // Input each Process information
        for(job_num = 1; job_num <= total_num_of_jobs; job_num += 1) 
        {                
                // Input Burst Time
                printf("\n Enter Burst Time of %d Process: ", job_num);
                scanf("%d", &burst_time);
                
                // Insert process information into Process Queue
                if (job_num == 1)                               
                        ps = new_process(1, burst_time);
                
                else
                        insert_process(&ps, job_num, burst_time);
        }        
        
        // calculate & display average and each processes Waiting Time and Turnaround Time
        calculate_process(&ps, total_num_of_jobs);
        
        // Free memory allocated to the process queue, exit the program
        finish_process(&ps);        
        return 0;
}

// Create new Process, returns a Process structure pointing to NULL
Process* new_process (int job_num, int burst_time) 
{
        // Initialize new process structre 
        Process* temp = (Process*) malloc (sizeof(Process));
        
        // Store Job ID and Burst Time
        temp -> job_num = job_num;
        temp -> burst_time = burst_time;

        // Return process structure
        return temp;
}

// Create new Process with job_num & burst_time and inserts into Process Queue with priority based on Burst Time
void insert_process(Process** head, int job_num, int burst_time)
{
        // Initialize current process pointer to process queue's head (first process)
        Process* curr = *head;
        
        // Create new process with provided information from given parameters        
        Process* temp = new_process(job_num, burst_time);

        // Insert to head of process queue if new process burst time is higher than the current head (first process) burst time        
        if ((curr -> burst_time) > burst_time)
        {
                temp -> next = *head;
                *head = temp;
        }
        // Else, traverse though the Queue and insert process
        else
        {
                while ( (curr -> next != NULL) && (curr -> next -> burst_time < burst_time) ) 
                        curr = curr -> next;
                
                temp -> next = curr -> next;
                curr -> next = temp;                       
        }        
}

// Traverse through Process Queue and calculate & display average and each processes Waiting Time and Turnaround Time
void calculate_process(Process** head, int total_num_of_jobs)
{
        // Initialize current process pointer to process queue's head (first process)
        Process *curr = *head;
        
        // Initialize total & current process waiting and turnaround time
        int curr_waiting_time = 0;
        int curr_turnaround_time = 0;        
        float total_waiting_time = 0;
        float total_turnaround_time = 0;
        
        printf("\n Job\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        
        // Traverse till end of Process Queue
        while (curr != NULL)
        {
                curr_turnaround_time += curr -> burst_time;
                
                total_waiting_time += curr_waiting_time;
                total_turnaround_time += curr_turnaround_time;

                // Display Process Stucture Information with its current waiting time and turnarounf time                
                printf(" %d\t\t%d\t\t%d\t\t%d\n", curr -> job_num, curr -> burst_time,
                curr_waiting_time, curr_turnaround_time);
                
                curr_waiting_time += curr -> burst_time;
                
                curr = curr -> next;
        }
        
        // Display Average Waiting Time and Turnaround time        
        printf("\n\t\tAverage Waiting time is %f\n", total_waiting_time/total_num_of_jobs);
        printf("\t\tAverage Turnaround time is %f\n\n", total_turnaround_time/total_num_of_jobs);
        
}

// Traverse Process Queue and free memory and its pointers
void finish_process (Process** head)
{
        // Initialize current and next process pointers
        Process *curr = *head;
        Process *next;

        // Traverse till end of Process Queue        
        while (curr != NULL)
        {
                next = curr -> next;
                free(curr);
                curr = next;      
        }
        
        *head = NULL;
}

