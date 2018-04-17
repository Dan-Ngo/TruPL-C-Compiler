#include "idtoken.h"

IdToken::IdToken(const string attribute)
	: Token(token_type::TOKEN_KEYWORD), attribute(attribute) {}

IdToken::~IdToken() {}

string IdToken::get_attribute() const {
	return attribute;
}

std::string IdToken::to_string() const {
	const std::string prefix = "TOKEN_KEYWORD:";

	return prefix + "ID_TOKEN";
}