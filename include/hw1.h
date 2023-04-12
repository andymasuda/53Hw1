// This is a C header guard
#ifndef HW1_H
#define HW1_H

//This is a simple multi-line definition
#define USAGE_MSG   "Usage:\n"   \
                    "  53mstats -e | -c | -l [-V]\n"  \
                    "  53mstats -r FLAG | -t\n"     

typedef enum { false, true } bool;

typedef struct Options {
  char f;  //r flag
  bool v;  //verbose mode
} Options;

#endif