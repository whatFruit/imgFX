#include<iostream>
#include<fstream>
#include<string>
#include "rgbColor.hh"

class ppmEncoder
{
public:
	//constructor|deconstructors
	ppmEncoder(int _width, int _height, std::string _fileName, int _maxVal);
	ppmEncoder(int width, int height, std::string _fileName);
	ppmEncoder();
	~ppmEncoder();

	//main functionality
	bool isReady();
	int writePPM(imgBuffer& ppmData);
	imgBuffer blankBuffer(); //returns 'width'X'height' imgBuffer of rgbColor pixels

	//setters
	void setDimension(int _width, int _height);
	void setMaxVal(int _maxVal);
	void setFileName(std::string _fileName);

	//getters
	int getWidth();
	int getHeight();
	int getMaxVal();
	std::string getFileName();

private:
	int width;
	int height;
	std::string fileName;
	int maxVal;
};