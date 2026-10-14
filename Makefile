CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude -Itests

# Arquivos de teste da pasta tests/
TEST_SRC = tests/Teste_produto.cpp \
           tests/teste_administrador.cpp \
           tests/teste_carrinho.cpp \
           tests/teste_catalogo.cpp \
           tests/teste_cliente.cpp \
           tests/teste_pedido.cpp \
           tests/teste_sistema.cpp \
           tests/teste_usuario.cpp

EXEC_TEST = build/run_tests

all: $(EXEC_TEST)

# Regra de compilacao
$(EXEC_TEST): $(TEST_SRC)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(EXEC_TEST)

# Regra para rodar os testes
test: $(EXEC_TEST)
	./$(EXEC_TEST)

# Regras adicionais de execucao e limpeza
run: test

clean:
	rm -rf build/ $(EXEC_TEST)

.PHONY: all test run clean
