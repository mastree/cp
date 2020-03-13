// C++ program to multiply two numbers represented 
// as strings. 
#include<bits/stdc++.h> 

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std; 

// Multiplies str1 and str2, and prints result. 
string multiply(string num1, string num2) 
{ 
	int len1 = num1.size(); 
	int len2 = num2.size(); 
	if (len1 == 0 || len2 == 0) 
	return "0"; 

	// will keep the result number in vector 
	// in reverse order 
	vector<int> result(len1 + len2, 0); 

	// Below two indexes are used to find positions 
	// in result. 
	int i_n1 = 0; 
	int i_n2 = 0; 
	
	// Go from right to left in num1 
	for (int i=len1-1; i>=0; i--) 
	{ 
		int carry = 0; 
		int n1 = num1[i] - '0'; 

		// To shift position to left after every 
		// multiplication of a digit in num2 
		i_n2 = 0; 
		
		// Go from right to left in num2			 
		for (int j=len2-1; j>=0; j--) 
		{ 
			// Take current digit of second number 
			int n2 = num2[j] - '0'; 

			// Multiply with current digit of first number 
			// and add result to previously stored result 
			// at current position. 
			int sum = n1*n2 + result[i_n1 + i_n2] + carry; 

			// Carry for next iteration 
			carry = sum/10; 

			// Store result 
			result[i_n1 + i_n2] = sum % 10; 

			i_n2++; 
		} 

		// store carry in next cell 
		if (carry > 0) 
			result[i_n1 + i_n2] += carry; 

		// To shift position to left after every 
		// multiplication of a digit in num1. 
		i_n1++; 
	} 

	// ignore '0's from the right 
	int i = result.size() - 1; 
	while (i>=0 && result[i] == 0) 
	i--; 

	// If all were '0's - means either both or 
	// one of num1 or num2 were '0' 
	if (i == -1) 
	return "0"; 

	// generate the result string 
	string s = ""; 
	
	while (i >= 0) 
		s += std::to_string(result[i--]); 

	return s; 
} 
  
// Function for finding sum of larger numbers 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string inttostr(ll x){
    string s="";
    ll a=abs(x);
    
    while (a){
        char c=a%10+'0';
        s.pb(c);
        a/=10;
    }

    if (x==0) return "0";
    if (x<0) s.pb('-');

    reverse(s.begin(),s.end());
    return s;
}

// Driver code 
int main() 
{ 
    for (ll a=1;a<10000;a++){
        for (ll b=1;b<10000;b++){
    

    if (a==1){
     //   cout << b/2 << el;
      //  return 0;
      continue;
    }
    else if (b==1){
     //   cout << a/2 << el;
      //  return 0;
      continue;
    }

    string str1,str2,ans;

    if (a%2==0){
        str1=inttostr(a/2);
        str2=inttostr(b);

        if((str1.at(0) == '-' || str2.at(0) == '-') && 
            (str1.at(0) != '-' || str2.at(0) != '-' )) 
            cout<<"-"; 


        if(str1.at(0) == '-' && str2.at(0)!='-') 
            { 
                str1 = str1.substr(1); 
            } 
            else if(str1.at(0) != '-' && str2.at(0) == '-') 
            { 
                str2 = str2.substr(1); 
            } 
            else if(str1.at(0) == '-' && str2.at(0) == '-') 
            { 
                str1 = str1.substr(1); 
                str2 = str2.substr(1); 
            } 
        ans= multiply(str1, str2); 
     //   return 0; 
    } else if (b%2==0){
        str1=inttostr(a);
        str2=inttostr(b/2);

        if((str1.at(0) == '-' || str2.at(0) == '-') && 
            (str1.at(0) != '-' || str2.at(0) != '-' )) 
            cout<<"-"; 


        if(str1.at(0) == '-' && str2.at(0)!='-') 
            { 
                str1 = str1.substr(1); 
            } 
            else if(str1.at(0) != '-' && str2.at(0) == '-') 
            { 
                str2 = str2.substr(1); 
            } 
            else if(str1.at(0) == '-' && str2.at(0) == '-') 
            { 
                str1 = str1.substr(1); 
                str2 = str2.substr(1); 
            } 
        ans=multiply(str1, str2); 
     //   return 0; 
    } else {
        str1=inttostr(a/2);
        str2=inttostr(b);

        if((str1.at(0) == '-' || str2.at(0) == '-') && 
            (str1.at(0) != '-' || str2.at(0) != '-' )) 
            cout<<"-"; 


        if(str1.at(0) == '-' && str2.at(0)!='-') 
            { 
                str1 = str1.substr(1); 
            } 
            else if(str1.at(0) != '-' && str2.at(0) == '-') 
            { 
                str2 = str2.substr(1); 
            } 
            else if(str1.at(0) == '-' && str2.at(0) == '-') 
            { 
                str1 = str1.substr(1); 
                str2 = str2.substr(1); 
            } 
        ans= findSum(multiply(str1, str2),inttostr(b/2)); 
      //  return 0; 

    }

    if (ans!=inttostr(a*b/2)){
        cout << a << " " << b << el;
        return 0;
    }
    }}
	
	return 0; 
} 
