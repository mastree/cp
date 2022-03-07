#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int ar[3][3];
vector<pii> pos;

int calc(){
    int mn = INF, mx = 0;
    int ret = 0;
    for (int i=0;i<3;i++){
        int totr = 0;
        // int totc = 0;
        for (int j=0;j<3;j++){
            totr += ar[i][j];
            // totc += ar[j][i];
        }
        mn = min(mn, totr);
        mx = max(mx, totr);
        // mn = min(mn, totc);
        // mx = max(mx, totc);
    }
    ret = max(ret, mx - mn);
    mn = INF, mx = 0;
    for (int i=0;i<3;i++){
        // int totr = 0;
        int totc = 0;
        for (int j=0;j<3;j++){
            // totr += ar[i][j];
            totc += ar[j][i];
        }
        // mn = min(mn, totr);
        // mx = max(mx, totr);
        mn = min(mn, totc);
        mx = max(mx, totc);
    }
    ret = max(ret, mx - mn);
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<int> setdah;
    for (int i=1;i<=9;i++){
        setdah.insert(i);
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cin >> ar[i][j];
            if (ar[i][j] == 0){
                pos.pb(mp(i, j));
            } else{
                setdah.erase(ar[i][j]);
            }
        }
    }
    vector<int> perm;
    for (auto& x : setdah) perm.pb(x);
    int ans = 0;
    int len = pos.size();
    do {
        for (int i=0;i<len;i++){
            ar[pos[i].fi][pos[i].se] = perm[i];
        }
        ans = max(ans, calc());
        for (int i=0;i<len;i++){
            ar[pos[i].fi][pos[i].se] = 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << el;

    return 0;
}