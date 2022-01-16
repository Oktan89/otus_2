#pragma once
#include <string>
#include <vector>
#include <algorithm>

class IpPool
{
    std::vector<std::vector<std::string>> _ippool;

public:

    IpPool() = default;

    explicit IpPool(const std::vector<std::vector<std::string>> &ippool);
    
    const std::vector<std::vector<std::string>>& reverseLexicographicallySort();

    std::pair<bool, std::vector<std::string>> filter(int octet) const;

    void getLineIpPoll();



private:
    std::vector<std::string> split(const std::string &str, char d);
    //ToDO
    //поиск по вервому октету и т.д.

};

struct PrintPool
{
    void show(const std::vector<std::vector<std::string>> &pool) const;
    void show(const std::vector<std::string> &pool) const;
};