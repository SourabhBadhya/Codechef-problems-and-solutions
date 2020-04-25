#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int k,n;
	    cin >> n >> k;
	    vector<ll> nums(n);
	    vector<ll> visited(n,0);
	    for (int i = 0;i < n;i++) {
	        cin >> nums[i];
	    }
	    for (int i = 0;i < n;i++) {
	        int index = i;
	        if (visited[index] == 0) {
	            vector<ll> u;
	            u.push_back(nums[index]);
	            visited[index] = 1;
	            while(index + k < n) {
	                u.push_back(nums[index + k]);
	                visited[index + k] = 1;
	                index += k;
	            }
	            sort(u.begin(),u.end());
	            index = i;
	            if (u.size() > 0) {
	                nums[index] = u[0];
	            }
	            int count = 1;
	            while(index + k < n && count < u.size()) {
	                nums[index + k] = u[count];
	                count++;
	                index += k;
	            }
	        }
	    }
	    ll prev = nums[0],flag = 0;
	    for (int i = 1;i < n;i++) {
	        if (nums[i] >= prev) {
	            prev = nums[i];
	        } else {
	            flag = 1;
	            break;
	        }
	    }
	    if (flag == 0) {
	        cout << "yes\n";
	    } else {
	        cout << "no\n";
	    }
	}
	return 0;
}
