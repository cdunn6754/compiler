#include <iostream>
#include <string>
#include <regex>
#include <unordered_map>


int main() {
  std::string code ("return 2;");

  std::array<std::string, 2> regex_strings = {
    std::string(";"),
    std::string("return \\d")
  };

  std::unordered_map<std::string, int> r_map;

  int current_idx = 0;

  while (current_index < code.length() - 1) {
    for (const auto& s : regex_strings) {

      if (r_map.find(s) && r_map[s] == current_index) {
        break;
      } else {
        std::smatch m;
        r_map[s] = std::regex_search(code, m, std::regex(s));
      }
    }

  }

  std::cout << m.str() << " " << "location: " << m.position() << " ";
  std::cout << std::endl;


  return 0;
}
