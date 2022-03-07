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
const int INF = 1e9 + 10;

int q;
int n;

void solve(){
    cin >> n;
    vector<pair<pii, int>> vec;
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        vec.pb(mp(mp(a, b), i));
    }
    sort(vec.begin(), vec.end());
    vector<pii> wait;

    pii mn = mp(INF, -1);
    int bef = -1;

    vector<int> ans(n + 1, -1);
    for (auto x : vec){
        if (bef != x.fi.fi){
            for (auto y : wait){
                mn = min(mn, y);
            }
            wait.clear();
        } 
        bef = x.fi.fi;
        wait.pb(mp(x.fi.se, x.se));
        if (mn.fi < x.fi.se){
            ans[x.se] = mn.se;
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;
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