#include <iostream>
#include <algorithm>

using namespace std;

// Structure for each process
struct Process {
    int id;         // Process ID
    int burstTime;  // Burst time
    int priority;   // Priority
    int waitingTime;
    int turnaroundTime;
};

// Function to calculate waiting time & turnaround time
void findWaitingTime(Process proc[], int n) {
    proc[0].waitingTime = 0; // First process has 0 waiting time

    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i - 1].waitingTime + proc[i - 1].burstTime;
    }
}

// Function to calculate turnaround time
void findTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaroundTime = proc[i].waitingTime + proc[i].burstTime;
    }
}

// Function to implement Priority Scheduling
void priorityScheduling(Process proc[], int n) {
    // Sort processes based on priority (lower number = higher priority)
    sort(proc, proc + n, [](Process a, Process b) {
        return a.priority < b.priority;
    });

    // Calculate waiting and turnaround times
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    // Print results
    cout << "Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << proc[i].id << "\t" << proc[i].burstTime << "\t\t"
             << proc[i].priority << "\t\t" << proc[i].waitingTime << "\t\t"
             << proc[i].turnaroundTime << endl;
    }

    // Calculate Average Waiting Time & Turnaround Time
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnaroundTime += proc[i].turnaroundTime;
    }
   
    cout << "\nAverage Waiting Time: " << totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << endl;
}

// Driver function
int main() {
    // Given burst times and priorities

    cout<<"Name: Sesha Sai Srinivas Koya\n";
    cout<<"SID: S00453667 \n";
    Process proc[] = {
        {1, 10, 3},
        {2, 1, 1},
        {3, 2, 4},
        {4, 1, 5},
        {5, 5, 2}
    };

    int n = sizeof(proc) / sizeof(proc[0]);

    priorityScheduling(proc, n);

    return 0;
}