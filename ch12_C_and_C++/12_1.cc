#include <iostream>
#include <fstream>

void printLastKLines(std::ifstream &file, int K) {
    std::stack<std::string> lines;

    std::string line;
    while (getline(file, line)){
        lines.push(line);
    }

    for (int i = 0; i < K; i++) {
        std::cout << lines.top() << std::endl;
        lines.pop();
    }
}

int main() {
    std::string filename("./sample.txt");
    std::ifstream file(filename);

    printLastKLines(file, 5);
}
