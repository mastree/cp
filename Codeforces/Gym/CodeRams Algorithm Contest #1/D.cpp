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

int n, q;
int ar[N];
int ton[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }    
    for (int i=1;i<=q;i++){
        int a;
        cin >> a;
        ton[1]++;
        ton[a + 1]--;
    }
    int ans = 0;
    int cur = 0;
    for (int i=1;i<=n;i++){
        cur += ton[i];
        if (cur >= ar[i]) ans++;
    }
    cout << ans << el;

    return 0;
}