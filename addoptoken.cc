#include "addoptoken.h"

AddopToken::AddopToken(const addop_attr attribute)
	: Token(token_type::TOKEN_KEYWORD), attribute(attribute) {}

AddopToken::~AddopToken() {}

addop_attr AddopToken::get_attribute() const {
	return attribute;
}

std::string AddopToken::to_string() const {
	const std::string prefix = "TOKEN_KEYWORD:";

	switch (attribute) {
	case addop_attr::ADDOP_ADD: {
		return prefix + "ADDOP_ADD";
	}
	case addop_attr::ADDOP_SUB: {
		return prefix + "ADDOP_SUB";
	}
	case addop_attr::ADDOP_OR: {
		return prefix + "ADDOP_OR";
	}
	case addop_attr::ADDOP_NO_ATTR: {
		return prefix + "ADDOP_NO_ATTR";
	}
	default: {
		return prefix + "ERROR";
	}
	}
}