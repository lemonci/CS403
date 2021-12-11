//data structure to store all the tokens
//function gettoken() return token

#ifndef __TOKENIZE_H
#define __TOKENIZE_H

#include <stddef.h>
#include <iostream>

#endif /* __TOKENIZE_H */

size_t str_tokenize(char*, char**, const size_t);
char toks[2000];
int tok_pos = 0;

struct token{
	char type [10];
	char per_info [255];
}

size_t str_tokenize(char* str, char** tokens, const size_t n) {
  size_t tok_size = 1;
  tokens[0] = str;
  
  size_t i = 0;
  while (i < n) {
    if (str[i] == ' ') {
      str[i] = '\0';
      i++;
      for (; i < n && str[i] == ' '; i++) 
        /* NOP */;
      if (i < n) {
        tokens[tok_size] = str + i;
        tok_size++;
      }
    }
    else 
      i++;
  }

  return tok_size;
}

char typeDic[][] = {
	{"0", "int"}, {"1", "char"}, {"2", "double"}, {"3", "if"}, {"4", "else"}, {"5", "while"}, {"6", "real"}, {"7", "true"}, {"8", "false"}
};

 struct token gettoken() {
	struct token temp_token;
	temp_token.per_info = toks[tok_pos];
	temp_token.type = ?;
	tok_pos ++;
	
	return temp_token;
}


int main()
{
	char fullLine[2000];
	cin >> fullLine;
	int t = str_tokenize(fullLine, toks, strlen(fullLine));
}
