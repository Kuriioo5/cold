#include "cold.h"
#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>

static void help_message()
{
  printf("Cold v%s\nUsage: cold <file>\n", COLD_VERSION);
}

int main(int argc, char **argv)
{
  if(argc < 2)
  {
    help_message();
    return 0;
  }

  FILE *file = fopen(argv[1], "r");
  if(!file)
  {
    printf("File '%s' not found.\n", argv[1]);
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file); 

  char *buffer = (char *) malloc(size + 1);
  if(!buffer)
  {
    printf("Error allocating memory.\n");
    return 1;
  }

  fread(buffer, 1, size, file);
  buffer[size] = '\0';
  fclose(file);

  Lexer *lexer = init_lexer(buffer);

  for(int i = 0; i < lexer->count; i++)
  {
    printf("Type: %i ; Value: %s\n", lexer->tokens[i].type, lexer->tokens[i].value);
  }
  
  free(buffer);
  free_lexer(lexer);
  free(lexer);

  return 0;
}