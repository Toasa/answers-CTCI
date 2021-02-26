#include <iostream>
#include <fstream>

void printLastKLines(std::ifstream &file, int K) {
    // circular array
    std::string *lines = (std::string *)calloc(1, sizeof(std::string *) * K);
    int i = 0;

    std::string line;
    while (getline(file, line)){
        lines[i] = line;
        i++;
        i %= K;
    }

    int j = i;
    while (1) {
        std::cout << lines[j] << std::endl;
        j = (j+1)%K;
        if (i == j)
            break;
    }
}

int main() {
    std::string filename("./sample.txt");
    std::ifstream file(filename);

    printLastKLines(file, 5);
}
