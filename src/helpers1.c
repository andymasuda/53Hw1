#include "../include/hw1.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void printNumLines(bool verbose) {
  int numLines = 0;
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
  printf("Total number of lines: %d\n", numLines);
}

void printNumComments(bool verbose) {
  int numComments = 0;
  bool isComment = false;
  char c;

  for (c = getc(stdin); c != EOF; c = getc(stdin)) {
    if (c == '#' && !isComment) {
      ++numComments;
      isComment = true;
    }
    if (c == '\n') {
      isComment = false;
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
  int numLines = 0;
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
  printf("r %c\n", flag);
}

void printNumInstructions() {
  printf("t\n");
}
