#pragma once

#include <cstdint>

typedef struct {
    uint32_t bits;
    uint32_t code;
    uint32_t type;

    uint64_t rs1_id;
    uint64_t rs2_id;
    uint64_t rs3_id;

    uint64_t rd;
    uint64_t rs1;
    uint64_t rs2;
    uint64_t rs3;

    int64_t u_imm;
    int64_t i_imm;
    int64_t s_imm;
    int64_t sb_imm;
    int64_t uj_imm;
} inst_issue;
