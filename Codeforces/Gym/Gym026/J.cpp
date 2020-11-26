#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string ans;
string s;

string to_lower(string s){
    for (auto& x : s){
        if ('A' <= x && x <= 'Z'){
            x = char((x - 'A') + 'a');
        }
    }
    return s;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string temp;
    while (getline(cin, temp)){
        for (auto x : temp){
            s.pb(x);
        }
    }
    string cur;
    for (auto x : s){
        if (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z') || x == '-'){
            cur.pb(x);
        } else{
            if (cur == "E-N-D") break;
            if (ans.size() < cur.size()) ans = cur;
            cur = "";
        }
    }
    cout << to_lower(ans) << el;

    return 0;
}