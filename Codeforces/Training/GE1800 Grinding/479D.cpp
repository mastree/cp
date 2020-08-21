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

const int N = 1e5 + 10;

map <ll, int> cek;

ll n, l, x, y;
ll ar[N];

vector <ll> v;
bool ada[4];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> x >> y;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cek[ar[i]]++;
    }

    v.pb(x);
    v.pb(y);
    v.pb(x + y);
    v.pb(y - x);
    for (int i=1;i<=n;i++){
        int id = 0;
        for (auto x : v){
            if (cek[ar[i] + x]){
                ada[id] = 1;
            }
            id++;
        }
    }

    if (ada[0] && ada[1]){
        cout << 0 << el;
        return 0;
    }
    if (ada[0] || ada[1]){
        ll baru;
        if (ada[0]) baru = v[1];
        else baru = v[0];
        cout << 1 << el;
        cout << baru << el;
        return 0;
    }

    if (ada[2]){
        ll baru = v[0];
        cout << 1 << el;
        for (int i=1;i<=n;i++){
            if (cek[ar[i] + v[2]]){
                cout << ar[i] + baru << el;
                return 0;
            }
        }
    }

    if (ada[3]){
        ll baru = v[1];
        for (int i=1;i<=n;i++){
            if (cek[ar[i] + v[3]]){
                if (ar[i] + baru <= l){
                    cout << 1 << el;
                    cout << ar[i] + baru << el;
                    return 0;
                } else if (ar[i] - v[0] >= 0){
                    cout << 1 << el;
                    cout << ar[i] - v[0] << el;
                    return 0;
                }
            }
        }
    }

    cout << 2 << el;
    cout << v[0] << " " << v[1] << el; 

    return 0;
}