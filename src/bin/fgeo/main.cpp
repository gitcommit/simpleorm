#include <iostream>

#include <fgeodatabase.hpp>

int main(int argc, char** argv) {
    FGeoDatabase db("db");
    std::cout << db << std::endl;
  return 0;
}
