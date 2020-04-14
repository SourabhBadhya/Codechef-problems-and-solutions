#include <bits/stdc++.h>
#define ll long long int
using namespace std;
//Function to calculate the modular inverse of a 
//Read this link for better understanding - 
//https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
ll modInverse(ll a,ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
       
    return x; 
} 
//For all possible 16 combinations of operands the result of OR operation is being computed by this function 
//Here 0 is '0', 1 is '1', '2' is 'a' and '3' is 'A'
int orop(int a,int b) {
    if (a == 0 && b == 0) {
        return(0);
    } else if (a == 0 && b == 1) {
        return(1);
    } else if (a == 0 && b == 2) {
        return(2);
    } else if (a == 0 && b == 3) {
        return(3);
    } else if (a == 1 && b == 0) {
        return(1);
    } else if (a == 1 && b == 1) {
        return(1);
    } else if (a == 1 && b == 2) {
        return(1);
    } else if (a == 1 && b == 3) {
        return(1);
    } else if (a == 2 && b == 0) {
        return(2);
    } else if (a == 2 && b == 1) {
        return(1);
    } else if (a == 2 && b == 2) {
        return(2);
    } else if (a == 2 && b == 3) {
        return(1);
    } else if (a == 3 && b == 0) {
        return(3);
    } else if (a == 3 && b == 1) {
        return(1);
    } else if (a == 3 && b == 2) {
        return(1);
    } else if (a == 3 && b == 3) {
        return(3);
    }
}
//For all possible 16 combinations of operands the result of AND operation is being computed by this function
//Here 0 is '0', 1 is '1', '2' is 'a' and '3' is 'A'
int andop(int a,int b) {
    if (a == 0 && b == 0) {
        return(0);
    } else if (a == 0 && b == 1) {
        return(0);
    } else if (a == 0 && b == 2) {
        return(0);
    } else if (a == 0 && b == 3) {
        return(0);
    } else if (a == 1 && b == 0) {
        return(0);
    } else if (a == 1 && b == 1) {
        return(1);
    } else if (a == 1 && b == 2) {
        return(2);
    } else if (a == 1 && b == 3) {
        return(3);
    } else if (a == 2 && b == 0) {
        return(0);
    } else if (a == 2 && b == 1) {
        return(2);
    } else if (a == 2 && b == 2) {
        return(2);
    } else if (a == 2 && b == 3) {
        return(0);
    } else if (a == 3 && b == 0) {
        return(0);
    } else if (a == 3 && b == 1) {
        return(3);
    } else if (a == 3 && b == 2) {
        return(0);
    } else if (a == 3 && b == 3) {
        return(3);
    }
}
//For all possible 16 combinations of operands the result of XOR operation is being computed by this function
//Here 0 is '0', 1 is '1', '2' is 'a' and '3' is 'A'
int xorop(int a,int b) {
    if (a == 0 && b == 0) {
        return(0);
    } else if (a == 0 && b == 1) {
        return(1);
    } else if (a == 0 && b == 2) {
        return(2);
    } else if (a == 0 && b == 3) {
        return(3);
    } else if (a == 1 && b == 0) {
        return(1);
    } else if (a == 1 && b == 1) {
        return(0);
    } else if (a == 1 && b == 2) {
        return(3);
    } else if (a == 1 && b == 3) {
        return(2);
    } else if (a == 2 && b == 0) {
        return(2);
    } else if (a == 2 && b == 1) {
        return(3);
    } else if (a == 2 && b == 2) {
        return(0);
    } else if (a == 2 && b == 3) {
        return(1);
    } else if (a == 3 && b == 0) {
        return(3);
    } else if (a == 3 && b == 1) {
        return(2);
    } else if (a == 3 && b == 2) {
        return(1);
    } else if (a == 3 && b == 3) {
        return(0);
    }
}
int main() {
	// your code goes here
	//mod value to be used
	int mod = 998244353;
	int t;
	//Input number of test cases
	cin >> t;
	while(t--) {
	    //Input expression string
	    string s;
	    cin >> s;
	    //Stack is used to store the current character of the expression
	    stack<char> st;
	    //Stack of vectors which contains the current result of the operations performed
	    stack<vector<ll>> computes;
	    //Number of operands required to compute inverse of q.
	    int operands = 0;
	    for (int i = 0;i < s.length();i++) {
	        //Check if current character is '(',if yes then push it onto 'st' stack.
	        //Else if current character is ')', till we encounter '(' pop the stack as well as identify 
	        //the operation that needs to performed. Take two results from the computes stack and perform 
	        //operation on them according to the operation encountered.
	        //Else if current character is '#' then push a 4-sized vector with value 1 into the computes stack
	        //as well as the operand '#' into 'st' stack.
	        //Else if current character is '&','|' or '^' then push the character onto the 'st' stack.
	        if (s[i] == '(') {
	            st.push('(');
	        } else if (s[i] == ')') {
	            //Initialise two vectors.
	            vector<ll> res1,res2;
	            //Variable to store the operation to be performed.
	            char operation;
	            //Keep popping till '(' is encountered and if stack contains any operation symbol 
	            //then store into variable.
	            while(st.top() != '(' && st.size() > 0) {
	                if (st.top() == '&' || st.top() == '|' ||  st.top() == '^') {
	                    operation = st.top();
	                    st.pop();
	                } else {
	                    st.pop();
	                }
	            }
	            //Pop the '(' symbol
	            if (st.size() > 0) {
	                st.pop();
	            }
	            //Retrieve two 4-sized vectors from computes stack and pop both of them.
	            if (computes.size() > 0) {
	                res1 = computes.top();
	                computes.pop();
	            }
	            if (computes.size() > 0) {
	                res2 = computes.top();
	                computes.pop();
	            }
	            //Initialise a result variable.
	            vector<ll> res3(4,0);
	            //If operation is '&'
	            //Else if operation is '|'
	            //Else if operation is '^'
	            if (operation == '&') {
	                for (int j = 0;j < 4;j++) {
	                    for (int k = 0;k < 4;k++) {
	                        //For all the 16 combination do AND operation.
	                        int res = andop(j,k);
	                        //Based on the past computation a past frequency of 0,1,a,A is being used to 
	                        //calculate the present frequency of 0,1,a,A.
	                        res3[res] = (res3[res] + (res1[j] * res2[k]) % mod) % mod;
	                    }
	                }
	                //Push the current result into computes stack.
	                computes.push(res3);
	            } else if (operation == '|') {
	                for (int j = 0;j < 4;j++) {
	                    for (int k = 0;k < 4;k++) {
	                        //For all the 16 combination do OR operation.
	                        int res = orop(j,k);
	                        //Based on the past computation a past frequency of 0,1,a,A is being used to 
	                        //calculate the present frequency of 0,1,a,A.
	                        res3[res] = (res3[res] + (res1[j] * res2[k]) % mod) % mod;
	                    }
	                }
	                //Push the current result into computes stack.
	                computes.push(res3);
	            } else if (operation == '^') {
	                for (int j = 0;j < 4;j++) {
	                    for (int k = 0;k < 4;k++) {
	                        //For all the 16 combination do XOR operation.
	                        int res = xorop(j,k);
	                        //Based on the past computation a past frequency of 0,1,a,A is being used to 
	                        //calculate the present frequency of 0,1,a,A.
	                        res3[res] = (res3[res] + (res1[j] * res2[k]) % mod) % mod;
	                    }
	                }
	                //Push the current result into computes stack.
	                computes.push(res3);
	            }
	        } else if (s[i] == '#') {
	            vector<ll> res(4,1);
	            computes.push(res);
	            st.push(s[i]);
	            operands++;
	        } else {
	            st.push(s[i]);
	        }
	    }
	    //After the expression is evaluated, only one 4-sized result vector remains.
	    //This vector has the information of 0,1,a,A.
	    vector<ll> final = computes.top();
	    //Variable to compute q.
	    ll denom = 1;
	    //Based on the number of operands the value of q is opwer(4,operands).
	    for (int i = 0;i < operands;i++) {
	        denom = (denom * 4) % mod;
	    }
	    //Compute inverse of q.
	    ll inverseofq = modInverse(denom,mod);
	    //Multiple every value of result vector with inverse of q.
	    for (int i = 0;i < 4;i++) {
	        final[i] = (final[i] * inverseofq) % mod;
	    }
	    //Output the result vector.
	    for (int i = 0;i < 4;i++) {
	        cout << final[i] << " ";
	    }
	    cout << "\n";
	}
	return 0;
}

