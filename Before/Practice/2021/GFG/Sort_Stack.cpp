#include<bits/stdc++.h>
using namespace std;

class SortedStack {
public:
	stack<int> s;
	void sort();
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
	int t;
	cin >> t;
	while (t--)
	{
		SortedStack *ss = new SortedStack();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			ss->s.push(k);
		}
		ss->sort();
		printStack(ss->s);
	}
}



void insert_in(stack<int> &s, int ele) {
	if (s.empty() or s.top() < ele) {
		s.push(ele);
	}
	else {
		int temp = s.top();
		s.pop();
		insert_in(s, ele);
		s.push(temp);
	}
}

void SortedStack :: sort() {

	if (s.empty()) {
		return;
	}

	int temp = s.top();
	s.pop();
	sort();
	insert_in(s, temp);
}