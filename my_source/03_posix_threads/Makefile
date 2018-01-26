CXX = gcc
CXX_FLAGS = -Wall -Wextra -g
CXX_LINK_FLAGS = -pthread

EXECS = posix_threads

all: ${EXECS}

posix_threads: posix_threads.c
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf $(EXECS)
