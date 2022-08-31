/*
This was a very good problem of use of stack and
I think I can do this problem in some other way
without using two stacks because that way the problem
would be more space efficent.
*/




#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h)
{
	stack<int>p_stack, h_stack;
	h.push_back(0);//increasing the size of the vector
	int len = h.size();
	int curr_area = 0, max_area = 0;
	int last_width = INT_MAX, height = 0;
	for (int i = 0; i < len; i++)
	{
		last_width = INT_MAX;
		while (h_stack.empty() == false && h_stack.top() > h[i])
		{

			last_width = p_stack.top();
			height = h_stack.top();
			curr_area = (i - p_stack.top()) * height;
			h_stack.pop();
			p_stack.pop();
			max_area = max(curr_area, max_area);

		}

		if (h_stack.empty() == true || h[i] > h_stack.top())
		{
			h_stack.push(h[i]);
			p_stack.push(min(last_width, i));
		}
		// cout << "the iteration" << "->" << i << endl;
		// cout << "inside this loop" << endl;
		// cout << "p.top()->" << p_stack.top() << endl;
		// cout << "h.top()->" << h_stack.top() << endl;
		// cout << "max_area->" << max_area << endl;
		// cout << "curr_area->" << curr_area << endl;
		// cout << "--------------------------------" << endl;


	}
	return max_area;
}

int main()
{
	// ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string h_temp_temp;
	getline(cin, h_temp_temp);

	vector<string> h_temp = split_string(h_temp_temp);

	vector<int> h(n);

	for (int i = 0; i < n; i++) {
		int h_item = stoi(h_temp[i]);

		h[i] = h_item;
	}

	long result = largestRectangle(h);

	cout << result << "\n";

	// fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
