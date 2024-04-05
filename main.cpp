#include <queue>
#include <string>
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2) {
        return 1;
    }
    size_t queueDefaultMaxSize = std::stoi(av[1]);
    std::queue<std::string> Q;
    int nestingLevel = 0;
    auto printAndPopAllCmds = [&Q] () {
        if (Q.size()) {
            std::cout << "bulk: ";
            while ( Q.size() ) {
                std::cout << Q.front();
                Q.pop();
                if (Q.size())  {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
    };
    for (std::string newLine; std::getline(std::cin, newLine);) {
        if (newLine == "{") {
            if (nestingLevel == 0) {
                printAndPopAllCmds();
            }
            nestingLevel++;
            continue;
        }
        if (newLine == "}") {
            nestingLevel--;
            if (nestingLevel == 0) {
                printAndPopAllCmds();    
            }
            continue;
        }
        Q.push(newLine);
        if (nestingLevel == 0  && Q.size() == queueDefaultMaxSize) {
            printAndPopAllCmds();
        }
    }
    return 0;
}