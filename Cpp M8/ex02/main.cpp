# include "MutantStack.hpp"
# include <list>

int main()
{
    {
        std::cout << "Subject Test..." << std::endl;
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    
        std::stack<int> s(mstack);

        std::cout << "List Output Comparision" << std::endl;
        std::list<int> listtest;

        listtest.push_back(5);
        listtest.push_back(17);

        std::cout << listtest.back() << std::endl;
        listtest.pop_back();

        std::cout << listtest.size() << std::endl;
        listtest.push_back(3);
        listtest.push_back(5);
        listtest.push_back(737);
        listtest.push_back(0);

        std::list<int>::iterator it1 = listtest.begin();
        std::list<int>::iterator ite1 = listtest.end();       

        ++it1;
        --it1;

        while (it1 != ite1) {
            std::cout << *it1 << std::endl;
            ++it1;
        }

    }

    std::cout << "**************************" << std::endl;
    std::cout << "Testing Orthodox Canonical Form Of Mutant Stack" << std::endl;
    {
        MutantStack<int> mstack2;
        MutantStack<int> mstack4;
        for (int i = 0; i < 5; i++)
            mstack2.push(i);
        MutantStack<int> mstack3(mstack2);
        std::cout << "Mstack3: " << std::endl;
        for (MutantStack<int>::iterator it = mstack3.begin(); it != mstack3.end(); ++it)
            std::cout << *it << std::endl;
        mstack4 = mstack3;
        std::cout << "Mstack4: " << std::endl;
        for (MutantStack<int>::iterator it = mstack4.begin(); it != mstack4.end(); ++it)
            std::cout << *it << std::endl;
    }
    std::cout << "**************************" << std::endl;
    std::cout << "Testing Const Iterator" << std::endl;
    return 0;
}