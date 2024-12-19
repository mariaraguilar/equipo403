# Archivos fuente
PLANCONVALIDACION_SRC = PlanConvalidacion.cc
TEST_PLANCONVALIDACION_SRC = test_planconvalidacion.cc
USUARIO_SRC = ../usuario/usuario.cc
SOLICITUD_SRC = ../solicitud/solicitud.cc
ASIGNATURA_SRC = ../asignatura/asignatura.cc
CARRERA_SRC = ../carrera/carrera.cc  # Agregado el archivo carrera.cc

# Archivos objeto
PLANCONVALIDACION_OBJ = PlanConvalidacion.o
TEST_PLANCONVALIDACION_OBJ = test_planconvalidacion.o
USUARIO_OBJ = ../usuario/usuario.o
SOLICITUD_OBJ = ../solicitud/solicitud.o
ASIGNATURA_OBJ = ../asignatura/asignatura.o
CARRERA_OBJ = ../carrera/carrera.o  # Agregado el archivo carrera.o

# Nombre del ejecutable
EXEC = test_planconvalidacion

# CXXFLAGS (flags de compilación)
CXXFLAGS = -g -Wall -Wextra -pthread -std=gnu++11

# Directorios de inclusión
INCLUDES = -I../usuario -I../solicitud -I../asignatura -I../carrera -I.

# Reglas de compilación
all: $(EXEC)

$(EXEC): $(PLANCONVALIDACION_OBJ) $(USUARIO_OBJ) $(SOLICITUD_OBJ) $(TEST_PLANCONVALIDACION_OBJ) $(ASIGNATURA_OBJ) $(CARRERA_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(PLANCONVALIDACION_OBJ): $(PLANCONVALIDACION_SRC) ../usuario/usuario.h ../solicitud/solicitud.h ../asignatura/asignatura.h ../carrera/carrera.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(PLANCONVALIDACION_SRC) -o $(PLANCONVALIDACION_OBJ)

$(TEST_PLANCONVALIDACION_OBJ): $(TEST_PLANCONVALIDACION_SRC) PlanConvalidacion.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(TEST_PLANCONVALIDACION_SRC) -o $(TEST_PLANCONVALIDACION_OBJ)

$(USUARIO_OBJ): $(USUARIO_SRC) ../usuario/usuario.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(USUARIO_SRC) -o $(USUARIO_OBJ)

$(SOLICITUD_OBJ): $(SOLICITUD_SRC) ../solicitud/solicitud.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SOLICITUD_SRC) -o $(SOLICITUD_OBJ)

$(ASIGNATURA_OBJ): $(ASIGNATURA_SRC) ../asignatura/asignatura.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(ASIGNATURA_SRC) -o $(ASIGNATURA_OBJ)

$(CARRERA_OBJ): $(CARRERA_SRC) ../carrera/carrera.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(CARRERA_SRC) -o $(CARRERA_OBJ)

# Limpiar objetos generados
clean:
	rm -f *.o $(EXEC)
