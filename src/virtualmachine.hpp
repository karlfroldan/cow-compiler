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


    /* FOR TESTING PURPOSES */
    std::vector<uchar>& get_memory() {
        return memory;
    }

    std::vector<Keyword> get_program() {
        return program;
    }

    size_t get_program_counter() {
        return program_counter;
    }

    size_t get_mem_position() {
        return mem_position;
    }

    std::optional<uchar> get_register() {
        return reg;
    }

    void set_program_counter(size_t i) { program_counter = i; }
    void set_mem_position(size_t i) { mem_position = i; }
    void set_register(uchar opt) { reg = opt; }

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
};