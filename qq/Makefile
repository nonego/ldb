C = gcc
CXX = g++
LINK = g++

CFLAGS = -Wall -I ../include 
CXXFLAGS = $(CFLAGS)

ifeq ($(DEBUG), 1)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2 -DNDEBUG
endif

LIBDIR = .
LIBS = -L $(LIBDIR) -lleveldb -lsnappy -lpthread

PUBLIBS =

OBJS = 

.PHONY:all

all: testread testwrite

testread: testread.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $< $(OBJS) $(PUBLIBS) $(LIBS)

testwrite: testwrite.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $< $(OBJS) $(PUBLIBS) $(LIBS)

clean:
	rm -rf $(OBJS) 
