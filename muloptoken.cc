#include "muloptoken.h"

MulopToken::MulopToken(const mulop_attr attribute)
	: Token(token_type::TOKEN_KEYWORD), attribute(attribute) {}

MulopToken::~MulopToken() {}

mulop_attr MulopToken::get_attribute() const {
	return attribute;
}

std::string MulopToken::to_string() const {
	const std::string prefix = "TOKEN_KEYWORD:";

	switch (attribute) {
	case mulop_attr::MULOP_MUL: {
		return prefix + "MULOP_MUL";
	}
	case mulop_attr::MULOP_DIV: {
		return prefix + "MULOP_DIV";
	}
	case mulop_attr::MULOP_AND: {
		return prefix + "MULOP_AND";
	}
	case mulop_attr::MULOP_NO_ATTR: {
		return prefix + "MULOP_NO_ATTR";
	}
	default: {
		return prefix + "ERROR";
	}
	}
}