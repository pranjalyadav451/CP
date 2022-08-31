#include<bits/stdc++.h>
using namespace std;

class ReverseStack {
public:
	stack<int> s;
	void reverse();
};

void printStack(stack<int> s)
{
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");
}

int main()
{
	int t = 1;
	// cin >> t;
	while (t--)
	{
		ReverseStack *ss = new ReverseStack();
		int n = 4;
		// cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			ss->s.push(i);
		}
		cout << "Before: " << endl;
		printStack(ss->s);
		cout << "After: " << endl;
		ss->reverse();
		printStack(ss->s);
	}
}

void reverse_push(stack<int> &s, int temp) {
	if (s.empty()) {
		s.push(temp);
		return;
	}
	int ele = s.top(); s.pop();
	reverse_push(s, temp);
	s.push(ele);
}

void ReverseStack::reverse() {
	if (s.empty())
		return;

	int temp = s.top();
	s.pop();
	reverse();
	reverse_push(s, temp);
}



