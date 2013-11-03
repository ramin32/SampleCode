/************************************************************
 * Reverse.java
 *
 * Reverses the first string passed through the cmdline.
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ***********************************************************/

public class Reverse
{
    public static void main(String... args)
    {
        StringBuilder str = new StringBuilder(args[0]);
        int start = 0;
        int end = str.length() - 1;
        while(start < end)
        {
            char temp = str.charAt(start);
            str.setCharAt(start,str.charAt(end));
            str.setCharAt(end, temp);
            start++;
            end--;
        }
        System.out.println(str);

    }
}
