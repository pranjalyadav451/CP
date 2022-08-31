//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {

    vector<vector<int>> graph;
    vector<char> color;
    string top;

    void build_graph(string dict[], int N) {
        graph.assign(26, vector<int>());
        color.assign(26, 0);


        for (int i = 0; i < N - 1; i++) {
            string first = dict[i], second = dict[i + 1];
            int n = first.size(), m = second.size();
            for (int j = 0; j < min(n, m); j++) {
                if (first[j] != second[j]) {
                    graph[first[j] - 'a'].push_back(second[j] - 'a');
                    break;
                }
            }
        }
    }

    bool is_cyclic(int node) {
        if (color[node] == 2) return false;
        color[node] = 1;

        bool ans = false;
        for (auto a : graph[node]) {
            if (color[a] == 1) return true;
            if (color[a] == 0) {
                ans |= is_cyclic(a);
            }
            if (ans) return ans;
        }
        color[node] = 2;
        return ans;
    }

    void topological(int node) {
        if (color[node]) return;
        color[node] = true;

        for (auto a : graph[node]) {
            if (not color[a])
                topological(a);
        }
        top.push_back(node + 'a');
    }



public:
    string findOrder(string dict[], int N, int K) {
        build_graph(dict, N);


        bool ans = false;

        color.assign(26, 0);
        for (int i = 0; i < 26; i++) {
            if (color[i] == 0) ans |= is_cyclic(i);
            if (ans) return "";
        }

        color.assign(26, 0);
        for (int i = 0; i < 26; i++) {
            if (graph[i].size() and color[i] == 0)topological(i);
        }
        reverse(top.begin(), top.end());
        return top;
    }
};



//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //  cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if (f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends