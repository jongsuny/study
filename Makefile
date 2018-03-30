# env related
CC						=g++
BUILD					=build

EXECUTABLE				=$(BUILD)/jcc

BUILD_NAME 				=jcc
CXXFLAGS				= -g
BUILD_NAME_DEBUG		=jcc-debug	
#LIB 					=/usr/local/lib/pugixml-1.8 
#INC 					=-I /usr/local/include/pugixml-1.8
INC 					+= -I src/include
INC 					+= -I pugixml
LINK					=-lpugixml
#SOURCES					= src/commons/file_operator.cpp src/main.cpp pugixml/pugixml.cpp 
SOURCES					= src/main.cpp
SOURCES					+= src/commons/jcc_io.cpp
SOURCES					+= pugixml/pugixml.cpp
OBJECTS					=$(SOURCES:%=$(BUILD)/%.o)

all:	$(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD)/%.o: %
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) $(INC)   -c $<  -o $@

clean:
	rm -rf $(BUILD)
run-help:
	./build/jcc -h
run:
	./build/jcc 
.PHONY: all clean
