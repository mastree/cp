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

const int N = 3e2 + 10;

int q;
int n, m;
int ar[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        unordered_map<int, int> cmap;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                int a;
                cin >> a;
                cmap[a]++;
            }
        }
        vector<int> od;
        vector<int> ev;
        for (auto x : cmap){
            int len = x.se;
            if (x.se & 1){
                od.pb(x.fi);
                len--;
            }
            for (int i=1;i<=len;i++){
                ev.pb(x.fi);
            }
        }
        int lenod = od.size();
        int lenev = ev.size();
        if (m & 1){
            if (lenod > n){
                cout << -1 << el;
                continue;
            } 
            if ((n - lenod) & 1){
                cout << -1 << el;
                continue;
            }
        }
        if ((m % 2 == 0) && lenod){
            cout << -1 << el;
            continue;
        }
        for (int i=i;i<=n;i++) fill(ar[i], ar[i] + m + 2, 0);
        if (m & 1){
            for (int i=1;i<=n;i++){
                if (lenod){
                    ar[i][(m + 1) / 2] = od[lenod - 1];
                    lenod--;
                } else{
                    ar[i][(m + 1) / 2] = ev[lenev - 1];
                    lenev--;
                }
            }
        }
        for (int i=1;i<=n;i++){
            int l = 1, r = m;
            while (l < r){
                ar[i][l] = ev[lenev - 1];
                ar[i][r] = ev[lenev - 2];
                lenev -= 2;
                l++;
                r--;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout << ar[i][j] << " ";
            }
            cout << el;
        }
    }

    return 0;
}