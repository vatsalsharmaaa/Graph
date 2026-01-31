class Solution {
public:
  
    void topo(vector<vector<int>>& adj, vector<int>& result,
              vector<int>& indegree, vector<bool>& present) {

        queue<int> q;

        for(int i = 0; i < 26; i++){
            if(present[i] && indegree[i] == 0){
                q.push(i);
                result.push_back(i);
            }
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(auto x : adj[temp]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                    result.push_back(x);
                }
            }
        }
    }

    string findOrder(vector<string> &words) {
        int n = words.size();

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        vector<int> result;

        // mark present characters
        for(auto &w : words){
            for(char c : w)
                present[c - 'a'] = true;
        }

        for(int i = 0; i < n - 1; i++){
            string s1 = words[i];
            string s2 = words[i + 1];

            int ptr = min(s1.size(), s2.size());
            bool found = false;

            for(int j = 0; j < ptr; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    indegree[s2[j] - 'a']++;
                    found = true;
                    break;
                }
            }

            // invalid prefix case
            if(!found && s1.size() > s2.size())
                return "";
        }

        topo(adj, result, indegree, present);

        int cnt = 0;
        for(bool x : present) if(x) cnt++;

        if(result.size() != cnt) return "";

        string ans = "";
        for(int x : result)
            ans.push_back(char(x + 'a'));

        return ans;
    }
};

