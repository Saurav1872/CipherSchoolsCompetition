#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int kSum(vector<int>& nums, int k) {
    int n = nums.size();
    int max_sum = 0;
    vector<int> subtract;
    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0) {
            max_sum += nums[i];
        } else {
            nums[i] = abs(nums[i]);
        }
    }
    sort(nums.begin(), nums.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> pq;
    pq.push({nums[0], 0});
    while (!pq.empty() && subtract.size() < k - 1) {
        pair<int,int> top = pq.top();
        pq.pop();
        int subt = top.first;
        int idx = top.second;
        subtract.push_back(subt);
        if (idx < n - 1) {
            pq.push({subt + nums[idx + 1], idx + 1});
            pq.push({nums[idx + 1] + (subt - nums[idx]), idx + 1});
        }
    }

    vector<int> ans;
    ans.push_back(max_sum);
    for (int subt : subtract) {
        ans.push_back(max_sum - subt);
    }
    return ans[k - 1];
}

int main() {
    cout << "Input: " << endl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    cout << "Output: " << endl;
    cout << kSum(nums, k) << endl;

    return 0;
}
