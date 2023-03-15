/**
* This class represents the Tetrominos which are the fundamental pieces of Tetris game.
* @author R.A.
*/

public class Tetromino{

enum Shapes{
    I,
    O,
    T,
    J,
    L,
    S,
    Z,
}

private Shapes tetroType;
private char[][] tetro;
private int c;
private int r;

/**
* Simple getter method for private member tetroType.
* @return tetroType - tetroType of a Tetromino object.
*/
public Shapes getTetroType() { return tetroType; }

/**
* Simple getter method for private member c.
* @return c - Column size of a Tetromino object.
*/
public int getColumn() { return c; }

/**
* Simple getter method for private member r.
* @return r - Row size of a Tetromino object.
*/

public int getRow() { return r; }

/**
* Simple getter method for private member tetro.
* @return tetro - Tetromino object itself.
*/

public char[][] getTetro() { return tetro;}


/**
* This method is a helper method to create array for the Tetromino objects.
*/

public void createArr(){
    tetro = new char[r][c];

    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            tetro[i][j] = ' ';
        }
    }

}

 /**
    * This is the constructor to create Tetromino objects properly.
    * @param shp Tetromino shape to be created.
    */
public Tetromino(Shapes shp){
    this.tetroType = shp;

    switch(getTetroType()){
        case I :
            r= 1; c=4;
            createArr(); //Creating objects.
            tetro[0][0] = 'I'; tetro[0][1] = 'I'; tetro[0][2] = 'I'; tetro[0][3] = 'I';
            break;
        case O :
            r=2; c=2;
            createArr();
            tetro[0][0] = 'O'; tetro[0][1] = 'O'; tetro[1][0] = 'O'; tetro[1][1] = 'O';
            break;
        case T :
            r=2; c=3;
            createArr();
            tetro[0][1] = 'T'; tetro[1][0] = 'T'; tetro[1][1] = 'T'; tetro[1][2] = 'T';
            break;
        case J :
            r=3; c=2;
            createArr();
            tetro[0][1] = 'J'; tetro[1][1] = 'J'; tetro[2][0] = 'J'; tetro[2][1] = 'J';
            break;
        case L :
            r=3; c=2;
            createArr(); //Creating objects.
            tetro[0][0] = 'L'; tetro[1][0] = 'L'; tetro[2][0] = 'L'; tetro[2][1] = 'L';
            break;
        case S :
            r=2; c=3;
            createArr();
            tetro[0][1] = 'S'; tetro[0][2] = 'S'; tetro[1][0] = 'S'; tetro[1][1] = 'S';
            break;
        case Z :
            r=2; c=3;
            createArr();
            tetro[0][0] = 'Z'; tetro[0][1] = 'Z'; tetro[1][1] = 'Z'; tetro[1][2] = 'Z';
            break;
        default:
            break;
    }
}




     /**
    * This method rotates the tetromino to the desired direction.
    * @param direction where to be rotated.
    */
public void rotate(char direction){

    int newColumn = 0;
    int newRow = 0;

    char[][] temp = new char[c][r];

    if(direction=='L'){ 
        for (int oldColumn = getColumn() - 1; oldColumn >= 0; oldColumn--)
        {  
            newColumn = 0;
            for (int oldRow = 0; oldRow < getRow(); oldRow++) //Rotating the object left.
            {
                temp[newRow][newColumn] = tetro[oldRow] [oldColumn];
                newColumn++;
            }
            newRow++;
        }
    }
   
    else{ 
        for (int oldColumn = 0; oldColumn<getColumn(); oldColumn++)//Rotating the object right.
        {
            newColumn = 0;
            for (int oldRow = getRow()-1; oldRow >= 0; oldRow--)
            {
                temp[newRow][newColumn] = tetro[oldRow] [oldColumn];
                newColumn++;
            }
            newRow++;
        }
    }

    tetro = new char[c][r];

    for(int i=0;i<getColumn();i++){ //tetro=temp;
        for(int j=0;j<getRow();j++){
            tetro[i][j]=temp[i][j];
        }
    }

    r = newRow;
    c = newColumn;

}



/**
* Helper method to output tetrominos on the screen.
*/
public void printTetro(){
    for(char arr[] : tetro){
        for(char val : arr){
            System.out.print(val);
        }
        System.out.println();
    }
}
   
}