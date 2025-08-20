CXX = clang++
CXXFLAGS = -std=c++17 -MMD -MP $(shell llvm-config --cxxflags)

CLANG_LIBS = $(wildcard /opt/homebrew/opt/llvm/lib/libclang*.a)
LDFLAGS = $(shell llvm-config --ldflags --system-libs --libs all) $(CLANG_LIBS)

	  # -lclangTooling -lclangFrontend -lclangSerialization \
	  # -lclangDriver -lclangParse -lclangSema \
	  # -lclangEdit -lclangAST -lclangLex -lclangBasic \
	  # -lclangAnalysis -lclangASTMatchers \
	  # -lclangRewrite -lclangRewriteFrontend \
	  # -lclangStaticAnalyzerFrontend -lclangStaticAnalyzerCheckers -lclangStaticAnalyzerCore

SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
BIN = build/corozivec

all: $(BIN)

# Compilation de l'executable
$(BIN): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

run: $(BIN)
	./$(BIN) test.c

debug:
	@echo "CXXFLAGS=$(CXXFLAGS)"
	@echo "LDFLAGS=$(LDFLAGS)"

clean: 
	rm -fr $(OBJ) $(DEP) $(BIN) compile_commands.json
