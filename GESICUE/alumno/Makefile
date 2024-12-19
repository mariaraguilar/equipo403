# Archivos fuente
ALUMNO_SRC = alumno.cc
TEST_ALUMNO_SRC = test_alumno.cc
USUARIO_SRC = ../usuario/usuario.cc
SOLICITUD_SRC = ../solicitud/solicitud.cc
PLANCONVALIDACION_SRC = ../planconvalidacion/PlanConvalidacion.cc

# Archivos objeto
ALUMNO_OBJ = alumno.o
TEST_ALUMNO_OBJ = test_alumno.o
USUARIO_OBJ = ../usuario/usuario.o
SOLICITUD_OBJ = ../solicitud/solicitud.o
PLANCONVALIDACION_OBJ = ../planconvalidacion/PlanConvalidacion.o

# Nombre del ejecutable
EXEC = test_alumno

# CXXFLAGS (flags de compilación)
CXXFLAGS = -g -Wall -Wextra -pthread -std=gnu++11

# Directorios de inclusión
INCLUDES = -I../usuario -I../solicitud -I../planconvalidacion -I.

# Reglas de compilación
all: $(EXEC)

$(EXEC): $(ALUMNO_OBJ) $(USUARIO_OBJ) $(SOLICITUD_OBJ) $(PLANCONVALIDACION_OBJ) $(TEST_ALUMNO_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(ALUMNO_OBJ): $(ALUMNO_SRC) ../usuario/usuario.h ../solicitud/solicitud.h ../planconvalidacion/PlanConvalidacion.h alumno.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(ALUMNO_SRC) -o $(ALUMNO_OBJ)

$(TEST_ALUMNO_OBJ): $(TEST_ALUMNO_SRC) alumno.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(TEST_ALUMNO_SRC) -o $(TEST_ALUMNO_OBJ)

$(USUARIO_OBJ): $(USUARIO_SRC) ../usuario/usuario.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(USUARIO_SRC) -o $(USUARIO_OBJ)

$(SOLICITUD_OBJ): $(SOLICITUD_SRC) ../solicitud/solicitud.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SOLICITUD_SRC) -o $(SOLICITUD_OBJ)

$(PLANCONVALIDACION_OBJ): $(PLANCONVALIDACION_SRC) ../planconvalidacion/PlanConvalidacion.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(PLANCONVALIDACION_SRC) -o $(PLANCONVALIDACION_OBJ)

# Limpiar objetos generados
clean:
	rm -f *.o $(EXEC)
