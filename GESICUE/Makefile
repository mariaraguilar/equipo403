# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Directorios de las carpetas de código fuente
SRC_DIR = .
USER_DIR = $(SRC_DIR)/usuario
PROF_DIR = $(SRC_DIR)/profesor
SOL_DIR = $(SRC_DIR)/solicitud
PC_DIR = $(SRC_DIR)/planconvalidacion
CAR_DIR = $(SRC_DIR)/carrera
ASIG_DIR = $(SRC_DIR)/asignatura
ADMI_DIR = $(SRC_DIR)/administrador


# Archivos fuente
SYST_SRC = $(SRC_DIR)/sistema.cc
USER_SRC = $(USER_DIR)/usuario.cc
PROF_SRC = $(PROF_DIR)/profesor.cc
SOL_SRC = $(SOL_DIR)/solicitud.cc
PC_SRC = $(PC_DIR)/PlanConvalidacion.cc 
CAR_SRC = $(CAR_DIR)/carrera.cc 
ASIG_SRC = $(ASIG_DIR)/asignatura.cc
ADMI_SRC = $(ADMI_DIR)/administrador.cc

# Nombre del ejecutable
EXEC = sistema

# Regla principal: compilar el ejecutable directamente desde los archivos fuente
$(EXEC): $(SYST_SRC) $(USER_SRC) $(PROF_SRC) $(SOL_SRC) $(PC_SRC) $(CAR_SRC) $(ASIG_SRC) $(ADMI_SRC)
	$(CXX) $(CXXFLAGS) -I$(USER_DIR) -I$(PROF_DIR) -I$(SOL_DIR) -I$(PC_DIR) -I$(CAR_DIR) -I$(ASIG_DIR) -I$(ADMI_DIR) $^ -o $(EXEC)

# Regla de limpieza
clean:
	rm -f $(EXEC)  # Eliminar el ejecutable
	rm -rf *.dSYM  # Eliminar archivos .dSYM generados por macOS