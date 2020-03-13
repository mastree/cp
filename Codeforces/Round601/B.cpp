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

const int N = 1e3 + 10;

int q;
int n, m;
pii ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        cin >> n >> m;

        int ans=0;
        for (int i=1;i<=n;i++){
            cin >> ar[i].fi;
            ar[i].se = i;
        }

        if (m<n || n==2){
            cout << -1 << el;
            continue;
        } 

        sort(ar+1, ar+n+1);
        for (int i=1;i<=n;i++){
            ans+=ar[i].fi;
        }
        ans*=2;
        m-=n;
        for (int i=0;i<m;i++){
            ans+=(ar[1].fi+ar[2].fi);
        }
        cout << ans << el;
        for (int i=1;i<=n;i++){
            cout << ar[i].se << " " << ar[(i%n) + 1].se << el;
        }
        for (int i=0;i<m;i++){
            cout << ar[1].se << " " << ar[2].se << el;
        }
    }

    return 0;
}