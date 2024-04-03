#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Process {
    string name;
    int arrival_time, burst_time, waiting_time, turnaround_time;
    bool isExecuted = false;
};

// to make it more simpler to understand, i created this function to return true or false
bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrival_time < p2.arrival_time;
}

void SJF(vector<Process>& processes) {
    
    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;

    while (true) {
        int shortestJobIndex = -1;
        int shortestJobBurst = INT_MAX;

        bool allProcessesExecuted = true;

        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].isExecuted && processes[i].arrival_time <= currentTime) {
                allProcessesExecuted = false;
                if (processes[i].burst_time < shortestJobBurst) {
                    shortestJobBurst = processes[i].burst_time;
                    shortestJobIndex = i;
                }
            }
        }

        if (allProcessesExecuted)
            break;

        if (shortestJobIndex != -1) {
            processes[shortestJobIndex].waiting_time = currentTime - processes[shortestJobIndex].arrival_time;
            processes[shortestJobIndex].turnaround_time = processes[shortestJobIndex].waiting_time + processes[shortestJobIndex].burst_time;
            currentTime += processes[shortestJobIndex].burst_time;
            processes[shortestJobIndex].isExecuted = true;
        } else {
            currentTime++;
        }
    }

    int total_waiting_time = 0, total_turnaround_time = 0;
    for (size_t i = 0; i < processes.size(); i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        cout << "Process " << processes[i].name << " - Waiting Time: "
                  << processes[i].waiting_time << " - Turnaround Time: "
                  << processes[i].turnaround_time << endl;
    }

    double avg_waiting_time = static_cast<double>(total_waiting_time) / processes.size();
    double avg_turnaround_time = static_cast<double>(total_turnaround_time) / processes.size();
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter details for process " << i + 1 << endl;
        cout << "Enter name: ";
        cin >> processes[i].name;
        cout << "Enter arrival time: ";
        cin >> processes[i].arrival_time;
        cout << "Enter burst time: ";
        cin >> processes[i].burst_time;
    }

    SJF(processes);

    return 0;
}
