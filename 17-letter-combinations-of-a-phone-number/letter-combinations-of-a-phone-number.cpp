class Solution {

    vector<string> result;
    vector<string > mp ={ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:

    void solve(string &digits,int idx,string &curr){

        if(idx==digits.length()){
            result.push_back(curr);
            return ;

        }

        int num= digits[idx]-'0';
        string alpha= mp[num];

        for(char c: alpha){

            curr.push_back(c);
            solve(digits,idx+1,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        string curr="";

        solve(digits,0,curr);
        return result;
        
    }
};




























































// class Solution {
// public:
//     vector<string> result;
//     vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

//     void solve(string &digits, int idx, string &curr) {
//         if (idx == digits.length()) {
//             result.push_back(curr);
//             return;
//         }
//         int num = digits[idx] - '0';
//         string alpha = mp[num];

//         for (char c : alpha) {
//             curr.push_back(c);
//             solve(digits, idx + 1, curr);
//             curr.pop_back();
//         }
//     }
//     vector<string> letterCombinations(string digits) {
//         if (digits.empty()) return {};
//         string curr = "";
//         solve(digits, 0, curr);
//         return result;
//     }
// };
