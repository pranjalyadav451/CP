#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define Bs binary_search
#define In insert
#define Mp make_pair
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second

const int mx1 = 55;
const int mx2 = 105;
const int mx3 = 1505;
const int mx4 = 10005;
const int mx5 = 200005;
const int mx6 = 1000005;

typedef vector<int> Vi;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vi> VVi;
typedef pair<int, int> Pii;
typedef pair<DD, DD> Pdd;
typedef vector<Pii> Vpi;
typedef vector<Pdd> Vpd;
typedef queue<int> Qi;
typedef stack<int> Si;
typedef deque<int> Di;

int _toggle(int N, int pos) {return N = N ^ (1 << pos);}
int _set(int N, int pos) {return N = N | (1 << pos);}
int _reset(int N, int pos) {return N = N & ~(1 << pos);}
bool _check(int N, int pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///******************************************************///

string s, a, b, c;
char c1, c2, c3;
int n;
Vi d, ans;
bool vis[15];

int fnd(char c, Vi v)
{
	for (int i = 0; i < s.size(); i++) {
		if (c == s[i]) {
			return v[i];
		}
	}
}

bool check()
{
	LL A = 0, B = 0, C = 0;
	for (int i = 0; i < a.size(); i++) {
		A *= 10;
		A += fnd(a[i], d);
	}
	for (int i = 0; i < b.size(); i++) {
		B *= 10;
		B += fnd(b[i], d);
	}
	for (int i = 0; i < c.size(); i++) {
		C *= 10;
		C += fnd(c[i], d);
	}
	if (A + B == C) {
		return 1;
	}
	return 0;
}

void call(int id)
{
	if (id == n) {
		if (check()) {
			ans = d;
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (!vis[i]) {
			if (i == 0 && (s[id] == c1 || s[id] == c2 || s[id] == c3)) {
				continue;
			}
			vis[i] = 1;
			d.Pb(i);
			call(id + 1);
			d.Bp();
			vis[i] = 0;
		}
	}
}

void solve()
{
	cin >> a >> b >> c;
	c1 = a[0], c2 = b[0], c3 = c[0];
	set<char> st;
	for (int i = 0; i < a.size(); i++) {
		st.In(a[i]);
	}
	for (int i = 0; i < b.size(); i++) {
		st.In(b[i]);
	}
	for (int i = 0; i < c.size(); i++) {
		st.In(c[i]);
	}
	if (st.size() > 10) {
		cout << "UNSOLVABLE" << '\n';
		return;
	}
	while (!st.empty()) {
		s.Pb(*st.begin());
		st.erase(st.begin());
	}
	n = s.size();
	call(0);
	if (ans.size() == 0) {
		cout << "UNSOLVABLE" << '\n';
		return;
	}
	LL A = 0, B = 0, C = 0;
	for (int i = 0; i < a.size(); i++) {
		A *= 10;
		A += fnd(a[i], ans);
	}
	for (int i = 0; i < b.size(); i++) {
		B *= 10;
		B += fnd(b[i], ans);
	}
	for (int i = 0; i < c.size(); i++) {
		C *= 10;
		C += fnd(c[i], ans);
	}
	cout << A << '\n' << B << '\n' << C << '\n';
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fast;
	int tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}
