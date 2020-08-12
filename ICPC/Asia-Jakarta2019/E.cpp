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
int l, r, k;
int ar[N];
vector<int> cnt, v, ans;
vector<pii> vans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (v.empty()){
            v.pb(ar[i]);
            cnt.pb(1);
        } else{
            if (v.back() != ar[i]){
                v.pb(ar[i]);
                cnt.pb(1);
            } else cnt.back()++;
        }
    }
    vans.pb(mp(l, r));
    int len = v.size();
    for (int i=1;i<len;i++){
        pii temp = vans.back();
        if (v[i - 1] == v[i]){
            vans.pb(temp);
        } else if (v[i - 1] < v[i]){
            temp.fi++;
            temp.se = min(temp.se + k, r);
            vans.pb(temp);
        } else{
            temp.fi = max(temp.fi - k, l);
            temp.se--;
            vans.pb(temp);
        }
    }
    for (auto x : vans){
        if (x.fi > x.se){
            cout << -1 << el;
            return 0;
        }
    }
    ans.pb(vans.back().fi);
    for (int i=len - 2;i>=0;i--){
        if (v[i + 1] == v[i]){
            ans.pb(ans.back());
        } else if (v[i + 1] < v[i]){
            ans.pb(max(ans.back() + 1, vans[i].fi));
        } else{
            ans.pb(max(ans.back() - k, vans[i].fi));
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i=0;i<len;i++){
        for (int j=0;j<cnt[i];j++) cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}