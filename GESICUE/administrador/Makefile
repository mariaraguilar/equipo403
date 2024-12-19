# Archivos fuente
ADMINISTRADOR_SRC = administrador.cc
TEST_ADMINISTRADOR_SRC = test_administrador.cc
USUARIO_SRC = ../usuario/usuario.cc

# Archivos objeto
ADMINISTRADOR_OBJ = administrador.o
TEST_ADMINISTRADOR_OBJ = test_administrador.o
USUARIO_OBJ = ../usuario/usuario.o

# Nombre del ejecutable
EXEC = test_administrador

# CXXFLAGS (flags de compilación)
CXXFLAGS = -g -Wall -Wextra -pthread -std=gnu++11

# Directorios de inclusión
INCLUDES = -I../usuario -I.

# Reglas de compilación
all: $(EXEC)

$(EXEC): $(ADMINISTRADOR_OBJ) $(USUARIO_OBJ) $(TEST_ADMINISTRADOR_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(ADMINISTRADOR_OBJ): $(ADMINISTRADOR_SRC) ../usuario/usuario.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(ADMINISTRADOR_SRC) -o $(ADMINISTRADOR_OBJ)

$(TEST_ADMINISTRADOR_OBJ): $(TEST_ADMINISTRADOR_SRC) administrador.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(TEST_ADMINISTRADOR_SRC) -o $(TEST_ADMINISTRADOR_OBJ)

$(USUARIO_OBJ): $(USUARIO_SRC) ../usuario/usuario.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(USUARIO_SRC) -o $(USUARIO_OBJ)

# Limpiar objetos generados
clean:
	rm -f *.o $(EXEC)
