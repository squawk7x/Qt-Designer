#include "patternMaker.h"
#include <chrono>

PatternMaker::PatternMaker(int base)
{
    m_base = 5;
    m_Hu.resize(m_base - 1);
    m_Hl.resize(m_base - 1);
    m_Mu.resize(60 / m_base - 1);
    m_Ml.resize(m_base - 1);
    m_Su.resize(11);
    m_Sl.resize(60 / m_base - 1);
}

void PatternMaker::makePatterns()
{
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::tm* localTime = std::localtime(&currentTime);
    int Hu = localTime->tm_hour / m_base;
    int Hl = localTime->tm_hour % m_base;
    int Mu = localTime->tm_min / m_base;
    int Ml = localTime->tm_min % m_base;
    int Su = localTime->tm_sec / m_base;
    int Sl = localTime->tm_sec % m_base;

    // Clear each vector
    m_Hu.clear();
    m_Hl.clear();
    m_Mu.clear();
    m_Ml.clear();
    m_Su.clear();
    m_Sl.clear();

    // Populate vectors based on current time
    for (int k = 0; k < m_base - 1; k++) {
        m_Hu.push_back(Hu > k);
        m_Hl.push_back(Hl > k);
        m_Ml.push_back(Ml > k);
        m_Sl.push_back(Sl > k);
    }
    for (int k = 0; k < (60 / m_base) - 1; k++) {
        m_Mu.push_back(Mu > k);
        m_Su.push_back(Su > k);
    }
}
