# env related
CC=g++

BUILD_NAME=jcc

BUILD_NAME_DEBUG=jcc-debug	
LIB=/usr/local/lib/pugixml-1.8 
INC 	=-I /usr/local/include/pugixml-1.8
INC 	+= -I include
all:	jcc
jcc: main.cpp
	$(CC) -L $(LIB) $(INC) -o $(BUILD_NAME) main.cpp
clean:
	rm -f $(BUILD_NAME) $(BUILD_NAME_DEBUG) *.o
