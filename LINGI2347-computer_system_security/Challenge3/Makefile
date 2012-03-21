EXEC=hello
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o) 
CC = g++
all: $(EXEC)
LDFLAGS = -lcrypto

hello: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean mrproper

clean:
	@rm *.o

mrproper: clean
	@rm $(EXEC)
