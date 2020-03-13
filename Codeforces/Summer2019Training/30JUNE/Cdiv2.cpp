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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    vector <pii> srt,un;
    for (int i=0;i<m;i++){
        int tm,a,b;
        cin >> tm >> a >> b;
        if (tm==1){
            srt.pb(mp(a,b));
        } else {
            un.pb(mp(a,b));
        }
    }

    int ar[n+1];

    int slen=srt.size(),ulen=un.size();
    sort(srt.begin(),srt.end());
  //  sort(un.begin(),un.end());
    
    vector <pii> v1;
    int cm=-1,len1=0;
    for (int i=0;i<slen;i++){
        if (srt[i].fi>cm){
            v1.pb(srt[i]);
            cm=srt[i].se;
            len1++;
        } else{
            cm=max(cm,srt[i].se);
            v1[len1-1].se=cm;
        }
    }

    int cur=100000000;
    for (int i=0;i<n+1;i++){
        ar[i]=cur;
        cur-=1002;
    }

    for (auto x : v1){
        int sek=ar[x.fi];
        for (int i=x.fi;i<=x.se;i++){
            ar[i]=sek;
            sek+=1000;
        }
    }

    bool bisa=1;
    for (auto x : un){
        bool asc=1;
        for (int i=x.fi;i<x.se;i++){
            if (ar[i]>ar[i+1]) asc=0;
        }
        if (asc) bisa=0;
    }

    if (bisa){
        cout << "YES" << el;
        for (int i=1;i<=n;i++){
            cout << ar[i] << " ";
        }
        cout << el;
    } else {
        cout << "NO" << el;
    }

    return 0;
}