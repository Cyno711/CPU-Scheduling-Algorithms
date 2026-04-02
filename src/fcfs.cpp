#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], wt[n], tat[n], pid[n];

    cout << "Enter Arrival Time and Burst Time:\n";
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Process " << i+1 << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << i+1 << " Burst Time: ";
        cin >> bt[i];
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    wt[0] = 0;

    for(int i = 1; i < n; i++) {
        wt[i] = (wt[i-1] + bt[i-1]) - (at[i] - at[i-1]);

        if(wt[i] < 0)
            wt[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}
