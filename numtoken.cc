#include "numtoken.h"

NumToken::NumToken(const string& attribute)
	: Token(token_type::TOKEN_KEYWORD), attribute(attribute) {}

NumToken::~NumToken() {}

string NumToken::get_attribute() const {
	return attribute;
}

std::string NumToken::to_string() const {
	const std::string prefix = "TOKEN_KEYWORD:";

	return prefix + "NUM_TOKEN";
}