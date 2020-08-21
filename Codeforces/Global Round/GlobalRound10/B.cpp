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
const ll INF = 1e18;

int q;
int n;
ll k;
ll ar[N];

void solve(){
    cin >> n >> k;
    ll mn = INF, mx = -INF;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mx = max(mx, ar[i]);
        mn = min(mn, ar[i]);
    }
    if (k == 1){
        for (int i=1;i<=n;i++){
            cout << mx - ar[i] << " ";
        }
        cout << el;
        return;
    }
    k--;
    for (int i=1;i<=n;i++){
        ar[i] = mx - ar[i];
    }
    mx = -INF, mn = INF;
    for (int i=1;i<=n;i++){
        mx = max(mx, ar[i]);
        mn = min(mn, ar[i]);
    }
    if (k & 1){
        for (int i=1;i<=n;i++){
            ar[i] = mx - ar[i];
        }
    }
    for (int i=1;i<=n;i++){
        cout << ar[i] << " ";
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