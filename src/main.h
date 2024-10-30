#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
  char *input; // a pointer to a string; it allows dynamic mainpulation of the string data within the parsers struct
  int pos;
} Parser;

void init_parser(Parser *parser, const char *input){
  parser->input = strdup(input); // sets parser.input = to string duplicate of input
  parser->pos = 0; // parser.pos = 0
}

char current_char(Parser *parser){
  return parser->input[parser->pos];
}
int is_whitespace(char c){
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void free_parser(Parser *parser){
  free(parser->input);
}
int parse_number(Parser *parser);
int parse_expression(Parser *parser);
