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
const int INF = 1e9 + 7;

int n, p;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    int mn = 0;
    for (int i=1;i<=n;i++){
        mn = max(mn, ar[i] - i + 1);
    }
    int mx = INF;
    for (int i=1;i<=n;i++){
        int temp = n - i + p;
        if (temp > n) continue;
        mx = min(mx, ar[i] - (n - temp));
    }
    int cnt =  max(0, mx - mn);
    cout << cnt << el;
    for (int i=mn;i<mn + cnt;i++){
        cout << i << ' ';
    }
    cout << el;

    return 0;
}