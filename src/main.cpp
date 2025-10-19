#include <iostream>
#include <nlohmann/json.hpp>
#include "webview/webview.h"
#include "index_html.h"

using json = nlohmann::json;

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

        main_window.bind("ping", [&](const std::string& args_str) -> std::string { 
            json args = json::parse(args_str);
            
            std::cout << "Ping from UI: " << args[0] << std::endl;

            json result = {{"code", 200}};
            return result.dump();
        });

        main_window.set_html(INDEX_HTML);
        main_window.run();
    } catch (const webview::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
