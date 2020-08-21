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

map <int,int> cnt;
string ans[2]={"sjfnb","cslnb"};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ar[n];
    ll tot=0;
    for(int i=0;i<n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
        tot+=(ll)ar[i];
    }

    if (n==1){
        cout << ans[(ar[0]+1)%2] << el;
        return 0;
    }

    if (cnt[0]>=2){
        cout << ans[1] << el;
        return 0;
    }

    int c2=0;
    for (auto x : cnt){
        if (x.se>2){
            cout << ans[1] << el;
            return 0;
        } 

        if (x.se==2){
            c2++;
            if (cnt[x.fi-1]>0 || c2>1){
                cout << ans[1] << el;
                return 0;
            }
        }

    }

    
    ll tm=(ll)(n-1)*(ll)n/2;
  //  cerr << tot << " " << tm << el;
    tot-=tm;
  //  cerr << tot << el;
    cout << ans[(tot+1)%2] << el;

    return 0;
}