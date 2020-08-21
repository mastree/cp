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

int n,edge;
bool sieve[1000006];
int cnt[1007];
bool cek[1007][1007];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve[1]=1;
    for (int i=2;i<1001;i++){
        if (sieve[i]) continue;
        for (int j=i*i;j<1000001;j+=i){
            sieve[j]=1;
        }
    }

    cin >> n;
    edge=n;
    for (int i=1;i<=n;i++){
        cnt[i]=2;
    }

  //  int id=1;
    while (sieve[edge]){
        edge++;
    }

    

    cout << edge << el;
    vector <pii> ans;

    for (int i=1;i<=n;i++){
        int tm=i+1;
        if (tm>n) tm=1;
        cek[i][tm]=1;cek[tm][i]=1;
        ans.pb(mp(i,tm));
    }
    
    edge-=n;
    for (int i=1;i<=n;i++){
        if (edge==0) break;
        for (int j=1;j<=n;j++){
            if (cnt[i]>2) break;
            if (i==j) continue;

            if (cnt[j]==2 && !cek[i][j]){
                cek[i][j]=1;cek[j][i]=1;
                cnt[i]++;
                cnt[j]++;
                ans.pb(mp(i,j));
                edge--;
                break;
            } 
        }
    }

    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}