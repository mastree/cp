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

int n;
ll ar[N];

ll ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }  

    ll cur = 0;
    ans[1] = ar[1];
    cur = max(cur, ans[1]);
    for (int i=2;i<=n;i++){
        ans[i] = ar[i] + cur;

        cur = max(cur, ans[i]);
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}