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
const int INF = 1e9;

int tc;
int n, q;
int ar[N];
int le[N], ri[N];
map<int, int> cekle, cekri;

// int t[2][4 * N];


// void build(int v, int tl, int tr){
//     if (tl == tr){
//         t[0][v] = le[tl] + tl; // le
//         t[1][v] = ri[tl] + (n - tl); // ri 
//     }
//     int tm = (tl + tr) / 2;
//     build(v * 2, tl, tm);
//     build(v * 2 + 1, tm + 1, tr);
// }


int calc(int s, int k){
    int l, r;
    l = s - 1;
    r = s;
    if (k == 1) return s;
    if (k == 2){
        if (ar[l] < ar[r]) return l;
        return r + 1;
    }
    k -= 2;
    

    return 0;
}

void init(){
    // fill(t[0], t[0] + 4 * n, 0);
    // fill(t[1], t[1] + 4 * n, 0);

    pii art[n + 2];
    set<int> setdah;
    setdah.insert(0);
    setdah.insert(n);
    for (int i=1;i<n;i++){
        art[i] = mp(ar[i], i);
        setdah.insert(i);
    }
    sort(art + 1, art + n);
    for (int i=1;i<n;i++){
        int val = art[i].fi;
        int pos = art[i].se;

        auto ita = setdah.lower_bound(pos);
        auto itb = ita;
        ita--;
        itb++;
        le[pos] = pos - *ita - 1;
        ri[pos] = *itb - pos - 1;
        setdah.erase(pos);
    }
    for (int i=1;i<n;i++){
        cekle[le[i] + i] = i;
    }
    for (int i=n - 1;i>=1;i--){
        cekri[ri[i] + (n - i)] = i;
    }
}

void solve(){
    cin >> n >> q;
    ar[0] = ar[n] = INF;
    for (int i=1;i<n;i++){
        cin >> ar[i];
    }
    init();
    while (q--){
        int s, k;
        cin >> s >> k;

        cout << calc(s, k) << " ";
    }

    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int cas=1;cas<=tc;cas++){
        cout << "Case #" << cas << ": ";
        solve();
    }

    return 0;
}