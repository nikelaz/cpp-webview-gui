#include "webview/webview.h"
#include <iostream>
#include "index_html.h"

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

    // add timestamp comment to the end of the file because webviews
    // cache aggressively
    main_window.set_html(INDEX_HTML);

    main_window.run();
  } catch (const webview::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}
