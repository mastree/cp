#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;

int n;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    ll cur = 0;
    for (int i=1;i<=n;i++){
        if ((n - i) & 1) cur -= ar[i];
        else cur += ar[i];
    }
    int q;
    cin >> q;
    while (q--){
        int l, r;
        ll a;
        cin >> l >> r >> a;
        if ((r - l + 1) & 1){
            if ((n - r) & 1){
                cur -= a;
            } else{
                cur += a;
            }
        } 
        cout << cur << el;
    }

    return 0;
}