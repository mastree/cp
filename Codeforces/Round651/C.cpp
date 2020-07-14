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

const string win[2] = {"Ashishgup",  "FastestFinger"};

int q;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;

        if (n == 1){
            cout << win[1] << el;
            continue;
        }
        if (n & 1){
            cout << win[0] << el;
            continue;
        }
        int temp = n;
        int ev = 1;
        while (temp % 2 == 0){
            temp /= 2;
            ev *= 2;
        }
        int od = n / ev;
        // cout << ev << " " << od << el;
        if (od == 1){
            if (ev == 2){
                cout << win[0] << el;
            } else{
                cout << win[1] << el;
            }
            continue;
        }
        if (ev > 2){
            cout << win[0] << el;
            continue;
        }
        bool facod = 0;
        for (int i=3;i * i<=od;i+=2){
            if (od % i == 0){
                facod = 1;
                break;
            }
        }
        if (facod){
            cout << win[0] << el;
            continue;
        }
        cout << win[1] << el;
    }

    return 0;
}