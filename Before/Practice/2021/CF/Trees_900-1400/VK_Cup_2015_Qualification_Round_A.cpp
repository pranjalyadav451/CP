#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rep(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define deb(x) cout << #x << " : " << x << endl
#define deb2(x, y) cout << #x << " : " << x << "	" << #y << " : " << y << endl

/* =========== Links ============ */

/* =========== Solution ============ */

vector<int> linearSearch(string s, vector<pair<string, string>> &repost)
{
    vector<int> res;
    int n = repost.size();
    for (int i = 0; i < n; i++)
    {
        auto a = repost[i];
        if (a.second == s)
            res.push_back(i);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    string a, b, c;
    vector<pair<string, string>> repost;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        for (char &chr : a)
            chr = tolower(chr);
        for (char &chr : c)
            chr = tolower(chr);

        repost.push_back({a, c});
    }

    queue<string> q;
    q.push("polycarp");
    q.push("");

    string temp = "";
    vector<int> pos;

    int level = 0;
    while (q.empty() == false)
    {
        temp = q.front();
        q.pop();

        if (q.front() == "")
        {
            level++;
            q.pop();
            q.push("");
        }

        pos = linearSearch(temp, repost);

        for (int a : pos)
        {
            q.push(repost[a].first);
        }
    }

    cout << level;
}

// ============== Notes =============== //
/**
 * Runtime error on test - 5 on codeforces online judge.
 * Correct Solution on Local Machine.
*/