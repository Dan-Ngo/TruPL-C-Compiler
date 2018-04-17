#include "eoftoken.h"

EofToken::EofToken()
	: Token(token_type::TOKEN_KEYWORD) {}

EofToken::~EofToken() {}

std::string EofToken::to_string() const {
	const std::string prefix = "TOKEN_KEYWORD:";

	return prefix + "EOF_TOKEN";
}