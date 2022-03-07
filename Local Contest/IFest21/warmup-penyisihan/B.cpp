#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
int n;
string s;

void solve(){
    getline(cin, s);
    n = s.size();
    stack<int> st;
    vector<bool> skip(n, 0);
    for (int i=0;i<n;i++){
        if (s[i] == '('){
            st.push(i);
        }
        if (s[i] == ')' && !st.empty()){
            int ss = st.top();
            st.pop();
            for (int j=ss;j<=i;j++){
                skip[j] = 1;
            }
        }
    }
    for (int i=0;i<n;i++){
        if (skip[i]) continue;
        if ('a' <= s[i] && s[i] <= 'z'){
            int cur = s[i] - 'a';
            s[i] = char('a' + (25 - cur));
        }
        
        if ('A' <= s[i] && s[i] <= 'Z'){
            int cur = s[i] - 'A';
            s[i] = char('A' + (25 - cur));
        }
    }
    cout << s << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    cin.ignore();
    while (q--){
        solve();
    }

    return 0;
}