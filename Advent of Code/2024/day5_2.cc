#include <cassert>
#include <compare>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

namespace {

enum class Direction : int {
  kBackward = -1,
  kAny = 0,
  kForward = 1,
  kInvalid = 2,
};

template <typename T>
concept HasComparisonOperator = requires(T a, T b) {
  { a > b } -> std::convertible_to<bool>;
  { a < b } -> std::convertible_to<bool>;
  { a == b } -> std::convertible_to<bool>;
};

template <typename T>
  requires HasComparisonOperator<T>
struct ValueCompress {
  std::map<T, int> value_id;
  std::map<int, T> id_value;
  int id_count = 0;

  void Add(T a) {
    if (!value_id.count(a)) {
      value_id[a] = ++id_count;
      id_value[id_count] = a;
    }
  }

  int GetId(T a) {
    Add(a);
    return value_id[a];
  }

  T GetValueById(int id) { return id_value[id]; }
};

int Solve(const std::vector<std::vector<Direction>> &direction_matrix,
          std::vector<int> &page_order, ValueCompress<int> &compress) {
  const int order_size = page_order.size();
  const int direction_size = direction_matrix.size();
  bool non_zero = false;

  for (int i = 0; i + 1 < order_size; i++) {
    int &source = page_order[i];
    if (source >= direction_size)
      continue;
    for (int j = i + 1; j < order_size; j++) {
      int &dest = page_order[j];
      if (dest >= direction_size)
        continue;
      if (direction_matrix[source][dest] != Direction::kAny &&
          direction_matrix[source][dest] != Direction::kForward) {
        non_zero = true;
        std::swap(source, dest);
      }
    }
  }

  return non_zero ? compress.GetValueById(page_order[order_size / 2]) : 0;
}

} // namespace

int main() {
  std::map<int, std::vector<int>> adjacency_list;
  ValueCompress<int> compress;
  {
    std::string input_line;
    while (std::getline(std::cin, input_line)) {
      if (input_line.size() == 0)
        break;

      std::istringstream ss(input_line);
      std::string temp;
      std::getline(ss, temp, '|');
      int a = std::stoi(temp);
      std::getline(ss, temp, '|');
      int b = std::stoi(temp);
      adjacency_list[a].emplace_back(b);
      compress.Add(a);
      compress.Add(b);
    }
  }

  std::vector<std::vector<Direction>> adjacency_id_matrix(
      compress.id_count + 1,
      std::vector<Direction>(compress.id_count + 1, Direction::kAny));
  for (const auto &[source, adj] : adjacency_list) {
    int source_id = compress.GetId(source);
    for (const auto &dest : adj) {
      int dest_id = compress.GetId(dest);
      if (adjacency_id_matrix[source_id][dest_id] != Direction::kAny &&
          adjacency_id_matrix[source_id][dest_id] != Direction::kForward) {
        // Do not expect cyclical ordering.
        assert(false);
        adjacency_id_matrix[source_id][dest_id] = Direction::kInvalid;
        adjacency_id_matrix[dest_id][source_id] = Direction::kInvalid;
      } else {
        adjacency_id_matrix[source_id][dest_id] = Direction::kForward;
        adjacency_id_matrix[dest_id][source_id] = Direction::kBackward;
      }
    }
  }

  long long total = 0;
  {
    std::string input_line;
    while (std::getline(std::cin, input_line)) {
      std::vector<int> seq;
      {
        std::istringstream ss(input_line);
        std::string temp;
        while (std::getline(ss, temp, ',')) {
          int val = std::stoi(temp);
          int val_id = compress.GetId(val);
          seq.emplace_back(val_id);
        }
      }

      total += Solve(adjacency_id_matrix, seq, compress);
    }
  }
  std::cout << total << '\n';

  return 0;
}
