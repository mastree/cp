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
    ll tot = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tot += ar[i];
    }
    ll sisa = tot % n;
    cout << sisa * (n - sisa) << el;
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