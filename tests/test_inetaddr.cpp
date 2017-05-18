
#include <gtest/gtest.h>
#include <InetAddress.h>
#include <Status.h>
#include <Logger.h>

using namespace net;

TEST(test_addr, test_addr)
{
  Status status;
  InetAddress addr4 = InetAddress::get_by_address("127.0.0.1", AF_INET, status);
  LOG_INFO("ip = %s", addr4.to_string().c_str());
  ASSERT_TRUE(addr4 == addr4);
  ASSERT_TRUE(addr4.family() == AF_INET);
  ASSERT_TRUE(addr4.v4());

  InetAddress addr5 = InetAddress::get_by_address("10.12.23.1", AF_INET, status);
  ASSERT_FALSE(addr4 == addr5);
  ASSERT_TRUE(addr4 != addr5);

  ASSERT_TRUE(addr4.v4());
  InetAddress addr6 = InetAddress::get_by_address("0:0:0:0:0:FFFF:204.152.189.116", AF_INET6, status);
  ASSERT_TRUE(addr6.v6());
  LOG_INFO("ip = %s", addr6.to_string().c_str());

  InetAddress::get_by_address("1279.0.0.1", AF_INET, status);
  ASSERT_TRUE(!status.is_ok());

  InetAddress addr = InetAddress::any(AF_INET);
  ASSERT_TRUE(addr.family() == AF_INET);
  addr = InetAddress::any(AF_INET6);
  ASSERT_TRUE(addr.family() == AF_INET6);
}

TEST(test_resolve, test_addr)
{

  Status status = Status::invalid_argument("aaa");
  InetAddress a = InetAddress::get_by_host("www.baidu.com", status);
  ASSERT_TRUE(status.is_ok());
  LOG_INFO("ip = %s", a.to_string().c_str());

  InetAddress::get_by_host("localhost", status);
  ASSERT_TRUE(status.is_ok());

  InetAddress::get_by_host("www.baidu.comppDDDp", status);
  ASSERT_TRUE(!status.is_ok());

}




int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}