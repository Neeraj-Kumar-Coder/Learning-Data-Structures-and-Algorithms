#include <bits/stdc++.h>

using namespace std;

class Process
{
public:
    int pid;
    int bt;
    int art;
    bool finish;
};

void findWaitingTime(vector<Process> proc, int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n)
    {
        int minm = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (!proc[j].finish && (proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0)
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
        t += rt[shortest];
        rt[shortest] = 0;
        proc[shortest].finish = 1;
        complete++;
        check = false;
        finish_time = t + 1;
        wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;
        if (wt[shortest] < 0)
            wt[shortest] = 0;
    }
}

void findTurnAroundTime(vector<Process> proc, int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime(vector<Process> proc, int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n << " ms";
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n << " ms";
}

int main(void)
{
    vector<Process> proc;
    fstream file;
    file.open("/home/ani_s/Desktop/InputFile/1.csv", ios::in);
    string s;
    if (file.is_open())
    {
        getline(file, s);
        int i = 1;
        while (getline(file, s))
        {
            stringstream str(s);
            string word;
            int j = 1;
            int bt, at;
            while (getline(str, word, ';'))
            {
                int x = stoi(word);
                if (j == 1)
                    at = x - 1376314846;
                else if (j == 4)
                    bt = (float)1000 / x;
                j++;
            }
            if (bt == 0)
                continue;
            Process p;
            p.pid = i;
            p.bt = bt;
            p.art = 0;
            p.finish = 0;
            proc.push_back(p);
            i++;
        }
        cout << "No. of process scheduled are " << proc.size() << endl;
    }
    else
    {
        cout << "1";
    }
    int n = proc.size();
    findavgTime(proc, n);
    return 0;
}