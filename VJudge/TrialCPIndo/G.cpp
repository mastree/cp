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

int n, m;
int cost[N];
pii ar[N];
vector<int> adl[N];
int ans;
bool del[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> cost[i];
        ar[i] = mp(cost[i], i);
    }   
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    sort(ar + 1, ar + n + 1, greater<pii>());
    for (int i=1;i<=n;i++){
        del[ar[i].se] = 1;
        for (int x : adl[ar[i].se]){
            if (!del[x]){
                ans += cost[x];
            }
        }
    }
    cout << ans << el;

    return 0;
}