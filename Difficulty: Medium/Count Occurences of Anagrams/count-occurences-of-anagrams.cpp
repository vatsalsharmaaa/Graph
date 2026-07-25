class Solution {
public:

    bool allzero(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }

    int search(string &pat, string &txt) {
        int n = pat.size();

        vector<int> arr(26, 0);

        int i = 0;
        int j = 0;
        int result = 0;

        for (int k = 0; k < n; k++) {
            arr[pat[k] - 'a']++;
        }

        while (j < txt.size()) {

            arr[txt[j] - 'a']--;

            if (j - i + 1 < n) {
                j++;
            }

            else if (j - i + 1 == n) {

                if (allzero(arr)) {
                    result++;
                }

                arr[txt[i] - 'a']++;
                i++;
                j++;
            }
        }

        return result;
    }
};