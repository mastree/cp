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

int n,m;
bool cek[7][7];
vector <int> adl[8];
int ar[8] = {0,1,2,3,4,5,6,7};

void re_cek(){
    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
            cek[i][j]=0;
        }
    }
}

int sol(){
    int res=0;

    re_cek();
    for (int i=1;i<=7;i++){
        if (ar[i]==7) continue;

        for (auto x : adl[i]){
            if (ar[x]==7) continue;
            if (!cek[ar[x]][ar[i]]){
                res++;
                cek[ar[x]][ar[i]]=1;
                cek[ar[i]][ar[x]]=1;
            }
        }
    }

    int res1,tm=0;
    for (int i=1;i<=7;i++){
        if (ar[i]==7){
            for (int j=1;j<=6;j++){
                res1=0;
                for (auto x : adl[i]){
                    if (!cek[ar[x]][j]){
                        res1++;
                    }
                }
                tm=max(tm,res1);
            }
        }
    }

    next_permutation(ar+1,ar+8);
    return res+tm;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    if (n<7){
        cout << m << el;
        return 0;
    }

    int ans=0;
    for (int i=0;i<5040;i++){
        ans=max(ans,sol());
    }

    cout << ans << el;

    return 0;
}