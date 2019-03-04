#pragma once

#include <iostream>

namespace mutil
{
    template<class T>
    T getNum() {

        T number;

        while (!(std::cin>>number)) {

            std::cout << "Please enter a valid number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return number;
    }

    bool yesNoDialog()
    {
        char answer = 0;

        std::cout << "Y/N?" << std::endl;

        while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {

            std::cin >> answer;
        }

        if (answer == 'Y' || answer == 'y') return true;

        else return false;
    }
}

