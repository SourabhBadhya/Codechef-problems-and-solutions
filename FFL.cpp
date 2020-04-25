#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int n,s;
	    cin >> n >> s;
	    vector<int> nums(n);
	    vector<int> type(n);
	    int min1 = INT_MAX;
	    int min0 = INT_MAX;
	    int count0 = 0,count1 = 0;
	    for (int i = 0;i < n;i++) {
	        cin >> nums[i];
	    }
	    for (int i = 0;i < n;i++) {
	        cin >> type[i];
	    }
	    for (int i = 0;i < n;i++) {
	        if (type[i] == 0) {
	            if(min0 > nums[i]) {
	                min0 = nums[i];
	            }
	            count0++;
	        } else {
	            if (min1 > nums[i]) {
	                min1 = nums[i];
	            }
	            count1++;
	        }
	    }
	    if (count1 == 0 || count0 == 0) {
	        cout << "no\n";
	    } else if ((s + min0 + min1) <= 100) {
	        cout << "yes\n";
	    } else {
	        cout << "no\n";
	    }
	}
	return 0;
}
