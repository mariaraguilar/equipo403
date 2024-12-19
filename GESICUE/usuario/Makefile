# Compilador y banderas
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++11

# Archivos fuente y objetos
SRCS = usuario.cc test_usuario.cc
OBJS = $(SRCS:.cc=.o)

# Ejecutable de prueba
TESTS = test_usuario

# Regla por defecto: compilar el archivo de prueba
all: $(TESTS)

# Regla para compilar test_usuario
test_usuario: usuario.o test_usuario.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los objetos de la clase Usuario
usuario.o: usuario.cc usuario.h
	$(CXX) $(CXXFLAGS) -c usuario.cc

# Regla para compilar el archivo de prueba
test_usuario.o: test_usuario.cc usuario.h
	$(CXX) $(CXXFLAGS) -c test_usuario.cc

# Limpiar los archivos generados
clean:
	rm -f $(OBJS) $(TESTS)

# Regla para ejecutar las pruebas
run: $(TESTS)
	./test_usuario

.PHONY: all clean run
