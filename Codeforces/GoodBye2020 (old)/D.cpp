#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const int N = 1e5 + 10;

int q;
int n;
ll ar[N];
vector<vector<int>> adj;

void solve(){
    cin >> n;
    adj.resize(n + 1);

    vector<ll> ans;
    ll cur = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cur += ar[i];
    }
    ans.pb(cur);
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<pli> vec;
    for (int i=1;i<=n;i++){
        int temp = (int)adj[i].size() - 1;
        if (temp) vec.pb(mp(ar[i], temp));
    }
    sort(vec.begin(), vec.end(), greater<pli>());
    {
        int id = 0;
        for (int i=0;i<n - 2;i++){
            while (vec[id].se <= 0) id++;
            cur += vec[id].fi;
            vec[id].se--;
            ans.pb(cur);
        }
    }
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    adj.clear();
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