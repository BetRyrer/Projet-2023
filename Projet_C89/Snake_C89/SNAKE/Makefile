CC = gcc
CFLAGS = -ansi -pedantic -lgraph 
SRCDIR = ./src
HDIR = ./fichier.h
ODIR = ./out
OFILES = $(subst $(SRCDIR)/,$(ODIR)/,$(subst .c,.o,$(shell find $(SRCDIR)/ -type f)))
EXE = snake

.PHONY: all clean run

all: $(EXE)

$(ODIR)/%.o : $(SRCDIR)/%.c 
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

$(EXE) : $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES)

run : $(EXE)
	./$(EXE)

clean : 
	-rm -rf $(ODIR)

$(EXE): $(ODIR)/a.out

#  construction 'out/a.out'
$(ODIR)/a.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)