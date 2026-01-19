#include <algorithm>
#include <iostream>
#include <utility>

int main() {
  std::vector<int> lista;
  std::vector<int> listb;
  {
    int a, b;
    while (std::cin >> a >> b) {
      lista.push_back(a);
      listb.push_back(b);
    }
  }
  const int kListCount = lista.size();
  std::sort(lista.begin(), lista.end());
  std::sort(listb.begin(), listb.end());
  long long total_dist = 0;
  for (int i = 0; i < kListCount; i++) {
    total_dist += std::abs(lista[i] - listb[i]);
  }
  std::cout << total_dist << '\n';

  return 0;
}
