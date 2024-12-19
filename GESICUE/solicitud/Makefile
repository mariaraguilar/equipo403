# Compilador y banderas
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++11

# Archivos fuente y objetos
SRCS = solicitud.cc test_solicitud.cc
OBJS = $(SRCS:.cc=.o)

# Ejecutable de prueba
TESTS = test_solicitud

# Regla por defecto: compilar el archivo de prueba
all: $(TESTS)

# Regla para compilar test_solicitud
test_solicitud: solicitud.o test_solicitud.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los objetos de la clase Solicitud
solicitud.o: solicitud.cc solicitud.h
	$(CXX) $(CXXFLAGS) -c solicitud.cc

# Regla para compilar el archivo de prueba
test_solicitud.o: test_solicitud.cc solicitud.h
	$(CXX) $(CXXFLAGS) -c test_solicitud.cc

# Limpiar los archivos generados
clean:
	rm -f $(OBJS) $(TESTS)

# Regla para ejecutar las pruebas
run: $(TESTS)
	./test_solicitud

.PHONY: all clean run
