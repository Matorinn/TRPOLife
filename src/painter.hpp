#pragma once
#include "string"
#include "map"

class Painter {
public:
  std::map<std::string,int> color{ {"red", 0}, {"white", 1}, {"magenta", 2}, {"dark_blue", 3}, {"green", 4}, {"brown", 5}, {"cyan", 6}, {"black", 7}};
    void rect(int x1, int y1, int x2, int y2);
    void setColor(int col);
    static std::string active;
};
