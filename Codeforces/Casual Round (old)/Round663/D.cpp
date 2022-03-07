#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;
const int INF = 1e9;

int n, m;
vector<vector<int>> ar;
bitset<N> odset[2], evset[2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if (n >= 4 && m >= 4){
        cout << -1 << el;
        return 0;
    }
    if (n <= m){
        ar.resize(n + 2, vector<int>(m + 2, 0));
        for (int i=1;i<=n;i++){
            string s;
            cin >> s;
            for (int j=1;j<=m;j++){
                int dig = s[j - 1] - '0';
                ar[i][j] = dig;
            }
        }
    } else{
        swap(n, m);
        ar.resize(n + 2, vector<int>(m + 2, 0));
        for (int i=1;i<=m;i++){
            string s;
            cin >> s;
            for (int j=1;j<=n;j++){
                int dig = s[j - 1] - '0';
                ar[j][i] = dig;
            }
        }
    }
    if (n == 1){
        cout << 0 << el;
        return 0;
    }
    if (n == 2){
        vector<int> stat(m + 2, 0);
        for (int i=1;i<=m;i++){
            stat[i] = ar[1][i] ^ ar[2][i];
        }
        int od = 0, ev = 0;
        for (int i=1;i<=m;i++){
            if (i & 1){
                if (stat[i]){
                    ev++;
                } else{
                    od++;
                }
            } else{
                if (stat[i]){
                    od++;
                } else{
                    ev++;
                }
            }
        }
        cout << min(od, ev) << el;
        return 0;
    }
    vector<vector<int>> stat(2, vector<int>(m + 2, 0));
    for (int i=1;i<=m;i++){
        stat[0][i] = ar[1][i] ^ ar[2][i];
        stat[1][i] = ar[2][i] ^ ar[3][i];
    }
    for (int i=0;i<2;i++){
        for (int j=1;j<=m;j++){
            if (j & 1){
                if (stat[i][j]){
                    evset[i][j] = 1;
                } else{
                    odset[i][j] = 1;
                }
            } else{
                if (stat[i][j]){
                    odset[i][j] = 1;
                } else{
                    evset[i][j] = 1;
                }
            }
        }
    }
    int ans = INF;
    for (int i=0;i<2;i++){
        int ni = (i ^ 1);
        ans = min(ans, (int)(odset[i] | evset[ni]).count());  
    } 
    ans = min(ans, (int)(odset[0] | odset[1]).count());
    ans = min(ans, (int)(evset[0] | evset[1]).count());
    cout << ans << el;   

    return 0;
}