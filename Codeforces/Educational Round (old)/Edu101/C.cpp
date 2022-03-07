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
int n, k;
int ar[N];

void solve(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int a, b;
    a = ar[1];
    b = ar[1];
    for (int i=2;i<=n - 1;i++){
        int mn = a - (k - 1);
        int mx = b + (k - 1);

        a = max(mn, ar[i]);
        b = min(mx, ar[i] + (k - 1));
        if (a > b){
            cout << "NO" << el;
            return;
        }
    }

    int mn = a - (k - 1);
    int mx = b + (k - 1);
    if (mn <= ar[n] && ar[n] <= mx){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
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