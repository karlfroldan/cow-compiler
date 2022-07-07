#include "virtualmachine.hpp"
#include "keywords.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>

VirtualMachine::VirtualMachine(size_t memsize, std::string __program)
    : program_counter {0},
      mem_position {0},
      program_flag {true}
{
    this->memory.reserve(memsize);
    // // fill with 0s.
    for (auto i {0}; i < memsize; ++i) {
        this->memory.push_back(0);
    }
    // register is initially null.
    reg.reset();

    program = to_keywords(__program, ' ');
}

VirtualMachine::~VirtualMachine() {}

// Search reverse looking for a matching MOO and 
// execute program from there.
void VirtualMachine::cmd_moo() {
    Keyword current_keyword;

    size_t i { this->program_counter };

    // SEARCH for the MOO
    while (this->program[i] != MOO && i >= 0) {
        i -= 1;
       
    }

    this->program_counter = i; // place where moo is.
    this->program_flag = false; // we need the MOO to execute.
    if (i < 0) {
        std::cout << "Exit code 2. Command MOO not found!" << std::endl;
        std::exit(2);
    }
}

// Move current memory position back one block.
void VirtualMachine::cmd_mOo() {
    mem_position -= 1;
    program_flag = true;
    if (mem_position < 0) {
        std::cout << "Exit code 3. Memory Position cannot be negative. This is due to using mOo command incorrectly!" << std::endl;
        std::exit(3);
    }
}

void VirtualMachine::cmd_moO() {
    mem_position += 1;
    program_flag = true;
    auto m {memory.size()};
    std::cout << mem_position << '\n' << m << '\n';
    if (mem_position >= memory.size()) {
        std::cout << "Exit code 3. Memory Position cannot be larger than 32768. This is due to using moO command incorrectly!" << std::endl;
        std::exit(3);
    }
}

void VirtualMachine::cmd_Moo() {
    if (get_mem() == 0) {
        char c { (char) getchar() };
        this->memory[this->mem_position] = c;
    } else {
        printf("%c", get_mem());
        fflush(stdout);
    }
    program_flag = true;
}

void VirtualMachine::cmd_mOO() {
    auto inst { get_mem() };

    switch (inst)
    {
    case 0:
        cmd_moo();
        break;
    case 1:
        cmd_mOo();
        break;
    case 2:
        cmd_moO();
        break;
    case 3:
        cmd_mOO();
        break;
    case 4:
        cmd_Moo();
        break;
    case 5:
        cmd_MOo();
        break;
    case 6:
        cmd_MoO();
        break;
    case 7:
        cmd_MOO();
        break;
    case 8:
        cmd_OOO();
        break;
    case 9:
        cmd_OOM();
        break;
    case 10: 
        cmd_oom();
        break;
    default:
        std::cout << inst << " is not a valid command. Exiting..." << std::endl;
        std::exit(4);
        break;
    }
}

void VirtualMachine::cmd_MOo() {
    this->memory[this->mem_position] -= 1;
    program_flag = true;
}

void VirtualMachine::cmd_MoO() {
    this->memory[this->mem_position] += 1;
    program_flag = true;
}

void VirtualMachine::cmd_MOO() {
    if (get_mem() == 0) {
        // skip next command until `moo`.
        size_t moo_pos {program_counter};

        while (program[moo_pos] != moo) {
            moo_pos += 1;
        }

        moo_pos += 1;
        program_counter = moo_pos;

    } else {
        program_counter += 1;
    }
    program_flag = false;
}

void VirtualMachine::cmd_OOO() {
    this->memory[this->mem_position] = 0;
    program_flag = true;
}

void VirtualMachine::cmd_MMM() {
    if (!reg.has_value()) {
        reg = get_mem();
    } else {
        this->memory[this->mem_position] = reg.value();
        // clear register
        reg.reset();
    }
    program_flag = true;
}

void VirtualMachine::cmd_OOM() {
    printf("%d", get_mem());
    fflush(stdout);
    program_flag = true;
}

void VirtualMachine::cmd_oom() {
    uchar integer;
    scanf("%hu", &integer);
    this->memory[this->mem_position] = integer;
    program_flag = true;
}

uchar VirtualMachine::get_mem() {
    return this->memory[this->mem_position];
}

void VirtualMachine::run_program() {

    // While we have not yet reached the end of our program.
    while (this->program_counter < this->program.size()) {
        auto i {this->program_counter};

        switch (this->program[i]) {
        case moo:
            this->cmd_moo();
            break;
        case mOo:
            this->cmd_mOo();
            break;
        case moO:
            this->cmd_moO();
            break;
        case mOO:
            this->cmd_mOO();
            break;
        case Moo:
            this->cmd_Moo();
            break;
        case MOo:
            this->cmd_MOo();
            break;
        case MoO:
            this->cmd_MoO();
            break;
        case MOO:
            this->cmd_MOO();
            break;
        case OOO:
            this->cmd_OOO();
            break;
        case MMM:
            this->cmd_MMM();
            break;
        case OOM:
            this->cmd_OOM();
            break;
        case oom:
            this->cmd_oom();
            break;
        default:
            std::cout << "Program " << this->program[i] << " is not valid.\n";
            std::cout << "Exiting..." << std::endl;
            std::exit(5);
            break;
        }

        if (program_flag) {
            this->program_counter += 1;
        }
    }
}