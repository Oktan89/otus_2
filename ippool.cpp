#include "ippool.h"
#include <iostream>
#include <utility>


IpPool::IpPool(const std::vector<std::vector<std::string>> & ippool)
{
    std::copy(ippool.begin(), ippool.end(), std::back_inserter(_ippool));
}

const std::vector<std::vector<std::string>>& IpPool::reverseLexicographicallySort()
{
    std::sort(_ippool.begin(), _ippool.end(), [](const std::vector<std::string> &ip1, const std::vector<std::string> &ip2)
            {
                for (auto ip_one = ip1.cbegin(), ip_two = ip2.cbegin(); ip_one != ip1.cend() && ip_two != ip2.cend(); ++ip_one, ++ip_two)
                {
                    if (ip_one->size() > ip_two->size())
                        return true;
                    else if (ip_one->size() < ip_two->size())
                        return false;
                    else
                    {
                        for (auto s = ip_one->cbegin(), st = ip_two->cbegin(); s != ip_one->cend() && st != ip_two->cend(); ++s, ++st)
                        {
                            if (*s > *st)
                                return true;
                            else if (*s < *st)
                                return false;
                            }
                        }
                    }

                return false; 
            });
   
    return _ippool;
}

std::pair<bool, std::vector<std::string>> IpPool::filter(int octet) const
{
    std::string oct = std::to_string(octet);
    std::vector<std::string> pool;  
/*     auto eq = std::lower_bound(_ippool.cbegin(), _ippool.cend(), oct);
    for(auto i = eq.first; i != eq.second; ++i )
    {
        std::string ip;
        for(auto j = i->cbegin(); j != i->cend(); ++j)
        {
            if (j != i->cbegin())
            {
                ip+= ".";
            }
            ip+= *j;
        }
        pool.push_back(ip);
    } */
    return std::make_pair(true, pool);
}

std::vector<std::string> IpPool::split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void IpPool::getLineIpPoll()
{
    for (std::string line; std::getline(std::cin, line);)
        {
            if (line == "" || line == "end")
                break;
            std::vector<std::string> v = split(line, '\t');
            _ippool.push_back(split(v.at(0), '.'));
        }
}

void PrintPool::show(const std::vector<std::vector<std::string>> &pool) const
{
    for (auto ip = pool.cbegin(); ip != pool.cend(); ++ip)
    {
        for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

void PrintPool::show(const std::vector<std::string> &pool) const
{
    for(const auto &s: pool)
        std::cout << s << std::endl;
}