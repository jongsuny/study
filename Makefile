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
SOURCES					=src/main.cpp pugixml/pugixml.cpp
OBJECTS					=$(SOURCES:%=$(BUILD)/%.o)

all:	$(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD)/%.o: %
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) $(INC)   -c $<  -o $@

clean:
	rm -rf $(BUILD)
.PHONY: all clean
