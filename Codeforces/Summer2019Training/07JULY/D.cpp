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

    int n,k,m,t;
    cin >> n >> k >> m >> t;

    pii ar[t];
    for (int i=0;i<t;i++){
        cin >> ar[i].fi >> ar[i].se;
    }

    int a=k-1,b=n-k;
    for (int i=0;i<t;i++){
        if (ar[i].fi==0){
            if (ar[i].se<=a){
                a-=ar[i].se;
                n-=ar[i].se;
            } else{
                int tm=n-ar[i].se;
                b-=tm;
                n-=tm;
            }
        } else{
            if (ar[i].se<=a+1){
                a++;
                n++;
            } else{
                b++;
                n++;
            }
        }

        cout << n << " " << a+1 << el;
    }

    return 0;
}