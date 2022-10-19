CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=llrec.o

all: llrec-test

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec.o: llrec.cpp llrec.h llrec-test.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

stack.o: stack.h stack.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c stack.cpp


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 