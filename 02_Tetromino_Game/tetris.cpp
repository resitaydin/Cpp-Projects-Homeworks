#include <iostream>
#include <vector>
#include <unistd.h>

#include "Tetromino.h"
#include "tetris.h"

using namespace std;



 Tetris::Tetris(int rowInput, int columnInput){
    setRowColumn(rowInput,columnInput);
 }

 inline void Tetris::setRowColumn(int r, int c){
    rowSize = r;
    columnSize = c;
}


void Tetris::draw() const{  // Printing map to the screen.
    
    for (vector<char> vec : map)
    {
        for (char x : vec)
        {
            cout << x << " ";
        }    
        cout << endl;
        
    }
} 
  
void Tetris::initMap(){  //Initializing the map.
    vector<vector<char>> vec( rowSize+1, vector<char> (columnSize+1, ' '));
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<columnSize;j++){
            if(i==0 || i==rowSize-1) vec[i][j] = '#';
            if(i%2==0 && (j==0 || j==columnSize-1)) vec[i][j] = '#';
        }
    }  
    map = vec;
}

void Tetris::addTetro(Tetromino &tetro){ // adding Tetris to the map(board).
    static int counter=0;
    int lower=0;
    int bound;
   
    while(lower<rowSize-5){
        if(counter!=1 && counter!=2){  //That's the case for the dropping object to the bottom middle.
            for(int i=1;i<5;i++){
                if(tetro.getTetroType()==Shapes::O) bound = lower+i-1;
                if(tetro.getTetroType()==Shapes::S || tetro.getTetroType()==Shapes::Z) bound = lower+i;
                else bound = lower+i+1;

                int k=0;
                for(int j= columnSize/2-2;j<columnSize/2+2;j++){
                    if(tetro.getTetro()[i-1][k]!= ' ' ) map[bound][j] = tetro.getTetro()[i-1][k];
                    k++;
                }
            }
            draw();
            if(lower<rowSize-6){
                for(int i=1;i<5;i++){
                    for(int j= columnSize/2-2;j<columnSize/2+2;j++){
                    if(map[lower+i][j]!= '#') map[lower+i][j] = ' ';
                    }
                }
            }
        } 
        if(counter==1){  //Left-side algorithm
            for(int i=1;i<5;i++){
                if(tetro.getTetroType()==Shapes::O) bound = lower+i;
                if(tetro.getTetroType()==Shapes::S || tetro.getTetroType()==Shapes::Z) bound = lower+i;
                else bound = lower+i+1;

                int k=0;
               
                for(int j= 1;j<columnSize/2-2;j++){
                    if(tetro.getTetro()[i-1][k]!= ' ' ) map[bound][j] = tetro.getTetro()[i-1][k];
                    k++;
                }
            } 
            draw();
            if(lower<rowSize-6){ 
                for(int i=1;i<5;i++){
                    for(int j= 1;j<columnSize/2-2;j++){
                        if(map[lower+i][j]!= '#') map[lower+i][j] = ' ';
                    }
                }
            }
            
        }    
        if(counter==2){ //Right-side algorithm.
            for(int i=1;i<5;i++){
                if(tetro.getTetroType()==Shapes::O) bound = lower+i;
                if(tetro.getTetroType()==Shapes::S || tetro.getTetroType()==Shapes::Z) bound = lower+i;
                else bound = lower+i+1;

                int k=0;
               
                for(int j= columnSize/2+2;j<columnSize-1;j++){
                    if(tetro.getTetro()[i-1][k]!= ' ' ) map[bound][j] = tetro.getTetro()[i-1][k];
                    k++;
                }
            } 
            draw();
            if(lower<rowSize-6){
                for(int i=1;i<5;i++){
                    for(int j= columnSize/2+2;j<columnSize-1;j++){
                        if(map[lower+i][j]!= '#') map[lower+i][j] = ' ';
                    }
                }
            }
        }    

        if(lower==0) BestFit(tetro);
        cout<<"\x1B[2J\x1B[H";  //To move cursor top left.
        usleep(50000);   //Sleeping a little bit to see the screen.
        lower++;     
    }
    counter++;
}

void Tetris::BestFit(Tetromino &tetro){

    if(getTetroType()==Shapes::T){
        tetro.rotate('R');
        tetro.rotate('R');
    }
    else if(getTetroType()==Shapes::J){
        tetro.rotate('R');
    }
    else if(getTetroType()==Shapes::L){
        tetro.rotate('L');
    }
    else{
        //do nothing.
    }

}
