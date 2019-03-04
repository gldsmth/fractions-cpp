#include "fraction.hpp"
#include "mutil.hpp"

Fraction makeFractionFromInput() {

    Fraction f;

    auto get = [] (std::string name) {

        int number = 0;

        std::cout << "Enter " + name + " greater then zero:\n";

        while (number <= 0) {

            number =  mutil::getNum<int>();

            if (number <= 0) std::cout << "Greater then zero please!\n";
        }

        return number;
    };

    f.setNumerator( static_cast<size_t>( get("numerator") ) );

    f.setDenominator( static_cast<size_t>( get("denominator") ) );

    return f;
}

int main()
{
    Fraction fractions[2], result;

    std::cout << "Hello! Here you can add/subtract/multiple/divide two fractions.ONLY FOR POSITIVE NUMBERS!!!"
              << "\n"
              <<"Create first fraction" << "\n";

    fractions[0] = makeFractionFromInput();

    std::cout << "\n" << "Create second fraction" << "\n";

    fractions[1] = makeFractionFromInput();

    std::cout << "First fraction - " << fractions[0] << "\n";

    std::cout << "Second fraction - " << fractions[1] << "\n";

    char key = 0;

    std::cout << "What do you want to do?"<< "\n";

    while(key < '1' || key > '4') {

        std::cout << "Enter:\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n";

        std::cin >> key;
    }
    switch (key) {

    case '1':
        result = fractions[0] + fractions[1];

        break;
    case '2':
    {
        try { result = fractions[0] - fractions[1]; }

        catch (std::logic_error &err) { std::cerr << err.what() << "\n"; return 0; }

        break;
    }
    case '3':
        result = fractions[0] * fractions[1];

        break;
    case '4':
        result = fractions[0] / fractions[1];

        break;
    default:
        break;
    }

    result.reductFraction();

    std::cout << "Result = " << result << "\n";

    return 0;
}
