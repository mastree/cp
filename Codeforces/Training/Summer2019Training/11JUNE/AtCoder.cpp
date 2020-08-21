#include <bits/stdc++.h>
#include <string>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const string c="ACGT";

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map <string,ll> dp[n+1];
  //  string c="ACGT";

    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            string s="";
            s.pb(c[i]);
            s.pb(c[j]);
            dp[2][s]++;
        }
    }

    for (int id=3;id<=n;id++){
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                for (int k=0;k<4;k++){
                    if (i==0){
                        if (j==1 && k==2) continue;
                        if (j==2 && k==1) continue;
                    } else if (i==2){
                        if (j==0 && k==1) continue;
                    }


                    string st1="",st2="";
                    st1.pb(c[i]);st1.pb(c[j]);
                    st2.pb(c[j]);st2.pb(c[k]);
                    dp[id][st2]+=dp[id-1][st1];
                    dp[id][st2]%=MOD;
                }
            }
        }
    }

    ll tot=0;
    for (auto x : dp[n]){
        tot=(tot+x.se)%MOD;
    }

    cout << tot << el;

    return 0;
}