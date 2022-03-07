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

const int N = 2e5 + 10;

int n, m;
ll ar[N];
ll ans[N];

ll pc[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    sort(ar + 1, ar + n + 1);
    for (int i=1;i<=m;i++){
        for (int j=i;j<=n;j+=m){
            pc[j] = ar[j];
            if (j>m){
                pc[j]+=pc[j-m];
            }
        }
    }

    // for (int i=1;i<=n;i++){
    //     cout << pc[i] << el;
    // }

    ll tot=0;
    for (int i=1;i<=m;i++){
        tot+=ar[i];
        ans[i]=tot;
        // cout << tot << " ";
    }

    int l = 1, r = m;
    for (int i=m+1;i<=n;i++){
        ll mk=(i+m-1)/m;
        tot+=pc[l];
        tot+=ar[i];
        // for (int j=l;j>=1;j-=m){
        //     tot+=ar[j];
        // }
        ans[i]=tot;
        l++;r++;
    }

    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}