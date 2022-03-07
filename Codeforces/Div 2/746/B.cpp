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

int q;
int n, x;
int ar[N], tar[N];

void solve(){
    cin >> n >> x;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tar[i] = ar[i];
    }
    sort(tar + 1, tar + n + 1);
    bool bisa = 1;
    int l = n - x + 1;
    int r = x;
    for (int i=l;i<=r;i++){
        if (ar[i] != tar[i]){
            bisa = 0;
            break;
        }
    }
    if (bisa) cout << "YES" << el;
    else cout << "NO" << el;
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