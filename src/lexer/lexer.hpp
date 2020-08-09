#include <string>
#include <vector>
#include <regex>
#include <utility>


enum class TokenType {

  // Keywords
  RETURN, INT,

  // Misc.
  SEMICOLON, RIGHT_BRACKET, LEFT_BRACKET, RIGHT_PAREN,
  LEFT_PAREN, IDENTIFIER, NUMBER,

  TOK_EOF, UNKNOWN,
};


class Token {
  TokenType type;
  std::string value;

  public:
    Token(TokenType type, std::string value);
    TokenType get_type();
    std::string get_value();
};


class Lexer {
  static std::vector<std::pair<TokenType, std::string>> regex_strings;

  Token get_next_token(
    std::string::const_iterator program_it,
    std::string::const_iterator program_end
  );

  public:

    std::vector<Token> tokenize(const std::string& program);
};
