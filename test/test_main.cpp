#include <gtest/gtest.h>
#include "../src/virtualmachine.hpp"

// TEST(HelloTest, BasicAssertions) {
//     // expect two strings not to be eqal
//     EXPECT_STRNE("hello", "world");
//     EXPECT_EQ(7 * 6, 42);
// }

TEST(VirtualMachineTest, TEST_moo) {
    VirtualMachine vm(10, "OOO mOo MOO oom moo mOO");
    vm.set_program_counter(4); // set it to the `moo`.
    vm.cmd_moo(); // it should move the program counter to 2.
    EXPECT_EQ(vm.get_program_counter(), 2);
}

TEST(VirtualMachineTest, TEST_mOO) {
    VirtualMachine vm(5, "oom MOO mOo mOO");
    vm.set_program_counter(3);
    // set memory pointer to 4.
    vm.set_mem_position(4);
    vm.get_memory()[4] = 0;
    vm.cmd_mOO();
    // this should execute `moo`.
    EXPECT_EQ(vm.get_program_counter(), 1);
}
