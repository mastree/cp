#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int q;
int n;
int ar[N];

int getsqrt(int x){
    int ret = (int)sqrt(x);
    if (ret * ret != x) ret++;
    return ret;
}
void solve(){
    vector<pii> ans;
    cin >> n;
    int cur = n;
    int sq = getsqrt(cur);
    for (int i=n;i>1;i--){
        if (i == cur) continue;
        if (i == sq){
            ans.pb(mp(cur, i));
            ans.pb(mp(cur, i));
            cur = i;
            sq = getsqrt(cur);
        } else{
            ans.pb(mp(i, cur));
        }
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }
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