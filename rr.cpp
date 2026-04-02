#include <iostream>
using namespace std;

int main()
{
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> tq;

    int pid[n], at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    bool completed[n];

    // Input process information
    for(int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "Process " << i+1 << " Arrival Time: ";
        cin >> at[i];

        cout << "Process " << i+1 << " Burst Time: ";
        cin >> bt[i];

        rt[i] = bt[i];
        completed[i] = false;
    }

    int currentTime = 0;
    int completedCount = 0;

    while(completedCount < n)
    {
        bool executed = false;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= currentTime && rt[i] > 0)
            {
                executed = true;

                if(rt[i] > tq)
                {
                    currentTime += tq;
                    rt[i] -= tq;
                }
                else
                {
                    currentTime += rt[i];
                    ct[i] = currentTime;

                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    rt[i] = 0;
                    completed[i] = true;
                    completedCount++;
                }
            }
        }

        if(executed == false)
            currentTime++;
    }

    cout << "\nProcess\tAT\tBT\tCT\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}