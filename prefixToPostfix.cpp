// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

bool isOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')		//	you may add operator here
		return true;
	return false;
}

int main()
{
	string prefix;
	cin >> prefix;
	
	stack <string> st;
	string t1, t2;
	
	int l = prefix.length();
	for (int i = l - 1; i >= 0; i--)
	{
		if (isOperator(prefix[i]))
		{
			t1 = st.top();		st.pop();
			t2 = st.top();		st.pop();
			t2 += prefix[i];
			st.push(t1 + t2);
		}
		else
		{
			t1 = "";
			t1 += prefix[i];
			st.push(t1);
		}
	}
	
	string postfix = st.top();		st.pop();
	cout << postfix << endl;
}
