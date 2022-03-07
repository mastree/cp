#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;
const int INF = 1e9 + 10;

int n;
vector<int> vec;

vector<int> z_function(const vector<int>& vec){
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && vec[z[i]] == vec[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        vec.pb(a);
    }
    reverse(vec.begin(), vec.end());
    auto z = z_function(vec);
    pii ans = mp(n - 1, 1);
    for (int i=1;i<n;i++){
        int p = i;
        int k = n - (i + z[i]);
        if (ans.fi + ans.se > k + p) ans = mp(k, p);
        else if (ans.fi + ans.se == k + p && p < ans.se) ans = mp(k, p);
    }
    cout << ans.fi << " " << ans.se << el;

    return 0;
}