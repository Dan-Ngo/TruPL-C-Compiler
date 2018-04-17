#ifndef NUMTOKEN_H
#define NUMTOKEN_H

using namespace std;

#include "token.h"
#include <string>

class NumToken : public Token
{
 public:
  NumToken();
  ~NumToken();
  NumToken(const string& attr);

  string get_attribute() const;
  void set_attribute(const string& attr);

  string to_string() const;

 private:
  string attribute;
};

#endif
