#include"main.h"

int main(int ac, char **argv) {

  char *prompt = "$ ";
  char *full_command = NULL, *copy_command = NULL;
  size_t n = 0;
  ssize_t nchars_read;
  const char *delim = " \n";
  int num_tokens = 0;
  char *token; 
  int i; 

  (void)ac;

  while(1) {


    printf("%s", prompt);
    nchars_read =  getline(&full_command, &n, stdin);

    if(nchars_read == -1) {
      printf("Exiting shell...\n");
      return (-1);
    }

    copy_command = malloc(sizeof(char) * nchars_read);
    if(copy_command == NULL) {
      perror("memory allocation error. Your shell sucks");
      return (-1);
    }

    strcpy(copy_command, full_command);

    token = strtok(full_command, delim); 

    while(token != NULL) {
      num_tokens++;
      token = strtok(NULL, delim);
    }
    num_tokens++;

    argv = malloc(sizeof(char *) * num_tokens);

    token = strtok(copy_command, delim);

    for(i = 0; token != NULL; i++) {
      argv[i] = malloc(sizeof(char) * strlen(token));
      strcpy(argv[i], token); 

      token = strtok(NULL, delim);
    }
    argv[i] = NULL;

    execmd(argv);
    
  }
  
  free(full_command);
  free(copy_command);
  
  return (0);
}
