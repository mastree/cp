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

const int N = 5;

int ar[N][N];

bool cek[102];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            cin >> ar[i][j];
        }
    }

    int n;
    cin >> n;
    while (n--){
        int a;
        cin >> a;
        cek[a] = 1;
    }

    bool yes = 0;
    for (int i=1;i<=3;i++){
        int cnt1 = 0, cnt2 = 0;
        for (int j=1;j<=3;j++){
            if (cek[ar[i][j]]) cnt1++;
            if (cek[ar[j][i]]) cnt2++;
        }
        if (cnt1 >= 3 || cnt2 >= 3) yes = 1;
    }
    if (yes){
        cout << "Yes" << el;
        return 0;
    }
    yes = 1;
    for (int i=1;i<=3;i++){
        if (!cek[ar[i][i]]) yes = 0;
    }
    if (yes){
        cout << "Yes" << el;
        return 0;
    }
    yes = 1;
    for (int i=1;i<=3;i++){
        if (!cek[ar[i][4 - i]]) yes = 0;
    }
    if (yes){
        cout << "Yes" << el;
        return 0;
    }
    cout << "No" << el;

    return 0;
}