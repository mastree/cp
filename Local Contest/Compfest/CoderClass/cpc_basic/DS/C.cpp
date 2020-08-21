#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

bool is_match(char a, char b){
    if (a == '(') return (b == ')');
    return (b == ']');
}

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        string s;
        cin >> s;
        stack<char> st;
        for (auto x : s){
            if (st.empty()){
                st.push(x);
                continue;
            }
            if (is_match(st.top(), x)){
                st.pop();
            } else{
                st.push(x);
            }
        }
        if (st.empty()) cout << "ya" << el;
        else cout << "tidak" << el;
    }

    return 0;
}