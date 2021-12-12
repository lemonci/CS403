//data structure to store all the tokens
//function gettoken() return token

#ifndef __TOKENIZE_H
#define __TOKENIZE_H

#include <stddef.h>
#include <iostream>

#endif /* __TOKENIZE_H */

size_t str_tokenize(char*, char**, const size_t);
char toks[2000][255];
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

char typeDic[][10] = {
	"real", "num", "id", "char", "int", "double",
	"bool", "true", "false", "while", "if", "else", 
	"(", ")", "+", "-", "*", "/",
	"==", "!=", ">", "<", ">=", "<=",
	"--", "!", "||", "&&", ";",
	"error"
}

 struct token gettoken() {
	struct token temp_token;
	temp_token.per_info = toks[tok_pos];
	temp_token.type = type_detection(tok_pos);
	tok_pos ++;
	return temp_token;
}

int type_detection(int position) {
	int cat;
	if (strcmp(toks[position],"-")==0) {
		if ( type_detection(toks[position-1])<3){
			cat = 15;
		}
		else cat = 24;
		return cat;
	}
	for (cat=0;cat < 26;cat++){
		if (strcmp(toks[position],typeDic[cat])==0){
			return cat;
		}
	}
	int i;
	int count_p = 0;
	int count_n = 0;
	int count_c = 0;
	int tok_len = strlen(toks[position]);
	for (i=0; i < tok_len; i++) {
		if ((65<= toks[position][i] && toks[position][i]<= 90)
		    || toks[position][i]=95
		    || (97<=toks[position][i] && toks[position][i] <= 122)) count_c++;
		else if (toks[position][i] == '.') count_p++;
		else if (48<=toks[position][i] && toks[position][i]<=57) count_n++;
	}
	if (count_n == tok_len) return 1;
	else if (count_p == 1 && (count_p + count_n == tok_len)) return 0; 
	else if(count_p + count_n + count_c == tok_len) return 2;
	else return 27;
}


int main()
{
	char fullLine[2000];
	cin >> fullLine;
	int t = str_tokenize(fullLine, toks, strlen(fullLine));
}
