#include "scanner.h"

enum class State : int {
	A = 0,
	AN = 1,
	AND = 2,
	B = 3,
	BE = 4,
	BEG = 5,
	BEGI = 6,
	BEGIN = 7,
	BO = 8,
	BOO = 9,
	BOOL = 10,
	E = 11,
	EL = 12,
	ELS = 13,
	ELSE = 14,
	EN = 15,
	END = 16,
	I = 17,
	IF = 18,
	IN = 19,
	INT = 20,
	L = 21,
	LO = 22,
	LOO = 23,
	LOOP = 24,
	N = 25,
	NO = 26,
	NOT = 27,
	O = 28,
	OR = 29,
	P = 30,
	PR = 31,
	PRI = 32,
	PRIN = 33,
	PRINT = 34,
	PRO = 35,
	PROC = 36,
	PROCE = 37,
	PROCED = 38,
	PROCEDU = 39,
	PROCEDUR = 40,
	PROCEDURE = 41,
	PROG = 42,
	PROGR = 43,
	PROGRA = 44,
	PROGRAM = 45,
	T = 46,
	TH = 47,
	THE = 48,
	THEN = 49,
	W = 50,
	WH = 51,
	WHI = 52,
	WHIL = 53,
	WHILE = 54,
	NUMBER = 55,

	START = 60,
	FINISH = 61,
	IDENTIFIER = 62,
	EXCLAM = 63,
	GT = 64,
	LT = 65,
	ASSIGN = 66,
	COMMENT = 67,
	EQ = 68,
	LEQ = 69,
	GEQ = 70,
	NEQ = 71,
	SEMI = 72,
	COLON = 73,
	COMMA = 74,
	OPEN = 75,
	CLOSE = 76,
	ADD = 77,
	SUB = 78,
	MUL = 79,
	DIV = 80,
};

int main(int argc, char** argv) {
	char *filename;
	if (argc != 2)
	{
		cout << ("Usage: ", argv[0], " file_name \n");
		exit(-2);
	}

	filename = argv[1];
	Scanner scanner(filename);
	Token* tokenPtr = new Token;

	do
	{
		tokenPtr = scanner.next_token();
		if (tokenPtr->get_token_type() == TOKEN_EOF)
		{
			cin.get();
			exit(0);
		}
		else if (tokenPtr->get_token_type() != TOKEN_NO_TYPE)
		{
			cout << tokenPtr->to_string() << NEW_LINE;
		}
		else
		{
			cout << "TOKEN_NO_TYPE OR EOF" << NEW_LINE;
		}
	} while (tokenPtr->get_token_type() != TOKEN_EOF);
}

Scanner::Scanner (char *filename)
{
  // Create and fill the buffer.
  buf = new Buffer (filename);
}

Scanner::~Scanner ()
{
  delete buf;
}

Token *Scanner::next_token()
{
  Token *lexeme = new Token;
  char c;
  std::string attr = "";
  State state = State::START;

  while (state != State::FINISH)
  {
	  if (buf->buffer.empty())
	  {
		  buf->fill_buffer();
	  }
	  c = buf->next_char();
	  if (buf->count() == 0)
	  {
		  state = State::FINISH;
		  lexeme->set_token_type(TOKEN_EOF);
	  }
	  switch (state)
	  {
		  case State::START:
		  {
				if (c == 'a') { state = State::A; } else
				if (c == 'b') { state = State::B; } else
				if (c == 'e') { state = State::E; } else
				if (c == 'i') { state = State::I; } else
				if (c == 'l') { state = State::L; } else
				if (c == 'n') { state = State::N; } else
				if (c == 'o') { state = State::O; } else
				if (c == 'p') { state = State::P; } else
				if (c == 't') { state = State::T; } else
				if (c == 'w') { state = State::W; } else
				if (c == 'c') { state = State::IDENTIFIER; } else
				if (c == 'd') { state = State::IDENTIFIER; } else
				if (c == 'f') { state = State::IDENTIFIER; } else
				if (c == 'g') { state = State::IDENTIFIER; } else
				if (c == 'h') { state = State::IDENTIFIER; } else
				if (c == 'j') { state = State::IDENTIFIER; } else
				if (c == 'k') { state = State::IDENTIFIER; } else
				if (c == 'm') { state = State::IDENTIFIER; } else
				if (c == 'q') { state = State::IDENTIFIER; } else
				if (c == 'r') { state = State::IDENTIFIER; } else
				if (c == 's') { state = State::IDENTIFIER; } else
				if (c == 'u') { state = State::IDENTIFIER; } else
				if (c == 'v') { state = State::IDENTIFIER; } else
				if (c == 'x') { state = State::IDENTIFIER; } else
				if (c == 'y') { state = State::IDENTIFIER; } else
				if (c == 'z') { state = State::IDENTIFIER; } else
				if (c == '0') { state = State::NUMBER; } else
				if (c == '1') { state = State::NUMBER; } else
				if (c == '2') { state = State::NUMBER; } else
				if (c == '3') { state = State::NUMBER; } else
				if (c == '4') { state = State::NUMBER; } else
				if (c == '5') { state = State::NUMBER; } else
				if (c == '6') { state = State::NUMBER; } else
				if (c == '7') { state = State::NUMBER; } else
				if (c == '8') { state = State::NUMBER; } else
				if (c == '9') { state = State::NUMBER; } else
				if (c == '=') { state = State::ASSIGN; } else
				if (c == '>') { state = State::GT; } else
				if (c == '<') { state = State::LT; } else
				if (c == '!') { state = State::EXCLAM; } else
				if (c == ',') { state = State::COMMA; } else
				if (c == ':') { state = State::COLON; } else
				if (c == ';') { state = State::SEMI; }	else
				if (c == '#') { state = State::COMMENT; } else
				if (c == '(') { state = State::OPEN; } else
				if (c == ')') { state = State::CLOSE; } else
				if (c == '+') { state = State::ADD; } else
				if (c == '-') { state = State::SUB; } else
				if (c == '*') { state = State::MUL; } else
				if (c == '/') { state = State::DIV; } else
				if (c == NEW_LINE) { state = State::START; } else
				if (c == SPACE) { state = State::START; } else
				if (c == TAB) { state = State::START; } else
				if (c == EOF_MARKER) 
				{ 
					state = State::FINISH;
					lexeme->set_token_type(TOKEN_EOF);
				}
			  break;
			}
		  case State::A:
		  {
			  if (c == 'n') 
			  { 
				  state = State::AN;
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::AN:
		  {
			  if (c == 'd') { state = State::AND; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::AND:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new MulopToken(MULOP_AND);
				  lexeme->set_token_type(TOKEN_MULOP);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::B:
		  {
			  if (c == 'e') { state = State::BE; } else
			  if (c == 'o') { state = State::BO; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::BE:
		  {
			  if (c == 'g') { state = State::BEG; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::BEG:
		  {
			  if (c == 'i') { state = State::BEGI; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::BEGI:
		  {
			  if (c == 'n') { state = State::BEGIN; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::BEGIN:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_BEGIN);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::BO:
		  {
			  if (c == 'o') { state = State::BOO; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::BOO:
		  {
			  if (c == 'l') { state = State::BOOL; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::BOOL:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_BOOL);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::E:
		  {
			  if (c == 'l') { state = State::EL; } else
			  if (c == 'n') { state = State::EN; } else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::EL:
		  {
			  if (c == 's') { state = State::ELS; } else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::ELS:
		  {
			  if (c == 'e') { state = State::ELSE; } else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::ELSE:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_ELSE);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::EN:
		  {
			  if (c == 'd') { state = State::END; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::END:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_END);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::I:
		  {
			  if (c == 'f') { state = State::IF; } else
			  if (c == 'n') { state = State::IN; } else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::IF:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_IF);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::IN:
		  {
			  if (c == 't') { state = State::INT; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::INT:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_INT);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::L:
		  {
			  if (c == 'o') { state = State::LO; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::LO:
		  {
			  if (c == 'o') { state = State::LOO; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::LOO:
		  {
			  if (c == 'p') { state = State::LOOP; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::LOOP:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_LOOP);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::N:
		  {
			  if (c == 'o') { state = State::NO; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::NO:
		  {
			  if (c == 't') { state = State::NOT; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::NOT:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_NOT);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::O:
		  {
			  if (c == 'r') { state = State::OR; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::OR:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new AddopToken(ADDOP_OR);
				  lexeme->set_token_type(TOKEN_ADDOP);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::P:
		  {
			  if (c == 'r') { state = State::PR; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PR:
		  {
			  if (c == 'i') { state = State::PRI; } else
			  if (c == 'o') { state = State::PRO; } else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PRI:
		  {
			  if (c == 'n') { state = State::PRIN; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PRIN:
		  {
			  if (c == 't') { state = State::PRINT; } else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PRINT:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_PRINT);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PRO:
		  {
			  if (c == 'c') { state = State::PROC; } else
			  if (c == 'g') { state = State::PROG; } else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROC:
		  {
			  if (c == 'e') { state = State::PROCE; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROCE:
		  {
			  if (c == 'd') { state = State::PROCED; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROCED:
		  {
			  if (c == 'u') { state = State::PROCEDU; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROCEDU:
		  {
			  if (c == 'r') { state = State::PROCEDUR; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROCEDUR:
		  {
			  if (c == 'e') { state = State::PROCEDURE; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROCEDURE:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_PROCEDURE);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROG:
		  {
			  if (c == 'r') { state = State::PROGR; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROGR:
		  {
			  if (c == 'a') { state = State::PROGRA; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROGRA:
		  {
			  if (c == 'm') { state = State::PROGRAM; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::PROGRAM:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_PROGRAM);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::T:
		  {
			  if (c == 'h') { state = State::TH; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::TH:
		  {
			  if (c == 'e') { state = State::THE; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::THE:
		  {
			  if (c == 'n') { state = State::THEN; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::THEN:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_THEN);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::W:
		  {
			  if (c == 'h') { state = State::WH; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::WH:
		  {
			  if (c == 'i') { state = State::WHI; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::WHI:
		  {
			  if (c == 'l') { state = State::WHIL; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::WHIL:
		  {
			  if (c == 'e') { state = State::WHILE; }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::WHILE:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new KeywordToken(KW_WHILE);
				  lexeme->set_token_type(TOKEN_KEYWORD);
			  }
			  else
			  {
				  state = State::IDENTIFIER;
			  }
			  break;
		  }
		  case State::EQ:
		  {
			  if (!is_alphanum(c)) 
			  { 
				  state = State::FINISH; 
				  lexeme = new RelopToken(RELOP_EQ);
				  lexeme->set_token_type(TOKEN_RELOP);
			  }
			  break;
		  }
		  case State::COMMENT:
		  {
			  if (c == '\n')
			  { 
				  state = State::FINISH;
			  }
			  break;
		  }
		  case State::EXCLAM:
		  {
			  if (c == '=') { state = State::FINISH; }
			  break;
		  }
		  case State::GT:
		  {
			  if (c == '=') { state = State::GEQ; }
			  break;
		  }
		  case State::LT:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new RelopToken(RELOP_LT);
				  lexeme->set_token_type(TOKEN_RELOP);
			  }
			  else if (c == '=') { state = State::LEQ; }
			  else if (c == '>') { state = State::NEQ; }
			  break;
		  }
		  case State::ASSIGN:
		  {
			  if (!is_alphanum(c))
			  { 
				  state = State::FINISH;
				  lexeme = new PuncToken(PUNC_ASSIGN);
				  lexeme->set_token_type(TOKEN_PUNC);
			  }
			  break;
		  }
		  case State::LEQ:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new RelopToken(RELOP_LE);
				  lexeme->set_token_type(TOKEN_RELOP);
			  }
			  break;
		  }
		  case State::GEQ:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new RelopToken(RELOP_GE);
				  lexeme->set_token_type(TOKEN_RELOP);
			  }
			  break;
		  }
		  case State::NEQ:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new RelopToken(RELOP_NE);
				  lexeme->set_token_type(TOKEN_RELOP);
			  }
			  break;
		  }
		  case State::SEMI:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new PuncToken(PUNC_SEMI);
				  lexeme->set_token_type(TOKEN_PUNC);
			  }
			  break;
		  }
		  case State::COLON:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new PuncToken(PUNC_COLON);
				  lexeme->set_token_type(TOKEN_PUNC);
			  }
			  else if (c == '=')
			  {
				  state = State::ASSIGN;
			  }
			  break;
		  }
		  case State::COMMA:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new PuncToken(PUNC_COMMA);
				  lexeme->set_token_type(TOKEN_PUNC);
			  }
			  break;
		  }
		  case State::OPEN:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new PuncToken(PUNC_OPEN);
				  lexeme->set_token_type(TOKEN_PUNC);
			  }
			  break;
		  }
		  case State::CLOSE:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new PuncToken(PUNC_CLOSE);
				  lexeme->set_token_type(TOKEN_PUNC);
			  }
			  break;
		  }
		  case State::ADD:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new AddopToken(ADDOP_ADD);
				  lexeme->set_token_type(TOKEN_ADDOP);
			  }
			  break;
		  }
		  case State::SUB:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new AddopToken(ADDOP_SUB);
				  lexeme->set_token_type(TOKEN_ADDOP);
			  }
			  break;
		  }
		  case State::MUL:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new MulopToken(MULOP_MUL);
				  lexeme->set_token_type(TOKEN_MULOP);
			  }
			  break;
		  }
		  case State::DIV:
		  {
			  if (!is_alphanum(c))
			  {
				  state = State::FINISH;
				  lexeme = new MulopToken(MULOP_DIV);
				  lexeme->set_token_type(TOKEN_MULOP);
			  }
			  break;
		  }
		  case State::IDENTIFIER:
		  {
			  if (c == NEW_LINE || c == SPACE || c == COMMENT_MARKER || c == TAB)
			  {
				  state = State::FINISH;
				  lexeme = new IdToken(attr);
				  lexeme->set_token_type(TOKEN_ID);
			  }
			  break;
		  }
		  case State::NUMBER:
		  {
			  if (!is_digit(c))
			  {
				  state = State::FINISH;
				  lexeme = new NumToken(attr);
				  lexeme->set_token_type(TOKEN_NUM);
			  }
			  break;
		  }
		}
		if (state == State::IDENTIFIER && !is_alphanum(c))
		{
			lexeme = new IdToken(attr);
			lexeme->set_token_type(TOKEN_ID);
			state = State::FINISH;
		}
		if (state == State::FINISH)
		{
			buf->unread_char(c);
		}
		else if (c != NEW_LINE && c != TAB && state != State::START)
		{
			attr += c;
			if (state == State::CLOSE)
			{
				lexeme = new PuncToken(PUNC_CLOSE);
				lexeme->set_token_type(TOKEN_PUNC);
				state = State::FINISH;
			}
			if (state == State::OPEN)
			{
				lexeme = new PuncToken(PUNC_OPEN);
				lexeme->set_token_type(TOKEN_PUNC);
				state = State::FINISH;
			}
		}
  }
  if (attr != "")
  {
	cout << attr << " ";
  }
  return lexeme;
}



void Scanner::scanner_fatal_error(const string& message)
{
  cerr << "Exiting on Scanner Fatal Error: " << message << endl;
  exit (-1);
}
