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

    ll n,m,k;
    cin >> n >> k >> m;

    ll ar[k];
    for (int i=0;i<k;i++) cin >> ar[i];
    sort(ar,ar+k);

    ll upb=0,cnt=0,temp=0,mn=0;

    for (int i=0;i<k;i++){ 
        mn+=temp;
        temp=0;
        upb=(ar[i]-mn)-((ar[i]-mn)%m);
        if (ar[i]-mn>upb) upb+=m;

        cnt++;
        while ((ar[i]-mn)<=upb){
            temp++;
            i++;
        }
        i--;
    }  

    cout << cnt << el;

    return 0;
}