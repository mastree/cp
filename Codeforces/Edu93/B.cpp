#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int q;
int n;
string s;

void solve(){
    cin >> s;
    n = s.size();
    int ans = 0;
    vector<int> v;
    int cur = 0;
    char bef = '0';
    for (auto x : s){
        if (x == bef){
            cur++;
        } else{
            if (bef == '1') v.pb(cur);
            cur = 1;
            bef = x;
        }
    }
    if (bef == '1') v.pb(cur);
    sort(v.begin(), v.end(), greater<int>());
    int len = v.size();
    for (int i=0;i<len;i++){
        if (i & 1 ^ 1) ans += v[i];
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}