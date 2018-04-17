#include "reloptoken.h"

RelopToken::RelopToken(const relop_attr attribute)
	: Token(token_type::TOKEN_KEYWORD), attribute(attribute) {}

RelopToken::~RelopToken() {}

relop_attr RelopToken::get_attribute() const {
	return attribute;
}

std::string RelopToken::to_string() const {
	const std::string prefix = "TOKEN_KEYWORD:";

	switch (attribute) {
	case relop_attr::RELOP_EQ: {
		return prefix + "RELOP_EQ";
	}
	case relop_attr::RELOP_NE: {
		return prefix + "RELOP_NE";
	}
	case relop_attr::RELOP_GT: {
		return prefix + "RELOP_GT";
	}
	case relop_attr::RELOP_GE: {
		return prefix + "RELOP_GE";
	}
	case relop_attr::RELOP_LT: {
		return prefix + "RELOP_LT";
	}
	case relop_attr::RELOP_LE: {
		return prefix + "RELOP_LE";
	}
	case relop_attr::RELOP_NO_ATTR: {
		return prefix + "RELOP_NO_ATTR";
	}
	default: {
		return prefix + "ERROR";
	}
	}
}