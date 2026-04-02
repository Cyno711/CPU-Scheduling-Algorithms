#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], rt[n], ct[n], wt[n], tat[n];

    for(int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "Process " << i+1 << " Arrival Time: ";
        cin >> at[i];

        cout << "Process " << i+1 << " Burst Time: ";
        cin >> bt[i];

        rt[i] = bt[i];  
    }

    int completed = 0;
    int currentTime = 0;

    while(completed < n)
    {
        int idx = -1;
        int minRT = 100000;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= currentTime && rt[i] > 0)
            {
                if(rt[i] < minRT)
                {
                    minRT = rt[i];
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            rt[idx]--;

            currentTime++;

            if(rt[idx] == 0)
            {
                ct[idx] = currentTime;

                tat[idx] = ct[idx] - at[idx];

                wt[idx] = tat[idx] - bt[idx];

                completed++;
            }
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
