#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process_Details
{
    int pid;
    int burst_time;
    int arrival_time;
};

void get_turn_around_time(Process_Details[], int, int[], int[]);
void get_waiting_time(Process_Details[], int, int[]);
void get_average_time(Process_Details[], int);

int main(void)
{
    Process_Details proc[] = {{1, 7, 2}, {2, 4, 3}, {3, 12, 32}, {4, 7, 10}};
    int n = sizeof(proc) / sizeof(proc[0]);
    get_average_time(proc, n);
    return 0;
}

void get_turn_around_time(Process_Details process[], int n, int waiting_time[], int turnaround_time[])
{
    for (int i = 0; i < n; i++)
        turnaround_time[i] = process[i].burst_time + waiting_time[i];
}

void get_waiting_time(Process_Details process[], int n, int waiting_time[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = process[i].burst_time;
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((process[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if (check == false)
        {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;

            waiting_time[shortest] = finish_time -
                                     process[shortest].burst_time -
                                     process[shortest].arrival_time;
            if (waiting_time[shortest] < 0)
                waiting_time[shortest] = 0;
        }

        t++;
    }
}

void get_average_time(Process_Details process[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                       total_tat = 0;

    get_waiting_time(process, n, wt);

    get_turn_around_time(process, n, wt, tat);
    cout << "Processes "
         << " Burst time "
         << " Waiting time "
         << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << process[i].pid << "\t\t" << process[i].burst_time << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}