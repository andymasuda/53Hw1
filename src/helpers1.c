#include "../include/hw1.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void printNumLines(bool verbose) {
  int numLines = 1;
  int bufferLength = 255;
  char buffer[bufferLength];

  while (fgets(buffer, bufferLength, stdin)) {
    if (buffer[0] == '\n') {
      continue;
    }
    if (verbose) {
      int i = 0;
      while (isspace(buffer[i])) {
        i++;
      }
      fprintf(stderr, "%d: %s", numLines, buffer + i);
    }
    numLines++;
  }
  printf("Total number of lines: %d\n", --numLines);
}

void printNumComments(bool verbose) {
  int lineNum = 1;
  int numComments = 0;
  bool isComment = false;
  char c;

  for (c = getc(stdin); c != EOF; c = getc(stdin)) {
    if (isComment && verbose) {
      printf("%c", c);
    }
    if (c == '#' && !isComment) {
      numComments++;
      isComment = true;
      if (verbose) {
        printf("%d: %c", lineNum, c);
      }
    }
    if (c == '\n') {
      isComment = false;
      lineNum++;
    }
  }
  printf("Total number of comments: %d\n", numComments);
}

bool isLabel(char *str) {
  int i = 0;

  if (isdigit(str[i]) || isspace(str[i])) {
    return false;
  }
  while (isalnum(str[i]) || str[i] == '_' || str[i] == '.') {
    i++;
  }
  if (str[i] == ':') {
    return true;
  }
  return false;
}

void printNumLabels(bool verbose) {
  int numLabels = 0;
  int numLines = 1;
  int bufferLength = 255;
  char buffer[bufferLength];

  while (fgets(buffer, bufferLength, stdin)) {
    if (isLabel(buffer)) {
      if (verbose) {
        fprintf(stderr, "%d: %s", numLines, buffer);
      }
      numLabels++;
    }
    numLines++;
  }
  printf("Total number of labels: %d\n", numLabels);
}

void printHistogram(char flag) {
  char c;
  int numRegisters;

  if (flag == 't') {
    numRegisters = 10;
  } else {
    numRegisters = 8;
  }

  int registers[numRegisters];

  while ((c = getchar()) != EOF) {
    if (c == '#') {
      while ((c = getchar()) != EOF && c != '\n') {
      }
    } else if (c == '$') {
      c = getchar();
      if (c == flag) {
        c = getchar();
        if (c >= '0' && c <= '7') {
          registers[c - '0']++;
        }
      }
    }
  }

  for (int i = 0; i < numRegisters; i++) {
    printf("$%c%d: ", flag, i);
    for (int j = 0; j < registers[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void printNumInstructions() { printf("t\n"); }
