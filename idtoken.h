#ifndef IDTOKEN_H
#define IDTOKEN_H

using namespace std;

#include "token.h"
#include <string>

class IdToken : public Token
{
 public:
  IdToken();
  ~IdToken();
  IdToken(const string attr);

  string get_attribute() const;
  void set_attribute(const string attr);

  string to_string() const;

 private:
  string attribute;
};

#endif
