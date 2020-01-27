CC=gcc
CXX=g++
RM=rm -f
CXXFLAGS=-g -std=c++11
CFLAGS= -g -O2

CXXSRCS=$(wildcard *.cpp)
CSRCS=$(wildcard *.c)
COBJS=$(subst .c,.o,$(CSRCS))
CXXOBJS=$(subst .cpp,.o,$(CXXSRCS))
CXXBINS=$(subst .cpp,,$(CXXSRCS))
COBJS=$(subst .c,.o,$(CSRCS))
CBINS=$(subst .c,,$(CSRCS))
CDSYMS=$(subst .c,.dSYM,$(CSRCS))
CXXDSYMS=$(subst .cpp,.dSYM,$(CXXSRCS))

SRCS = $(CXXSRCS) $(CSRCS)
OBJS = $(CXXOBJS) $(COBJS)
BINS = $(CXXBINS) $(CBINS)

all: $(BINS)

clean:
	@$(RM) $(OBJS) $(BINS)

distclean: clean
	@$(RM) -r $(CXXDSYMS) $(CDSYMS)
