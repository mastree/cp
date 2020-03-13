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

int n;
pii ar[100];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
//    map <pii,bool> cek;
    map <pii,int> del;
    for (int i=0;i<n;i++){
        cin >> ar[i].fi >> ar[i].se;
 //       cek[mp(ar[i].fi,ar[i].se)]=1;
    }


    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (i==j) continue;
            pii tm;
            tm.fi=ar[i].fi-ar[j].fi;
            tm.se=ar[i].se-ar[j].se;
            del[tm]++;
            del[mp(-tm.fi,-tm.se)]++;
        }
    }

    int res=0;
    for (auto delta : del){
        res=max(res,delta.se);
    }

    cout << n-res << el;

    return 0;
}