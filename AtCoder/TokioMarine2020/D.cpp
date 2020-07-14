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

const int N = (1 << 19) + 10;

int n, q;
pii ar[N];

vector<pii> va[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se; // val, weight
    }
    va[0].pb(mp(0, 0));
    int pre = min((1 << 10), n);
    for (int i=1;i<=pre;i++){
        int p = i / 2;
        pii temp = ar[i];
        for (auto x : va[p]){
            va[i].pb(x);
            va[i].pb(mp(x.fi + temp.se, x.se + temp.fi));
        }
        sort(va[i].begin(), va[i].end());
        for (int j=1;j<va[i].size();j++){
            va[i][j].se = max(va[i][j].se, va[i][j - 1].se);
        }
    }

    cin >> q;
    while (q--){
        int node, mx;
        cin >> node >> mx;
        if (node <= pre){
            int ans = 0;
            for (auto x : va[node]){
                if (x.fi <= mx) ans = max(ans, x.se);
            }
            cout << ans << el;
            continue;
        }
        vector<int> path;
        while (node > pre){
            path.pb(node);
            node >>= 1;
        }
        int len = path.size();
        vector<pii> vb; // weight, val
        vb.pb(mp(0, 0));
        for (int i=0;i<len;i++){
            vector<pii> temp;
            pii isi = ar[path[i]];
            for (auto x : vb){
                temp.pb(mp(x.fi + isi.se, x.se + isi.fi));
            }
            for (auto x : temp){
                vb.pb(x);
            }
        }
        int ans = 0;
        int valen = va[node].size();
        for (auto x : vb){
            int low = 0, high = valen - 1;
            while (low < high){
                int mid = (low + high + 1) / 2;
                if (x.fi + va[node][mid].fi <= mx){
                    low = mid;
                } else{
                    high = mid - 1;
                }
            }
            if (x.fi + va[node][low].fi <= mx) ans = max(ans, x.se + va[node][low].se);
        }
        cout << ans << el;
    }

    return 0;
}