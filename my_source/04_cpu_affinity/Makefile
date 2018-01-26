CXX = gcc
CXX_FLAGS = -Wall -Wextra -g
CXX_LINK_FLAGS = -pthread

EXECS = cpu_affinity

all: ${EXECS}

cpu_affinity: cpu_affinity.c
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf $(EXECS)
