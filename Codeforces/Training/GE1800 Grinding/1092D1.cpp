#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n, ar[N];
vector<int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ar[i] &= 1;
    }
    v.pb(2);
    for (int i=1;i<=n;i++){
        if (v.back() == ar[i]) v.pop_back();
        else v.pb(ar[i]);
    }
    if (v.size() > 2) cout << "NO" << el;
    else cout << "YES" << el;

    return 0;
}