#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

void DummyTest_pass1(void)
{
    printf("OK pass 1");
    assert(true);
}

void DummyTest_pass2(void)
{
    printf("OK pass 2");
    assert(true);
}

void DummyTest_pass3(void)
{
    printf("OK pass 3");
    assert(true);
}

void DummyTest_fail1(void)
{
    printf("OK fail 1");
    assert(false);
}

void DummyTest_fail2(void)
{
    printf("OK fail 2");
    assert(false);
}

void DummyTest_slow1(void)
{
    sleep(2);
    assert(true);
}
void DummyTest_slow2(void)
{
    sleep(2);
    assert(true);
}

void DummyTest_runAll(void)
{ /* dummy */
}

typedef void TestFunction(void);

void Tester_checkSingleTest(int argc, char *argv[])
{
    unsigned long long address;

    if (argc != 1 + 3)
    {
        return;
    }

    if (strcmp(argv[1], "-test") != 0)
    {
        return;
    }

    if (strlen(argv[2]) != 16)
    {
        return;
    }

    if (strspn(argv[2], "0123456789abcdef") != 16)
    {
        return;
    }

    address = strtoull(argv[2], NULL, 16);
    if ((address == 0) || (address == ULLONG_MAX))
    {
        perror(NULL); // fprintf(stderr, "");
        exit(EXIT_FAILURE);
    }

    printf("address : %llu\n", address);
    TestFunction *test = (TestFunction *)address;
    fprintf(stderr, "Testing %s: ", argv[3]);
    fflush(stderr);
    test();
    fprintf(stderr, "OK\n");
    exit(EXIT_SUCCESS);
}
int main(int argc, char *argv[])
{
    Tester_checkSingleTest(argc, argv);
    fprintf(stdout, "hi hi!\n");
    return 0;
}
