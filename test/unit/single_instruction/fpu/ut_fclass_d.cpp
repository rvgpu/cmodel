#include "ut_inst.hpp"

TEST_F(ut_inst, decode_and_execute_rv64id_fclass_d) {
    // 0xe2001553 : fclass.d a0, f0
    insts.push_back(0xe2001553);

    SetFReg(fpreg::f0, std::bit_cast<uint64_t>(1.1));
    ExecuateInst();
    
    uint64_t res = GetIReg(reg::a0);
    EXPECT_EQ(res, 1 << 6);
}