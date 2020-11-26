#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int q;
int n;

void solve(){
    cin >> n;
    vector<int> v;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        v.pb(a);
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    {
        int cur1 = 0, cur2 = 0;
        while (!v.empty()){
            if (v.back() == cur1) cur1++;
            else if (v.back() == cur2) cur2++;
            v.pop_back();
        }
        ans = cur1 + cur2;
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