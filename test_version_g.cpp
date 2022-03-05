#include "lib.h"
#include "ippool.h"
#include <gtest/gtest.h>

std::vector<std::vector<std::string>> initPoolIp();

std::vector<std::vector<std::string>> initReversSortPoolIp();

std::vector<std::string> initPoolIp1Octet1();

std::vector<std::string> initPoolIpfilterTwoOctet46and70();

std::vector<std::vector<std::string>> initPoolIpfilterAny46();

TEST(testVersionGoogle, testValidVersion) {

  EXPECT_GT(version(), 0);
}

TEST(ipPoolTests, reverseLexicographicallySortInIpool){
  
    IpPool testpool(initPoolIp());

    EXPECT_TRUE(initReversSortPoolIp() == testpool.reverseLexicographicallySort()) << "IpoolIp not sorted";
}

TEST(ipPoolTests, filterOneOctetIN1){
  
    IpPool testpool(initPoolIp());
    
    EXPECT_TRUE(initReversSortPoolIp() == testpool.reverseLexicographicallySort()) << "IpoolIp not sorted";

    EXPECT_TRUE(initPoolIp1Octet1() == testpool.filter(1).second) << "Filter for octet 1 not work";
}

TEST(ipPoolTests, filterTwoOctetIN46and70)
{
    IpPool testpool(initPoolIp());
    
    EXPECT_TRUE(initReversSortPoolIp() == testpool.reverseLexicographicallySort()) << "IpoolIp not sorted";

    EXPECT_TRUE(initPoolIpfilterTwoOctet46and70() == testpool.filter(46, 70).second) << "Filter for two octet 46 and 70 not work";

}

TEST(ipPoolTests, filterAny46)
{
    IpPool testpool(initPoolIp());
    
    EXPECT_TRUE(initReversSortPoolIp() == testpool.reverseLexicographicallySort()) << "IpoolIp not sorted";

    EXPECT_TRUE(initPoolIpfilterAny46()==testpool.filter_any(46).second) << "Filter for any octet 46 not work";
}

std::vector<std::vector<std::string>> initPoolIp()
{
  std::vector<std::vector<std::string>> ippool
  {
      {"222", "173", "235", "246"},
      {"1", "29", "168", "152"}, 
      {"222", "82", "198", "61"}, 
      {"46", "70", "29", "76"}, 
      {"222", "130", "177", "64"}, 
      {"1", "70", "44", "170"}, 
      {"46", "70", "147", "26"}, 
      {"1", "1", "234", "8"}, 
      {"46", "70", "225", "39"}, 
      {"46", "70", "113", "73"}, 
      {"5", "189", "203", "46"}, 
      {"39", "46", "86", "85"}
  };
  return ippool;
}

std::vector<std::vector<std::string>> initReversSortPoolIp()
{
  std::vector<std::vector<std::string>> ippool
  {
      
      {"222", "173", "235", "246"},
      {"222", "130", "177", "64"}, 
      {"222", "82", "198", "61"}, 
      {"46", "70", "225", "39"}, 
      {"46", "70", "147", "26"}, 
      {"46", "70", "113", "73"}, 
      {"46", "70", "29", "76"},
      {"39", "46", "86", "85"},
      {"5", "189", "203", "46"}, 
      {"1", "70", "44", "170"}, 
      {"1", "29", "168", "152"},
      {"1", "1", "234", "8"}, 
  };
  return ippool;
}

std::vector<std::string> initPoolIp1Octet1()
{
  std::vector<std::string> ippool
  {
      {"1.70.44.170"}, 
      {"1.29.168.152"},
      {"1.1.234.8"} 
  };
  return ippool;
}

std::vector<std::string> initPoolIpfilterTwoOctet46and70()
{
  std::vector<std::string> ippool
  {
      {"46.70.225.39"}, 
      {"46.70.147.26"}, 
      {"46.70.113.73"}, 
      {"46.70.29.76"}
  };
  return ippool;
}

std::vector<std::vector<std::string>> initPoolIpfilterAny46()
{
  std::vector<std::vector<std::string>> ippool
  {
      {"46", "70", "225", "39"}, 
      {"46", "70", "147", "26"}, 
      {"46", "70", "113", "73"}, 
      {"46", "70", "29", "76"},
      {"39", "46", "86", "85"},
      {"5", "189", "203", "46"}
  };
  return ippool;
}