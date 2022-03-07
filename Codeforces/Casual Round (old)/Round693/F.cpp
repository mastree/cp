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

const int N = 2e5 + 10;

int q;
int n, m;
pii ar[N];
bool cek[N * 5][2];

void solve(){
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> ar[i].se >> ar[i].fi;
    }
    if (m & 1){
        cout << "NO" << el;
        return;
    }
    sort(ar + 1, ar + m + 1);
    {
        int last = 0;
        for (int i=1;i<=m;i++){
            if (ar[i].fi == ar[i - 1].fi){
                ar[i].fi = last;
                continue;
            }
            int jar = ar[i].fi - last;
            jar %= 2;
            if (jar == 0) jar += 2;
            ar[i].fi = last + jar;
            last = ar[i].fi;
        }
    }
    int mxpos = ar[m].fi;
    for (int i=1;i<=m;i++){
        cek[ar[i].fi][ar[i].se - 1] = 1;
    }
    bool ok = 1;
    bool cur[2] = {1, 1};
    // for (int i=1;i<=mxpos;i++){
    //     cout << cek[i][0] << cek[i][1] << el;
    // }
    for (int i=1;i<=mxpos;){
        assert(cur[0] || cur[1]);
        if (cek[i][0] && cek[i][1]){
            if (cur[0] && cur[1]) i++;
            else{
                ok = 0;
                break;
            }
            continue;
        } else if (!cek[i][0] && !cek[i][1]){
            swap(cur[0], cur[1]);
            i++;
            continue;
        } else if (!cek[i][0] && cek[i][1]){
            if (cur[0] && cur[1]){
                if (cek[i + 1][0]){
                    ok = 0;
                    break;
                } else{
                    cur[0] = 1;
                    cur[1] = cek[i + 1][1]; 
                    i+=2;
                    continue;
                }
            } else if (cur[0]){
                ok = 0;
                break;
            } else{
                cur[0] = 1;
                cur[1] = 1;
            }
            i++;
            continue;
        } else{ // cek[i][0] && !cek[i][1]
            if (cur[0] && cur[1]){
                if (cek[i + 1][1]){
                    ok = 0;
                    break;
                } else{
                    cur[0] = cek[i + 1][0]; 
                    cur[1] = 1;
                    i+=2;
                    continue;
                }
            } else if (cur[1]){
                ok = 0;
                break;
            } else{
                cur[0] = 1;
                cur[1] = 1;
            }
            i++;
            continue;
        }
    }
    if (ok && cur[0] && cur[1]){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }

    for (int i=0;i<=mxpos;i++){
        cek[i][0] = cek[i][1] = 0;
    }
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