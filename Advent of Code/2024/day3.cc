#include <iostream>
#include <optional>
#include <string>

namespace {

bool IsDigit(char c) { return '0' <= c && c <= '9'; }

std::optional<int> GetNumber(std::string s, const int max_length = 3) {
  if (s.empty() || s.size() > max_length)
    return std::nullopt;
  std::string ret;
  for (auto c : s)
    if (!IsDigit(c))
      return std::nullopt;
  try {
    return std::stoi(s);
  } catch (const std::exception &any_err) {
    // no-handling
  }
  return std::nullopt;
}

} // namespace

int main() {
  std::string error;
  {
    std::string input_line;
    while (std::getline(std::cin, input_line)) {
      error += input_line + '\n';
    }
  }

  long long total = 0;
  std::function<void(std::vector<std::variant<std::string, int>> &,
                     std::string &, char)>
      machine_process = [&machine_process, &total](
                            std::vector<std::variant<std::string, int>> &tokens,
                            std::string &cur, char c) {
        // -- find "mul" when token empty --
        if (tokens.empty()) {
          constexpr char kMul[] = "mul(";
          cur += c;
          if (kMul[cur.size() - 1] != c) {
            tokens.clear();
            cur.clear();
            if (c == 'm')
              machine_process(tokens, cur, c);
            return;
          }
          if (cur.size() == 4) {
            tokens.emplace_back(std::move(cur));
            cur.clear();
          }
          return;
        }

        // -- check for first args "a" mul(a, b) --
        else if (tokens.size() == 1) {
          if (IsDigit(c)) {
            cur += c;
            return;
          }

          if (c != ',') {
            tokens.clear();
            cur.clear();
            machine_process(tokens, cur, c);
            return;
          }

          std::optional<int> num = GetNumber(cur);
          if (num == std::nullopt)
            tokens.clear();
          else
            tokens.emplace_back(*num);

          cur.clear();
          return;
        }

        // -- check for second args "b" mul(a, b) --
        else if (tokens.size() == 2) {
          if (IsDigit(c)) {
            cur += c;
            return;
          }

          if (c != ')') {
            tokens.clear();
            cur.clear();
            machine_process(tokens, cur, c);
            return;
          }

          std::optional<int> num = GetNumber(cur);
          if (num == std::nullopt)
            tokens.clear();
          else {
            total += get<int>(tokens.back()) * (*num);
            tokens.clear();
          }

          cur.clear();
          return;
        }
      };

  std::vector<std::variant<std::string, int>> tokens;
  std::string cur;
  for (auto c : error) {
    machine_process(tokens, cur, c);
  }
  std::cout << total << '\n';

  return 0;
}