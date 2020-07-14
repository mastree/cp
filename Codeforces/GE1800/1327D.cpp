#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;
const int INF = 1e9;

int q, n;
int ar[N], col[N];
bool vis[N];

void init(){
    fill(vis, vis + n + 2, 0);
}

void x_rotation(vector<int>& cir, int x){
    int len = cir.size();
    for (int i = 0; i < len; i++){
        ar[cir[i]] = cir[(i + x) % len];
    }
}

bool visid[N];
bool bisa(vector<int>& cir){
    bool ret = 0;
    for (auto x : cir) visid[x] = 0;
    for (int x : cir){
        if (visid[x]) continue;
        int cur = x;
        int sama = col[x];

        bool b = 1;
        while (!visid[cur]){
            visid[cur] = 1;
            if (col[cur] != sama) b = 0;
            cur = ar[cur];
        }
        if (b){
            ret = 1;
            break;
        }
    }
    return ret;
}

int solve(int id){
    vector<int> v;
    v.pb(id);
    for (int curid = ar[id]; curid != id; curid = ar[curid]){
        v.pb(curid);
    }
    for (int x : v) vis[x] = 1;
    int ans = INF;
    int len = v.size();

    vector<int> fac;
    for (int i = 1; i * i <= len; i++){
        if (len % i == 0){
            int i2 = len / i;
            fac.pb(i);
            if (i2 != i) fac.pb(i2);
        }
    }
    sort(fac.begin(), fac.end());
    for (int x : fac){
        x_rotation(v, x);
        if (bisa(v)){
            ans = min(ans, x);
        }
    }

    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        init();
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<=n;i++){
            cin >> col[i];
        }
        
        int ans = INF;
        for (int i=1;i<=n;i++){
            if (vis[i]) continue;
            ans = min(ans, solve(i));
        }
        cout << ans << el;
    }

    return 0;
}