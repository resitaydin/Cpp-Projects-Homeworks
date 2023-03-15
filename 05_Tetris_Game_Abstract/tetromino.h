#ifndef TETROMINO
#define TETROMINO

enum struct Shp: char {I='I', O='O', T = 'T', J = 'J', L= 'L', S = 'S', Z = 'Z'};



class Tetromino{

    public:
        Tetromino(Shp shape);
        Tetromino();

        char** getTetro() const{ return tetro;}
        Shp getTetroType() const{ return tetroType;} //getter
        void setTetroType(Shp shape) { tetroType = shape;} //setter

        void rotate(char direction);
        void printTetro(); //For testing purpose.
        void createArr();
        int getRow()const {return r;}
        int getColumn()const {return c;}

        Tetromino& operator=(const Tetromino&); //overloaded

        ~Tetromino();  //dest.
        
    private:
        char** tetro;
        Shp tetroType;
        int r;
        int c;
};


#endif