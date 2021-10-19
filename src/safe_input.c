/**
 * @file safe_input.h
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief this source file provide some functions for working with input.
 * i assure you this functions is absolutely secure.
 * this minimal library also useful for preventing buffer overflow vulnerabilities.
 * @version 0.1
 * @date 2021-07-20
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "cli/safe_input.h"

inline void *
safeCalloc (size_t size)
{
  void *temp = (void *)malloc (size);

  if (temp == NULL && size > 0)
    {
      fprintf (stderr, "Couldn't allocate memory\n");
      exit (EXIT_FAILURE);
    }

  return temp;
}

void
safeInputInit (struct safe_input *input, size_t size)
{
  input->str_len = size;

  input->sen_len = size;

  input->str = (char *)safeCalloc (sizeof (char) * input->str_len);

  input->sen = (char *)safeCalloc (sizeof (char) * input->sen_len);

  input->ch = '\0';
}

void
getSafeLine (struct safe_input *input)
{
  char *tmp = (char *) safeCalloc (sizeof (char) * input->sen_len);

  size_t size = sizeof (tmp);

  if (getline (&tmp, &size, stdin) < input->sen_len)
    tmp[strlen (tmp) - 1] = '\0';

  strncpy (input->sen, tmp, input->sen_len);

  free (tmp);
}

void
getSafeStr (struct safe_input *input)
{
  char *tmp = (char *) safeCalloc (sizeof (char) * input->str_len);

  size_t size = sizeof (tmp);

  if (getline (&tmp, &size, stdin) < input->sen_len)
    tmp[strlen (tmp) - 1] = '\0';

  strncpy (input->str, tmp, input->str_len);

  input->str = strtok (input->str, " ");

  if (input->str == NULL)
    input->str = (char *)safeCalloc (input->str_len);

  free (tmp);
}

void
getSafeChar (struct safe_input *input)
{
  char *tmp = (char *) safeCalloc (sizeof (input->ch) / sizeof (char));

  size_t tmp_len = sizeof (tmp);

  getline (&tmp, &tmp_len, stdin);

  input->ch = tmp[0];

  free (tmp);
}

void
safeInputClose (struct safe_input *input)
{
  input->ch = '\0';

  if (sizeof (input->str) == sizeof (char) * input->str_len)
    free (input->str);

  free (input->sen);
}