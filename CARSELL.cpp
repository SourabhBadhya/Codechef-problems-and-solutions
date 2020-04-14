#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	ll t;
	//Number of test cases
	cin >> t;
	ll mod = 1000 * 1000 * 1000 + 7;
	while(t--) {
	    //Input number of years
	    ll n;
	    cin >> n;
	    //Price of cars
	    vector<ll> num(n);
	    for (ll i = 0;i < n;i++) {
	        cin >> num[i];
	    }
	    //Sort the prices in descending order (greater<ll>() is a standard function in STL 
	    //which sorts in descending order) 
	    sort(num.begin(),num.end(),greater<ll>());
	    //Maximum profit variable
	    ll sum = 0;
	    //Here, i represents number of years. The obvious way to maximise the price is take the 
	    //largest price first and then add it to the profilt variable
	    for (ll i = 0;i < n;i++) {
	        sum = (sum + max((ll)0,num[i] - i)) % mod;
	    }
	    //Output profit
	    cout << sum << "\n";
	}
	return 0;
}