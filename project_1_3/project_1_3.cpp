#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========
  std::cout << "x: {" ;
  for (int i = 0; i < x.size(); i++) {
    if (i == x.size() - 1) {
      std::cout << x[i];
    } else {
      std::cout << x[i] << ", ";
    }
  }
  std::cout << "}" << std::endl;

  std::cout << "w: {" ;
  for (int i = 0; i < w.size(); i++) {
    if (i == w.size() - 1) {
      std::cout << w[i];
    } else {
      std::cout << w[i] << ", ";
    }
  }
  std::cout << "}" << std::endl;

  int packing_size = (w.size() - 1) / 2;      // The packing size is how far the first element of w is away from the center of w, which the kernel is focused on.
  // std::cout << "y: {" ;
  for (int i = 0; i < x.size(); i++) {
    double sum = 0;
    for (int j = 0; j < w.size(); j++) {
      if (!pack_with_zeros && i - packing_size + j < 0) {
        sum += x[0] * w[j];
      } else if (!pack_with_zeros && i - packing_size + j >= x.size()) {
        sum += x[x.size() - 1] * w[j];
      } else {
        sum += x[i - packing_size + j] * w[j];
      }
    }
    y.push_back(sum);
    if (i == x.size() - 1) {
      std::cout << y[i];
    } else {
      std::cout << y[i] << ", ";
    }
    
  }
  std::cout.flush();
  std::cout << "}" << std::endl;
  // =========== END ===========

  return 0;
}

