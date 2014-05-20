CC        = cc 
CSOURCE   = main.c purple_malloc.c tree.c
CHEADER	 = purple_malloc.h tree.h
EXECBIN   = purple_malloc

all : ${EXECBIN}

${EXECBIN} : ${CSOURCE:.c=.o}
	${CC} -o  $@ ${CSOURCE:.c=.o}

%.o : %.c
	${CC} -c  $<

clean:
	-rm ${CSOURCE:.c=.o} ${EXECBIN}

move:
	cp ${CSOURCE} ${CHEADER} ~/Desktop/MINIX/root/Project-3
