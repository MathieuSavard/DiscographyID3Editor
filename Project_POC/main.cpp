#include "app.hpp"
//#include "file_system/boost/boost_file_system.hpp"
#include "taglib_id3_editor.hpp"

int main(int argc, char* argv[]) {
  Application application(NULL, NULL);
  return application.Start();
}