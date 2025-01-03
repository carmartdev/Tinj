#include "main.h"

int main(){
  //const char *input = "355 + 2";
  Parser parser;
  
  init_parser(&parser, "1 == 2");
  printf("%d\n",parse_expression(&parser));
  free_parser(&parser);
  
  return 0;
}

int parse_number(Parser *parser){
  //[ ]TODO: check if the number is int or float 

  int num = 0;
  while (is_whitespace(current_char(parser))){
    parser->pos++;
  }
  while (isdigit(current_char(parser))){
    num = num * 10 + (current_char(parser) - '0');
    parser->pos++;
  }
  return num;
}

int parse_expression(Parser *parser){

  int left = parse_number(parser);

  while (is_whitespace(current_char(parser))){
    parser->pos++;
  }
  while(current_char(parser) == '='){
    char op = current_char(parser);
    parser->pos++;
    while (is_whitespace(current_char(parser))){
      parser->pos++;
    }
    if (current_char(parser)){
      parser->pos++;
      while (is_whitespace(current_char(parser))){
	 parser->pos++;
      }
      int right = parse_number(parser);
      if (left == right){
	return 1;
      }else{
	return 0;
      }
    }
  }
  while(current_char(parser) == '+' || current_char(parser) == '-' || current_char(parser) == '*' || current_char(parser) == '/'){
    
    char op = current_char(parser);
    parser->pos++;// skips the operator

    while (is_whitespace(current_char(parser))){
      parser->pos++;
    }
    
    int right = parse_number(parser);
    
    if (op == '+'){
      left += right;
    }else if (op == '-'){
      left -= right;
    }else if (op == '/'){
      left /= right;
    }else if (op == '*'){
      left *= right;
    }
  }
  return left;
}
