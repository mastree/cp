#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int M = 3;
const int INF = 1e9;

int len;
int n[M];
int skill[M];
vector<pair<int, pii>> vec;
int ar[N];

bool bisa(int mn){
    int sisa[M];
    for (int i=0;i<M;i++) sisa[i] = n[i];

    for (int i=1;i<=len;i++){
        bool ok = 0;
        for (auto x : vec){
            if (((x.se.fi == x.se.se && sisa[x.se.fi] >= 2) || (x.se.fi != x.se.se && sisa[x.se.fi] && sisa[x.se.se])) && ar[i] * x.fi >= mn){
                sisa[x.se.fi]--;
                sisa[x.se.se]--;
                ok = 1;
                break;
            }
        }
        if (!ok) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<M;i++){
        cin >> n[i];
        len += n[i];
    }
    len /= 2;
    for (int i=0;i<M;i++){
        cin >> skill[i];
    }
    for (int i=0;i<M;i++){
        for (int j=i;j<M;j++){
            vec.pb(mp(skill[i] + skill[j], mp(i, j)));
        }
    }
    sort(vec.begin(), vec.end());
    for (int i=1;i<=len;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + len + 1);
    // for (int i=1;i<=len;i++){
    //     cout << ar[i] << " ";
    // }
    // for (auto x : vec){
    //     cout << x.fi << " " << x.se.fi << " " << x.se.se << el; 
    // }
    // cout << el;
    int l = 0, r = INF;
    while (l < r){
        int m = (l + r + 1) / 2;
        if (bisa(m)){
            l = m;
        } else{
            r = m - 1;
        }
    }
    cout << l << el;

    return 0;
}