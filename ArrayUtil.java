/************************************************************************
 * Ramin Rakhamimov
 *
 * Name: ArrayUtil.java
 * Description: An Array utility class.
 * **********************************************************************/

import java.util.Random;

public class ArrayUtil
{
    private static final Random random_ = new Random(System.currentTimeMillis());

    private ArrayUtil(){}  // <-- Make uninstantiable.

    public static int[] copyArray(int array[])
    {
        int arrayCopy[] = new int[array.length];
        for(int i = 0; i < array.length; i++)
            arrayCopy[i] = array[i];

        return arrayCopy;
    }

    public static void selectionSort(int array[])
    {
        for(int i = 0; i < array.length; i++)
        {
            int minIndex = i;
            for(int j = i + 1; j < array.length; j++)
            {
                if(array[j] < array[minIndex])
                    minIndex = j;
            }

            swapInts(array, i, minIndex);
        }

    }

    public static int partition(int array[], int start, int end)
    {        

    	int rangeSize = end - start;
    	if(rangeSize <= 1)
    		return start;
    	
    	int pivotIndex = start + random_.nextInt(rangeSize);
        int pivot = array[pivotIndex]; 
   
        start--; // Even out start to be 1 less, end is naturally 1 more.
        
        while(true)
        {
        	while(array[++start] <= pivot);
        	while(array[--end] >= pivot);
        	if(start < end)
        		swapInts(array, start, end);
        	else
        		return end;
        }        
    }

    private static void quickSort(int[] array, int start, int end)
    {
        if(end - start <= 1 || array.length <= 1)
            return;

        int pivot = partition(array, start, end);
        quickSort(array, start, pivot);
        quickSort(array, pivot, end);
    }

    public static void quickSort(int[] array)
    {
        quickSort(array, 0, array.length);
    }

    public static boolean linearSearch(int[] array, int key)
    {
        for(int i: array)
        {
            if(i == key)
                return true;
        }
        return false;
    }


    public static int binarySearch(int[] array, int key)
    {
        if(array.length <= 0)
            return -1;

        int start = 0;
        int end = array.length - 1;
        while(start < end)
        {
            int midPoint = (end + start)/2;
            if(key < array[midPoint])
                end = midPoint - 1;
            else if(key > array[midPoint])
                start = midPoint + 1;
            else if(key == array[midPoint])
                return midPoint;
            else 
            	return -1;
        }
        
        return -1;
    }

    public static void swapInts(int[] array, int i, int j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static int[] getRandomArray(int size, int range)
    {
        int[] array = new int[size];
        for(int i = 0; i < size; i++)
            array[i] = random_.nextInt(range);
        return array;
    }

    public static void printArray(String msg, int[] array)
    {
        System.out.println(msg);
        for(int i = 0; i < array.length; i++)
            System.out.print(array[i] + " ");

        System.out.println();
        System.out.println();
    }
}
