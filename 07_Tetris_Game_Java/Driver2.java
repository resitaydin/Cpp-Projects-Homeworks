import java.util.Scanner;
import java.util.Random;

public class Driver2 {
    public static void main(String[] args) {
        int row, column;

        String input;

        Tetromino.Shapes shape_arr[]= {Tetromino.Shapes.I,
            Tetromino.Shapes.O,Tetromino.Shapes.T,
            Tetromino.Shapes.J,Tetromino.Shapes.L, 
            Tetromino.Shapes.S, Tetromino.Shapes.Z }; //random array

        
        System.out.print("Enter row of the board: ");
        Scanner sc = new Scanner(System.in);

        row = sc.nextInt();

        System.out.print("Enter column of the board: ");
        column = sc.nextInt();

        System.out.println("Game board is creating... ");
        Tetris tetBoard = new Tetris(row, column);

        boolean flag = false;
        while(!tetBoard.isGameOver() || flag){
            flag = false;

            System.out.print("Enter the tetromino type(I,O,T,J,L,S,Z or R for random, Q for Quit.): ");
            input = sc.next();
            System.out.println(input);

            Tetromino.Shapes myShape;

            if(input.equals("Q")) {
                System.out.println("Quitting the game...");
                System.exit(1);
            }

            else if(input.equals("I") || input.equals("O") || input.equals("T") || input.equals("J") ||input.equals("L")
             || input.equals("S") || input.equals("Z") || input.equals("R")){
                if(input.equals("R")){
                    Random rand = new Random(); // Creating a random reference.
                    int int_rand = rand.nextInt(7);
                    myShape = shape_arr[int_rand];
                }
                else{
                    myShape = Tetromino.Shapes.valueOf(input);
                }
                Tetromino tetro = new Tetromino(myShape);  //Creating tetromino object using shape input.
                tetBoard.add(tetro);
                tetBoard.draw();

                System.out.println("Tetromino has been moved and rotated randomly...");
                System.out.println("Started lowing the tetromino...");

                tetBoard.animate();
            }     
            else{
                flag= true;
                System.out.println("Invalid  value. Try Again...");
            }

        }
        System.out.println("Game is Over!");
        sc.close();
    
    } // End of main method
} // End of Class
