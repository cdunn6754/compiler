#include "lexer.hpp"

Token::Token(TokenType type, std::string value) {
  this->type = type;
  this->value = value;
}

TokenType Token::get_type() {
  return type;
}

std::string Token::get_value() {
  return value;
}

std::vector<std::pair<TokenType, std::string>> Lexer::regex_strings = {
  std::make_pair(TokenType::SEMICOLON, std::string(";")),
  std::make_pair(TokenType::RETURN, std::string("return")),
  std::make_pair(TokenType::RIGHT_BRACKET, std::string("}")),
  std::make_pair(TokenType::LEFT_BRACKET, std::string("\\{")),
  std::make_pair(TokenType::RIGHT_PAREN, std::string("\\(")),
  std::make_pair(TokenType::LEFT_PAREN, std::string("\\)")),
  std::make_pair(TokenType::INT, std::string("int")),
  std::make_pair(TokenType::IDENTIFIER, std::string("[a-zA-Z]\\w*")),
  std::make_pair(TokenType::NUMBER, std::string("[0-9]+")),
};

std::vector<Token> Lexer::tokenize(const std::string& program) {

  if (program.empty()) {
    return {};
  }

  std::vector<Token> tokens;

  std::string::const_iterator program_it = program.begin();
  std::string::const_iterator program_end = program.end();

  while (true) {
    while(program_end != program_it && std::isspace(*program_it)) {
      program_it++;
    }
    if (program_it == program_end) {
      tokens.push_back(Token(TokenType::TOK_EOF, "eof"));
      break;
    }

    Token next_tok = get_next_token(program_it, program_end);
    if (next_tok.get_type() == TokenType::UNKNOWN) {
      program_it += 1;
    } else {
      program_it += next_tok.get_value().length();
    }
    tokens.push_back(next_tok);
  }

  return tokens;
}

Token Lexer::get_next_token(
  std::string::const_iterator program_it,
  std::string::const_iterator program_end) {

  auto tmp_it = program_it;
  std::smatch m;
  for (const auto& regex_pair : this->regex_strings) {
    std::string regex_string = regex_pair.second;
    tmp_it = program_it;
    bool found = std::regex_search(tmp_it, program_end, m, std::regex(regex_string));
    if (found && m.position() == 0) {
      Token tok = Token(regex_pair.first, m.str());
      return tok;
    }
  }
  return Token(TokenType::UNKNOWN, "unknown");
}

std::string strip_leading_whitespace(const std::string& s) {
  std::smatch m;
  std::regex_search(s, m, std::regex("\\s+"));
  return m.suffix();
}
