#ifndef _MC723_H
#define _MC723_H

#include <vector>

#define NOT_USED -1

// --------- hazard ------------

typedef enum {
  UNITIALIZED,
  MEMORY_READ,
  NORMAL_INST
} InstructionType;

typedef struct {
  int r_dest, r_read1, r_read2;
  InstructionType type;
} InstructionContext;

InstructionContext lastInstruction;
InstructionContext currentInstruction;

void createContext (int r_dest, int r_read1, int r_read2, InstructionType type);

// ---------- cache ------------

#define CACHE_SIZE 32

typedef struct {
    int addr;
    bool valid;
} CacheData;

CacheData cache[CACHE_SIZE];

#endif
