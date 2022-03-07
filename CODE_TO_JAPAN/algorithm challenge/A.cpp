// untuk ai: https://app.tracks.run/asiatojapan/share/60d87d619f744d5cb10e1ca8a5c2e118

#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10;

int n, m, k;
bool drow[N], dcol[N];
int mat[N][N];

int main(){
  cin >> n >> m >> k;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      char c;
      cin >> c;
      if (c == 'B'){
        drow[i] = 1;
        dcol[j] = 1;
      } else{
        int dig = c - '0';
        mat[i][j] = dig;
      }
    }
  }
  vector<int> alive, dead;
  int ans = 0;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      if (mat[i][j] == 0) continue;
      if (drow[i] || dcol[j]){
        dead.push_back(mat[i][j]);
      } else{
        alive.push_back(mat[i][j]);
        ans += mat[i][j];
      }
    }
  }
  int saved = alive.size();
  sort(alive.begin(), alive.end(), greater<int>());
  sort(dead.begin(), dead.end());

  while (k && !alive.empty() && !dead.empty() && alive.back() < dead.back()){
    k--;
    ans += dead.back() - alive.back();
    alive.pop_back();
    dead.pop_back();
  }
  cout << ans << '\n';

  return 0;
}

/*
Explanation of Code:

Basically, first thing you have to do is to flagged all the safe cell and all 
the unsafe cell. Safe cell is a cell that will not get exploded by any bombs 
and vice versa. 

After that, you can list the value (number of bills there) in two different 
container, which is alive and dead. Container alive have all the value in the 
safe cell, while container dead have all the value in the unsafe cell. 

After listing them, you can perform swapping (maximum k times) of items greedily. 
If the lowest element in alive container is lower than the highest element in dead 
container and you still can swap, then just swap them. You can do this operation 
until one of the container is empty or you have perform swapping k times or you don't 
need to swap anymore (lowest element in alive container is greater than the highest 
element in dead).

The answer will be the sum of value in alive container after all operation has been done. 
Using this will result in O(N^2 . log(N^2)) time complexity because of the sorting.
*/