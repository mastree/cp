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

string s;
ll cnt[100010][13];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n=s.length();

    ll now=1;
    cnt[n][0]=1;
    for (int i=n-1;i>=0;i--){
        if (s[i]=='?'){
            for (ll j=0;j<10;j++){
                ll tm=j*now%13;
               
                for (ll k=0;k<13;k++){
                    cnt[i][(k+tm)%13]+=cnt[i+1][k];
                    cnt[i][(k+tm)%13]%=MOD;
                }
            }
        } else{
            ll tm=(ll)(s[i]-'0');
            tm=tm*now%13;
            for (ll k=0;k<13;k++){
                cnt[i][(k+tm)%13]+=cnt[i+1][k];
                cnt[i][(k+tm)%13]%=MOD;
            }
        }

        now=now*10%13;
    }

    cout << cnt[0][5] << el;

    return 0;
}