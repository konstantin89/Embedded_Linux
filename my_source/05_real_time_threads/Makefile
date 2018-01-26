CXX = gcc
CXX_FLAGS = -Wall -Wextra -g
CXX_LINK_FLAGS = -pthread

EXECS = real_time_threads

all: ${EXECS}

real_time_threads: real_time_threads.c
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf $(EXECS)
