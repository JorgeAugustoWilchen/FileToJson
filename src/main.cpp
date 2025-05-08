#include "main.hpp"


FileToJson::FileToJson() {
    pdf = new FromPDF();
    image = new FromImage();
    excel = new FromExcel();
}

FileToJson::~FileToJson()
{
}

std::string FileToJson::convert(std::string filename)
{
    std::string extension = filename.substr(filename.find_last_of(".") + 1);
    if (extension == "pdf") {
        return pdf->convertToJson(filename);

    } else if (extension == "jpg" || extension == "png") {
        return image->convertToJson(filename);
        
    } else if (extension == "xls" || extension == "xlsx") {
        return excel->convertToJson(filename);

    } else {
        return std::string("Error: Unsupported file type");
    }
}

int main () {
    FileToJson fj;

    std::cout 
    << "File to JSON Converter:" 
    << fj.convert("/home/endplay/Documents/Jorge_Augusto_Wilchen_Eng.pdf") 
    << std::endl;
    
    return 0;
};