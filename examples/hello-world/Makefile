include ../../uni.mk
include ../examples.mk

LIBRARY = hello-world$(DLEXT)

all: $(LIBRARY) C/hello-world-test

run: all
	$(RUN_EXAMPLE)

C/hello-world-test: hello-world-test.c
	mkdir -p C
	$(ACC) $(SDK_INC) -Wall hello-world-test.c -o C/hello-world-test

$(LIBRARY): hello-world.cpp
	$(CXX) $(SDK_INC) -Wall hello-world.cpp $(SHARED) -o $(LIBRARY)

clean:
	rm $(LIBRARY) C/hello-world-test
