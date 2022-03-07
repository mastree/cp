#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int q;
int n;
ll h;
int ar[N];

void solve(){
    cin >> n >> h;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    ll pw = ar[n] + ar[n - 1];
    ll ans = (h / pw) * 2LL;
    h %= pw;
    if (h){
        if (h <= ar[n]) ans++;
        else ans += 2;
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