#include "shell.h"

int main(int ac, char **av, char **env)
{(void)ac;
  (void)av;

  prompt(env);
  return(0);
}
