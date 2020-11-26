#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 10;

int r[2], c[2];
int rook, bis, king;
bool vis[N][N];

int di[4] = {1, 1, -1, -1};
int dj[4] = {-1, 1, -1, 1};

bool valid(int a, int b){
    return 1 <= a && a <= 8 && 1 <= b && b <= 8;
}
int solve(){
    queue<pair<int, pii>> qu;

    qu.push(mp(0, mp(r[0], c[0])));
    vis[r[0]][c[0]] = 1;
    while (!qu.empty()){
        int cur = qu.front().fi;
        pii node = qu.front().se;
        qu.pop();
        if (node == mp(r[1], c[1])) return cur;

        for (int mag=1;mag<=7;mag++){
            for (int i=0;i<4;i++){
                int deli = di[i];
                int delj = dj[i];
                
                int ni = node.fi + deli * mag;
                int nj = node.se + delj * mag;
                if (!valid(ni, nj)) continue;
                if (vis[ni][nj]) continue;
                vis[ni][nj] = 1;
                qu.push(mp(cur + 1, mp(ni, nj)));
            }
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<2;i++){
        cin >> r[i] >> c[i];
    }
    {
        int delx = abs(r[1] - r[0]);
        int dely = abs(c[1] - c[0]);
        king = min(delx, dely);
        king += delx + dely - king * 2;
    }
    {
        int delx = abs(r[1] - r[0]);
        int dely = abs(c[1] - c[0]);
        if (delx == 0 && dely == 0){
            rook = 0;
        } else if (delx == 0 || dely == 0){
            rook = 1;
        } else{
            rook = 2;
        }
    }
    {
        bis = solve();
    }
    cout << rook << " " << bis << " " << king << el;

    return 0;
}