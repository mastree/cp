#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e4 + 10;

int n, t;
int nx[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for (int i=1;i<n;i++){
        cin >> nx[i];
    }
    int cur = 1;
    while (cur < t){
        cur = cur + nx[cur];
    }
    if (cur == t) cout << "YES" << el;
    else cout << "NO" << el;

    return 0;
}