#include "main.h"
#include <stdio.h>

void execmd(char **argv) {
  char *command = NULL;
  if(argv) {
    command = argv[0];

    char *actual_command = get_location(command); 

    if(execve(actual_command, argv, NULL) == -1) {
      perror("Error: ");
    }
  }
}
