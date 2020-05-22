CC	= g++
CFLAGS	= -g -std=c++17 -MMD -Wall -Ofast
LDFLAGS = -Ofast
LIBS	= 
INCLUDE = -I ./include
SRC_DIR = ./source
OBJ_DIR = ./build
SOURCES = $(shell ls $(SRC_DIR)/*.cpp) 
OBJS		= $(subst $(SRC_DIR),$(OBJ_DIR), $(SOURCES:.cpp=.o))
TARGET	= BymlEditor
DEPENDS = $(OBJS:.o=.d)

all: clean $(OBJS) $(TARGET) run
$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	@if [ ! -d $(OBJ_DIR) ]; \
		then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
	fi
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
run:
	./BymlEditor

clean:
	$(RM) $(OBJS) $(TARGET) $(DEPENDS)

-include $(DEPENDS)

.PHONY: all clean run
