# Nome do executável
TARGET = sigfinance

# Diretório com o arquivo principal
MAIN = sigfinance.c

# Diretórios de cabeçalhos
INCLUDES = -Imoradores -Idespesas -Itarefas -Iinformacoes -Irelatorios

# Fontes e objetos
SRC_DIRS = moradores despesas tarefas informacoes relatorios
SOURCES = $(MAIN) $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJECTS = $(SOURCES:.c=.o)

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g $(INCLUDES)

# Variável de detecção do SO
OS := $(shell uname -s)

# Definir comandos de remoção e execução dependendo do sistema operacional
ifeq ($(OS),Linux)
	RM = rm -f
	RUN = ./$(TARGET)
else
	RM = del /F /Q
	RUN = $(TARGET).exe
endif

# Regra principal para construir o programa
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para executar o programa
.PHONY: run
run: $(TARGET)
	$(RUN)

# Limpeza dos arquivos gerados
.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(TARGET)
