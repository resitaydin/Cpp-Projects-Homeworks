#include "TetrisVector.h"

#include <unistd.h>

int AbstractTetris::numberOfMoves_ = 0;

namespace tetrisVector{

TetrisVector::TetrisVector() : AbstractTetris(){
    //Deliberately empty.
}

TetrisVector::TetrisVector(int r, int c) : AbstractTetris(r,c){

    vector<vector<char>> vec( r, vector<char> (c, ' '));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 || i==r-1) vec[i][j] = '#';
            if(i%2==0 && (j==0 || j==c-1)) vec[i][j] = '#';
        }
    } 
    board = vec;
}

void TetrisVector::draw() const{
    for (vector<char> vec : board) // Printing map onto the screen.
    {
        for (char x : vec)
        {
            cout << x;
        }    
        cout << endl;
    }
}

AbstractTetris& TetrisVector::operator+=(const Tetromino& tetro) 
{
    AbstractTetris::numberOfMoves_++;
    // cout<<"Number of moves: " << numberOfMoves() <<endl;

    tetrom = tetro; // Assigning our private object to tetro object using overloaded = operator.

    int midPoint=(getC()/2)-1;

    for(int i=0;i<tetro.getRow();i++){
        for(int j=0;j<tetro.getColumn(); j++){
            board[i+1][j+midPoint]=tetro.getTetro()[i][j];  //Adding tetro to the map.
        }
    }
    draw();

    for(int i=0;i<tetro.getRow();i++){
        for(int j=0;j<tetro.getColumn(); j++){
            board[i+1][j+midPoint]=' '; 
        }
    }

    return *this;
}

void TetrisVector::move(){
    char mD;
    int mC;

    do{
    cout<<"Enter the move direction(R for Right, L for Left) and count: ";
    cin>> mD;
    cin>> mC;

    } while(mC>= getC()/2-1 || mC<0) ;


    lastMove_.first = mD;
    lastMove_.second = mC;  //Updating last move.

    if(mD=='L') mC = -mC; //if we move it to left, we just decrease its x property.

    int mid=(getC()/2)-1;

    for(int i=0;i<tetrom.getRow();i++){
        for(int j=0;j<tetrom.getColumn(); j++){
            board[i+1][j+mid]=' ';  //Clearing the map where object used to be.
        }
    }

    for(int i=0;i<tetrom.getRow();i++){
        for(int j=0;j<tetrom.getColumn(); j++){
            board[i+1][j+mid+mC]=tetrom.getTetro()[i][j];
        }
    }
    loc = mid + mC; // Updating location.

}

void TetrisVector::rotate(){
    char direction;
    int count;

    cout<<"Enter rotation direction(R for Right, L for Left) and rotation count: ";
    cin>> direction;
    cin>> count;

    for(int i=0; i<count; ++i)  tetrom.rotate(direction);

}

void TetrisVector::animate(){
    rotate();
    move();

    for(int i=0; i<tetrom.getColumn(); ++i){
        if(board[tetrom.getRow()+1][i+getLoc()] != ' ') GameOver = 1;
    }
    int counters[4] = {0,0,0,0};
    int min= 9999;
    int c=0;

    //  cout<<"Last move is going "<<lastMove().first<<" "<<lastMove().second<<" unit with tetrotype: "<<static_cast<char> (tetrom.getTetroType());
    
    for(int i=0; i<tetrom.getRow(); ++i){
        for(int j=0; j<tetrom.getColumn(); ++j){
            if(tetrom.getTetro()[i][j] != ' ' && board[i+2][getLoc()+j] ==' '){
                do{
                    counters[c]++;    
                    // cout<<counters[c]<<endl;

                }
                while(board[i + counters[c]+2][j+getLoc()] ==' ' && board[i + counters[c]+2][j+getLoc()] !='#');
                c++;
            } 
        }
    }
      
    for(int i=0;i<tetrom.getRow();i++)
        for(int j=0;j<tetrom.getColumn();j++)
            board[i+1][j+getLoc()]=' ';

    for(int i=0; i<tetrom.getColumn(); ++i){
        if(counters[i]<min){
            min = counters[i];
        }
    }
    for(int k=0; k<min+1; k++){
        if(k!=0){
            for(int i=0;i<tetrom.getRow();i++){
                for(int j=0;j<tetrom.getColumn();j++){
                    board[i+k][getLoc()+j]=' ';  // Making map empty.
                }
            }
        }

        for(int i=0;i<tetrom.getRow();i++){// Adding tetro to the board and lowering it.
            for(int j=0;j<tetrom.getColumn();j++){
                if(tetrom.getTetro()[i][j] != ' ') board[i+k+1][getLoc() +j]=tetrom.getTetro()[i][j];
            }
        }
        cout << "\x1B[2J\x1B[H";
        draw();
        usleep(150000);
    }
}

void TetrisVector::writeToFile(string filename){
    ofstream myFile;
    myFile.open(filename);

    if(!myFile){
        cerr<< "File cannot be opened...\n";
    }

    for (vector<char> vec : board) // Printing map in the specified file.
    {
        for (char x : vec)
        {
            myFile << x;
        }    
        myFile << endl;
    }
    cout<< "Board has been written to the specified file.\n";

    myFile.close();
}


void TetrisVector::readFromFile(string filename){
    string line;

    ifstream readFile;
    readFile.open(filename);

    if(!readFile){
        cerr<< "File cannot be opened...\n";
        return ;
    }

    cout<< "Board has been read from the file and it's being printed...\n";
    while(getline(readFile, line)){
        cout<<line;   //Reading from the file and printing it
        cout<<endl;
    }

    readFile.close();
}

} //namespace
