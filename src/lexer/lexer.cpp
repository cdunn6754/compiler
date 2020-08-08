#include "lexer.hpp"

Token::Token(TokenType type, std::string value) {
  type = type;
  value = value;
}
TokenType Token::get_type() {
  return type;
}

std::string Token::get_value() {
  return value;
}

std::vector<Token> Lexer::tokenize(std::string program) {
  // std::vector<std::string> regex_strings = {
  //   std::string(";"),
  //   std::string("return"),
  //   std::string("}"),
  //   std::string("\\{"),
  //   std::string("\\("),
  //   std::string("\\)"),
  //   std::string("int"),
  //   std::string("[a-zA-Z]\\w*"),
  //   std::string("[0-9]+"),
  // };

  // std::vector<std::string> tokens;

  // std::unordered_map<int, std::smatch> r_map;

  // int current_idx = 0;

  // std::smatch m;

  // code = strip_leading_whitespace(code);
  // while (code.length()) {
  //   for (const auto& s : regex_strings) {
  //     std::cout << s << std::endl;
  //     std::smatch m_tmp;
  //     auto found = std::regex_search(code, m_tmp, std::regex(s));
  //     std::cout << "found: " << found << " idx: " << m_tmp.position() << std::endl;
  //     if (found && m_tmp.position() == 0) {
  //       break
  //     }
  //   }

  //   std::cout << "current idx: " << current_idx << std::endl;
  //   if (r_map.count(current_idx) == 0) {
  //     std::cout << "Invalid input at index: " << current_idx << std::endl;
  //     return 0;
  //   }

  //   m = r_map[current_idx];
  //   std::cout << "current match: " << m.str() << std::endl;
  //   tokens.push_back(m.str());
  //   current_idx += m.length();
  // }

  // std::cout << "tokens: ";
  // for (auto token:tokens) std::cout << token << ", ";
  // std::cout << std::endl;

  return std::vector<Token>();
}


std::string strip_leading_whitespace(const std::string& s) {
  std::smatch m;
  std::regex_search(s, m, std::regex("\\s+"));
  return m.suffix();
}