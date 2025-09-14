#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct
{
  Lexer *lexer;
  int index;
  Token cur_tok;
  Token next_tok;
} Parser;

Parser *init_parser(Lexer *lexer);

#endif