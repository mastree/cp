#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e2 + 10;

int n;
vector<pii> pt;

ll area(pii a, pii b, pii c){
    ll ret = 0;
    vector<pii> v{a, b, c};
    for (int i=0;i<3;i++){
        int ni = (i + 1) % 3;
        ret += v[i].fi * v[ni].se - v[i].se * v[ni].fi;
    }
    return abs(ret);
}
ll prec[N][N][N];
ll solve(vector<pii> const& pt){
    int n = pt.size();
    ll ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                if (i != k && i != j && j != k){
                    prec[i][j][k] = area(pt[i], pt[j], pt[k]);
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=i + 1;j<n;j++){
            for (int k=j + 1;k<n;k++){
                ll temp = prec[i][j][k];
                ll cnt = 0;
                for (int pos=0;pos<n;pos++){
                    if (pos == i || pos == j || pos == k) continue;
                    ll cur = 0;
                    cur += prec[i][j][pos] + prec[i][k][pos] + prec[k][j][pos];//area(pt[i], pt[j], pt[pos]);
                    if (temp == cur){
                        cnt++;
                    }
                }
                ans += cnt * (cnt - 1) * (cnt - 2) / 6;
            }
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        pii temp;
        cin >> temp.fi >> temp.se;
        pt.pb(temp);
    }
    cout << solve(pt) << el;

    return 0;
}