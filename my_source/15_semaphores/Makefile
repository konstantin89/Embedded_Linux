CXX = gcc
CXX_FLAGS = -Wall -Wextra -g
CXX_LINK_FLAGS = -pthread

EXEC = posix_semaphores

all: ${EXEC}

${EXEC}: ${EXEC}.c
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf ${EXEC}
