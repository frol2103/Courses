CC = g++
all: $(EXEC)
LDFLAGS = -lcrypto -lpthread
CFLAGS = -g

EXEC = precompute merge find

PRECOMPUTE_OBJ 	= md5chainedlist.o md5i.o md5table.o passchain.o util.o precompute.o
MERGE_OBJ 		= merge.o md5chainedlist.o md5table.o md5i.o passchain.o util.o
FIND_OBJ 		= find.o md5chainedlist.o md5table.o md5i.o passchain.o util.o
TEST_OBJ 		= test.o md5chainedlist.o md5table.o md5i.o passchain.o util.o

md5chainedlist.o : md5chainedlist.cpp md5chainedlist.h passchain.o
md5i.o : md5i.cpp md5i.h
md5table.o : md5table.h md5table.cpp md5chainedlist.o passchain.o
passchain.o : md5i.o
util.o : util.cpp util.h
precompute.o : precompute.cpp
merge.o : merge.cpp
find.o : find.cpp
test.o : test.cpp

precompute: $(PRECOMPUTE_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

merge: $(MERGE_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

find: $(FIND_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

test: $(TEST_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean mrproper

clean:
	@rm *.o

mrproper: clean
	@rm $(EXEC)
