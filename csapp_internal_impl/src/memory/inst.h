#include <stdint.h>
#include <stdlib.h>

#ifndef INST_H
#define INST_H

#define NUM_INST_TYPE 30

typedef enum OP
{
    MOV_REG_REG,
    ADD_REG_REG,
    MOV_REG_MEM,
    MOV_MEM_REG,
    POP_REG,
    PUSH_REG,
    CALL,
    RET,
} op_t;

typedef enum OD_TYPE
{
    EMPTY,
    IMM,
    REG,
    MM_IMM,
    MM_REG,
    MM_IMM_REG,
    MM_REG1_REG2,
    MM_IMM_REG1_REG2,
    MM_REG2_S,
    MM_IMM_REG2_S,
    MM_REG1_REG2_S,
    MM_IMM_REG1_REG2_S,
} od_type_t;

typedef struct OD
{
    od_type_t type;
    int64_t imm;
    int64_t scale;
    uint64_t *reg1;
    uint64_t *reg2;
} od_t;

typedef struct INSTRUCT_STRUCT
{
    op_t op;
    od_t src;
    od_t dst;
    char code[100];
} inst_t;

// op function
// typedef

typedef void (*handler_t)(uint64_t, uint64_t);

handler_t handler_table[NUM_INST_TYPE];

void init_handler_table();

void add_reg_reg_handler(uint64_t src, uint64_t dst);
void move_reg_reg_handler(uint64_t src, uint64_t dst);

void inst_cycle();

#endif
