#pragma once

#include <vector>
#include <string>

enum Keyword {
    moo = 0,  // search reverse looking for a matching MOO command.
    mOo = 1,  // move current memory position back one block
    moO = 2,  // move current memory position forward one block
    mOO = 3,  // execute value in current memory block as if it's an instruction
    Moo = 4,  // read an ASCII from STDIN and store in current memory block. Otherwise, print to STDOUT
    MOo = 5,  // decrement current memory block value by 1
    MoO = 6,  // increment current memory block value by 1
    MOO = 7,  // if 0, skip next command and resume execution after the next matching moo command.
              // if not 0, then continue with next command.
    OOO = 8,  // set current memory block value to 0.
    MMM = 9,  // if no current value in register, copy current memory block value.
              // otherwise, paste value in the current memory block and clear register.
    OOM = 10, // print value of current memory block to STDOUT as an integer.
    oom = 11  // read an integer from stdin and put it into the current memory block
};

std::vector<Keyword> to_keywords(std::string, char);