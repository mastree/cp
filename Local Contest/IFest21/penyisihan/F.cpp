#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
int n;

void solve(){
    cin >> n;
    vector<int> vec(n + 3);
    for (int i=1;i<=n;i++){
        cin >> vec[i];
    }
    vec[0] = vec[1];
    vec[n + 1] = vec[n];
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (vec[i] != vec[i - 1] || vec[i] != vec[i + 1]) ans++;
    }
    cout << ans << el;
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