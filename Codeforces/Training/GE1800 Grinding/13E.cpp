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

const int N = 1e5 + 10, M = 320;

int n, m;
int ar[N];
pii tar[N]; // tujuan, cnt
int cek[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        int cur = i, cnt = 0;

        while (cur + ar[cur] <= n && (cur + ar[cur]) - i <= M){
            cur += ar[cur];
            cnt++;
        }
        tar[i] = mp(cur, cnt);
    }

    while (m--){
        int tipe;
        cin >> tipe;
        if (tipe == 0){
            int a, b;
            cin >> a >> b;
            ar[a] = b;

            int cur = a, cnt = 0;
            vector<int> urut;
            urut.pb(a);
            while (cur + ar[cur] <= n && (cur + ar[cur]) - a <= M){
                cur += ar[cur];
                urut.pb(cur);
                cnt++;
            }
            tar[a] = mp(cur, cnt);
            int mx = max(1, a - M);

            int last = urut.size() - 1;
            vector<int> vcek;
            cek[a] = 1;
            vcek.pb(a);
            for (int i=a - 1;i>=mx;i--){
                if (i + ar[i] > n) continue;
                int temp = cek[i + ar[i]];
                if (temp){
                    cek[i] = temp + 1;
                    vcek.pb(i);
                    while (urut[last] - i > M) last--;
                    tar[i] = mp(urut[last], temp + last);
                }
            }
            for (auto x : vcek) cek[x] = 0;
        } else{
            int a;
            cin >> a;

            int cur = a, cnt = 0;
            while (1){
                if (tar[cur].fi == cur){
                    cnt++;
                    if (cur + ar[cur] <= n){
                        cur += ar[cur];
                    } else break;
                }
                cnt += tar[cur].se;
                cur = tar[cur].fi;
            }
            cout << cur << " " << cnt << el;
        }
    }

    return 0;
}