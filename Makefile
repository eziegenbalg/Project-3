CC        = cc
CSOURCE   = main.c purple_malloc.c tree.c
CHEADER	 = purple_malloc.h tree.h
EXECBIN   = purple_malloc

all : ${EXECBIN}

${EXECBIN} : ${CSOURCE:.c=.o}
	${CC} -o  $@ ${CSOURCE:.c=.o} -lm

%.o : %.c
	${CC} -c  $<

clean:
	-rm ${CSOURCE:.c=.o} ${EXECBIN}

move:
	cp ${CSOURCE} ${CHEADER} Makefile ~/Desktop/MINIX/root/Project-3
