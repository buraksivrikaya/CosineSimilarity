OBJS =  CosSimilarity.c LinkedList.c FileReader.c
CC = gcc
LIBS = -lm

CosSim:${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core CosSim

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
