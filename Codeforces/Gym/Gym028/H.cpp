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
int n, k, m;

int ar[N];
int getid[N];
set<int> setdah;

void init(){
    setdah.clear();
}

void solve(){
    cin >> n >> k >> m;
    init();
    for (int i=1;i<=m;i++){
        cin >> ar[i];
        getid[ar[i]] = i;
        setdah.insert(ar[i]);
    }
    ar[m + 1] = n + 1;
    int butuh = k - 1;
    if ((n - m) % butuh != 0){
        cout << "NO" << el;
        return;
    }
    int side = butuh / 2;
    vector<int> vec;
    for (int i=1;i<=m + 1;i++){
        int temp = ar[i] - ar[i - 1] - 1;
        if (temp > 0){
            vec.pb(temp);
        }
    }
    int l = 0, md = 0, r = 0;
    for (auto x : vec){
        if (l + x >= (n - m) / 2){
            md = x;
            break;
        }
        l += x;
    }
    r = (n - m) - (l + md);
    while (md >= k){
        md -= k - 1;
    }
    int tot = l + md + r;
    if (l + md == (tot) / 2){
        l += md;
        md = 0;
        cout << "YES" << el;
        return;
    }
    int lkur = (tot) / 2 - l;
    int rkur = (tot) / 2 - r;
    while (md){
        if (l >= side){
            int ambil = min(rkur, side);
            md -= ambil;
            rkur -= ambil;
            r -= side - ambil;
            l -= side;
        } else if (r >= side){
            int ambil = min(lkur, side);
            md -= ambil;
            lkur -= ambil;
            l -= side - ambil;
            r -= side;
        } else break;
        if (lkur == 0 || rkur == 0){
            cout << "YES" << el;
            return;
        }
    }
    if (md){
        cout << "NO" << el;
    } else{
        cout << "YES" << el;
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