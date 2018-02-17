CXX = gcc
CXX_FLAGS = -Wall -Wextra -g
CXX_LINK_FLAGS = -pthread

SERVER=ipc_sock_server
CLIENT=ipc_sock_client
EXECS = ${SERVER} ${CLIENT}

all: ${EXECS}

${SERVER}: ${SERVER}.c ipc_sock.h
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

${CLIENT}: ${CLIENT}.c ipc_sock.h
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf $(EXECS)
