#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int M = 30;
const int INF = 1e9;

int n;
vector<vector<int>> ar(M);

int get_degree(int x){
    for (int i=M - 1;i>=0;i--){
        if (x & (1 << i)) return i; 
    }
    return 0;
}
int solve(vector<vector<int>>& v){
    bool lgsg = 1;

    int n = 0;
    int ada = 0;
    for (int i=0;i<M;i++){
        n += v[i].size();
        if ((int)v[i].size() > 1){
            lgsg = 0;
        }
        if (v[i].size()) ada++;
    }
    if (lgsg) return 0;
    int ret = n;
    int pre = 0;
    for (int i=0;i<M;i++){
        if (v[i].size() == 0) continue;
        ada--;
        int cur = n - (int)v[i].size() - ada;
        if (pre) cur--;
        vector<vector<int>> temp(M);
        for (auto x : v[i]){
            int y = x - (1 << i);
            temp[get_degree(y)].pb(y);
        }
        cur += solve(temp);
        ret = min(ret, cur);
        pre += v[i].size();
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        ar[get_degree(a)].pb(a);
    }
    cout << solve(ar) << el;

    return 0;
}