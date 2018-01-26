CXX = gcc
CXX_FLAGS = -Wall -Wextra -g
CXX_LINK_FLAGS = -pthread

EXECS = defines

all: ${EXECS}

defines: defines.c
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf $(EXECS)
