CXX = g++
CXXFLAGS = -g -Wall 
LIBS = -lpthread
UNITTEST_CFLAGS = $(shell pkg-config --cflags unittest++)
UNITTEST_LIBS = $(shell pkg-config --libs unittest++)

.SUFFIXES: .o .cpp

library_name = libjthread.a
source_files =									\
	src/jRunnable.cpp							\
	src/jThread.cpp
object_files = $(patsubst %.cpp, %.o, $(source_files))

library_test = testjThread
test_source_files =								\
	test/main.cpp							\
	test/testjThread.cpp
test_object_files = $(patsubst %.cpp, %.o, $(test_source_files))

all: $(library_test)

$(library_name): $(object_files)
	@echo creating $(library_name) library...
	@ar cr $(library_name) $(object_files)

$(library_test): $(library_name) $(test_object_files)
	@echo linking $(library_test)...
	$(CXX) -o $(library_test) $(test_object_files) $(library_name) $(LIBS) $(UNITTEST_LIBS)
	@echo runing unit tests...
	@./$(library_test)

clean:
	@rm -f $(object_files) $(test_object_files) $(library_test) $(library_name)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(UNITTEST_CFLAGS) -c -o $@ $< $(LIBS) 
