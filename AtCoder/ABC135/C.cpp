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

    ll mon[n+1],ar[n+1];
    for (int i=0;i<n+1;i++) cin >> mon[i];
    for (int i=0;i<n;i++) cin >> ar[i];
    ar[n]=0;

    ll tot=0,bef=0;
    for (int i=0;i<n+1;i++){
        tot+=min(mon[i],bef);
        mon[i]=max(mon[i]-bef,(ll)0);

        tot+=min(mon[i],ar[i]);
        ar[i]=max(ar[i]-mon[i],(ll)0);
        bef=ar[i];
    }

    cout << tot << el;

    return 0;
}