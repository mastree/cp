#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define el '\n'

using namespace std;

int n;
pll ar[7005]; // skills, value
unordered_map <ll,ll> cek, cnt;
ll cekar[7001],cntar[7001];
ll conv[7007];
bool take[7001];
vector <ll> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++) cin >> ar[i].fi;
    for (int i=0;i<n;i++) cin >> ar[i].se;
    for (int i=0;i<n;i++){
        if (cek[ar[i].fi]==0){
            v.pb(ar[i].fi);
        }
        cek[ar[i].fi]+=ar[i].se;
        cnt[ar[i].fi]++;
    }

    sort(v.begin(),v.end());
    int len=v.size();
    for (int i=0;i<len;i++){
        cekar[i]=cek[v[i]];
        cntar[i]=cnt[v[i]];
    }

    ll ans=0;
    for (int i=0;i<len;i++){
        if (cntar[i]>1){
            for (int j=0;j<i;j++){
                if ((v[i]|v[j])==v[i] && cntar[j]==1){
                    // ans+=cekar[j];
                    take[j]=1;
                }
            }
            // ans+=cekar[i];
            take[i]=1;
        }
    }

    for (int i=0;i<len;i++){
        if (take[i]) ans+=cekar[i];
    }

    cout << ans << el;


    return 0;
}