#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main() {
  printf("Welcome!\n");
  char c[100];
  char sentence[100];
  List *history = init_history();
  char hist_choice[100];
  char *hist_out;

  while (1) {
    printf("\nPlease select an option:\n");
    printf("To input Tokens enter -> t\n");
    printf("To view history enter -> h\n");
    printf("To quit enter -> q\n>");
    fgets(c,100,stdin);

    int choice = menuOpt(c);

    switch (choice) {
    case 1:
      printf("Please enter the string you would like tokeninze\n>");
      fgets(sentence,100,stdin);
      char **tokens = tokenize(sentence);
      print_tokens(tokens);
      add_history(history, sentence);
      free_tokens(tokens);
      break;
    case 2:
      printf("Displaying History... Enter a number to view a sentence from history ");
      printf("or enter 'h' to view all history\n>");
      fgets(hist_choice, 100, stdin);

      if (hist_choice[0] == 'h') {
	print_history(history);
	break;
      }
      int id = atoi(hist_choice);
      hist_out = get_history(history, id);
      printf("%d: ", id);
      if (*hist_out != '\0') {    // not found
	printf("%s\n", hist_out);
	break;
      }
      printf("Enter a valid input\n");
      break;
    case 0:
      printf("Bye!");
      goto done;
    default:
      printf("Unrecognized option, please try again.\n");
    }
  }
  
 done:
  return 0;
}
