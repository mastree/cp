#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

ll n, d, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> d;
    if (k>=n){
        for (int i=1;i<=d;i++){
            for (int j=1;j<=n;j++){
                cout << j << " ";
            }
            cout << el;
        }
        return 0;
    } 

    if (k == 1){
        if (n == 1){
            for (int i=1;i<=d;i++){
                cout << 1 << el;
            }
            return 0;
        } else{
            cout << -1 << el;
            return 0;
        }
    }

    ll butuh = 0;
    ll cur = 1;
    while (cur < n){
        butuh++;
        cur *= k;
    }

    if (butuh > d){
        cout << -1 << el;
        return 0;
    }

    ll del = 1;
    ll day;
    for (day=1;day<=butuh;day++){
        cur = 0;
        for (int i=0;i<n;i++){
            if (i % del == 0) cur = (cur % k + 1);
            cout << cur << " ";
        }
        cout << el;
        del *= k;
    }

    for (day;day<=d;day++){
        for (int i=1;i<=n;i++){
            cout << 1 << " ";
        }
        cout << el;
    }

    return 0;
}