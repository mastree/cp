#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 100;
const int INF = 2e9;

int n, m;
vector<pii> ril;
map<int, int> getid;
int getpos[N];

int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(getpos, getpos + N, INF);
    getpos[0] = 0;

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        getid[a] = 1;
        getid[b] = 1;
        ril.pb(mp(a, b));
    }
    getid[m] = 1;
    int tempid = 0;
    for (auto& x : getid){
        x.se = ++tempid;
        getpos[tempid] = x.fi;
    }
    for (auto x : ril){
        int a = getid[x.fi];
        int b = getid[x.se];
        ar[a] = max(ar[a], b);
    }
    for (int i=2;i<N;i++){
        ar[i] = max(ar[i], ar[i - 1]);
    }
    int ans = 0, last = 0;
    m = getid[m];
    while (last < m){
        if (getpos[last + 1] - getpos[last] == 1){
            if (ar[last + 1] <= last){
                cout << -1 << el;
                return 0;
            }
            last = ar[last + 1];
            ans++;
        } else{
            if (ar[last] <= last){
                cout << -1 << el;
                return 0;
            }
            last = ar[last];
            ans++;
        }
    }
    cout << ans << el;

    return 0;
}