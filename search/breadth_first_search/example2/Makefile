CXX = g++

CXXFLAGS = -std=c++17 -Wall

EXAMPLE_EXECUTABLE = example
SOURCES = example.cpp

BUILD_DIR = build

OBJECTS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

all: $(BUILD_DIR) $(EXAMPLE_EXECUTABLE)

$(EXAMPLE_EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXAMPLE_EXECUTABLE) $(OBJECTS)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean target
clean:
	rm -rf $(BUILD_DIR) $(EXAMPLE_EXECUTABLE)

.PHONY: all clean
