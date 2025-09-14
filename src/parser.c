#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

static void consume(Parser *parser);

Parser *init_parser(Lexer *lexer)
{
  Parser *parser = malloc(sizeof(Parser));
  parser->lexer = lexer;
  parser->index = 0;
  parser->cur_tok = lexer->tokens[parser->index];

  return parser;
}

static void consume(Parser *parser)
{
  parser->next_tok = parser->lexer->tokens[parser->index + 1];
  parser->index++;
  parser->cur_tok = parser->next_tok;
}