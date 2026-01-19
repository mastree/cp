#include <cassert>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

namespace {

bool IsReportSafe(const std::vector<int> &report) {
  const int report_size = report.size();
  if (report_size == 0)
    return false;
  if (report_size <= 2)
    return true;

  // mark -1 for decreasing gap, 1 for increasing gap, 0 for invalid.
  // > mark[i] is for report[i] to report[i + 1].
  std::vector<int> mark(report_size - 1);
  int total = 0;
  for (int i = 1; i < report_size; i++) {
    int diff = report[i] - report[i - 1];
    if (diff == 0 || std::abs(diff) > 3) {
      mark[i - 1] = 0;
    } else {
      mark[i - 1] = (diff > 0) ? 1 : -1;
    }
    total += mark[i - 1];
  }
  // simulate delete i-th element.
  for (int i = 0; i < report_size; i++) {
    int cur_total = total;
    if (i > 0)
      cur_total -= mark[i - 1];
    if (i < report_size - 1)
      cur_total -= mark[i];
    if (0 < i && i < report_size - 1) {
      int diff = report[i + 1] - report[i - 1];
      if (diff != 0 && std::abs(diff) <= 3) {
        cur_total += (diff > 0) ? 1 : -1;
      }
    }
    if (std::abs(cur_total) == report_size - 2)
      return true;
  }

  return false;
}

} // namespace

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