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

int n;
ll ar[N], ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=n;i>=1;i--){
        ans[i] = ar[i] - ar[i + 2] + ans[i + 1];
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}