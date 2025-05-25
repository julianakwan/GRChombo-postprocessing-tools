# -*- Mode: Makefile -*-

### This makefile produces an executable for each name in the `ebase'
###  variable using the libraries named in the `LibNames' variable.

# Included makefiles need an absolute path to the Chombo installation

# := means simply expanded, expanded once on the line and never again
PROJ_DIR := $(realpath $(shell pwd)/..)
BUILD_DIR := $(realpath $(shell pwd))



DIRS = Source SmallDataIOTest
SRC_DIRS = $(foreach dir, $(DIRS), $(addprefix $(PROJ_DIR)/, $(dir)))

#$(error   SRC_DIRS is $(SRC_DIRS))

VPATH = $(SRC_DIRS)

# Filesystem library is a C++17 feature
XTRACXXFLAGS := $(XTRACXXFLAGS) -std=c++17
#export XTRACXXFLAGS

# Older versions of GCC require explicit linking with the Filesystem library
XTRALDFLAGS := $(XTRALDFLAGS) -lstdc++fs
#export XTRALDFLAGS



LD = $(CXX)
LIB = 
INCL = 

BINROOT=./
EX=test.out
SHELL=/bin/bash

SRC = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))
HEADERS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.hpp))
INC = $(foreach dir, $(SRC_DIRS), $(addprefix -I, $(dir)))

#SRC = $(wildcard *.cpp)
#INC = $(wildcard *.hpp)
OBJ = $(SRC:.cpp=.o)


CXX = mpicxx
CXXFLAGS = 
CXXFLAGS += -std=c++17 -DTEST

#
# -- target : 	Dependencies
# --		Rule to create target

$(EX): 	$(OBJ) 
	$(LD) -o $@ $(CXXFLAGS) $(OBJ) $(LIB) 

####################################################################

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(INC) $< -o $@ 
#
# -- Remove *.o and *~ from the directory
clean:
	rm -f *.o *~ $(OBJ)
#
# -- Remove *.o, *~, and executable from the directory
realclean:
	rm -f *.o *~ $(OBJ) ./$(EX)

#
# -- Simple dependencies

$(OBJ) : $(HEADERS)
