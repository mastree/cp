#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 18;
const int MASK = (1 << N);
const int INF = 1e9;

int h, w, n;
vector<string> vec;

bool inside(const string& a, const string& b){
    int lena = a.size();
    int lenb = b.size();
    for (int i=0;i<lenb - lena + 1;i++){
        bool ok = 1;
        for (int j=0;j<lena;j++){
            if (a[j] != b[i + j]){
                ok = 0;
                break;
            }
        }
        if (ok) return 1;
    }
    return 0;
}
bool comp(const string& a, const string& b){
    return a.size() < b.size();
}
int inter(const string& a, const string& b){
    int lena = a.size();
    int lenb = b.size();
    int mx = min(lena, lenb);
    for (int i=mx;i>=1;i--){
        bool ok = 1;
        for (int j=0;j<i;j++){
            if (a[lena - i + j] != b[j]){
                ok = 0;
                break;
            }
        }
        if (ok) return i;
    }
    return 0;
}

int dp[MASK][N]; // dp[mask][last] = dist
int dist[N][N];
pii par[MASK][N];

void init(){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            dist[i][j] = (int)vec[j].size() - inter(vec[i], vec[j]);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w >> n;    
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        if (s.size() > w){
            cout << "impossible" << el;
            return 0;
        }
        vec.pb(s);
    }
    {
        sort(vec.begin(), vec.end(), &comp);
        vector<bool> msk(n, 1);
        for (int i=0;i<n;i++){
            for (int j=i + 1;j<n;j++){
                if (inside(vec[i], vec[j])){
                    msk[i] = 0;
                    break;
                }
            }
        }
        vector<string> baru;
        for (int i=0;i<n;i++){
            if (msk[i]) baru.pb(vec[i]);
        }
        vec.swap(baru);
        n = vec.size();
    }
    init();
    for (int i=0;i<MASK;i++){
        fill(dp[i], dp[i] + N, INF);
    }
    for (int i=0;i<n;i++){
        dp[(1 << i)][i] = (int)vec[i].size();
        par[(1 << i)][i] = mp(-1, -1);
    }
    for (int mask=1;mask<(1 << n);mask++){
        for (int last=0;last<n;last++){
            for (int nlast=0;nlast<n;nlast++){
                int bit = (1 << nlast);
                if (mask & bit) continue;
                int nmask = mask + bit;
                int nval = dp[mask][last] + dist[last][nlast];
                if ((nval - 1) / w > (dp[mask][last] - 1) / w){
                    nval = ((dp[mask][last] + w - 1) / w) * w + vec[nlast].size();
                }
                if (dp[nmask][nlast] > nval){
                    dp[nmask][nlast] = nval;
                    par[nmask][nlast] = mp(mask, last);
                }
            }
        }
    }
    vector<pii> ans;
    for (int i=0;i<n;i++){
        if (ans.empty()){
            ans.pb(mp((1 << n) - 1, i));
            continue;
        }
        if (dp[ans.back().fi][ans.back().se] > dp[(1 << n) - 1][i]) ans.back() = mp((1 << n) - 1, i);
    }
    if (dp[ans.back().fi][ans.back().se] > h * w){
        cout << "impossible" << el;
        return 0;
    }
    while (ans.back() != mp(-1, -1)){
        ans.pb(par[ans.back().fi][ans.back().se]);
    }
    vector<string> jawab(h);
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (auto x : ans){
        int row = (dp[x.fi][x.se] - 1) / w;
        int len = vec[x.se].size();
        int sama = inter(jawab[row], vec[x.se]);
        int tam = len - sama;
        for (int i=0;i<tam;i++){
            jawab[row].pb(vec[x.se][len - tam + i]);
        }
    }
    for (auto& x : jawab){
        while ((int)x.size() < w){
            x.pb('A');
        }
    }
    for (auto x : jawab){
        cout << x << el;
    }

    return 0;
}