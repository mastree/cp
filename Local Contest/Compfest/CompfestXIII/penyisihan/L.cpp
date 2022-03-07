#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll n, m;
vector<pii> pos[2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if (n & 1 ^ 1){
        for (int i=1;i<=n;i++){
            for (int j=0;j<m;j++){
                if (i & 1){
                    pos[(j % 4 < 2)].emplace_back(i, j + 1);
                    // cout << (j % 4 < 2) << ' ';
                } else{
                    pos[!(j % 4 < 2)].emplace_back(i, j + 1);
                    // cout << !(j % 4 < 2) << ' ';
                }
            }
            // cout << el;
        }
    } else{
        for (int i=0;i<n;i++){
            for (int j=1;j<=m;j++){
                if (j & 1){
                    pos[(i % 4 < 2)].emplace_back(i + 1, j);
                } else{
                    pos[!(i % 4 < 2)].emplace_back(i + 1, j);
                }
            }
        }
    }
    for (int i=1;i<=n * m;i++){
        char c;
        cin >> c;
        cout << pos[(c == 'X')].back().fi << " " << pos[(c == 'X')].back().se << endl;
        pos[(c == 'X')].pop_back();
    }

    return 0;
}