#include "app.hpp"
#include "id3_editor.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  App app;
  app.printMessage();
  std::cout << Id3Editor::Instance()->GetDuration("C:/Users/mathi/Downloads/file_example_MP3_700KB.mp3") << std::endl;
  return 0;
}