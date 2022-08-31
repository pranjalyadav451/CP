// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict, string pattern);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        string tt;
        cin >> tt;

        vector<string> res = findMatchedWords(s, tt);
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

    }
}// } Driver Code Ends


/* The function returns a  vector of strings
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(vector<string> dict, string pattern) {

    int np = pattern.size();
    int match[200], each[200];
    memset(match, 0, sizeof(match));
    for (int i = 0; i < np; i++) {
        match[pattern[i]]++;
    }


    int nd = dict.size();
    vector<string>res;
    bool any = true;

    for (int i = 0; i < nd; i++) {
        memset(each, 0, sizeof(each));
        any = true;

        for (int j = 0; j < dict[i].size(); j++) {
            each[dict[i][j]]++;
        }
        for (int j = 0; j < pattern.size(); j++) {
            if (each[dict[i][j]] != match[pattern[j]] or pattern.size() != dict[i].size()) {
                any = false;
                break;
            }
        }
        if (any == true) {
            res.push_back(dict[i]);
        }

    }
    return res;
}