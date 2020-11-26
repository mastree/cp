#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 60;

int q;
int n, m;
int cnt[N], ar[N];

void solve(){
    cin >> n >> m;
    fill(cnt, cnt + N, 0);
    fill(ar, ar + N, 0);
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int j=1;j<=m;j++){
        int a;
        cin >> a;
        ar[a]++;
    }
    int id1 = 0, id2 = 0;
    while (id1 < N && id2 < N){
        if (cnt[id1] == 0){
            id1++;
            continue;
        }
        if (cnt[id1] <= ar[id2]){
            id1++;
            id2++;
        } else id2++;
    }
    if (id1 == N) cout << "YES" << el;
    else cout << "NO" << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}