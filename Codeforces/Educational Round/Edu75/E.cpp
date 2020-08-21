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

const int N = 200008;

int q, n;
pair<ll, ll> ar[N], ar2[N];
ll p[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        cin >> n;

        ll cnt[n+5];

        for (int i=0;i<n+5;i++) cnt[i]=0;

        for (int i=0;i<n;i++){
            cin >> ar[i].fi >> ar[i].se;
            // ar2[i].se=ar[i].fi;
            // ar2[i].fi=ar[i].se;
            cnt[ar[i].fi]++;
        }

        int last=0;

        sort(ar, ar + n);
        // sort(ar2, ar2 + n);
        ll need=0;
        for (ll i=0;i<n;i++){
            if (ar[i].fi>i && i==0){
                if (need<ar[i].fi-i) {
                    need=ar[i].fi-i;
                    last=ar[i].fi;
                }
            } else if (ar[i].fi>i && ar[i-1].fi!=ar[i].fi){
                if (need<ar[i].fi-i) {
                    need=ar[i].fi-i;
                    last=ar[i].fi;
                }
            }
        }

        for (int i=1;i<=n;i++){
            cnt[i]+=cnt[i-1];
            // if (cnt[i]<need){
            //     last=i;
            // }
        }
        //cout << last << el;

        ll plus=0;
        
        int len=0;
        vector <ll> vectm;
        for (int i=0;i<n;i++){
            if (ar[i].fi > last){
            //    cout << ar[i].se << " ";
                p[len]=ar[i].se;
                len++;
            }
            if (ar[i].fi==last) vectm.pb(ar[i].se);
        }

        sort(vectm.begin(), vectm.end());
        for (int i=0;i<vectm.size()-1;i++){
            p[len]=vectm[i];
            len++;
        }

        sort(p,p+len);


        ll tot=0, id=0;
        
        for (int i=1;i<=last;i++){
            ll kurang=i-cnt[i-1];
            if (kurang-plus>0){
                while (kurang-plus>0){
                    plus++;
                    tot+=p[id];
                    id++;
                }
            }
        }

        cout << tot << el;

    }

    return 0;
}