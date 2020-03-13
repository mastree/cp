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

const int N = 1e6 + 8;

int n;
int ar[N];
vector <int> v;
unordered_map <int, int> getId;

ll bit[N], bit2[N], isi[N];
ll ans;

void upd(int pos, ll add){
    for (; pos<N; pos = pos + (pos & (-pos))) bit[pos] += add;
}

ll ask(int a){
    ll res = 0;
    for (; a>0; a = a - (a & (-a))){
        res += bit[a];
    }
    return res;
}

ll ask(int a, int b){
    return ask(b) - ask(a-1);
}

void upd2(int pos, ll add){
    for (; pos<N; pos = pos + (pos & (-pos))) bit2[pos] += add;
}

ll ask2(int a){
    ll res = 0;
    for (; a>0; a = a - (a & (-a))){
        res += bit2[a];
    }
    return res;
}

ll ask2(int a, int b){
    return ask2(b) - ask2(a-1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        v.pb(ar[i]);
    }
    sort(v.begin(), v.end());
    for (int i=0;i<n;i++){
        getId[v[i]] = i+1;
    }
    for (int i=1;i<=n;i++){
        ar[i]=getId[ar[i]];
    }

    for (int i=1;i<=n;i++){
        isi[ar[i]] = ask(ar[i], n);
        upd(ar[i], (ll)1);
    }

    for (int i=1;i<=n;i++){
        ans += ask2(ar[i], n);
        upd2(ar[i], isi[ar[i]]);
    }
    cout << ans << el;

    return 0;
}