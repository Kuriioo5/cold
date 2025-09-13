#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void add_token(Lexer *lexer, TokenType type, char *value);
static void handle_identifier(Lexer *lexer);

Lexer *init_lexer(char *src)
{
  Lexer *lexer = malloc(sizeof(Lexer));
  lexer->start_tok = src;
  lexer->cur_tok = src;
  lexer->tokens = NULL;
  lexer->line = 0;
  lexer->capacity = 0;
  lexer->count = 0;

  while(*lexer->cur_tok != '\0')
  {
    switch(*lexer->cur_tok)
    {
      case ' ':
        break;
      case '\n':
        lexer->line++;
        break;
      case ';':
        add_token(lexer, TOK_SEMI, ";");
        break;
      case '{':
        add_token(lexer, TOK_LBRACE, "{");
        break;
      case '}':
        add_token(lexer, TOK_RBRACE, "}");
        break;
      case '(':
        add_token(lexer, TOK_LPAREN, "(");
        break;
      case ')':
        add_token(lexer, TOK_RPAREN, ")");
        break;
      case '.':
        //TODO: 
      default:
        break;
    }

    lexer->cur_tok++;
  }

  add_token(lexer, TOK_EOF, NULL);
  return lexer;
}

static void add_token(Lexer *lexer, TokenType type, char *value)
{
  if(lexer->count == lexer->capacity)
  {
    size_t capacity = lexer->capacity == 0 ? 8 : lexer->capacity * 2;
    lexer->tokens = (Token *) realloc(lexer->tokens, capacity * sizeof(Token));

    if(!lexer->tokens)
    {
      printf("Error reallocating memory.\n");
      exit(1);
    }

    lexer->capacity = capacity;
  }

  lexer->tokens[lexer->count].type = type;
  lexer->tokens[lexer->count].value = value;
  lexer->count++;
}

void free_lexer(Lexer *lexer)
{
  free(lexer->tokens);
}