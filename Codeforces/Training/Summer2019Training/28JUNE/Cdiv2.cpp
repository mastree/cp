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

string a,b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    int alen=a.length(),blen=b.length();
    ll ar1[alen],ar2[blen];
    for (int i=0;i<alen;i++){
        ar1[i]=(ll)(a[i]-'0');
    }

    for (int i=0;i<blen;i++){
        ar2[i]=(ll)(b[i]-'0');
    }

    int del=0;
    for (int i=0;i<blen-1;i++){
        if (ar2[i]!=ar2[i+1]) del++;
    }
 //   cerr << del << el;
    del%=2;
    int hit[alen-blen+1];
    hit[0]=0;
    for (int i=0;i<blen;i++){
        hit[0]+=(ar1[i]!=ar2[i]);
    }
    hit[0]%=2;
    //cerr << hit[0] << " ";
    for (int i=1;i<alen-blen+1;i++){
        hit[i]=hit[i-1]+del;
        hit[i]+=(ar1[i+blen-1]!=ar2[blen-1]);
        hit[i]-=(ar1[i-1]!=ar2[0]);
        hit[i]%=2;
    //    cerr << hit[i] << " ";
    }
    //cerr << el;

    int ans=0;
    for (int i=0;i<alen-blen+1;i++){
        ans+=(hit[i]==0);
    }

    cout << ans << el;

    return 0;
}