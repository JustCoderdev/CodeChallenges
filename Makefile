# General Makefile for C projects
# to set flags use $(flag_name) and make flag_name=10

# Run file with
# $ make FILE_ENTRY="001_Multiples_of_3_or_5"

FILE_ENTRY=$(wildcard 015*)

FLAGS=-xc -Wall -Wextra -Werror -Wpedantic \
	  -pedantic -pedantic-errors -std=c89  \
	  -fcolor-diagnostics

SRC_FILES=${FILE_ENTRY} \
 		  $(wildcard lib/*.c)

local: clean build run
clean:
	@echo "Cleaning..."
	@rm -f ./bin/${FILE_ENTRY:.c=}

build: clean
	@echo "Compiling... "
	@mkdir -p bin
	@clang ${FLAGS} ${SRC_FILES} -o bin/${FILE_ENTRY:.c=}

run:
	@echo "Running... "
	@chmod +x bin/${FILE_ENTRY:.c=}
	@cd bin && ./${FILE_ENTRY:.c=}
