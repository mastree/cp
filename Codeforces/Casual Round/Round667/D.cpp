#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int N = 20;

int q;

string string128(ld x){
    string ret = to_string(x);
    int cnt = 0;
    for (int i=0;i<ret.size();i++){
        if (ret[i] == '.'){
            cnt = ret.size() - i;
        }
    }
    while (cnt--) ret.pop_back();
    if (ret.empty()) ret.pb('0');
    return ret;
}
int eval(string const& s){
    int ret = 0;
    for (auto x : s){
        ret += x - '0';
    }
    return ret;
}

int getlen(ld x){
    return (int)string128(x).size();
}
ld calc(ld n, int mx){
    int len = getlen(n);
    ld ret = -1;
    for (int i=1;i<=len;i++){
        ld cur = n;
        for (int j=0;j<i;j++){
            cur /= 10;
            cur = floor(cur);
        }
        cur++;
        for (int j=0;j<i;j++){
            cur *= 10;
        }
        if (eval(string128(cur)) <= mx){
            ret = cur - n;
            break;
        }
    }
    return ret;
}

void solve(){
    int mx;
    ld n; 
    {
        ll temp;
        cin >> temp >> mx;
        n = temp;
    }
    if (eval(string128(n)) <= mx){
        cout << 0 << el;
        return;
    }
    cout << string128(calc(n, mx)) << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}