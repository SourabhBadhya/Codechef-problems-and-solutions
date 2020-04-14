#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	//Input number of test cases
	cin >> t;
	while(t--) {
	    //Input number of elements in array
	    int n;
	    cin >> n;
	    //Input vector
	    vector<ll> num(n);
	    for (ll i = 0;i < n;i++) {
	        cin >> num[i];
	    }
	    //flag0 indicates whether there is an existence of one '1'.
	    //flag1 is set to 1 if the distance is less than 6 feet.
	    //prev is the index of previously stored '1'
	    //rightnow is the index of currently encountered '1'.
	    int flag0 = 0,rightnow,flag1 = 0,prev;
	    for (int i = 0;i < n;i++) {
	        if (flag0 == 0 && num[i] == 1) {
	            prev = i;
	            flag0 = 1;
	        } else if (num[i] == 1) {
	            rightnow = i;
	            if (rightnow - prev >= 6) {
	                prev = rightnow;
	            } else {
	                flag1 = 1;
	                break;
	            }
	        }
	    }
	    //Output YES if there is no '1' or if flag1 is not set to 1, else output NO.
	    if(flag0 == 0) {
	        cout << "YES\n";
	    } else if (flag1 == 0) {
	        cout << "YES\n";
	    } else {
	        cout << "NO\n";
	    }
	}
	return 0;
}

