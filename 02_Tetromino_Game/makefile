all: clear clean compile1 run1 clean compile2 run2
clear: 
	@clear

compile1: driver1.cpp tetromino.cpp tetris.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ driver1.cpp tetromino.cpp tetris.cpp -o playTetris

run1:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./playTetris
	@echo "================================================================================="
	@echo "Completed tests...."

compile2: driver2.cpp tetromino.cpp tetris.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ driver2.cpp tetromino.cpp tetris.cpp -o tetris

run2:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./tetris
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f tetris
	@rm -f tetrisdemo
