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

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#if !defined(_SAFE_INPUT_H)
#define _SAFE_INPUT_H

void *safeCalloc (size_t size);

typedef struct safe_input
{
  char ch;

  char *str;

  char *sen;

  size_t str_len;

  size_t sen_len;
} safeInput;

void safeInputInit (struct safe_input *input, size_t size);

void getSafeChar (struct safe_input *input);

void getSafeLine (struct safe_input *input);

void getSafeStr (struct safe_input *input);

void safeInputClose (struct safe_input *input);

#endif