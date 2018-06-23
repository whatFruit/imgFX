#include <vector>

struct rgbColor{
	int r;
	int g;
	int b;

	rgbColor(): r(0),g(0),b(0){};
	rgbColor(int _r, int _g, int _b): r(_r), g(_g), b(_b){};
};

//matrix of pixels
typedef std::vector<rgbColor> imgBufferCols;
typedef std::vector<std::vector<rgbColor> > imgBuffer;