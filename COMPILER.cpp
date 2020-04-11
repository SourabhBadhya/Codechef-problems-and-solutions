#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    //Input string
	    cin >> s;
	    //Variable to store current status of the expression
	    int sum = 0;
	    //Variable to store the length of valid prefix
	    int length = 0;
	    for (int i = 0;i < s.length();i++) {
	        //Check if current character is '<' or '>', based on it update sum variable
	        if (s[i] == '<') {
	            sum++;
	        } else {
	            sum--;
	        }
	        //If sum is less than 0, than more '>' than '<' hence expression is invalid, 
	        //else if sum is 0, then '<' and '>' are balanced.
	        if (sum < 0) {
	            break;
	        } else if (sum == 0) {
	            length = (i + 1);
	        }
	    }
	    //Output length of valid string
	    cout << length << "\n";
	}
	return 0;
}
