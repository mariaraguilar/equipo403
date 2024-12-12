# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Directorios de las carpetas de código fuente
SRC_DIR = .
USER_DIR = $(SRC_DIR)/usuario
PROF_DIR = $(SRC_DIR)/profesor
SOL_DIR = $(SRC_DIR)/solicitud

# Archivos fuente
SYST_SRC = $(SRC_DIR)/sistema.cc
USER_SRC = $(USER_DIR)/usuario.cc
PROF_SRC = $(PROF_DIR)/profesor.cc
SOL_SRC = $(SOL_DIR)/solicitud.cc

# Nombre del ejecutable
EXEC = sistema

# Regla principal: compilar el ejecutable directamente desde los archivos fuente
$(EXEC): $(SYST_SRC) $(USER_SRC) $(PROF_SRC) $(SOL_SRC)
	$(CXX) $(CXXFLAGS) -I$(USER_DIR) -I$(PROF_DIR) -I$(SOL_DIR) $^ -o $(EXEC)

# Regla de limpieza
clean:
	rm -f $(EXEC)  # Eliminar el ejecutable
	rm -rf *.dSYM  # Eliminar archivos .dSYM generados por macOS
