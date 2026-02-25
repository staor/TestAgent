

#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

/*==================== 主程序示例 ====================*/
int main(void)
{
    printf("================================1\n\n");

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




  fs::path config_path = fs::current_path() / "config" / "settings.ini";
  std::cout << "配置文件路径: " << config_path << std::endl;

  printf("\n================================\n\n");
    return 0;
}
