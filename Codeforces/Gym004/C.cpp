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

const int N = 1e3 + 10;
const int INF = 2e9;

int n, m;
pii pos[N];
vector <int> v;

map<int, bool> ada;
int dp[N][2]; //[posisi][ambil ujung][sisa]
int cnt[N][3]; //[posisi][le, center, right]

pii par[N][2];

int gg(pii a){
    return dp[a.fi][a.se];
}

pii fp(pii a){
    return par[a.fi][a.se];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    pos[0] = mp(-1, -1);
    for (int i=1;i<=n;i++){
        cin >> pos[i].fi >> pos[i].se;
    }
    sort(pos + 1, pos + n + 1);
    cin >> m;
    for (int i=0;i<m;i++){
        int a;
        cin >> a;
        ada[a] = 1;
        v.pb(a);
    }
    int cur = 1;
    for (auto x : v){
        if (x <= pos[cur].se && x >= pos[cur].fi){
            if (x == pos[cur].fi) cnt[cur][0]++;
            else if (x == pos[cur].se) cnt[cur][2]++;
            else cnt[cur][1]++;
        } else{
            while (x > pos[cur].se){
                cur++;
                if (cur == n+1) break;
            }
            if (cur == n+1) break;
            if (x >= pos[cur].fi){
                if (x == pos[cur].fi) cnt[cur][0]++;
                else if (x == pos[cur].se) cnt[cur][2]++;
                else cnt[cur][1]++;
            }
        }
    }

    for (int i=1;i<N;i++){
        for (int j=0;j<2;j++){
            // for (int k=0;k<3;k++){
                dp[i][j] = MOD;
            // }
        }
    }
    dp[0][0] = 0;
    dp[0][1] = MOD;

    for (int i=1;i<=n;i++){
        if (pos[i-1].se == pos[i].fi){
            int temp = dp[i-1][0];
            int tot = cnt[i][0] + cnt[i][1] + cnt[i][2];

            if (tot > 2){
                continue;
            }
            int sisa = 2 - tot;
            // cout << sisa << el;
            if (!cnt[i][2] && ((!cnt[i][0]) + pos[i].se - pos[i].fi - 1 - cnt[i][1] >= sisa)){
                if (dp[i][0] > temp + sisa){
                    par[i][0] = mp(i - 1, 0);
                }
                dp[i][0] = min(dp[i][0], temp + sisa);
            }
            if (sisa || cnt[i][2]){
                if (dp[i][1] > temp + sisa){
                    par[i][1] = mp(i - 1, 0);
                }
                dp[i][1] = min(dp[i][1], temp + sisa);
            }

            bool masuk = 0;
            if (!cnt[i][0]){
                masuk = 1;
                // sisa--;
                cnt[i][0]++;
                tot++;
            }
            temp = dp[i-1][1];
            // cout << temp << el;
            if (tot > 2){
                if (masuk){
                    cnt[i][0]--;
                }
                continue;
            }
            sisa = 2 - tot;
            // cout << sisa << el;
            if (!cnt[i][2] && ((!cnt[i][0]) + pos[i].se - pos[i].fi - 1 - cnt[i][1] >= sisa)){
                if (dp[i][0] > temp + sisa){
                    par[i][0] = mp(i - 1, 1);
                }
                dp[i][0] = min(dp[i][0], temp + sisa);
            }
            if (sisa || cnt[i][2]){
                if (dp[i][1] > temp + sisa){
                    par[i][1] = mp(i - 1, 1);
                }
                dp[i][1] = min(dp[i][1], temp + sisa);
            }
            if (masuk){
                cnt[i][0]--;
            }
        } else{
            pii tt; 
            if (dp[i-1][0] < dp[i-1][1]){
                tt = mp(i-1, 0);
            } else{
                tt = mp(i-1, 1);
            }
            int temp = min(dp[i-1][0], dp[i-1][1]);
            int tot = cnt[i][0] + cnt[i][1] + cnt[i][2];

            if (tot > 2){
                continue;
            }
            int sisa = 2 - tot;
            // cout << sisa << el;
            if (!cnt[i][2] && ((!cnt[i][0]) + pos[i].se - pos[i].fi - 1 - cnt[i][1] >= sisa)){
                if (dp[i][0] > temp + sisa){
                    par[i][0] = tt;
                }
                dp[i][0] = min(dp[i][0], temp + sisa);
            }
            if (sisa || cnt[i][2]){
                if (dp[i][1] > temp + sisa){
                    par[i][1] = tt;
                }
                dp[i][1] = min(dp[i][1], temp + sisa);
            }
        }
        // cout << dp[i][0] << " " << dp[i][1] << el;
    }

    int ans = INF;
    for (int i=0;i<2;i++){
        // for (int j=0;j<3;j++){
            ans = min(ans, dp[n][i]);
        // }
    }
    if (ans < MOD){
        cout << ans << el;
        pii cur;
        for (int i=0;i<2;i++){
            if (dp[n][i] == ans){
                cur = mp(n, i);
                break;
            }
        }

        while (cur != mp(0, 0)){
            pii nex = fp(cur);

            int ambil = gg(cur) - gg(nex);
            if (ambil == 0){
                cur = nex;
                continue;
            }
            if (cur.se){
                if (!ada[pos[cur.fi].se]){
                    ambil--;
                    cout << pos[cur.fi].se << " ";
                }
            }

            vector <int> simpen;
            for (int i=pos[cur.fi].fi + 1;i<pos[cur.fi].se;i++){
                if (simpen.size() == ambil) break;
                if (!ada[i]){
                    simpen.pb(i);
                }
            }
            for (auto x : simpen){
                cout << x << " ";
            }
            cur = nex;
        }
        cout << el;
    } else{
        cout << "impossible" << el;
    }

    return 0;
}