#include "keywordtoken.h"

KeywordToken::KeywordToken(const keyword_attr attribute)
	: Token(token_type::TOKEN_KEYWORD), attribute(attribute) {}

KeywordToken::~KeywordToken() {}

keyword_attr KeywordToken::get_attribute() const {
	return attribute;
}

std::string KeywordToken::to_string() const {
	const std::string prefix = "TOKEN_KEYWORD:";

	switch (attribute) {
	case keyword_attr::KW_PROGRAM: {
		return prefix + "KW_PROGRAM";
	}
	case keyword_attr::KW_PROCEDURE: {
		return prefix + "KW_PROCEDURE";
	}
	case keyword_attr::KW_INT: {
		return prefix + "KW_INT";
	}
	case keyword_attr::KW_BOOL: {
		return prefix + "KW_BOOL";
	}
	case keyword_attr::KW_BEGIN: {
		return prefix + "KW_BEGIN";
	}
	case keyword_attr::KW_END: {
		return prefix + "KW_END";
	}
	case keyword_attr::KW_IF: {
		return prefix + "KW_IF";
	}
	case keyword_attr::KW_THEN: {
		return prefix + "KW_THEN";
	}
	case keyword_attr::KW_ELSE: {
		return prefix + "KW_ELSE";
	}
	case keyword_attr::KW_WHILE: {
		return prefix + "KW_WHILE";
	}
	case keyword_attr::KW_LOOP: {
		return prefix + "KW_LOOP";
	}
	case keyword_attr::KW_PRINT: {
		return prefix + "KW_PRINT";
	}
	case keyword_attr::KW_NOT: {
		return prefix + "KW_NOT";
	}
	case keyword_attr::KW_NO_ATTR: {
		return prefix + "KW_NO_ATTR";
	}
	default: {
		return prefix + "ERROR";
	}
	}
}