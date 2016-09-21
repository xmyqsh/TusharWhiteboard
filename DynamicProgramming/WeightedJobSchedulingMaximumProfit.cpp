/**
 * https://www.youtube.com/watch?v=cr6Ip0J9izc
 * http://www.cs.princeton.edu/courses/archive/spr05/cos423/lectures/06dynamic-programming.pdf
 * Given set of jobs with start and end interval and profit, how to maximize profit such that
 * jobs in subset do not overlap.
 */

#include "../tools/tools.h"

struct Job {
    int begin, end, profit;
    Job(int b, int e, int p) : begin(b), end(e), profit(p) {}
};

int maxProfit(const vector<Job*>& jobs) {
    vector<int> dp(jobs.size(), 0);
    for (int i = 0; i != jobs.size(); ++i) dp[i] = jobs[i]->profit;
    int maxP = dp[0];
    for (int i = 1; i != jobs.size(); ++i) {
        for (int j = 0; j != i; ++j) {
            if (jobs[j]->end > jobs[i]->begin) break;
            dp[i] = max(dp[i], jobs[i]->profit + dp[j]);
        }
        maxP = max(maxP, dp[i]);
    }
    return maxP;
}

int main() {
    vector<Job*> jobs;
    jobs.push_back(new Job(1,3,5));
    jobs.push_back(new Job(2,5,6));
    jobs.push_back(new Job(4,6,5));
    jobs.push_back(new Job(6,7,4));
    jobs.push_back(new Job(5,8,11));
    jobs.push_back(new Job(7,9,2));
    sort(jobs.begin(), jobs.end(), [](const Job* job1, const Job* job2) {
            return job1->end < job2->end;
        });
    cout << maxProfit(jobs) << endl;
    return 0;
}
