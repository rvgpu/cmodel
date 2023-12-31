#include "ut_inst.hpp"

TEST_F(ut_inst, decode_and_execute_rv64i_slliw) {
    //bits 0x00169c1b  #slliw   s8, a3, 1
    //operate on 32-bit values and produce signed 32-bit results
    insts.push_back(0x00169c1b);
    SetIReg(reg::a3, 0xf0000001);
    ExecuateInst();
    auto res = GetIReg(reg::s8);
    EXPECT_EQ(res, (int64_t)(int32_t)(0xf0000001 << 1));
}