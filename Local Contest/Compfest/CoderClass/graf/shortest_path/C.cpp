#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Edge{
    int a, b, c;
    Edge() {}
    Edge(int a, int b, int c) : a(a), b(b), c(c) {}
};

const int N = 210;
const int INF = 1e9;

int s, e;
int n, m;
vector<Edge> edges;
int dp[N];

bool ok = 1;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> e;
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    fill(dp, dp + n + 2, INF);
    dp[s] = 0;
    for (int lup=1;lup<=n;lup++){
        for (auto x : edges){
            if (dp[x.b] > dp[x.a] + x.c){
                if (lup == n){
                    ok = 0;
                    break;
                }
                dp[x.b] = dp[x.a] + x.c;
            }
        }
    }
    if (dp[e] >= INF) ok = 0;
    if (ok) cout << "BISA" << el;
    else cout << "TIDAK" << el;

    return 0;
}