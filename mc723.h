#ifndef _MC723_H
#define _MC723_H

#include <vector>

// --------- hazard ------------

#define NOT_USED -1

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

#define DATA_CACHE_SIZE 256
#define INSTRUCTION_CACHE_SIZE 32

// BLOCK_OFFSET_BITS must be log2(CACHE_BLOCK_SIZE*4)

#define CACHE_BLOCK_SIZE 8
#define BLOCK_OFFSET_BITS 5

typedef struct {
    int addr;
    bool valid;
    bool dirty;
} CacheEntry;

CacheEntry dataCache[DATA_CACHE_SIZE];
CacheEntry instructionCache[INSTRUCTION_CACHE_SIZE];

#endif
