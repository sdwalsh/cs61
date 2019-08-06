#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main (int ac, char *av[]) {
    std::vector<std::string> words(av + 1, av + ac);
    std::sort(words.begin(), words.end(), [] (std::string const a, std::string const b) { return a < b;});

    for (std::vector<std::string>::const_iterator i = words.begin(); i != words.end(); ++i)
        std::cout << *i << "\n";
    return 1;
}