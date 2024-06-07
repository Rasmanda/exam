#include <iostream>
#include <cmath>

int main() {
    int a, b, c, x;
    std::cout << "Enter the values for a, b, c, and x:\n";
    std::cin >> a >> b >> c >> x;

    int result;
    int intPart = x / b; // int(x/b)
    int intermediate = a * a + intPart; // a^2 + int(x/b)
    
    // Inline assembly to calculate (c - (intermediate)^3)
    __asm {
        mov eax, intermediate    // Move intermediate value to eax
        imul eax, eax            // Calculate intermediate^2
        imul eax, intermediate   // Calculate intermediate^3
        mov ebx, c               // Move c to ebx
        sub ebx, eax             // Calculate c - intermediate^3
        mov result, ebx          // Move result to variable
    }
    
    std::cout << "---- Rezults of the calculations ----\n";
    std::cout << "The function is f(x) = (c - (a^2 + int(x / b))^3)\n";
    std::cout << "The entered values: a = " << a << ", b = " << b << ", c = " << c << ", and x = " << x << "\n";
    std::cout << "The calculated value of the function f: f(x) = " << result << "\n";

    return 0;
}
