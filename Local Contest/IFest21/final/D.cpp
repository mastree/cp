#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int n, m;
int ar[N];
vector<vector<int>> ans;

bool bisa(int gap){
    int tot = 1;
    int last = ar[1];
    for (int i=1;i<=n;i++){
        if (ar[i] - last > gap){
            last = ar[i];
            tot++;
        }
    }
    return tot <= m;
}

void solve(int gap){
    int tot = 0;
    int last = -1;
    vector<int> cur;
    for (int i=1;i<=n;i++){
        if (last == -1){
            last = ar[i];
            tot++;
            cur.clear();
            cur.pb(ar[i]);
        } else{
            if (n - i + 1 <= m - tot){
                last = ar[i];
                tot++;
                ans.pb(cur);
                cur.clear();
                cur.pb(ar[i]);
            } else if (ar[i] - last > gap){
                last = ar[i];
                tot++;
                ans.pb(cur);
                cur.clear();
                cur.pb(ar[i]);
            } else{
                cur.pb(ar[i]);
            }
        }
    }
    ans.pb(cur);
    for (int i=0;i<m;i++){
        for (auto x : ans[i]){
            cout << x << ' ';
        }
        cout << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    int l = 0, r = 100;
    int best = -1;
    while (l <= r){
        int md = (l + r) / 2;
        if (bisa(md)){
            r = md - 1;
            best = md;
        } else{
            l = md + 1;
        }
    }
    solve(best);

    return 0;
}