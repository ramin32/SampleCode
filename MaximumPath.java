/***************************************************************
 * MaximumPath.java
 *
 * Description: Finds maximum path from root to leaf of a tree 
 *          where adjacent nodes share 1 child. 
 * Complexity: O(n)
 *
 * Author: 
 * Ramin Rakhamimov
 * http://raminrakhamimov.com
 ***************************************************************/

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;

public class MaximumPath
{
    private static final String INPUT_FILE="triangle.txt";

    public static void main(String... args) throws FileNotFoundException
    {
        final List<List<Integer>> integerLists = loadIntegerLists(INPUT_FILE);
        System.out.println(maximumPathSum(integerLists));
    }

    public static List<List<Integer>> loadIntegerLists(String inputFile) throws FileNotFoundException
    {
        final List<List<Integer>> integerLists = new ArrayList<List<Integer>>();
        final Scanner scanner = new Scanner(new File(inputFile));
        while(scanner.hasNextLine())
        {
            integerLists.add(parseIntLine(scanner.nextLine()));
        }
        return integerLists;
    }

    public static List<Integer> parseIntLine(String line)
    {
        Scanner intScanner = new Scanner(line);
        List<Integer> integerList = new ArrayList<Integer>();
        while(intScanner.hasNextInt())
        {
            integerList.add(intScanner.nextInt());
        }
        return integerList;
    }

    public static int maximumPathSum(List<List<Integer>> integerLists)
    {
        if(integerLists.size() == 0)
            return 0;

        int maximumPathSum = integerLists.get(0).get(0);
        int prevMaxIndex = 0;
        for(int i = 1; i < integerLists.size(); i++)
        {
            int leftChild = integerLists.get(i).get(prevMaxIndex);
            int rightChild = integerLists.get(i).get(prevMaxIndex + 1);

            if(leftChild > rightChild)
            {
                maximumPathSum += leftChild;
            }
            else
            {
                maximumPathSum += rightChild;
                prevMaxIndex++;
            }
        }
        return maximumPathSum;
    }

}
