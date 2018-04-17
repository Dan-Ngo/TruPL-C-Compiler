#include "punctoken.h"

PuncToken::PuncToken(const punc_attr_type attribute)
	: Token(token_type::TOKEN_KEYWORD), attribute(attribute) {}

PuncToken::~PuncToken() {}

punc_attr_type PuncToken::get_attribute() const {
	return attribute;
}

std::string PuncToken::to_string() const {
	const std::string prefix = "TOKEN_KEYWORD:";

	switch (attribute) {
	case punc_attr_type::PUNC_SEMI: {
		return prefix + "PUNC_SEMI";
	}
	case punc_attr_type::PUNC_COLON: {
		return prefix + "PUNC_COLON";
	}
	case punc_attr_type::PUNC_COMMA: {
		return prefix + "PUNC_COMMA";
	}
	case punc_attr_type::PUNC_ASSIGN: {
		return prefix + "PUNC_ASSIGN";
	}
	case punc_attr_type::PUNC_OPEN: {
		return prefix + "PUNC_OPEN";
	}
	case punc_attr_type::PUNC_CLOSE: {
		return prefix + "PUNC_CLOSE";
	}
	case punc_attr_type::PUNC_NO_ATTR: {
		return prefix + "PUNC_NO_ATTR";
	}
	default: {
		return prefix + "ERROR";
	}
	}
}