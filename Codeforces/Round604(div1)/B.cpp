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

int ar[4];
vector <int> v1, v2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<4;i++){
        cin >> ar[i];
    }

    if (ar[1]<ar[0] || ar[2]<ar[3]){
        if (ar[1]<ar[0] && ar[2]==0 && ar[3]==0){
            if (ar[0]-ar[1]==1){
                cout << "YES" << el;
                while (ar[1]){
                    cout << "0 1 ";
                    ar[1]--;
                }
                cout << "0" << el;
                return 0;
            }
        }
        else if (ar[2]<ar[3] && ar[0]==0 && ar[1]==0){
            if (ar[3]-ar[2]==1){
                cout << "YES" << el;
                while (ar[2]){
                    cout << "3 2 ";
                    ar[2]--;
                }
                cout << "3" << el;
                return 0;
            }
        }
        cout << "NO" << el;
        return 0;
    }

    v1.pb(-1);
    v2.pb(-1);

    while (ar[0]!=0 && ar[1]!=0){
        v1.pb(0);
        ar[0]--;
        v1.pb(1);
        ar[1]--;
    }

    while (ar[2]!=0 && ar[3]!=0){
        v2.pb(3);
        ar[3]--;
        v2.pb(2);
        ar[2]--;
    }

    if (abs(ar[1]-ar[2])>=2){
        cout << "NO" << el;
        return 0;
    }
    if (ar[1]>ar[2]){
        v1[0]=1;
        ar[1]--;
    }
    else if (ar[2]>ar[1]){
        v2[0]=2;
        ar[2]--;
    }

    for (;ar[1];ar[1]--){
        v1.pb(2);
        v1.pb(1);
    }
    reverse(v2.begin(), v2.end());
    cout << "YES" << el;
    for (auto x : v1){
        if (x==-1) continue;
        cout << x << " ";
    }
    for (auto x : v2){
        if (x==-1) continue;
        cout << x << " ";
    }
    cout << el;

    return 0;
}