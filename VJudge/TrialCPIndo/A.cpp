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

string name[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int n;
queue<pii> qu;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<5;i++){
        qu.push(mp(i, 1));
    }
    while (n){
        auto temp = qu.front();
        qu.pop();
        n -= temp.se;
        if (n <= 0){
            cout << name[temp.fi] << el;
            return 0;
        }
        temp.se <<= 1;
        qu.push(temp);
    }

    return 0;
}