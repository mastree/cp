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

ll n,k,cnt[50],best[50],pcbest[50];
ll pow2[50];

ll lg(ll a){
    if (a==0) return -1;
    return log2(a);
}

ll sol(ll a){
    if (a==0) return 0;
    ll tm=lg(a),res=best[tm];

    a-=pow2[tm];
    for (ll i=lg(a)+1;i<tm;i++) res+=cnt[i];

    return max(pcbest[tm-1]+cnt[tm],res+sol(a));

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i=0;i<50;i++){
        cnt[i]=0;
        pow2[i]=((ll)1 << i);
    }

    cin >> n >> k;
    for (ll i=0;i<n;i++){
        ll tm;
        cin >> tm;
        for (ll j=0;j<50;j++){
        //    cerr << (tm&pow2[j]) << " ";
            if ((tm&pow2[j])>0) cnt[j]++;
        //    cerr << cnt[j] << " ";
        }
    //    cerr << el;
    }

    for (ll i=0;i<50;i++){
    //    cerr << cnt[i] << " ";
        best[i]=max(cnt[i],n-cnt[i])*pow2[i];
        cnt[i]*=pow2[i];
    }
    pcbest[0]=best[0];
    for (ll i=1;i<50;i++){
        pcbest[i]=pcbest[i-1]+best[i];
    }

    ll tot=0;
    for (ll i=lg(k)+1;i<50;i++) tot+=cnt[i];
    cout << tot+sol(k) << el;

    return 0;
}