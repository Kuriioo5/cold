#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>

typedef enum
{
  TOK_EOF,
  TOK_IDENT,
  TOK_LITERAL,
  TOK_NUMBER,
  TOK_SEMI,
  TOK_LPAREN,
  TOK_RPAREN,
  TOK_LBRACE,
  TOK_RBRACE,
  TOK_DOT,
  TOK_RETURN,
  TOK_USE,
  TOK_FUNCTION
} TokenType;

typedef struct
{
  TokenType type;
  char *value;
} Token;


typedef struct 
{
  char *start_tok;
  char *cur_tok;
  Token *tokens;
  size_t count;
  size_t capacity;
  int line;
} Lexer;

Lexer *init_lexer(char *src);
void free_lexer(Lexer *lexer);

#endif