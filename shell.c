#include "shell.h"

int main(){
  Parser parser;
  
  init_parser(&parser, input());
  printf("%d\n",parse_expression(&parser));
  free_parser(&parser);
  return 0;
}
