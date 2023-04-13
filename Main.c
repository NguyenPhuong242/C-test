#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>
#include <signal.h>

#include "Tester.h"

//------------------------------------------------------------------------------

void DummyTest_pass1 (void) { assert (true ); }
void DummyTest_pass2 (void) { assert (true ); }
void DummyTest_pass3 (void) { assert (true ); }

void DummyTest_fail1 (void) { assert (false); }
void DummyTest_fail2 (void) { assert (false); }

void DummyTest_slow1 (void) { sleep (2); assert (true); }
void DummyTest_slow2 (void) { sleep (2); assert (true); }

void DummyTest_runAll (void) { /* dummy */ }

//------------------------------------------------------------------------------

int main (int argc, char * argv[]) {
  Tester_checkAllTests          (argc, argv);
  Tester_checkAllTestsWithPopen (argc, argv);
  Tester_checkAllTestsWithFork  (argc, argv);
  Tester_checkAllTestsWithExec  (argc, argv);
  Tester_checkAllTestsWithPipe  (argc, argv);
  Tester_checkSingleTest        (argc, argv);
  fprintf (stdout, "Hello World!\n");
  return 0;
}
