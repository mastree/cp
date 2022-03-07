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

int n;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    ll ans = 0;
    int l = 1, r = n;
    while (l < r){
        ll temp = ar[l] + ar[r];
        ans += temp * temp;
        l++;
        r--;
    }
    cout << ans << el;

    return 0;
}