#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdexcept>  // For std::runtime_error

namespace fs = std::filesystem;

using namespace std;

class VideoPlayer_exception : public runtime_error {
public:
    explicit VideoPlayer_exception(const string& msg) : runtime_error(msg) {}
};

class VideoPlayer {
private:
    string filename;
    ifstream file;
public:
    explicit VideoPlayer(const string& filename);
    void Play();
};

VideoPlayer::VideoPlayer(const string& filename) {
    this->filename = filename;
    if (!fs::exists(filename)) {
        throw VideoPlayer_exception("Error: File does not exist.");
    }
    file.open(filename);
    if (!file.is_open()) {
        throw VideoPlayer_exception("Error: Unable to open file.");
    }
}

void VideoPlayer::Play() {
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

int main() {
    string filename = "./me.txt";

    try {
        VideoPlayer vp(filename);
        vp.Play();
    } catch (const VideoPlayer_exception& e) {
        cout << e.what() << endl;
    } catch (const exception& e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}
