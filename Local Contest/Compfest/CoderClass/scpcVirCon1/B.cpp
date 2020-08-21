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

ll md;
string con="ABCDEF";
bool lead;

ll fpow(ll a,ll b){
    if (b==0) return 1;
    if (b==1) return a;

    ll tm=fpow(a,b/2);
    if (b&1) return (tm*tm%md)*a%md;
    return tm*tm%md;
}

bool ada(ll a,ll b){
    ll tm=1;
    for (ll i=0;i<b;i++){
        tm*=a;
        if (tm>md) return 1;
    }
    tm=tm-1;
    if (tm*tm>md) return 1;
    return 0;
}

void ans(ll a,ll b,ll d){
    vector <char> res;

    if (lead){
        for (int i=0;i<d;i++){
            ll tm=a%b;
            if (tm<10){
                res.pb(char((int)tm+'0'));
            } else{
                res.pb(con[tm-10]);
            }

            a/=b;
        }
    } else{
        while (a>0){
            ll tm=a%b;
            if (tm<10){
                res.pb(char((int)tm+'0'));
            } else{
                res.pb(con[tm-10]);
            }

            a/=b;
        }
    }

    int len=res.size();
    for (int i=len-1;i>=0;i--){
        cout << res[i];
    }

    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while (q--){
        md=1;
        ll n,b,d;
        cin >> n >> b >> d;

        for (ll i=0;i<d;i++){
            md*=b;
        }
    //    cerr << md << el;

        ll res=fpow(b,n/2);
        res=(res-1)%md;
        res=res*res%md;
        lead=ada(b,n/2);

        ans(res,b,d);
    }

    return 0;
}