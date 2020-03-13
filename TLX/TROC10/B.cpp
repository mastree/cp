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

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n==0){
        cout << 1 << el;
        return 0;
    }
    if (n==1){
        cout << 0 << el;
        return 0;
    }
    if (n&1){
        cout << 4;
        for (int i=0;i<n/2;i++){
            cout << 8;
        }
        cout << el;
        return 0;
    }

    if (n==2){
        cout << 8 << el;
        return 0;
    }
    for (int i=0;i<n/2;i++){
        cout << 8;
    }
    cout << el;

    return 0;
}