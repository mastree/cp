#include <iostream>

int main() {
  std::vector<int> lista;
  std::unordered_map<int, int> b_count;
  {
    int a, b;
    while (std::cin >> a >> b) {
      lista.push_back(a);
      b_count[b]++;
    }
  }
  long long total = 0;
  for (auto a : lista) {
    total += a * b_count[a];
  }
  std::cout << total << '\n';

  return 0;
}