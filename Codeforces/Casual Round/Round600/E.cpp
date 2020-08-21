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

const int N = 2e5 + 7;

int n,m;
int ant[N];
int ar[N];
vector <pii> rusak;
vector <pii> range;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;


    for (int i=0;i<n;i++){
        int x,s;
        cin >> x >> s;
        ant[x] = s;
        ar[max(x-s, 1)]++;
        ar[min(x+s+1, m+1)]--;
        range.pb(mp(max(x-s, 1),min(x+s, m)));
        // cout <<  max(x-s, 1) << " " << x+s+1 << el;
    }

    // for (int i=0;i<=m+100;i++){
    //     cout << i << " => " << ar[i] << el;
    // }
    int tm=0;
    int last=0;
    int bef=1;
    ar[m+1]=1;
    for (int i=1;i<=m+1;i++){
        tm+=ar[i];
        // cout << i << " => " << tm << el; 
        if (tm==0){
            if (bef>0){
                last=i;
                bef=0;
            } 
        } else{
            if (bef==0){
                rusak.pb(mp(last,min(i-1,m)));
                bef=tm;
            }
        }
    }

    int len = rusak.size();
    if (len==0){
        cout << 0 << el;
        return 0;
    }

    int l=0,r=0;
    for (int i=0;i<len;i++){
        while (range[l]<)
    }

    return 0;
}