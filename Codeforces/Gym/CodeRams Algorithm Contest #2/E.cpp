#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int POW = 18;

string num;
ll p10[POW + 1];

ll solve(string s){
    int n = s.size();
    if (n & 1){
        // cout << s << " " << p10[n] - 1 - stoll(s) << el;
        return p10[n] - 1 - stoll(s);
    }
    string a = s.substr(0, n / 2);
    string b = s.substr(n / 2, n / 2);
    if (a >= b){
        // cout << s << " " << stoll(a) - stoll(b) << el;
        return stoll(a) - stoll(b) + 1 + solve(a);
    }
    ll tam = stoll(a) + 1 + (p10[n / 2] - stoll(b));
    // cout << s << " " << tam << el;
    return tam + 1 + solve(to_string(stoll(a) + 1));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p10[0] = 1;
    for (int i=1;i<=POW;i++){
        p10[i] = p10[i - 1] * 10LL;
    }
    cin >> num;
    cout << solve(num) << el;

    return 0;
}