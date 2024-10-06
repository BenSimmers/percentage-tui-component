# flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lncurses -pthread

# directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin


# files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
TARGET = $(BINDIR)/percentage_bar_component

# rules
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# main target ( build the program )
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# phony targets and dependencies
$(OBJDIR):
	mkdir -p $(OBJDIR)

# create bin directory
$(BINDIR):
	mkdir -p $(BINDIR)

# run the program
run:
	$(BINDIR)/percentage_bar_component

# clean the project
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: clean
