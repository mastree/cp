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

ll n,m,q;
ll cnt[500001];
pair<ll,ll> query[500001];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    
    for (int i=0;i<n;i++){
        int tm;
        cin >> tm;
        cnt[tm]++;
    }
    ll maks=0;
    for (int i=0;i<m;i++) maks=max(maks,cnt[i]);
    ll kurang=0;
    for (int i=0;i<m;i++) kurang+=maks-cnt[i];

    ll ada[maks+2], under_cnt[maks+2];
    for (int i=0;i<maks+2;i++){
        ada[i]=0;
        under_cnt[i]=0;
    }
    for (int i=0;i<m;i++) ada[cnt[i]]++;
    
    for (int i=1;i<maks+1;i++){
        under_cnt[i]=under_cnt[i-1]+under_cnt[i-1]+cnt[i-1];
    }
    

    for (int i=1;i<=q;i++){
        cin >> query[i].fi;
        query[i].se=i;
    }
    sort(query,query+q);

    

    return 0;
}