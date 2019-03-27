import java.util.*;

class StringDemo
{
    public static void main(String [] args)
    {
        System.out.println(new StringDemo());
        String s1 = "RAM";
        String s2 = "RAM";
        s2 = new String("RAM");
        if (s1 == s2)
        {
            System.out.println("True");
        }
        else
        {
            System.out.println("False");
        }
    }
}
