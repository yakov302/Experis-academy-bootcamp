#include "mu_test.h"

#include  <sstream>

#include "working_memory.hpp"
#include "bf_code.hpp"
#include "bf_machine.hpp"
#include "bf_instructions.hpp"

BEGIN_TEST(bf_memory_test)

    bf::WorkingMemory<short> data;

    auto w = data.read();    
    ASSERT_EQUAL(w, 0);   
    
    data.forward();
    w = data.read();
    ASSERT_EQUAL(w, 0);    
    
    data.write(42);
    w = data.read();
    ASSERT_EQUAL(w, 42);  

END_TEST


BEGIN_TEST(bf_code_test)

    using BrainOpCode = unsigned char;
    using MemoryUnit = short;
    
    std::istringstream program{"+++++ +++[- >++++ ++++< ]>+++ +++++ ++++. <++++ +[->+ ++++< ]>.-- .<++++[->+ +++<] >+.+. ---.< +++[- >---< ]>--- -.<++ +++++ +[->- ----- --<]>----- .<+++ +++++ [->++ +++++ +<]>+ +++++ +++++ ++++. -.<++ +++++ +[->------ --<]> ----- ----- ----. <++++ +++[- >++++ +++<] >++.< +++++ [->+++++<] >++++ +++++ .---- ---.< +++[- >---< ]>-.- --.<+ +++[- >++++ <]>+++++++ +.<++ +++++ ++[-> ----- ----< ]>--- ----- .<+++ +++++ +[->+ ++++++++<] >++++ ++.<+ ++[-> ---<] >---- -.+++ ..<++ +++++ +[->- ----- --<]>----- ----- --.<+ +++++ +++[- >++++ +++++ <]>++ .+.<+ +++[- >---- <]>---.<++ ++[-> ++++< ]>+.+ +.<++ +++++ ++[-> ----- ----< ]>--- .<+++ +++++[->++ +++++ +<]>+ .<+++ +[->+ +++<] >+++. <++++ +++++ [->-- ----- --<]>---.< +++++ [->++ +++<] >.+.- ----- -.--- .--.< +++[- >---< ]>--- --.<++++++ [->++ ++++< ]>+++ +++++ +.<++ ++++[ ->+++ +++<] >++++ .<+++ [->---<]>- ---.- ----- -.<++ +[->+ ++<]> +++.. <+++[ ->--- <]>-- -.+++ .<"};
    
    bf::CodeSegment<BrainOpCode> code(program);
    bf::WorkingMemory<MemoryUnit> memory;

    bf::InstructionSet<BrainOpCode, MemoryUnit> isa;
    bf::BrainFuckMachine<MemoryUnit, BrainOpCode> machine{memory, code, isa};
    machine.run();

    ASSERT_PASS();    

END_TEST


BEGIN_SUITE(brainfuck)

    TEST(bf_memory_test)
    TEST(bf_code_test)

END_SUITE
