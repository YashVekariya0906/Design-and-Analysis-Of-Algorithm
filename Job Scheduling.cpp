#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job {
public:
    string job_id;
    int deadline;
    int profit;

    Job(string id, int d, int p) {
        job_id = id;
        deadline = d;
        profit = p;
    }
};

// Comparator to sort jobs by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

pair<vector<string>, int> job_scheduling(vector<Job> &jobs, int n) {
    // Sort jobs by descending profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find maximum deadline
    int max_deadline = 0;
    for (auto &job : jobs)
        max_deadline = max(max_deadline, job.deadline);

    // Time slots (index 1..max_deadline)
    vector<string> slots(max_deadline + 1, "-1");

    int total_profit = 0;
    vector<string> job_sequence;

    // Assign jobs to slots
    for (auto &job : jobs) {
        for (int t = job.deadline; t > 0; t--) {
            if (slots[t] == "-1") {
                slots[t] = job.job_id;
                total_profit += job.profit;
                job_sequence.push_back(job.job_id);
                break;
            }
        }
    }

    return {job_sequence, total_profit};
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    for (int i = 0; i < n; i++) {
        string job_id;
        int deadline, profit;

        cout << "Enter Job ID for job " << i + 1 << ": ";
        cin >> job_id;
        cout << "Enter deadline for job " << i + 1 << ": ";
        cin >> deadline;
        cout << "Enter profit for job " << i + 1 << ": ";
        cin >> profit;

        jobs.push_back(Job(job_id, deadline, profit));
    }

    auto result = job_scheduling(jobs, n);

    cout << "\nSelected Job Sequence: ";
    for (auto &id : result.first)
        cout << id << " ";
    cout << "\nMaximum Profit: " << result.second << endl;

    return 0;
}
