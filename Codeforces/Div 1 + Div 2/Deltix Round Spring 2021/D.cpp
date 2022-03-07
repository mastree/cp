#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 1;
const int M = 61;

int n, m, p;
bool ar[N][M];
int cnt[M];

bitset<N> bset[M];
bitset<N> bcur;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;    
    for (int i=1;i<=n;i++){
        bool a;
        char c;
        for (int j=0;j<m;j++){
            cin >> c;
            a = (c == '1');
            ar[i][j] = a;
            if (a){
                cnt[j]++;
                bset[j][i] = 1;
            }
        }
    }
    vector<int> pos;
    int mn = (n + 1) / 2;
    for (int i=0;i<m;i++){
        if (cnt[i] >= mn){
            pos.pb(i);
        }
    }
    int len = pos.size();
    int mxmask = (1 << len);

    vector<int> ans;
    for (int mask=1;mask<mxmask;mask++){
        int msize = __builtin_popcount(mask);
        if (msize > p) continue;
        bcur.reset();
        bool awal = 1;
        vector<int> temp;
        if (ans.size() < msize){
            for (int i=0;i<len;i++){
                if (mask & (1 << i)){
                    if (awal) bcur |= bset[i];
                    else bcur &= bset[i];
                    temp.pb(i);
                }
            }
            if (bcur.count() >= mn){
                cout << bcur.count() << el;
                ans.swap(temp);
            }
        }
    }
    vector<bool> bans(m, 0);
    for (auto& x : ans){
        bans[x] = 1;
    }
    for (int i=0;i<m;i++){
        cout << bans[i];
    }
    cout << el;

    return 0;
}