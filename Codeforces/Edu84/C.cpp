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

const int N = 210;

int n, m, k;

pii start[N], fin[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=k;i++){
        cin >> start[i].fi >> start[i].se;
    }
    for (int i=1;i<=k;i++){
        cin >> fin[i].fi >> fin[i].se;
    }

    cout << n + m - 2 + n * m << el;
    for (int i=1;i<n;i++){
        cout << 'U';
    }
    for (int j=1;j<m;j++){
        cout << 'L';
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<m;j++){
            if (i & 1) cout << 'R';
            else cout << 'L';
        }
        cout << 'D';
    }
    cout << el;

    return 0;
}