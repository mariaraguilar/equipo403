# Archivos fuente
PROFESOR_SRC = profesor.cc
TEST_PROFESOR_SRC = test_profesor.cc
USUARIO_SRC = ../usuario/usuario.cc
SOLICITUD_SRC = ../solicitud/solicitud.cc

# Archivos objeto
PROFESOR_OBJ = profesor.o
TEST_PROFESOR_OBJ = test_profesor.o
USUARIO_OBJ = ../usuario/usuario.o
SOLICITUD_OBJ = ../solicitud/solicitud.o

# Nombre del ejecutable
EXEC = test_profesor

# CXXFLAGS (flags de compilación)
CXXFLAGS = -g -Wall -Wextra -pthread -std=gnu++11

# Directorios de inclusión
INCLUDES = -I../usuario -I../solicitud -I.

# Reglas de compilación
all: $(EXEC)

$(EXEC): $(PROFESOR_OBJ) $(USUARIO_OBJ) $(SOLICITUD_OBJ) $(TEST_PROFESOR_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(PROFESOR_OBJ): $(PROFESOR_SRC) ../usuario/usuario.h ../solicitud/solicitud.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(PROFESOR_SRC) -o $(PROFESOR_OBJ)

$(TEST_PROFESOR_OBJ): $(TEST_PROFESOR_SRC) profesor.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(TEST_PROFESOR_SRC) -o $(TEST_PROFESOR_OBJ)

$(USUARIO_OBJ): $(USUARIO_SRC) ../usuario/usuario.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(USUARIO_SRC) -o $(USUARIO_OBJ)

$(SOLICITUD_OBJ): $(SOLICITUD_SRC) ../solicitud/solicitud.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SOLICITUD_SRC) -o $(SOLICITUD_OBJ)

# Limpiar objetos generados
clean:
	rm -f *.o $(EXEC)
