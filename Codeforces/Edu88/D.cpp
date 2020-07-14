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

const int N = 1e5 + 10;
const int M = 100, B = 30;
const int INF = 1e9;

int n;
int ar[N];
int pc[N];

vector<int> _pos[M];
vector<int> *pos = _pos + M / 2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        pos[ar[i]].pb(i);
    }
    int ans = 0;
    for (int pus=B;pus>=0;pus--){
        if (pos[pus].empty()) continue;
        int mn = 0, cur = 0;
        for (int i=1;i<=n;i++){
            cur += ar[i];
            if (ar[i] == -INF){
                cur = 0;
                mn = 0;
                continue;
            }
            mn = min(mn, cur);
            ans = max(ans, cur - mn - pus);
        }
        for (auto x : pos[pus]){
            ar[x] = -INF;
        }
    }
    cout << ans << el;

    return 0;
}