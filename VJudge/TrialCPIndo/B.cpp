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

const int N = 3e5 + 10;

int n, q;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll tot = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tot += ar[i];
    }
    sort(ar + 1, ar + n + 1, greater<int>());
    cin >> q;
    while (q--){
        int a;
        cin >> a;
        cout << tot - ar[a] << el;
    }

    return 0;
}