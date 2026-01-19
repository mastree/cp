#include <iostream>
#include <string>
#include <sstream>

namespace {

bool IsReportSafe(const std::vector<int>& report) {
  const int report_size = report.size();
  if (report_size == 0) return false;
  bool is_increasing = 0;
  for (int i = 1; i < report_size; i++) {
    int diff = report[i] - report[i - 1];
    if (diff == 0 || std::abs(diff) > 3) return false;
    if (i == 1) {
      is_increasing = (diff > 0);
      continue;
    }
    if (is_increasing != (diff > 0)) return false;
  }
  return true;
}

}  // namespace

int main() {
  std::string input_line;
  int safe_count = 0;
  while (std::getline(std::cin, input_line)) {
    std::stringstream ss;
    ss << input_line;
    std::vector<int> report;
    int val;
    while (ss >> val) {
      report.push_back(val);
    }
    safe_count += IsReportSafe(report);
  }

  std::cout << safe_count << '\n';
}