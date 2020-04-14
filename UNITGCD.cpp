#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	//Input number of test cases
	cin >> t;
	while(t--) {
	    //Input number of pages to be read 
	    int n;
	    cin >> n;
	    //If n is less than or equal to 3 then from 1 to n we can assign the pages on the same day.
	    //If n is greater than 3 then from 1 to 3 assign it to first day and successive 2 pages can be
	    //assigned on the next days until n.
	    //Number of days required is floor(n / 2) or (n / 2) in C++.
	    if (n <= 3) {
	        cout << 1 << "\n";
	        cout << n << " ";
	        for (int i = 1;i <= n;i++) {
	            cout << i << " ";
	        }
	        cout << "\n";
	    } else {
	        int count = n / 2;
	        cout << count << "\n";
	        cout << 3 << " ";
	        for (int i = 1;i <= 3;i++) {
	            cout << i << " ";
	        }
	        cout << "\n";
	        int i = 4;
	        while(i <= n) {
	            if (i + 1 <= n) {
	                cout << 2 << " " << i << " " << (i + 1) << "\n";
	                i += 2;
	            } else {
	                cout << 1 << " " << i << "\n";
	                i += 1;
	            }
	        }
	    }
	}
	return 0;
}
