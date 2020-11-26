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

ll n;
ll ar[N];
ll sisa[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> ar[i];
        sisa[i] = ar[i] % n;
    }
    if (n == 1){
        cout << 1 << " " << 1 << el;
        cout << 0 << el;
        cout << 1 << " " << 1 << el;
        cout << 0 << el;
        cout << 1 << " " << 1 << el;
        cout << -ar[1] << el;
        return 0;
    }
    cout << 1 << " " << n - 1 << el;
    for (ll i=1;i<=n - 1;i++){
        cout << (n - 1) * sisa[i] << " ";
        ar[i] += (n - 1) * sisa[i];
        sisa[i] = 0;
    }
    cout << el;
    cout << 2 << " " << n << el;
    for (ll i=2;i<=n;i++){
        cout << (n - 1) * sisa[i] << " ";
        ar[i] += (n - 1) * sisa[i];
        sisa[i] = 0;
    }
    cout << el;
    cout << 1 << " " << n << el;
    for (int i=1;i<=n;i++){
        cout << -ar[i] << " ";
    }
    cout << el;

    return 0;
}