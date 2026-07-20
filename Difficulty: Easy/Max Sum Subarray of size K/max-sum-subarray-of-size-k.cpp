class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        int i = 0;
        int j = 0;
        int sum = 0;
        int maxi = INT_MIN;

        while (j < n) {
            // Current element window me add karo
            sum += arr[j];

            // Window size k se chhoti hai
            if (j - i + 1 < k) {
                j++;
            }

            // Window size exactly k hai
            else if (j - i + 1 == k) {
                maxi = max(maxi, sum);

                // Leftmost element remove karo
                sum -= arr[i];

                i++;
                j++;
            }
        }

        return maxi;
    }
};