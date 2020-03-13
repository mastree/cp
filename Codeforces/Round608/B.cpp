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

const int N = 210;

int n;
string s;
vector <int> ans;
int w, b, ar[N];

void cek(){
    for (int i=0;i<n;i++){
        cout << ar[i] << " ";
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i=0;i<n;i++){
        ar[i]=(s[i]=='W');
    }

    for (int i=0;i<n;i++){
        w+=ar[i];
    }
    b=n-w;
    // cout << b << " " << w << el;

    if ((b&1) && (w&1)){
        cout << -1 << el;
        return 0;
    }

    if (w%2==0){
        for (int i=0;i<n-1;i++){
            if (ar[i]){
                int cur=i;
                while (ar[cur+1]!=1){
                    swap(ar[cur], ar[cur+1]);
                    ans.pb(cur);
                    cur++;
                }

                ans.pb(cur);
                ar[cur]=0;
                ar[cur+1]=0;
            }
        }
        // for (int i=0;i<n-1;i++){
        //     if (ar[i] && ar[i+1]){
        //         ar[i]=0;
        //         ar[i+1]=0;
        //         ans.pb(i);
        //         i++;
        //         // cek();
        //     }
        // }

        // for (int i=0;i<200*200;i++){
        //     for (int j=0;j<n-1;j++){
        //         if (ar[j]==1 && ar[j+1]==0){
        //             swap(ar[j], ar[j+1]);
        //             ans.pb(j);
        //             // cek();
        //         }
        //     }
        // }

        // for (int i=0;i<n-1;i++){
        //     if (ar[i] && ar[i+1]){
        //         ar[i]=0;
        //         ar[i+1]=0;
        //         ans.pb(i);
        //         i++;
        //         // cek();
        //     }
        // }

        cout << ans.size() << el;
        for (auto x : ans){
            cout << x+1 << " ";
        }
        cout << el;
        return 0;
    }
    
    for (int i=0;i<n-1;i++){
        if (ar[i]==0){
            int cur=i;
            while (ar[cur+1]!=0){
                swap(ar[cur], ar[cur+1]);
                ans.pb(cur);
                cur++;
            }

            ans.pb(cur);
            ar[cur]=1;
            ar[cur+1]=1;
        }
    }

    // for (int i=0;i<n-1;i++){
    //     if (ar[i]==0 && ar[i+1]==0){
    //         ar[i]=1;
    //         ar[i+1]=1;
    //         ans.pb(i);
    //         i++;
    //         // cek();
    //     }
    // }

    // for (int i=0;i<200*200;i++){
    //     for (int j=0;j<n-1;j++){
    //         if (ar[j]==0 && ar[j+1]==1){
    //             swap(ar[j], ar[j+1]);
    //             ans.pb(j);
    //             // cek();
    //         }
    //     }
    // }

    // for (int i=0;i<n-1;i++){
    //     if (ar[i]==0){
    //         ar[i]=1;
    //         ar[i+1]=1;
    //         ans.pb(i);
    //         i++;
    //         // cek();
    //     }
    // }

    cout << ans.size() << el;
    for (auto x : ans){
        cout << x+1 << " ";
    }
    cout << el;

    return 0;
}