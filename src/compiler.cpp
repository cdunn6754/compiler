#include <iostream>
#include <string>
#include <regex>

#include "lexer.hpp"

int main() {
  std::string code ("int main() {return 2;}");

  Lexer lexer;
  std::vector<Token> tokens = lexer.tokenize(code);

  for (auto token : tokens)
    std::cout << " Token Value: " << token.get_value() << std::endl;

  return 0;
}
