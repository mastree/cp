#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll=loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e4 + 10;
const int K = 4e2 + 10;
const int INF = 1e9;

int n, m, k;
int ar[N];

int cnt[N];

int cost[N][K];
int dp[N][K];

void init_cost(){
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j] = INF;
        }
    }

    for (int i=1;i<=n;i++){
        int pos = i;
        int cur = 0;
        fill(cnt, cnt + n + 1, 0);

        while (cur <= k){
            while (pos <= n && cnt[ar[pos]] < m){
                cnt[ar[pos]]++;
                pos++;
            }
            cost[i][cur] = pos - i;
            if (pos > n) break;
            cur++;
            pos++; 
        }
        for (int j=1;j<=k;j++){
            cost[i][j] = max(cost[i][j], cost[i][j - 1]);
        }
    }
}

void solsol(){
    int too[k + 5][n + 10];
    int ccnt[k + 5][n + 10];
    int lebih[k + 5];
    memset(ccnt, 0, sizeof(ccnt));
    memset(too, 0, sizeof(too));
    memset(lebih, 0, sizeof(lebih));
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j] = INF;
        }
    }
    for (int kk=0;kk<=k;kk++){
        for (int i=1;i<=n;i++){
            if (--ccnt[kk][ar[i - 1]] == m) lebih[kk]--;
            too[kk][i] = too[kk][i - 1];
            for (int j=too[kk][i] + 1;j<=n;j++){
                if (++ccnt[kk][ar[j]] > m) lebih[kk]++;
                if (lebih[kk] <= kk){
                    too[kk][i] = j;
                } else{
                    --ccnt[kk][ar[j]];
                    lebih[kk] = kk;
                    break;
                }
            }
        }
    }
    dp[0][0] = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=k;j++){
            for (int j2=0;j + j2<=k;j2++){
                dp[too[j2][i + 1]][j + j2] = min(dp[too[j2][i + 1]][j + j2], dp[i][j] + 1);
            }
        }
    }
    int ans = n;
    for (int i=0;i<=k;i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    if (k == n){
        cout << 0 << el;
        return 0;
    }

    int c1 = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i] == 1) c1++;
    }
    if (c1 == n){
        cout << (n - k + m - 1) / m << el;
        return 0;
    }
    if (k == 0){
        int last = 1;
        int ans = 0;

        vector<int> pus;
        while (last <= n){
            for (auto x : pus){
                cnt[x] = 0;
            }
            pus.clear();

            int cur = last;
            while (cur <= n && cnt[ar[cur]] < m){
                cnt[ar[cur]]++;
                pus.pb(ar[cur]);
                cur++;
            }
            ans++;
            last = cur;
        }
        cout << ans << el;
        return 0;
    }
    if (k <= 20){
        solsol();
        return 0;
    }
    init_cost();
    dp[0][0] = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=k;j++){
            for (int j2=0;j + j2<=k;j2++){
                int temp = cost[i + 1][j2];
                if (temp == 0) continue;
                dp[i + temp][j + j2] = min(dp[i + temp][j + j2], dp[i][j] + 1);
            }
        }
    }
    int ans = n;
    for (int i=0;i<=k;i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << el;

    return 0;
}