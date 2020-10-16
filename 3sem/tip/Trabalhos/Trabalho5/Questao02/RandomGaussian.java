package Q2;

import java.util.Random;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public final class RandomGaussian {
    public static void main(String args[]) {
        RandomGaussian gaussian = new RandomGaussian();
        double mean = 100.0f;
        double variance = 5.0f;

        

        try {
            // Creates a new file to insert the numbers
            File f = new File("Q2/results.txt");
            if (f.createNewFile()) {
                for (int idx = 1; idx <= 10; idx++) {
                    FileWriter fw = new FileWriter(f, true);
                    log(gaussian.getGaussian(mean, variance));
                    // Write Gaussian numbers to file
                    fw.write(Double.toString(gaussian.getGaussian(mean, variance)) + "\n");
                    fw.close();
                }
                sort(f);
            }
        } catch (IOException e) {
            System.out.println("An error occurred");
            e.printStackTrace();
        }
    }

    private Random fRandom = new Random();

    private double getGaussian(double aMean, double aVariance) {
        return aMean + fRandom.nextGaussian() * aVariance;
    }

    private static void log(Object aMsg) {
        System.out.println(String.valueOf(aMsg));
    }

    private static void sort(File f) {
        // ArrayList for sorting the numbers
        ArrayList<Double> numbers = new ArrayList<Double>();
        try {
            Scanner scanner = new Scanner(f);
            while (scanner.hasNextLine()) {
                numbers.add(Double.parseDouble(scanner.nextLine()));
            }
            // Sort the numbers in increasing order.
            Collections.sort(numbers);
            scanner.close();
            System.out.println(numbers);
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred");
            e.printStackTrace();
        }
        // Creates a new file to store the sorted numbers
        File sf = new File("Q2/results.txt");
        try {
            FileWriter fw = new FileWriter(sf, false);
            for (Double number : numbers) {
                fw.write(Double.toString(number) + "\n");
            }
            fw.close();
        } catch (IOException e) {
            System.out.println("An error occurred");
        }
    }
}
