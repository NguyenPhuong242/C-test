#ifndef TESTER_H
#define TESTER_H

typedef void TestFunction (void);

void Tester_checkSingleTest        (int argc, char * argv[]);

void Tester_checkAllTests          (int argc, char * argv[]);
void Tester_checkAllTestsWithPopen (int argc, char * argv[]);
void Tester_checkAllTestsWithFork  (int argc, char * argv[]);
void Tester_checkAllTestsWithExec  (int argc, char * argv[]);
void Tester_checkAllTestsWithPipe  (int argc, char * argv[]);

#endif
