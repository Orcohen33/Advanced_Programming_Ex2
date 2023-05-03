.PHONY: all
all: task stdinExample coder

task:
	gcc basic_main.c ./libCodec.so -o encoder

stdinExample:
	gcc stdin_main.c ./libCodec.so -o tester

coder:
	gcc coder_main.c threadpool.c ./libCodec.so -o coder -lpthread

.PHONY: clean
clean:
	-rm encoder tester coder *file 2>/dev/null