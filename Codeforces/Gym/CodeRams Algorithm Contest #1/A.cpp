#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
unordered_map<int, int> cnt;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    for (auto& x : cnt){
        if (x.se == 1) ans++;
    }
    cout << ans << el;

    return 0;
}