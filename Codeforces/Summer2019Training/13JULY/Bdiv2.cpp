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

int cnt[10][3];
string cek="mps";

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s[3];
    for (int i=0;i<3;i++) cin >> s[i];

    for (int i=0;i<3;i++){
        int id=-1;
        for (int j=0;j<3;j++){
            if (cek[j]==s[i][1]){
                id=j;
                break;
            }
        }

        cnt[s[i][0]-'0'][id]++;
    }

    int mk=-1;
    for (int i=0;i<10;i++){
        for (int j=0;j<3;j++){
            mk=max(mk,cnt[i][j]);
        }
    }

    for (int j=0;j<3;j++){
        
        for (int i=1;i+2<10;i++){int cnt1=0;
            for (int plus=0;plus<3;plus++){
                if (cnt[i+plus][j]>0) cnt1++;
            }mk=max(mk,cnt1);
        }
        
    }

    cout << 3-mk << el; 

    return 0;
}