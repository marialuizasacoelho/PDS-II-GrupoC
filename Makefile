
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude -Itests

# Arquivos de teste
TEST_SRC = tests/Teste_produto.cpp \
           tests/teste_administrador.cpp \
           tests/teste_carrinho.cpp \
           tests/teste_catalogo.cpp \
           tests/teste_cliente.cpp \
           tests/teste_pedido.cpp \
           tests/teste_sistema.cpp \
           tests/teste_usuario.cpp

# Arquivos de implementação em src/
SRC = $(wildcard src/*.cpp)

EXEC_TEST = build/run_tests

all: $(EXEC_TEST)

# Compila os testes junto com as implementações
$(EXEC_TEST): $(TEST_SRC) $(SRC)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(SRC) -o $(EXEC_TEST)

# Executa os testes
test: $(EXEC_TEST)
	./$(EXEC_TEST)

run: test

clean:
	rm -rf build/

.PHONY: all test run clean
