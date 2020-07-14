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

const int N = 1e5 + 10;

int n;
ll m, tot = 0;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        tot += a;
        ar[i] = a - b;
    }
    sort(ar + 1, ar + n + 1, greater<int>());
    if (tot <= m){
        cout << 0 << el;
        return 0;
    }
    for (int i=1;i<=n;i++){
        tot -= ar[i];
        if (tot <= m){
            cout << i << el;
            return 0;
        }    
    }
    cout << -1 << el;

    return 0;
}