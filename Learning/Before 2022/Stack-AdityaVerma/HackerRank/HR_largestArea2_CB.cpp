/*
This was a very good problem of use of stack and
I think I can do this problem in some other way
without using two stacks because that way the problem
would be more space efficent.
*/
/*
Update - I solved this using other technique
- I have to learn stack because I was doing silly mistakes	in the code due to lack of practice in stack.
*/



#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h)
{
	int len = h.size();
	stack<int> index;
	int height = 0;
	int currentArea = 0;
	int maxArea = 0;
	h.push_back(0);
	len = h.size();
	for (int i = 0; i < len; ++i)
	{
		if (not index.empty() and h[index.top()] > h[i])
		{
			// cout << "here for poppping " << endl;
			while (index.empty() == false and h[index.top()] > h[i])
			{
				height = h[index.top()];
				// cout << "value at the top of the stack ->" << h[index.top()] << endl;
				index.pop();
				if (index.empty())
				{
					currentArea = i * height;
				}
				else
				{
					currentArea = (i - index.top() - 1) * height;
				}
				maxArea = max(maxArea, currentArea);
			}


		}
		// if (index.empty() == true)
		// {
		// 	cout << "index is empty" << endl;
		// }


		if (index.empty() or h[i] >= h[index.top()])
		{
			index.push(i);

		}



		maxArea = max(maxArea, currentArea);
		// cout << "i_th iteration ->" << i << endl;
		// cout << "value at i ->" << h[i] << endl;
		// if (index.empty() == false) {
		// 	cout << "value at top ->" << h[index.top()] << endl;
		// 	cout << "index.top() ->" << index.top() << endl;
		// }
		// cout << "height->" << height << endl;
		// cout << "maxArea ->" << maxArea << endl;
		// cout << endl;
		// cout << endl;
	}
	// cout << index.empty() << endl;
	return maxArea;
}

int main()
{
	// ofstream fout(getenv("OUTPUT_PATH"));
	int t; cin >> t;
	while (t--)
	{	int n;
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
	}

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
