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

/************** Cache ****************/

#define DATA_CACHE_SIZE 64
#define DATA_CACHE_SIZE_BITS 6
// mask to get the INDEX value from the address without the block offset (we are interested in the last bits)
#define DATA_ROW_MASK 0x3F
// #define DATA_BLOCK_OFFSET_SIZE 4
#define DATA_BLOCK_OFFSET_SIZE_BITS 4

#define BYTE_OFFSET_SIZE_BITS 2
// mask to get the BLOCK OFFSET from address (0000001 in binary)
#define DATA_BLOCK_OFFSET_MASK 1

#define INSTRUCTION_CACHE_SIZE 16
#define INSTRUCTION_CACHE_SIZE_BITS 4
// mask to get the INDEX value from the address without the block offset (we are interested in the last bits)
#define INSTRUCTION_ROW_MASK 0xF
// #define INSTRUCTION_BLOCK_OFFSET_SIZE 16
#define INSTRUCTION_BLOCK_OFFSET_SIZE_BITS 6

// *_BLOCK_OFFSET_BITS must be log2(CACHE_BLOCK_SIZE*4)

typedef struct {
    int tag;
    bool valid;
    bool dirty;
} CacheEntry;

CacheEntry dataCache[DATA_CACHE_SIZE];
CacheEntry instructionCache[INSTRUCTION_CACHE_SIZE];

/*************************************************/

/************** Branch Prediction ****************/

#define K 15
#define PRED_INDEX(ADDR) ((ADDR >> 2) & ((1 << K) - 1))

enum OneBitState {
  NOT_TAKEN    = 0,
  TAKEN        = 1
};

enum TwoBitState {
  NOT_TAKEN_1 = 0,
  NOT_TAKEN_0 = 1,
  TAKEN_0     = 2,
  TAKEN_1     = 3
};

struct AlwaysTakenPredictor {
  unsigned int jump_to;
};

typedef AlwaysTakenPredictor NeverTakenPredictor;

struct OneBitPredictor {
  OneBitState state;
  unsigned int jump_to; 
};

struct TwoBitPredictor {
  TwoBitState state;
  unsigned int jump_to;
};

// Counting
unsigned long long alwaysTakenHitCount;
unsigned long long alwaysTakenMissCount;
unsigned long long neverTakenHitCount;
unsigned long long neverTakenMissCount;
unsigned long long oneBitHitCount;
unsigned long long oneBitMissCount;
unsigned long long twoBitHitCount;
unsigned long long twoBitMissCount;

// States
NeverTakenPredictor neverTakenPredictor[1 << K];
AlwaysTakenPredictor alwaysTakenPredictor[1 << K];
OneBitPredictor oneBitPredictor[1 << K];
TwoBitPredictor twoBitPredictor[1 << K];

/*************************************************/

#endif
