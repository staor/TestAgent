

#include <string>
#include <iostream>
#include <filesystem>
#include <cstdio>

namespace fs = std::filesystem;

/*==================== 主程序示例 ====================*/
int main(void)
{
    printf("================================4\n\n");
    //终端中输入 chcp 65001 来设置终端使用 UTF-8 编码 来正确显示中文
    // printf("__STDC_VERSION__:%ld\n", __STDC_VERSION__);
    printf("__cplusplus:%ld\n", __cplusplus);

#ifdef _WIN32
  std::cout << "Windows系统\n";
#elif __linux__
  std::cout << "Linux系统\n";
#elif __APPLE__
  std::cout << "macOS系统\n";
#endif

  // 文件路径处理示例
#ifdef _WIN32
  const char* data_path = "C:\\data\\config.txt";
#else
  const char* data_path = "/usr/local/data/config.txt";
#endif
    printf("data_path:%s\n",data_path);


  std::string s = "Hello, World!";


  fs::path config_path = fs::current_path() / "config" / "settings.ini";
  std::cout << "配置文件路径: " << config_path << std::endl;

  printf("\n================================\n\n");
    return 0;
}
