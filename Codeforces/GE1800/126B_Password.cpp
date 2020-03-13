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
int n;
vector <int> pref;

vector<int> cons_prefix(){
    int l=0,r=1;
    vector <int> pref(n,0);

    while (r<n){
        while (l!=0 && s[l]!=s[r]) l=pref[l-1];
        if (s[l]==s[r]){
            l++;
            pref[r]=l;
        } else{
            pref[r]=l;
        }
        r++;
    }

    return pref;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n=s.length();
    pref = cons_prefix();
    //for (auto x : pref) cout << x << " ";cout << el;

    // int kur=0;
    // for (int i=0;i<n;i++){
    //     int sisa=n-i-1;
    //     if (sisa==pref[i]){
    //         kur=sisa;
    //     }

    //     if (pref[i]>kur) pref[i]-=kur;
    // }

   // for (auto x : pref) cout << x << " ";cout << el;

    int tm=pref[n-1],ans=0;
    for (int i=0;i<n-1;i++){
        if (pref[i]==tm) ans=tm;
    }

    if ((pref[n-1]-1)>=0) ans=max(ans,pref[pref[n-1]-1]);
    if (ans){
        for (int i=0;i<ans;i++){
            cout << s[i];
        }cout << el;
    }
    else cout << "Just a legend" << el;

    return 0;
}