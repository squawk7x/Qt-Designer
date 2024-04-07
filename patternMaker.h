#ifndef PATTERNMAKER_H
#define PATTERNMAKER_H

#include <vector>

class PatternMaker
{
private:
    int m_base = 5;

public:
    std::vector<bool> m_Hu; // pattern of upper hour indicator
    std::vector<bool> m_Hl; // pattern of lower hour indicator
    std::vector<bool> m_Mu;
    std::vector<bool> m_Ml;
    std::vector<bool> m_Su;
    std::vector<bool> m_Sl;

public:
    PatternMaker(int base);

    void makePatterns();
};

#endif // PATTERNMAKER_H
