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

const int N = 1e6 + 10;
const int INF = 1e9;

int n, m, k;

vector<vector<int>> dp;
vector<vector<int>> pre;
set<int> r[N], c[N];

pii st, tar;

bool bisa(int xa, int ya, int xb, int yb){
    if (xa > xb) swap(xa, xb);
    if (ya > yb) swap(ya, yb);
    return (pre[xb][yb] - pre[xa - 1][yb] - pre[xb][ya - 1] + pre[xa - 1][ya - 1] == 0);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    cin >> st.fi >> st.se >> tar.fi >> tar.se;

    dp.resize(n + 2, vector<int>(m + 2, INF));
    pre.resize(n + 2, vector<int>(m + 2, 0));
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=m;j++){
            if (s[j - 1] == '.'){
                r[i].insert(j);
                c[j].insert(i);
            } else{
                pre[i][j] = 1;
                if (i == st.fi && j == st.se){
                    cout << -1 << el;
                    return 0;
                }
            }  
        }
    }
    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=1;j<=m;j++){
            cur += pre[i][j];
            pre[i][j] = pre[i - 1][j] + cur;
        }
    }
    queue<pair<int, pii>> qu; // turn, pos;
    r[st.fi].erase(st.se);
    c[st.se].erase(st.fi);
    qu.push(mp(0, st));

    while (!qu.empty()){
        auto temp = qu.front();
        qu.pop();
        int turn = temp.fi;
        int x = temp.se.fi;
        int y = temp.se.se;
        if (dp[x][y] <= turn) continue;
        dp[x][y] = turn; 

        // same row
        int mn, mx;
        int low, high;
        mn = max(1, y - k);
        mx = min(m, y + k);

        low = mn;
        high = y;
        while (low < high){
            int mid = (low + high) / 2;
            if (bisa(x, y, x, mid)){
                high = mid;
            } else{
                low = mid + 1;
            }
        }
        mn = high;
        low = y;
        high = mx;
        while (low < high){
            int mid = (low + high + 1) / 2;
            if (bisa(x, y, x, mid)){
                low = mid;
            } else{
                high = mid - 1;
            }
        }
        mx = low;
        auto it = r[x].lower_bound(mn);
        vector<int> pus;
        while (it != r[x].end() && *it <= mx){
            qu.push(mp(turn + 1, mp(x, *it)));
            pus.pb(*it);
            it++;
        }
        for (auto h : pus){
            r[x].erase(h);
            c[h].erase(x);
        }

        // same col
        mn = max(1, x - k);
        mx = min(n, x + k);

        low = mn;
        high = x;
        while (low < high){
            int mid = (low + high) / 2;
            if (bisa(x, y, mid, y)){
                high = mid;
            } else{
                low = mid + 1;
            }
        }
        mn = high;
        low = x;
        high = mx;
        while (low < high){
            int mid = (low + high + 1) / 2;
            if (bisa(x, y, mid, y)){
                low = mid;
            } else{
                high = mid - 1;
            }
        }
        mx = low;
        it = c[y].lower_bound(mn);
        pus.clear();
        while (it != c[y].end() && *it <= mx){
            qu.push(mp(turn + 1, mp(*it, y)));
            pus.pb(*it);
            it++;
        }
        for (auto h : pus){
            r[h].erase(y);
            c[y].erase(h);
        }
    }
    if (dp[tar.fi][tar.se] == INF){
        cout << -1 << el;
    } else{
        cout << dp[tar.fi][tar.se] << el;
    }

    return 0;
}