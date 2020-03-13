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

int q;

void tulis(int a){
    int len = 0;
    int tm = a;
    while (a){
        a/=10;
        len++;
    }

    for (int i=0;i<4-len;i++){
        cout << 0;
    }
    if (tm!=0) cout << tm;
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int n;
        map <int, int> cek;
        vector <int> v, vans;
        cin >> n;

        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            v.pb(a);
            cek[a]++;
        }

        int ans=0;
        for (auto x : v){
            int tm = x;
            int lastdig = x%10;

            if (cek[tm]>1)
                while (cek[tm]>=1){
                    lastdig = (lastdig+1) % 10;
                    tm/=10;
                    tm*=10;
                    tm+=lastdig;
                }

            if (cek[x]>1){
                ans++;
                cek[x]--;
                cek[tm]++;
                vans.pb(tm);
            } else{
                vans.pb(x);
            }
        }

        cout << ans << el;
        for (auto x : vans){
            tulis(x);
        }
    }

    return 0;
}