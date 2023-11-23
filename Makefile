#   /**
#    * @author Jakub Hýl <hylkuba@gmail.com>
#    * @date 22.11.2023
#   */

NAME = wordle

ifeq ($(shell uname),Linux)
    CXX = g++
    LD = g++
    CXXFLAGS = -Wall -pedantic -std=c++17 -g -O2 -fsanitize=address
    LDFLAGS = -fsanitize=address
    TARGET = $(NAME)
else
    CXX = g++
    LD = g++ -mconsole
    CXXFLAGS = -Wall -pedantic -Wextra -std=c++17 -g -O2 -mconsole
    LDFLAGS = -m64
    TARGET = $(NAME).exe
endif

HEADERS = $(wildcard src/*.h)
# SOURCES = $(wildcard src/*.cpp)

DIR_NAME = bin

OBJS = $(DIR_NAME)/main.o $(DIR_NAME)/application.o  $(DIR_NAME)/controls.o $(DIR_NAME)/ui.o $(DIR_NAME)/wordCheck.o $(DIR_NAME)/wordGen.o

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

#-----------------------------------------------------------------------
# All .o objects stored in folder
run: | $(DIR_NAME) compile
	./$(TARGET)

$(DIR_NAME):
	mkdir -p $(DIR_NAME)

compile: $(DIR_NAME) $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile

.PHONY: clean
clean:
	rm -rf $(DIR_NAME) $(TARGET) doc/ 2>/dev/null

$(DIR_NAME)/%.o: src/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all
all: doc run clean

#-----------------------------------------------------------------------
# Object files dependencies
$(DIR_NAME)/main.o: src/main.cpp src/application.h src/ui.h \
 src/controls.h src/wordCheck.h src/wordGen.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_NAME)/application.o: src/application.cpp src/application.h src/ui.h \
 src/controls.h src/wordCheck.h src/wordGen.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_NAME)/controls.o: src/controls.cpp src/controls.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_NAME)/ui.o: src/ui.cpp src/ui.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_NAME)/wordCheck.o: src/wordCheck.cpp src/wordCheck.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_NAME)/wordGen.o: src/wordGen.cpp src/wordGen.h
	$(CXX) $(CXXFLAGS) -c $< -o $@