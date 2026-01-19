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

  constexpr std::string_view kMases[] = {"MAS", "SAM"};
  constexpr int kMasSize = kMases[0].size();
  const int kRowCount = vec.size();
  const int kColCount = vec[0].size();
  int xmas_count = 0;
  auto is_xmas = [&kMases](const std::string &s) {
    return s == kMases[0] || s == kMases[1];
  };
  for (int i = 0; i < kRowCount; i++) {
    for (int j = 0; j < kColCount; j++) {
      int deli = 1;
      int delj = 1;

      if (std::clamp(i + deli, 0, kRowCount - 1) != i + deli ||
          std::clamp(j + delj, 0, kColCount - 1) != j + delj ||
          std::clamp(i - deli, 0, kRowCount - 1) != i - deli ||
          std::clamp(j - delj, 0, kColCount - 1) != j - delj)
        continue;

      std::string tl;
      tl += vec[i - deli][j - delj];
      tl += vec[i][j];
      tl += vec[i + deli][j + delj];

      std::string tr;
      tr += vec[i - deli][j + delj];
      tr += vec[i][j];
      tr += vec[i + deli][j - delj];

      xmas_count += (is_xmas(tl) && is_xmas(tr));
    }
  }
  std::cout << xmas_count << '\n';

  return 0;
}