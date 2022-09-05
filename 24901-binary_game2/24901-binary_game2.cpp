//; # \u000a import java.util.Scanner; class Main { public static void main(String[] args) { Scanner sc = new Scanner(System.in); int[] lst = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010}; int n; n = sc.nextInt(); for (int i = 0; i <= n; i++) System.out.print(lst[i]); } } /*
#if true /*                                                                                                          \
list = [0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010]; n = gets.chomp().to_i; (0..n).each{ |i| print list[i] } \
=begin                                                                                                               \
/* */                                                                                                                \
         // \u000a /*
#include <iostream>
int main()
{
    int list[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010};
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; i++)
        std::cout << list[i];
    return 0;
}
// */
// */ let list = [0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010]; let n = Int(readLine()!); for i in 0...n! { print(list[i], terminator : "") } // \u000a /*
#endif
/*
=end
# */