#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 200;

int q;
int n, ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<=n;i++){
            if (i & 1) cout << abs(ar[i]) << " ";
            else cout << -abs(ar[i]) << " ";
        }
        cout << el;
    }

    return 0;
}