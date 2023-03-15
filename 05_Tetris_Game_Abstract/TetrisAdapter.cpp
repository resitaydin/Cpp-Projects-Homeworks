#include "TetrisAdapter.h"

#include <unistd.h>

namespace tetrisAdapter{

template <typename T>
TetrisAdapter<T>::TetrisAdapter() : AbstractTetris(){

}

template <typename T>
TetrisAdapter<T>::TetrisAdapter(int r, int c) : AbstractTetris(r,c){
    board = T (r*c, ' ');

    for(int i=0; i<getR(); ++i){
        for(int j=0; j<getC(); ++j){
            if(i==0 || i==r-1) board.at(i*getC() +j)= '#';
            else if(i%2==0 && (j==0 || j==c-1)) board.at(i*getC() +j) = '#';
            else board.at(i*getC() +j) = ' ';
        }
    }
}

template <typename T>
void TetrisAdapter<T>::draw() const{
    for(int i=0; i<getR(); ++i){
        for(int j=0; j<getC(); ++j){
            cout<< board.at(i*getC() +j);
        }
        cout<<endl;
    }
}

template <typename T>
AbstractTetris& TetrisAdapter<T>::operator+=(const Tetromino& tetro) {
    AbstractTetris::numberOfMoves_++;
    // cout<<"Number of moves: "<< numberOfMoves() <<endl;

    tetrom = tetro; // Assigning our private object to tetro object using overloaded = operator.

    int midPoint=(getC()/2)-1;

    for(int i=0;i<tetro.getRow();i++){
        for(int j=0;j<tetro.getColumn(); j++){
            // board[i+1][j+midPoint]=tetro.getTetro()[i][j];  //Adding tetro to the map.
            board.at((i+1)*getC() + j + midPoint) = tetro.getTetro()[i][j];
        }
    }
    draw();

    for(int i=0;i<tetro.getRow();i++){
        for(int j=0;j<tetro.getColumn(); j++){
            // board[i+1][j+midPoint]=' '; 
            board.at((i+1)*getC() + j + midPoint) = ' ';
        } 
    }

    return *this;
}

template <typename T>
void TetrisAdapter<T>::move(){
    char mD;
    int mC;

    do{
        cout<<"Enter the move direction(R for Right, L for Left) and count: ";
        cin>> mD;
        cin>> mC;   
    } while(mC>= getC()/2-1 || mC<0);

    lastMove_.first = mD;
    lastMove_.second = mC;

    if(mD=='L') mC = -mC; //if we move it to left, we just decrease its x property.

    int mid=(getC()/2)-1;

    for(int i=0;i<tetrom.getRow();i++){
        for(int j=0;j<tetrom.getColumn(); j++){
            // board[i+1][j+mid]=' ';  //Clearing the map where object used to be.
            board.at((i+1)*getC() + j + mid) = ' ';
        }
    }

    for(int i=0;i<tetrom.getRow();i++){
        for(int j=0;j<tetrom.getColumn(); j++){
            // board[i+1][j+mid+mC]=tetrom.getTetro()[i][j];
            board.at((i+1)*getC() + j + mid + mC) = tetrom.getTetro()[i][j];
        }
    }
    loc = mid + mC; // Updating location.
}

template <typename T>
void TetrisAdapter<T>::rotate(){
    char direction;
    int count;

    cout<<"Enter rotation direction(R for Right, L for Left) and rotation count: ";
    cin>> direction;
    cin>> count;

    for(int i=0; i<count; ++i)  tetrom.rotate(direction);
}

template <typename T>
void TetrisAdapter<T>::animate(){
    rotate();
    move();

    for(int i=0; i<tetrom.getColumn(); ++i){
        if(board.at((tetrom.getRow()+1)*getC() + i+getLoc()) != ' ') GameOver = 1;
    }
    int counters[4] = {0,0,0,0};
    int min= 9999;
    int c=0;

    //  cout<<"Last move is going "<<lastMove().first<<" "<<lastMove().second<<" unit with tetrotype: "<<static_cast<char> (tetrom.getTetroType());

    for(int i=0; i<tetrom.getRow(); ++i){
        for(int j=0; j<tetrom.getColumn(); ++j){
            if(tetrom.getTetro()[i][j] != ' ' && board.at((i+2)*getC()+ getLoc()+ j) ==' '){
                do{
                    counters[c]++;    
                    // cout<<counters[c]<<endl;
                }
                while(board.at((i+counters[c]+2)*getC()+ getLoc()+ j) ==' ' && board.at((i+counters[c]+2)*getC()+ getLoc()+ j) !='#');
                c++;
            } 
        }
    }
      
    for(int i=0;i<tetrom.getRow();i++)
        for(int j=0;j<tetrom.getColumn();j++)
            board.at((i+1)*getC()+ getLoc()+ j)=' ';

    for(int i=0; i<tetrom.getColumn(); ++i){
        if(counters[i]<min){
            min = counters[i];
        }
    }
    for(int k=0; k<min+1; k++){
        if(k!=0){
            for(int i=0;i<tetrom.getRow();i++){
                for(int j=0;j<tetrom.getColumn();j++){
                    board.at((i+k)*getC() + getLoc() +j)=' ';
                }
            }
        }
        for(int i=0;i<tetrom.getRow();i++){// Adding tetro to the board and lowering it.
            for(int j=0;j<tetrom.getColumn();j++){
                if(tetrom.getTetro()[i][j] != ' ') board.at((i+k+1)*getC() + getLoc() +j)=tetrom.getTetro()[i][j];
            }
        }
        cout << "\x1B[2J\x1B[H";
        draw();
        usleep(150000);
    }
}

template <typename T> 
void TetrisAdapter<T>::writeToFile(string filename){
    ofstream myFile;
    myFile.open(filename);

    if(!myFile){
        cerr<< "File cannot be opened...\n";
    }

    for(int i=0; i<getR(); ++i){
        for(int j=0; j<getC(); ++j){
            myFile<< board.at(i*getC() + j);  // Writing board to the specified file.
        }   
        myFile<< endl;
    }
    cout<< "Board has been written to the specified file!\n";
    myFile.close();
}

template<typename T>
void TetrisAdapter<T>::readFromFile(string filename){
    string line;

    ifstream readFile;
    readFile.open(filename);

    if(!readFile){
        cerr<< "File cannot be opened...\n";
        return ;
    }

    cout<< "Board has been read from the file and it's being printed...\n";
    while(getline(readFile, line)){
        cout<<line;  //Reading from the file and printing it
        cout<<endl;
    }
    readFile.close();
}

}
