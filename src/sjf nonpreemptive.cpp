#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n];
    bool completed[n];

    for(int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "Process " << i+1 << " Arrival Time: ";
        cin >> at[i];

        cout << "Process " << i+1 << " Burst Time: ";
        cin >> bt[i];

        completed[i] = false;
    }

    int currentTime = 0;
    int completedCount = 0;

    while(completedCount < n)
    {
        int idx = -1;
        int minBT = 100000;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= currentTime && completed[i] == false)
            {
                if(bt[i] < minBT)
                {
                    minBT = bt[i];
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            currentTime += bt[idx];
            ct[idx] = currentTime;

            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            completed[idx] = true;
            completedCount++;
        }
        else
        {
            currentTime++;
        }
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
