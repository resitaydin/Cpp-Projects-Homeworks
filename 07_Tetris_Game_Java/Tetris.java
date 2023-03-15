
import java.util.Random;

/**
* This class represents the Tetris board.
* @author R.A.
*/

public class Tetris {
    private int c;
    private int r;
    private int loc;
    private boolean GameOver;
    private char[][] board;
    private Tetromino.Shapes shp;
    Tetromino tetromino;

    /**
    * Simple getter method for private member c.
    * @return c - column of table
    */
    public int getC() { return c;}

    /**
    * Simple getter method for private member c.
    * @return r - row of the table
    */
    public int getR() { return r; }

    /**
    * Simple getter method for private member loc.
    * @return loc - location of the table
    */
    public int getLoc() { return loc; }

    /**
    * Simple getter method for private member shp.
    * @return Shape shp - shape of the tetromino obj.
    */
    public Tetromino.Shapes getShp() { return shp; }


   /**
    * Simple getter method for private member GameOver.
    * @return GameOver
    */
    public boolean isGameOver() { return GameOver; }

    /**
    * This is the constructor to take the rectangular size of the Tetris board.
    * @param row Row size of the table to be created.
    * @param column Column size of the table to be created.
    */
    public Tetris(int row, int column){
        r = row;
        c = column;

        board = new char[r][c]; 

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                board[i][j] = ' ';
            }
        } 

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || i==r-1) board[i][j] = '#';
                if(i%2==0 && (j==0 || j==c-1)) board[i][j] = '#';
                
            }
        }

    }

    /**
    * This method draws the board on the screen.
    */

    public void draw(){
        for (char[] arr : board) 
        {
            for (char x : arr)
            {
                System.out.print(x);
            }    
            System.out.println();
        }
    }
    /**
    * Accepts a Tetromino object and add it to the board.
    * @param tetro Tetromino object to be added to the board
    */
    public void add(Tetromino tetro){

        int midPoint=(getC()/2)-1;

        for(int i=0;i<tetro.getRow();i++){
            for(int j=0;j<tetro.getColumn(); j++){
                board[i+1][j+midPoint]=tetro.getTetro()[i][j]; 
            }
        }
        draw();

        for(int i=0;i<tetro.getRow();i++){
            for(int j=0;j<tetro.getColumn(); j++){
                board[i+1][j+midPoint]=' '; 
            }
        }

        tetromino = tetro;
    }

    /**
    * This method moves the tetromino objects to the right or left.
    * 
    */

    public void move(){

    Random rand = new Random(); // Creating a random reference.
    char mD;

    int mC = rand.nextInt(getC()/2 -2);
    int rand1 = rand.nextInt(2);


    if(rand1==0) mD= 'R';
    else mD= 'L';


    if(mD=='L') mC = -mC; //if we move it to left, we just decrease its x property.

    int mid=(getC()/2)-1;

    for(int i=0;i<tetromino.getRow();i++){
        for(int j=0;j<tetromino.getColumn(); j++){
            board[i+1][j+mid]=' ';  //Clearing the map where object used to be.
        }
    }

    for(int i=0;i<tetromino.getRow();i++){
        for(int j=0;j<tetromino.getColumn(); j++){
            board[i+1][j+mid+mC]=tetromino.getTetro()[i][j];
        }
    }
    loc = mid + mC; // Updating location.

    }

    
    /**
    * This method rotates the tetromino objects to the right or left.
    */
    public void rotate(){

    char direction;
    
    Random rand = new Random(); // Creating a random reference.

    int count = rand.nextInt(5); // Generates integers between 0-4 (including 0 and 4).
    int diRection = rand.nextInt(2); // Generates either 0 or 1

    System.out.println(count);
    System.out.println(diRection);

    if(diRection==0) direction = 'R';
    else direction = 'L';

    for(int i=0; i<count; ++i)  tetromino.rotate(direction);

    
    }

    
/**
* This method animates the tetrominos till they hit the bottom of the board.
*/

public void animate() {

    rotate();
    move();

    for(int i=0; i<tetromino.getColumn(); ++i){
        if(board[tetromino.getRow()+1][i+getLoc()] != ' ') GameOver = true;
    }

    int counters[] = {0,0,0,0};
    int min= 9999;
    int c=0;
    
    for(int i=0; i<tetromino.getRow(); ++i){
        for(int j=0; j<tetromino.getColumn(); ++j){
            if(tetromino.getTetro()[i][j] != ' ' && board[i+2][getLoc()+j] ==' '){
                do{
                    counters[c]++;    

                }
                while(board[i + counters[c]+2][j+getLoc()] ==' ' && board[i + counters[c]+2][j+getLoc()] !='#');
                c++;
            } 
        }
    }
      
    for(int i=0;i<tetromino.getRow();i++)
        for(int j=0;j<tetromino.getColumn();j++)
            board[i+1][j+getLoc()]=' ';

    for(int i=0; i<tetromino.getColumn(); ++i){
        if(counters[i]<min){
            min = counters[i];
        }
    }
    for(int k=0; k<min+1; k++){
        if(k!=0){
            for(int i=0;i<tetromino.getRow();i++){
                for(int j=0;j<tetromino.getColumn();j++){
                    board[i+k][getLoc()+j]=' ';  // Making map empty.
                }
            }
        }

        for(int i=0;i<tetromino.getRow();i++){// Adding tetro to the board and lowering it.
            for(int j=0;j<tetromino.getColumn();j++){
                if(tetromino.getTetro()[i][j] != ' ') board[i+k+1][getLoc() +j]=tetromino.getTetro()[i][j];
            }
        }

        // System.out.printf("%s","\\x1B[2J\\x1B[H");
        System.out.print("\033c");
        draw();
        try {
            Thread.sleep(150);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

} // End of method

} // End of Class
