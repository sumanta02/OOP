import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            File newFile = new File("./text.txt");
            newFile.createNewFile();
            FileInputStream fileIn = new FileInputStream(newFile);
            FileOutputStream fileOut = new FileOutputStream(newFile);
            System.out.println("\nEnter the text to be written into the file: ");
            String dataIn = sc.nextLine();
            System.out.println ("\nWritten to file (using FileOutputStream): " + dataIn + "\n");
            byte[] inArray = dataIn.getBytes();
            fileOut.write(inArray);
            fileOut.flush();
            fileOut.close();
            byte[] outArray = new byte[500];
            fileIn.read(outArray);
            String dataOut = new String(outArray);
            System.out.println("\nData read from file (using FileInputStream): " + dataOut + "\n");
            fileIn.close();
            FileReader file = new FileReader("./text.txt");
            int bit;
            System.out.print("\nData read from file (using FileReader): ");
            while((bit = file.read()) != -1) {
                System.out.print((char)bit);
            }
            System.out.println();
            file.close();
            BufferedReader buffer = new BufferedReader(new FileReader("./text.txt"));
            String currLine;
            System.out.print("\nData read from file (using BufferedReader): ");
            while((currLine = buffer.readLine()) != null) {
                System.out.println(currLine);
            }
            System.out.println();
            buffer.close();
            Scanner fileScanner = new Scanner(newFile);
            System.out.print("\nData read from file (using Scanner): ");
            while(fileScanner.hasNextLine()) {
                System.out.println(fileScanner.nextLine());
            }
            System.out.println();
            fileScanner.close();
        } catch (Exception e) {
            e.getStackTrace();
        }
        sc.close();
    }
}
