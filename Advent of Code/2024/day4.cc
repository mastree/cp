#include <algorithm>
#include <iostream>

int main() {
  std::vector<std::string> vec;
  {
    std::string input_line;
    while (std::getline(std::cin, input_line)) {
      vec.emplace_back(input_line);
    }
  }
  if (vec.size() == 0) {
    std::cout << 0 << '\n';
    return 0;
  }

  constexpr std::string_view kXmas = "XMAS";
  const int kRowCount = vec.size();
  const int kColCount = vec[0].size();
  int xmas_count = 0;
  for (int i = 0; i < kRowCount; i++) {
    for (int j = 0; j < kColCount; j++) {
      for (int deli = -1; deli <= 1; deli++) {
        for (int delj = -1; delj <= 1; delj++) {
          if (deli == delj && deli == 0)
            continue;
          int ei = i + deli * (kXmas.size() - 1);
          int ej = j + delj * (kXmas.size() - 1);
          if (std::clamp(ei, 0, kRowCount - 1) != ei ||
              std::clamp(ej, 0, kColCount - 1) != ej)
            continue;

          std::string s;
          for (int idx = 0; idx < kXmas.size(); idx++) {
            s += vec[i + deli * idx][j + delj * idx];
          }
          xmas_count += (s == kXmas);
        }
      }
    }
  }
  std::cout << xmas_count << '\n';

  return 0;
}