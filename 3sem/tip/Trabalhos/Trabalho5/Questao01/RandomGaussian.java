import java.util.Random;
import java.io.File;
import java.io.FileWriter;
// import java.io.PrintWriter;
import java.io.IOException;

public final class RandomGaussian {
    public static void main (String args[]) {
        RandomGaussian gaussian = new RandomGaussian();
        double mean = 100.0f;
        double variance = 5.0f;

        // Deletes the file to start with a fresh version
        File old_results = new File("results.txt");
        old_results.delete();

        for (int idx = 1; idx <= 10; idx++) {
            try { 
                FileWriter fw = new FileWriter("results.txt", true);

                // Write Gaussian numbers to file
                fw.write(Double.toString(gaussian.getGaussian(mean, variance)) + "\n");
                fw.close();
            } catch (IOException e) {
                    System.out.println("An error occurred");
                    e.printStackTrace();
            }
        }
    }

    private Random fRandom = new Random();

    private double getGaussian(double aMean, double aVariance) {
        return aMean + fRandom.nextGaussian() * aVariance;
    }

    private static void log(Object aMsg) {
        System.out.println(String.valueOf(aMsg));
    }
}