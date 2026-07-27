// class Solution {
// public:
//     int longestSubarray(vector<int>& arr, int k) {
//         int n = arr.size();
//         int i = 0, j = 0;
//         int sum = 0;
//         int ans = 0;

//         while (j < n) {
//             sum += arr[j];

//             while (sum > k) {
//                 sum -= arr[i];
//                 i++;
//             }

//             if (sum == k) {
//                 ans = max(ans, j - i + 1);
//             }

//             j++;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> mp;

        long long sum = 0;
        int ans = 0;

        mp[0] = -1;

        for (int j = 0; j < arr.size(); j++) {
            sum += arr[j];

            if (mp.find(sum - k) != mp.end()) {
                ans = max(ans, j - mp[sum - k]);
            }

            // Store only the first occurrence for maximum length
            if (mp.find(sum) == mp.end()) {
                mp[sum] = j;
            }
        }

        return ans;
    }
};