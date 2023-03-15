#ifndef TETROMINO_H
#define TETROMINO_H

 #include <vector>

using namespace std;

enum struct Shapes : char {I='I',O='O',T='T',J='J',L= 'L',S='S',Z='Z'} ;
class Tetromino {

    public:
            Tetromino(Shapes shape){setTetroType(shape); };
           
            inline vector<vector<char>> getTetro() const {return tetro; } ;
            void setTetro();

            inline void setTetroType(Shapes shape){ tetroType = shape; };
            inline Shapes getTetroType() const { return tetroType; } ;

            void printTetro() const;
            void rotate(char direction);

            bool canFit(Tetromino &other, int position);
            bool canFitO(Tetromino &other);
            bool canFitI(Tetromino &other);
            bool canFitT(Tetromino &other);
            bool canFitJ(Tetromino &other);
            bool canFitL(Tetromino &other);
            bool canFitS(Tetromino &other);
            bool canFitZ(Tetromino &other);

    private:
            Shapes tetroType;
            vector<vector<char>> tetro;

};


#endif