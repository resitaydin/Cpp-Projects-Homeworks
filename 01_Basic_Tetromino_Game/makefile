all: clear clean compile run
clear: 
	@clear

compile: main.cpp Tetromino.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ main.cpp Tetromino.cpp -o tetris

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./tetris
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f test
