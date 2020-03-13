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

    int n,m,k;
    cin >> n >> m >> k;

    int pw[n+1];
    for (int i=1;i<=n;i++){
        cin >> pw[i];
    }

    int gr[n+1],mx[m+1];
    for (int i=0;i<m+1;i++) mx[i]=0;
    for (int i=1;i<=n;i++){
        cin >> gr[i];
        mx[gr[i]]=max(mx[gr[i]],pw[i]);
    } 

    int ans=0;
    for (int i=0;i<k;i++){
        int tm;
        cin >> tm;
       // cerr << pw[tm] << " " << mx[gr[tm]] << el;
        if (pw[tm]<mx[gr[tm]]) ans++;
    }

    cout << ans << el;

    return 0;
}