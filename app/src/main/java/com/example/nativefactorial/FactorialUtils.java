package com.example.nativefactorial;

public class FactorialUtils {

    public native static void calcFactorial(int num);

    public static void updateGUI(long num)
    {
        MainActivity.displayResult(num);
    }
}
