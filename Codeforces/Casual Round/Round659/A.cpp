#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = 1e9;

int q;
int n;
string a, b;

int v[20][20]; 

void solve(){
    cin >> n;
    cin >> a >> b;
    bool ok = 1;
    for (int i=0;i<20;i++){
        for (int j=0;j<20;j++){
            v[i][j] = 0;
        }
    }
    for (int i=0;i<n;i++){
        if (a[i] > b[i]){
            ok = 0;
            break;
        }
        int dig = (a[i] - 'a'), to = (b[i] - 'a');
        if (dig < to) v[dig][to]++;
    }
    if (!ok){
        cout << -1 << el;
        return;
    }
    int ans = 0;
    for (int i=0;i<20;i++){
        int mn = INF;
        for (int j=0;j<20;j++){
            if (v[i][j]) mn = min(mn, j);
        }
        if (mn == INF) continue;
        ans ++;
        for (int j=0;j<20;j++){
            if (j != mn){
                v[mn][j] += v[i][j];
            }
        }
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