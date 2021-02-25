#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c) {

  if ((c == ' ' || c == '\t') && c != '\0')
    return 1;
  else
    return 0;
}

int non_space_char(char c) {

  if ((c != ' ' && c != '\t') && c != '\0')
    return 1;
  else
    return 0;

}

char *word_start(char *s) {

  while (space_char(*s))  // iterate to the next address until a non space char is found
    s++;
  return s;

}

char *word_terminator(char *word) {

  while (non_space_char(*word))  // iterate to the next address until a space char is foun
    word++;
  return word;

}

int count_words(char *s) {

  int count = 0;
  char *temp = s;
  temp = word_start(temp);

  while (*temp) { //while *temp yields a true value (non-zero)
    if (non_space_char(*temp))
      count++;
    
    temp = word_terminator(temp);
    temp = word_start(temp);
  }

  return count;

}

char *copy_str(char *inStr, short len) {

  char *copy = malloc(sizeof(char) * (len + 1));
  int i;  // i is created here so it can be used outside of the for loop

  for (i = 0; i < len; i++) 
    copy[i] = inStr[i];

  copy[i] = '\0'; //end it with the terminator
  return  copy;

}

char **tokenize(char* str) {

  int num_words = count_words(str);
  char **tokens = malloc((num_words + 1) * sizeof(char *));
  int i;  // i is created here so it can be used outside of the for loop
  int len;
  char *p = str;

  for (i = 0; i < num_words; i++) {
    p = word_start(p);
    len = word_length(p);
    tokens[i] = copy_str(p, len);
    p = word_terminator(p);
  }

  tokens[i] = '\0';
  return tokens;

}

void print_tokens(char **tokens) {

  for (int i = 0; tokens[i]; i++)
    printf("Token %d is %s\n", i, tokens[i]);
  
  printf("\n");

}

void free_tokens(char **tokens) {

  for (int i = 0; tokens[i]; i++)
    free(tokens[i]);

}

int menuOpt(char *str){

}

int word_length(char *str) {

  return word_terminator(str) - word_start(str);

}
