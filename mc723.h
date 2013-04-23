#ifndef _MC723_H
#define _MC723_H

#include <vector>

typedef enum {
  type1
} InstructionType;

typedef struct {
  int r_dest, r_read1, r_read2;
  InstructionType type;
} InstructionContext;

std::vector <InstructionContext> lastInstructions;

void createContext (int r_dest, int r_read1, int r_read2, InstructionType type);

#endif
