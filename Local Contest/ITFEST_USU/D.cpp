#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e2 + 10;

int n;
string s[N];

string low(string temp){
    for (int i=0;i<temp.length();i++){
        if (temp[i] >= 'A' && temp[i] <= 'Z'){
            temp[i] = char((int)temp[i] - (int)('A' - 'a')); 
        }
    }
    return temp;
}

int main () {
    cin >> n;
    cin.ignore();
    int id = 1;
    while(getline(cin, s[id])){
        id++;
    }
    
    for (int i=1;i<id;i++){
        stringstream ss(s[i]);
        string temp;
        vector <string> ans;
        while (ss >> temp){
            ans.pb(temp);
        }
        int len = ans.size();
        for (int i=0;i<len;i++){
            if (i == 0){
                cout << ans[i] << " ";
                continue;
            }
            if (low(ans[i]) != low(ans[i-1])) cout << ans[i] << " ";
        }   
        cout << el; 
    }

    return 0;
}