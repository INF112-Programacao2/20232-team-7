# Nome do executável
TARGET = comptify

# Compilador
CXX = g++

# Diretórios dos arquivos-fonte
SRCDIR = src

# Diretórios e Flags da SFML
SFML_INCLUDE = -I/usr/include/SFML
SFML_LIB = -L/usr/lib/x86_64-linux-gnu
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Flags e opções de compilação
CXXFLAGS = -std=c++11 -Wall

# Regra padrão para construir o programa
all: $(TARGET)

# Regra para construir o programa a partir dos objetos e das bibliotecas SFML
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $(wildcard $(SRCDIR)/*.cpp) -o $@ $(SFML_LIB) $(SFML_FLAGS)

# Remove o executável
clean:
	rm -f $(TARGET)
