import java.util.Scanner;

public class Driver1 {
    public static void main(String[] args) {
    

    System.out.print("Enter the tetromino type(L,S,Z,O,I,J,T): ");
    
    Scanner inp = new Scanner(System.in);
        
    String type = inp.nextLine();

    Tetromino.Shapes myShape = Tetromino.Shapes.valueOf(type);

    Tetromino tetro = new Tetromino(myShape);


    tetro.printTetro();  //Printing tetro
    System.out.println("Tetromino is being rotated to Right(R)... ");
    tetro.rotate('R');
    System.out.println("Rotated tetromino is: ");
    tetro.printTetro();

    System.out.println("Tetromino is being rotated to Left(L) 2 times... ");
    tetro.rotate('L');
    tetro.rotate('L');
    System.out.println("Rotated tetromino is: ");
    tetro.printTetro();

    System.out.println("------------------------------------------");
    try {
        Thread.sleep(4000);
    } catch (InterruptedException e) {
        // TODO Auto-generated catch block
        e.printStackTrace();
    }
    System.out.println("Tetris board is being created... ");
    Tetris tet_board = new Tetris(15,15);

    System.out.println("Creating some tetromino objects to add to the board... ");

    Tetromino tetro1 = new Tetromino(Tetromino.Shapes.S);
    Tetromino tetro2 = new Tetromino(Tetromino.Shapes.L);
    Tetromino tetro3 = new Tetromino(Tetromino.Shapes.O);
    Tetromino tetro4 = new Tetromino(Tetromino.Shapes.Z);

    System.out.println("Calling add (and move, rotate randomly) function on each objects...");
    tet_board.add(tetro);
    tet_board.animate();

    tet_board.add(tetro1);
    tet_board.animate();

    tet_board.add(tetro2);
    tet_board.animate();

    tet_board.add(tetro3);
    tet_board.animate();

    tet_board.add(tetro4);
    tet_board.animate();

    System.out.println("Objects have been added to the board and animated...");



    inp.close();

    }
}
