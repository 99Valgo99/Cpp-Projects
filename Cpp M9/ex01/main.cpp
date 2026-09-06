# include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::string exp = argv[1];
    if (!RPN::expressionNature(exp)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    int operandCount = 0;
    int operatorCount = 0;
    std::string opExp;
    std::istringstream stream(exp);
    std::stack<double> stack;

    while (stream >> opExp) {
        if (opExp.length() == 1 && std::isdigit(opExp[0])) {
            operandCount++;
            stack.push(RPN::convertReturn(opExp));
        } else if (opExp.length() == 1 && RPN::operatorNature(opExp[0])) {
            operatorCount++;
            if (stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            double y = stack.top(); stack.pop();
            double x = stack.top(); stack.pop();
            double result = RPN::applyOps(x, y, opExp[0]);
            if (std::isinf(result) || std::isnan(result)) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            stack.push(result);
        } else {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    if (operatorCount != operandCount - 1 || stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << stack.top() << std::endl;
    return 0;
}