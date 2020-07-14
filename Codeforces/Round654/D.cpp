#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e2 + 10;
const int INF = 1e9;

int q;
int n, k;
int ans[N][N];

int calc(){
    int ret = 0;
    int mn = INF, mx = -INF;

    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=1;j<=n;j++){
            cur += ans[i][j];
        }
        mn = min(mn, cur);
        mx = max(mx, cur);
    }
    // cout << mn << " " << mx << el;
    ret += mx - mn;
    mn = INF, mx = -INF;

    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=1;j<=n;j++){
            cur += ans[j][i];
        }
        mn = min(mn, cur);
        mx = max(mx, cur);
    }
    // cout << mn << " " << mx << el;
    ret += mx - mn;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                ans[i][j] = 0;
            }
        }
        // set<pii> setdah; // sisa, col
        // for (int i=1;i<=n;i++){
        //     setdah.insert(mp(0, i));
        // }
        for (int i=1;i<=k;i++){
            int lup = (i - 1) / n;
            int r = i % n;
            if (r == 0) r += n;
            int c = r + lup;
            if (c > n) c -= n;
            ans[r][c] = 1;

            // pii temp;
            // for (auto x : setdah){
            //     if (ans[r][x.se] == 0){
            //         temp = x;
            //         break;
            //     }
            // }
            // setdah.erase(temp);
            // ans[r][temp.se] = 1;
            // temp.fi++;
            // setdah.insert(temp);
        }
        cout << calc() << el;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                cout << ans[i][j];
            }
            cout << el;
        }
    }

    return 0;
}