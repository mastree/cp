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

const int N = 50;
const ll bound = 2e9 + 1;

ll w, m;
ll ar[N];
bool vis[N];
ll n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> m;
    ll mx = 1, cur;
    while (mx < bound){
        n++;
        mx *= w;
    }

    ll temp = m;
    bool bisa = 1;
    cur = mx;
    for (int i=n;i>=0;i--){
        ar[i] = temp / cur;
        temp %= cur;
        cur /= w;
    }

    cur = 1;
    for (int i=0;i<=n;i++){
        if (ar[i] == w){
            ar[i + 1]++;
            ar[i] = 0;
        }
        if (ar[i] > 1){
            if (ar[i] == w - 1){
                vis[i] = 1;
                ar[i] = 0;
                ar[i + 1]++;
            } else{
                bisa = 0;
                break;
            }
        }
    }

    for (int i=0;i<N;i++){
        if (ar[i] && vis[i]){
            bisa = 0;
        }
    }
    if (bisa){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}