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
int ar[N];
ll pc[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int n;
        cin >> n;
        n*=2;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }

        map <int, int> le, ri;
        le[0] = 0;
        for (int i=1;i<=n/2;i++){
            int tm;
            if (ar[i]==1) tm=1;
            else tm=-1;
            pc[i] = pc[i-1] + tm;
            le[pc[i]] = i;
        }

        pc[n+1] = 0;
        ri[0] = n+1;    
        for (int i=n;i>n/2;i--){
            int tm;
            if (ar[i]==1) tm=1;
            else tm=-1;
            pc[i] = pc[i+1] + tm;
            // cout << pc[i] << "+" << tm << el;
            ri[pc[i]] = i;
            // cout << pc[i] << " => " << i << el; 
        }
        // cout << le[0] << " " << ri[0] << el;

        int ans=MOD;
        for (auto x : le){
            int tar = -x.fi;
            int l = x.se, r;
            if (ri.count(tar)){
                r = ri[tar];
                ans = min(ans, r-l-1);
            }
            // cout << l << " " << r << el;
        }

        cout << ans << el;
    }

    return 0;
}