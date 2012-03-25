CC = g++
all: $(EXEC)
LDFLAGS = -lcrypto
CFLAGS = -g

EXEC = precompute

PRECOMPUTE_OBJ = md5chainedlist.o md5i.o md5table.o passchain.o util.o precompute.o

md5chainedlist.o : md5chainedlist.cpp md5chainedlist.h passchain.o
md5i.o : md5i.cpp md5i.h
md5table.o : md5table.o md5table.cpp md5chainedlist.o passchain.o
passchain.o : md5i.o
util.o : util.cpp util.h
precompute.o : precompute.cpp 

precompute: $(PRECOMPUTE_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean mrproper

clean:
	@rm *.o

mrproper: clean
	@rm $(EXEC)
