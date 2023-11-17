#include <fstream>
#include <string>

namespace teensy_serial {
class TeensySerial {
public:
  TeensySerial(std::string port_name);
  ~TeensySerial();
  void write(std::string data);
  std::string read();

private:
  std::fstream f;
};
}

inline teensy_serial::TeensySerial::TeensySerial(std::string port_name) {
  f.open(port_name.c_str());
}

inline teensy_serial::TeensySerial::~TeensySerial() { f.close(); }

inline void teensy_serial::TeensySerial::write(std::string data) { f << data; }

inline std::string teensy_serial::TeensySerial::read() {
  std::string output;
  f >> output;
  return output;
}