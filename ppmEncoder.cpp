#include "ppmEncoder.hh"

//corrected file output for rgbColor (just 3 RGB ints) struct.
std::ofstream& operator<<(std::ofstream& outFileStream, rgbColor rgbCol){
	outFileStream 	<< rgbCol.r << " "
					<< rgbCol.g << " "
					<< rgbCol.b << " ";
	return outFileStream;
}

ppmEncoder::ppmEncoder(int _width, int _height, std::string _fileName, int _maxVal)
	:width(_width),height(_height),fileName(_fileName), maxVal(_maxVal){}

ppmEncoder::ppmEncoder(int _width, int _height, std::string _fileName)
	:width(_width),height(_height),fileName(_fileName), maxVal(255){}

ppmEncoder::ppmEncoder(){}

ppmEncoder::~ppmEncoder(){}

int ppmEncoder::writePPM(imgBuffer& ppmData){
	if(!isReady()){
		std::cout << "Failed: width, heiht, fileName, and maxVal must be defined" << std::endl;
		return -1;
	}
	if(ppmData.size() != height || ppmData[0].size() != width){
		std::cout << "Failed: Wrong amount of data passed" << std::endl;
		return -1;
	}


	//open out file stream
	std::ofstream outFile;
	outFile.open(fileName + ".PPM",std::ofstream::out);

	//header data
	outFile 	<< "P3\n" 
				<< width << " " << height << "\n" 
				<< maxVal << "\n ";

	//output pixel data
	for(auto &row: ppmData){
		for(auto &pixel: row){
			outFile<<pixel << "\n ";
		}
	}

	outFile.flush();
	return 1;
}

bool ppmEncoder::isReady(){
	return (width != 0) && (height!= 0) && (maxVal!= 0) && (fileName.size() != 0);
}

imgBuffer ppmEncoder::blankBuffer(){

	if(width == 0 || height == 0){
		std::cout << "Failed: Width and/or Height not set (is 0)" << std::endl;
	}

	//make 'width' pixels
	imgBufferCols newImgBufferCol(width, rgbColor());
	//make 'height' rows, each a column of 'width' pixels;
	imgBuffer newImgBuffer(height,newImgBufferCol);

	return newImgBuffer;

}

void ppmEncoder::setDimension(int _width, int _height){
	width = _width;
	height = _height;
}

void ppmEncoder::setMaxVal(int _maxVal){
	maxVal = _maxVal;
}