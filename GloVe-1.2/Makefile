CC = gcc
#For older gcc, use -O3 or -O2 instead of -Ofast
CFLAGS = -lm -pthread -Ofast -march=native -funroll-loops -Wno-unused-result
BUILDDIR := build
SRCDIR := src

all: dir vocab_count shuffle cooccur glove 

dir :
	mkdir -p $(BUILDDIR)
glove : $(SRCDIR)/glove.c
	$(CC) $(SRCDIR)/glove.c   $(SRCDIR)/get_vocabhash.c   -o $(BUILDDIR)/glove $(CFLAGS)
shuffle : $(SRCDIR)/shuffle.c
	$(CC) $(SRCDIR)/shuffle.c -o $(BUILDDIR)/shuffle $(CFLAGS)
cooccur : $(SRCDIR)/cooccur.c
	$(CC) $(SRCDIR)/cooccur.c -o $(BUILDDIR)/cooccur $(CFLAGS)
vocab_count : $(SRCDIR)/vocab_count.c
	$(CC) $(SRCDIR)/vocab_count.c -o $(BUILDDIR)/vocab_count $(CFLAGS)

test:
	$(CC) $(SRCDIR)/test.c -o $(BUILDDIR)/test $(CFLAGS)
	./$(BUILDDIR)/test
clean:
	rm -rf glove shuffle cooccur vocab_count build
