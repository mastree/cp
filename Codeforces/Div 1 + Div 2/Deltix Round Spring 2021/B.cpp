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
const int MX = 5e3;

int q;
int n;
ll ar[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    cout << 6 * n / 2 << el;
    for (int i=1;i<=n / 2;i++){
        int pi = i + n / 2;   
        cout << 1 << " " << i << " " << pi << el;
        cout << 2 << " " << i << " " << pi << el;
        cout << 2 << " " << i << " " << pi << el;
        cout << 1 << " " << i << " " << pi << el;
        cout << 2 << " " << i << " " << pi << el;
        cout << 2 << " " << i << " " << pi << el;
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