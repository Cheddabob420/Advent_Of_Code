#include <cstdio>
#include <cstring>
#include <openssl/md5.h>
#include <string>

int main() {
  int exitFlag = 0;
  std::string key = "yzbqklnj";
  // int number = 609043;
  for (int number = 1; number > 0; number++) {
    std::string input = key + std::to_string(number);

    unsigned char hash[MD5_DIGEST_LENGTH];

    MD5((const unsigned char *)input.c_str(), input.size(), hash);

    // printf("%s: ", input.c_str());

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
      // printf("%02x", hash[i]);
      if (hash[0] == 0 && hash[1] == 0 && hash[2] < 16) {
        printf("%d", number);
        exitFlag = 1;
        break;
      }
    if (exitFlag == 1) {
      break;
    }
    // printf("\n");
  }
  return 0;
}
