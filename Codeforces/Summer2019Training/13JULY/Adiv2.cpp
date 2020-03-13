#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

// 1,3,2,0

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;

    int rem=x%4;

    if (rem==1){
        cout << 0 << " A" << el;
        return 0;
    } 

    if (rem==2){
        cout << 1 << " B" << el;
        return 0;
    }

    if (rem==3){
        cout << 2 << " A" << el;
        return 0;
    }

    cout << 1 << " A" << el;

    return 0;
}