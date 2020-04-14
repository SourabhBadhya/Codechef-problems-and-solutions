#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	//Input number of test cases
	cin >> t;
	while(t--) {
	    //Input x - Number of positive divisors, k - Number of prime divisors
	    int x,k;
	    cin >> x >> k;
	    //Set of primes factors of the number 'x'
	    set<int> primes;
	    //Powers of the prime factors of the number 'x'
	    map<int,int> freq;
	    //Check for power of 2
	    while(x % 2 == 0) {
	        primes.insert(2);
	        freq[2]++;
	        x /= 2;
	    }
	    //Check for powers of 3,5,7...till square root of 'x' (Prime factorisation method)
	    for (int i = 3;i <= sqrt(x);i += 2) {
	        while(x % i == 0) {
	            primes.insert(i);
	            freq[i]++;
	            x /= i;
	        }
	    }
	    //Check if there is something left
	    if (x > 2) {
	        primes.insert(x);
	        freq[x]++;
	    }
	    //sum variable is used to store all the sum of powers
	    int sum = 0;
	    //Add all the powers of the prime factors 
	    for (auto i = primes.begin();i != primes.end();i++) {
	        sum += (freq[*i]);
	    }
	    //Check if sum is greater or equal to k. If yes, then 1 else 0
	    if (sum >= k) {
	        cout << 1 << "\n";
	    } else {
	        cout << 0 << "\n";
	    }
	}
	return 0;
}
