#include <string>
#include <vector>
#include <regex>


enum class TokenType {
  // Keywords
  RETURN, INT,

  // Misc.
  SEMICOLON, RIGHT_BRACKET, LEFT_BRACKET, RIGHT_PAREN,
  LEFT_PAREN, IDENTIFIER, NUMBER,

  EOF, UNKNOWN
};


class Token {
  TokenType type;
  std::string value;

  public:
    Token(TokenType s, std::string value);
    TokenType get_type();
    std::string get_value();
};


// template <class T>
// class ValueToken: Token {
//   T value;

//   public:
//     ValueToken(TokenType s, T value);


// };

class Lexer {
  static std::vector<std::string> regex_strings = {
    std::string(";"),
    std::string("return"),
    std::string("}"),
    std::string("\\{"),
    std::string("\\("),
    std::string("\\)"),
    std::string("int"),
    std::string("[a-zA-Z]\\w*"),
    std::string("[0-9]+"),
  };

  public:

    std::vector<Token> tokenize(const std::string& program);
};
