#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int NODE = 1e6 + 10, N = 410;

int di[6] = {1, -1, 0, 0, 0, 0};
int dj[6] = {0, 0, 1, -1, 0, 0};
int dk[6] = {0, 0, 0, 0, 1, -1};

struct Graf{
    int n;
    unordered_map<int, bool> forbid;
    vector<bool> vis;
    int st, tar;

    Graf(){}
    Graf(int n) : n(n) {
        vis.resize(6 * n * n + 10, 0);
    }

    int get_id(int a, int b, int c){
        int temp = n * n;
        if (a == 1){
            return (b - 1) * n + c;
        } else if (a == n){
            return temp + (b - 1) * n + c;
        } else if (b == 1){
            return temp * 2 + (a - 1) * n + c;
        } else if (b == n){
            return temp * 3 + (a - 1) * n + c;
        } else if (c == 1){
            return temp * 4 + (a - 1) * n + b;
        } else if (c == n){
            return temp * 5 + (a - 1) * n + b;
        } 
        return 0;
    }
    pair<int, pii> get_pos(int id){
        int temp = (id - 1) / (n * n);
        id -= temp * n * n;

        int c = (id - 1) % n + 1;
        int b = (id - c) / n + 1; 
        if (temp == 0){
            return mp(1, mp(b, c)); 
        } else if (temp == 1){
            return mp(n, mp(b, c));
        } else if (temp == 2){
            return mp(b, mp(1, c));
        } else if (temp == 3){
            return mp(b, mp(n, c));
        } else if (temp == 4){
            return mp(b, mp(c, 1));
        }
        return mp(b, mp(c, n));
    }

    void add_forbid(int a, int b, int c){
        forbid[get_id(a, b, c)] = 1;
    }

    void set_start(int a, int b, int c){
        st = get_id(a, b, c);
    }
    void set_target(int a, int b, int c){
        tar = get_id(a, b, c); 
    }
    bool is_valid(int a, int b, int c){
        if (1 > a || a > n) return 0;
        if (1 > b || b > n) return 0;
        if (1 > c || c > n) return 0;
        if (!(a == 1 || a == n || b == 1 || b == n || c == 1 || c == n)) return 0;

        if (forbid[get_id(a, b, c)]) return 0;
        return 1;
    }

    int solve(){
        if (st == tar) return 0;
        queue<pii> qu;
        qu.push(mp(0, st));
        vis[st] = 1;
        while (!qu.empty()){
            int cur = qu.front().fi;
            int id = qu.front().se;
            qu.pop();
            auto poss = get_pos(id);
            int a = poss.fi;
            int b = poss.se.fi;
            int c = poss.se.se;
            for (int i=0;i<6;i++){
                int na = a + di[i];
                int nb = b + dj[i];
                int nc = c + dk[i];

                if (is_valid(na, nb, nc)){
                    int nid = get_id(na, nb, nc);
                    if (!vis[nid]){
                        if (nid == tar) return cur + 1;
                        qu.push(mp(cur + 1, nid));
                        vis[nid] = 1;
                    }
                }
            }
        }
        return -1;
    }
};

int q;
int n, m;

void solve(){
    cin >> n >> m;
    Graf graf(n);
    for (int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf.add_forbid(a, b, c);
    }
    if (1){
        int a, b, c;
        cin >> a >> b >> c;
        graf.set_start(a, b, c);
    }
    
    if (1){
        int a, b, c;
        cin >> a >> b >> c;
        graf.set_target(a, b, c);
    }
    cout << graf.solve() << el;
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