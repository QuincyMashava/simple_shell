#include "shell.h"

/**
 * c_atoi - custom atoi converts string to int
 * @string: string passed onto atoi
 * Return: number upon success, -1 contains characters that are not numbers
 */
int c_atoi(char *string)
{
  int i = 0;
  unsigned int num = 0;

  while (string[i] != '\0')
    {
      if (string[i] >= '0' && string[i] <= '9') /* calculate num */
	num = num * 10 + (string[i] - '0');
      if (string[i] > '9' || string[i] < '0') /* account for non-numbers */
	return (-1);
      i++;
    }
  return (num);
}

/**
 * __exit - frees user input and then exits main program with a value
 * @cmd: user's input command into shell 
 * @num: print command input along with error message
 * @env: free environmental variable upon error detection
 * @command: free command
 * Return: 0 @ success ,and 2 when fail
 */
int __exit(char **cmd, list_t *env, int num, char **command)
{
  int e_value = 0;

  if (cmd[1] != NULL) /* return 0 */
    e_value = c_atoi(cmd[1]);

  if (e_value == -1) /* invalid input upon after exit */
    {
      illegal_number(cmd[1], num, env); /* print error msg */
      free_double_ptr(cmd);
      return (2);
    }
  free_double_ptr(cmd); /* free user input before exiting program */
  free_linked_list(env);
  if (command != NULL)
    free_double_ptr(command);
  exit(e_value);
}
