CC = clang
CFLAGS = -std=c99 -W -Wall -Werror -pedantic -Wfatal-errors -g
CFLAGS += -D_XOPEN_SOURCE=700 # we use popen()
LIBS = # -lm

EXEC= autotest
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
MODULES = $(basename $(SOURCES))
OBJECTS = $(addsuffix .o , $(MODULES))

$(EXEC): $(OBJECTS)
	@echo === LINKING $@ ===
	$(CC) $^ $(LIBS) -o $@

.c.o:
	@echo === COMPILING $@ ===
	$(CC) $< $(CFLAGS) -c

depend: $(SOURCES) $(HEADERS)
	@echo === COMPUTING $@ ===
	$(CC) -MM $(SOURCES) | tee $@

clean ::
	@echo === CLEANING ===
	rm -f *.o

-include depend

