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
ll ar[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    ll ans = 0;
    ll last = 0, op = 0;
    for (int i=1;i<=n;i++){
        ll cur = 0;
        if (last > ar[i]){
            cur = last - ar[i];
        }
        if (cur >= op){
            ans += cur - op;
            op = cur;
        } else{
            op = cur;
        }
        last = ar[i] + cur;
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