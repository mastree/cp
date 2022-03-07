#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 7;

int q;
int n, ar[N];
// pii stree[4*N];

// void constree(int v, int tl, int tr){
//     if (tl == tr){
//         stree[v] = mp(ar[tl], ar[tl]);
//         return;
//     }

//     int vl = v * 2 + 1;
//     int mid = (tl + tr) / 2;
//     constree(vl, tl, mid);
//     constree(vl + 1, mid + 1, tr);
//     stree[v] = mp(max(stree[vl].fi, stree[vl + 1].fi), min(stree[vl].se, stree[vl + 1].se));
// }

// pii ask(int v, int tl, int tr, int l, int r){
//     if (l<=tl && tr<=r){
//         return stree[v];
//     } 
//     if (tr<l || tl>r){
//         return mp(-1, MOD);
//     }

//     int vl - v * 2 + 1;
//     int mid == (tl + tr) / 2;
//     pii tm1 = ask(vl, tl, mid, l, r);
//     pii tm2 = ask(vl + 1, mid + 1, tr, l, r);

//     return mp(max(tm1.fi, tm2.fi), min(tm1.se, tm2.se));
// }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }

        int l=1, r=1;
        int kiri=ar[1];
        bool bisa = 0;
        // kiri++;
        for (int i=2;i<=n;i++){
            r = i;
            if (kiri >= ar[i]){
                kiri = ar[i];
                l = i;
            } else{
                kiri++;
            }
            // cout << l << " " << r << el;

            if (kiri<ar[i]){
                bisa = 1;
                break;
            }
        }

        if (bisa){
            cout << "YES" << el;
            cout << l << " " << r << el;
            continue;
        } 

        l = 1; r = 1;
        kiri = ar[1];
        // kiri--;
        for (int i=2;i<=n;i++){
            r = i;
            if (kiri <= ar[i]){
                kiri = ar[i];
                l = i;
            } else{
                kiri--;
            }
            // cout << l << " " << r << el;

            if (kiri>ar[i]){
                bisa = 1;
                break;
            }
        }
        
        if (bisa){
            cout << "YES" << el;
            cout << l << " " << r << el;
            continue;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}