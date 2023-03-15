all: clear clean compile run
clear: 
	@clear

compile: driver.cpp DayOfYear.cpp DayOfYearSet.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ driver.cpp DayOfYear.cpp DayOfYearSet.cpp -o program

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./program
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f program
