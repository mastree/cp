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

int sqr;
int n, m, q;
int ar[N];
pair<pii, int> quer[N];
vector<int> vec;
int ans[N];

bool comp(int a, int b){
    pii ra = mp(quer[a].fi.fi / sqr, quer[a].fi.se / sqr);
    pii rb = mp(quer[b].fi.fi / sqr, quer[b].fi.se / sqr);
    return ra < rb;
}

int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    sqr = (int)sqrt(n);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=q;i++){
        int l, r, x;
        cin >> l >> r >> x;
        quer[i] = mp(mp(l, r), x);
        vec.pb(i);
    }
    sort(vec.begin(), vec.end(), &comp);
    int l = 1, r = 0;
    for (auto x : vec){
        int ql = quer[x].fi.fi, qr = quer[x].fi.se;
        int col = quer[x].se;
        
        while (l < ql){
            cnt[ar[l]]--;
            l++;
        }
        while (l > ql){
            l--;
            cnt[ar[l]]++;
        }
        while (r < qr){
            r++;
            cnt[ar[r]]++;
        }
        while (r > qr){
            cnt[ar[r]]--;
            r--;
        }
        ans[x] = cnt[col];
    } 
    for (int i=1;i<=q;i++){
        cout << ans[i] << el;
    }

    return 0;
}