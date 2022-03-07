#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
ll n, a, b;

void solve(){
    cin >> n >> a >> b;
    if (b == 1){
        cout << "Yes" << el;
        return;
    }
    if (a == 1){
        if (n % b == 1){
            cout << "Yes" << el;
        } else{
            cout << "No" << el;
        }
        return;
    }
    ll cur = 1;
    while (cur < n && (n - cur) % b != 0){
        cur *= a;
    }
    if (cur <= n && (n - cur) % b == 0){
        cout << "Yes" << el;
    } else{
        cout << "No" << el;
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