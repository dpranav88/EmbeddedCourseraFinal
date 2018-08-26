#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for generating executable, output, map and assembler code 
# from main.c and memory.c
# 
# Student: Pranav S. Deshpande
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build, compile-all, main.o, memory.o, main.asm, memory.asm, main.i, 
#      memory.i, main.d, memory.d, c1m2.asm
#
# Platform Overrides:
#      PLATFORM=HOST, PLATFORM=MSP432
#
#------------------------------------------------------------------------------
include sources.mk

.PHONY: build
.PHONY: compile-all
.PHONY: clean

# Paths for sources and includes

# Platform Overrides
PLATFORM = HOST
TARGET=c1m2.out

# Compile time switch to enable 'course1()' in 'main.c'
ifeq ($(COURSE1),1)
  COURSE1FLAGS = -DCOURSE1
endif
# Compile time switch to enable pritning in 'print_array()'
ifeq ($(VERBOSE),1)
  VERBOSEFLAGS = -DVERBOSE
endif

ifeq ($(PLATFORM),HOST) # for PC
	CC = gcc # compiler
	CFLAGS = -Wall -Werror -g -O0 -std=c99 # compiler flags
	CPPFLAGS = -MM -MT $*.d -MF $*.d -MD # preprocessor flags
	LDFLAGS = $(INCLUDES) -Wl,-Map=c1m2.map # Linker flags 
	OBJDUMP = objdump # objdump utility
	SIZE = size # size
	LINKER_FILE = # empty for host
	ARCH = # Architecture empty for host
	CPU = # CPU empty for host
	SPECS = # Specs empty for host
else # for uC
	CC = arm-none-eabi-gcc # compiler
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfpu=fpv4-sp-d16 --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99 # compiler flags
	CPPFLAGS = -MM -MT $*.d -MF $*.d -MD # preprocessor flags	
	LDFLAGS = -T$(LINKER_FILE) $(INCLUDES) -Wl,-Map=c1m2.map # Linker flags
	OBJDUMP = arm-none-eabi-objdump #objdump utility
	SIZE = arm-none-eabi-size # size
	LINKER_FILE = ./msp432p401r.lds # Linker file
	ARCH = thumb # Architecture
	CPU=cortex-m4 # CPU 
	SPECS = nosys.specs # Specs
endif

# compile and link all
build: compile-all main.d memory.d
	$(CC) $(CFLAGS) $(LDFLAGS) main.o memory.o -o $(TARGET)
	$(SIZE) $(TARGET) $(VERBOSEFLAGS) $(COURSE1FLAGS)
	
# dependencies
%.d:src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $< -D$(PLATFORM)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $< -D$(PLATFORM)

# executables
%.o: src/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $(@) -D$(PLATFORM)

# preprocessed files
%.i: src/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -E $< -o $(@) -D$(PLATFORM)

# assemblies
%.asm: src/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -S $< -o $(@) -D$(PLATFORM)

c1m2.asm: c1m2.out
	$(OBJDUMP) -S $< > $(@)

# compile all
compile-all: memory.o main.o

# clean: remove all unwanted files for fresh compilation	
clean:
	rm *.out *.o *.i *.asm *.map *.d -f
