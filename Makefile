# Definições de compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_DIR = bin

# Nome do executável
TARGET = $(BIN_DIR)/tp2.out

# Arquivos de origem e objeto
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Cria o diretório de binários, se não existir
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Cria o diretório de objetos, se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regra padrão
all: $(OBJ_DIR) $(BIN_DIR) $(TARGET)

# Compila o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compila os arquivos .cpp para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Executa o programa
run: all
	./$(TARGET)

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean run
