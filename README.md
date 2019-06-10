Small program to test the multiplicative persistence.
This small project was inspired by the [Numberphile video](https://www.youtube.com/watch?v=Wim9WJeDTHQ) on the topic.

I programmed an algorithm which computes smartly the maximum multiplicative persistence of all numbers with a given number of digits. Furthermore, I choosed to use C++ to get better performances. When the program launches, enter the range of digits number you want. It will compute the maximum multiplicative persistence of each element of this range and display the number associated.

Warning : do not compile with maximum optimizations on the microsoft compiler, it gives wrong results.

# Requirements

This program uses the [mpir](https://github.com/BrianGladman/mpir) library, however all the files needed are included in this project. Note that mpir is under the GPL v3 license. The terms are inside the include directory.