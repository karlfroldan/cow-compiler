#pragma once

#include <vector>
#include <optional>
#include <string>

#include "keywords.hpp"

using uchar = unsigned short int;

class VirtualMachine {
public:
    VirtualMachine(size_t, std::string);
    ~VirtualMachine();

    void run_program();
private:
    std::vector<Keyword> program;
    size_t program_counter;
    size_t mem_position;
    std::vector<uchar> memory;
    std::optional<uchar> reg;

    // if TRUE, then increase program counter on execution
    // if FALSE, then do not increase program counter on execution.
    bool program_flag;

    uchar get_mem();

    void cmd_moo();
    void cmd_mOo();
    void cmd_moO();
    void cmd_mOO();
    void cmd_Moo();
    void cmd_MOo();
    void cmd_MoO();
    void cmd_MOO();
    void cmd_OOO();
    void cmd_MMM();
    void cmd_OOM();
    void cmd_oom();
};