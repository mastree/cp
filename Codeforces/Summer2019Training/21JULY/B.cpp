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
ll ans;
ll cnto,cntw,now;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    int n=s.length();
    for (int i=1;i<n;i++){
        if (s[i]==s[i-1] && s[i]=='v'){
            ans+=now;
            cntw++;
        } else if (s[i]=='o'){
            now+=cntw;
        }
     //   cerr << i << " " << cnto << " " << cntw << " " << ans << el;
    }

    cout << ans << el;

    return 0;
}