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
int ar[N];

void solve(){
    cin >> n;
    int cnt1 = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt1 += ar[i];
    }
    if (n - cnt1 >= n / 2){
        cout << n - cnt1 << el;
        for (int i=1;i<=n - cnt1;i++) cout << 0 << " ";
        cout << el;
        return;
    }
    if (cnt1 & 1) cnt1--;
    cout << cnt1 << el;
    for (int i=1;i<=cnt1;i++) cout << 1 << " ";
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