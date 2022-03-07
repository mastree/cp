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

const int N = 1e5 + 7;
const int INF = 2e9;

int n;
int ar[N];
int ans = -1;
queue <pii> x;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ans=max(ar[i], ans);
    }
    x.push(mp(0, ans));

    for (int i=30;i>=0;i--){
        int curxor, curans;
        int dig = (1 << i);
        queue <pii> baru;
        // cout << ans << " " << x.front().fi << ":" << x.front().se << el;
        // cout << x.front().fi << el;
        while (!x.empty()){
            auto temp = x.front();
            // if (i<3) cout << temp.fi << " " << temp.se << el;
            x.pop();
            curxor = (temp.fi ^ dig);
            ans = temp.se;
            curans = -1;
            int cnt = 0;
            for (int id=1;id<=n;id++){
                if (curans < (ar[id] ^ curxor)){
                    curans = (ar[id] ^ curxor);
                    cnt = 1;
                } else if (curans == (ar[id] ^ curxor)){
                    cnt++;
                }
            }
            // if (((ans & dig) & (curans & dig))){    
                baru.push(temp);
                baru.push(mp(curxor, curans));
            //     continue;
            // } 
            // if (ans>curans){
            //     baru.push(mp(curxor, curans));
            //     // x = curxor;
            //     // ans = curans;
            // } else{
            //     baru.push(temp);
            // }

        }
        // cout << baru.size() << el;
        pii a1 = mp(-1, INF), a0 = mp(-1, INF);
        vector <pii> v;
        while (!baru.empty()){
            auto temp = baru.front();
            if (temp.fi & dig){
                if (a1.se > temp.se){
                    a1.se = temp.se;
                }
            } else{
                if (a0.se > temp.se){
                    a0.se = temp.se;
                }
            }
            v.pb(temp);
            baru.pop();
        }
        for (auto wah : v){
            if (wah.fi & dig){
                if ((wah.se&dig) == (a1.se&dig)){
                    x.push(wah);
                }
            } else{
                if (wah.se == a0.se){
                    x.push(wah);
                }
            }
        }
    }
    while (!x.empty()){
        ans = min(x.front().se, ans);
        x.pop();
    }
    cout << ans << el;

    return 0;
}