#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll N = 1e16 + 10;

int q;
ll n;

set<int> setdah;
int mx = 0, mn = 100000;
int befb;

void cari(int id){
    int a, b, c;
    for (a=1;;a++){
        if (setdah.find(a) == setdah.end()) break;
    }
    setdah.insert(a);
    for (b=a + 1;;b++){
        if (setdah.find(b) == setdah.end() && setdah.find((a ^ b)) == setdah.end()) break;
    }
    setdah.insert(b);
    c = (a ^ b);
    setdah.insert(c);
    bitset<10> temp(b);
    cout << "b = (" << temp << ") ||||" << a << " " << b << " " << c << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=1;i<257;i++){
        cari(i);
    }

    // cin >> q;
    // while (q--){
    //     cin >> n;

    // }

    return 0;
}