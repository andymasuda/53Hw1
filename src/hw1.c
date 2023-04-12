#include "hw1.h"
#include "helpers1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  Options option;

  if (argc > 3 || argc < 2 || argv[1][0] != '-') {
    perror(USAGE_MSG);
    exit(1);
  }

  if (argc == 3) {
    if (!strcmp(argv[1], "-e") || !strcmp(argv[1], "-c") ||
        !strcmp(argv[1], "-l")) {
      if (!strcmp(argv[2], "-V")) {
        option.v = true;
      } else {
        perror(USAGE_MSG);
        exit(1);
      }
      switch (argv[1][1]) {
      case 'e':
        printNumLines(option.v);
        break;
      case 'c':
        printNumComments(option.v);
        break;
      case 'l':
        printNumLabels(option.v);
        break;
      default:
        perror(USAGE_MSG);
        exit(1);
      }
    } else if (!strcmp(argv[1], "-r")) {
      if (!strcmp(argv[2], "s")) {
        option.f = 's';
      } else if (!strcmp(argv[2], "t")) {
        option.f = 't';
      } else {
        perror(USAGE_MSG);
        exit(1);
      }
      printHistogram(option.f);
    } else {
      perror(USAGE_MSG);
      exit(1);
    }
  } else {
    if (!strcmp(argv[1], "-e") || !strcmp(argv[1], "-c") ||
        !strcmp(argv[1], "-l") || !strcmp(argv[1], "-t")) {
      switch (argv[1][1]) {
      case 'e':
        printNumLines(option.v);
        break;
      case 'c':
        printNumComments(option.v);
        break;
      case 'l':
        printNumLabels(option.v);
        break;
      case 't':
        printNumInstructions();
        break;
      default:
        perror(USAGE_MSG);
        exit(1);
      }
    } else {
      perror(USAGE_MSG);
      exit(1);
    }
  }
  return 0;
}
