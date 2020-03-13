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

int q;
ll n,s;
ll mid;
pair<ll,ll> v[200010];

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if (a.se<mid){
        return 1;
    } 

    if (b.se<mid){
        return 0;
    }

    return a.fi<b.fi;
}

// bool comp(ll a, ll b){
//     return a<b;
// }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        cin >> n >> s;

        ll mxr=0, sisa=s;
        for (int i=0;i<n;i++){
            ll a, b;
            cin >> a >> b;
            v[i]=mp(a,b);
            sisa-=a;
            mxr=max(mxr,b);
        }

        ll len=n;
        sort(v, v+n);

        ll low=v[len/2].fi, high=mxr;

        while (low<high){
            mid=(low+high+1)/2;

            vector <ll> tes;
            for (int i=0;i<n;i++){
                if (v[i].se>=mid) tes.pb(v[i].fi);
            }
        //    sort(v, v+n, cmp);
            ll tlen=tes.size();
            if (tlen<=len/2){
                high=mid-1;
                continue;
            }
            ll tmid=tlen-len/2-1;
            sort(tes.begin(), tes.end());
            ll tot=0;
            for (int i=tmid;i<tlen;i++){
                if (tes[i]<mid) tot+=mid-tes[i];
            }

            if (tot>sisa){
                high=mid-1;
            } else{
                low=mid;
            }
        }

        cout << low << el;
    }

    return 0;
}