#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    int cnt[k+5];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans=0;
    for (int i=1;i<=k;i++) {
        if (cnt[i]%2==1) ans++;
    }
    if (ans==0) cout << n << endl;
    else {
        cout << n-ans/2 << endl;
    }
    return 0;
}    