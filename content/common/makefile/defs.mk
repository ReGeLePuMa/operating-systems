CC = gcc

# Get the relative path to the directory of the current makefile.
MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
INCLUDES_DIR := $(MAKEFILE_DIR)..
UTILS_DIR := $(MAKEFILE_DIR)../utils
LOGGER_DIR := $(UTILS_DIR)/log

<<<<<<< HEAD
CPPFLAGS += -I$(INCLUDES_DIR)
=======
CPPFLAGS += -I$(UTILS_DIR) -I$(LOGGER_DIR)
>>>>>>> noul
CFLAGS += -g -Wall -Wextra
LOGGER_OBJ = log.o
LOGGER = $(LOGGER_DIR)/$(LOGGER_OBJ)
