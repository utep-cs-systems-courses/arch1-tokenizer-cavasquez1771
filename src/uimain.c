#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Welcome!\n");

  while (1) {
    printf("Enter a string or enter '?' to quit. \n > ");
    char user_string[100];
    fgets(user_string, 100, stdin);
    puts(user_string);

    
    if (user_string[0] == 63) // ascii value of '?'
      return 0;




  }
}
