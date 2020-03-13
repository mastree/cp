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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        int x,y;
        cin >> x >> y;

        if (x==1){
            if (y==1){
                cout << "YES" << el;
            } else{
                cout << "NO" << el;
            }
        } else if (x==2 || x==3){
            if (y<=3){
                cout << "YES" << el;
            } else{
                cout << "NO" << el;
            }
        } else{
            cout << "YES" << el;
        }
    }

    return 0;
}