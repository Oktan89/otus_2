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

    std::pair<bool, std::vector<std::string>> filter(int octet_1, int octet_2 = -1) const;

    std::pair<bool, std::vector<std::vector<std::string>>> filter_any(int octet) const;

    void getLineIpPoll();



private:
    std::vector<std::string> split(const std::string &str, char d);
    std::vector<std::string> split(std::vector<std::vector<std::string>>::const_iterator found_first,
                                std::vector<std::vector<std::string>>::const_iterator found_last) const ;

};

struct PrintPool
{
    void show(const std::vector<std::vector<std::string>> &pool) const;
    void show(const std::vector<std::string> &pool) const;
};

template<class ForwardIt, class T>
std::pair<ForwardIt,ForwardIt> 
    myequal_range(ForwardIt first, ForwardIt last, const T& value, int index)
{
    return std::make_pair(std::lower_bound(first, last, value, [index](const std::vector<std::string> &ip, const std::string &o)
    {
        return std::stoi(ip.at(index)) > std::stoi(o);
    }), std::upper_bound(first, last, value, [index](const std::string &o, const std::vector<std::string> &ip)
    {
        return std::stoi(ip.at(index)) < std::stoi(o);
    }));
}