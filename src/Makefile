OBJS = tokenizer.o history.o uimain.o
CFLAGS = -g -O3

all: Tokenizer

Tokenizer: $(OBJS)
	cc -o Tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o Tokenizer

run: Tokenizer
	./Tokenizer
