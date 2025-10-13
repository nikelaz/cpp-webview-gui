#include "webview/webview.h"
#include <iostream>

const char index_html[] = {
    #embed "../ui/dist/index.html"
};

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE /*hInst*/, HINSTANCE /*hPrevInst*/,
                   LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
#else
int main() {
#endif
  try {
    webview::webview main_window(false, nullptr);
    main_window.set_title("Prompt Workbench");
    main_window.set_size(1280, 720, WEBVIEW_HINT_NONE);
    main_window.set_html(index_html);
    main_window.run();
  } catch (const webview::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}
