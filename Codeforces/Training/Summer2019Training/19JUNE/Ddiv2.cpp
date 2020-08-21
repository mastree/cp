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

    int n;
    cin >> n;

    pair <int,int> ar[n+1];
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
        ar[i].se=i;
    }

    sort(ar+1,ar+n+1);
    int del[n+1]; // del[i]=ar[i+1]-ar[i];
    map <int,int> cek;
    
    for (int i=1;i<n;i++){
        del[i]=ar[i+1].fi-ar[i].fi;
        cek[del[i]]++;
    }

    int sz=0;
    for (auto x : cek) sz++;

    if (sz>3){
        cout << -1 << el;
        return 0;
    }

    for (int i=1;i<=n;i++){
        bool bisa=0;
        if (i==1){
            cek[del[i]]--;
            int cnt=0;
            for (auto x : cek){
                if (x.se>0) cnt++;
            }

            if (cnt<=1) bisa=1;
            cek[del[i]]++;

        } else if (i==n){
            cek[del[i-1]]--;
            int cnt=0;
            for (auto x : cek){
                if (x.se>0) cnt++;
            }

            if (cnt<=1) bisa=1;
        } else{
            cek[del[i]]--;
            cek[del[i-1]]--;

            int cnt=0,a;
            for (auto x : cek){
                if (x.se>0){
                    cnt++;
                    a=x.fi;
                }
            }// cerr << cnt <<" " << a << el;

            if (cnt<=1 && (del[i-1]+del[i]==a)) bisa=1; 
            cek[del[i]]++;
            cek[del[i-1]]++;

        }

    //    for (auto x : cek) cerr << x.se << " "; cerr << el;

        if (bisa){
            cout << ar[i].se << el;
            return 0;
        }
    }
    cout << -1 << el;

    return 0;
}