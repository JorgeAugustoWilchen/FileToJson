#include "pdf/frompdf.hpp"
#include "image/fromimage.hpp"
#include "excel/fromexcel.hpp"

class FileToJson
{
    public:
        FileToJson();
        ~FileToJson();
        std::string convert(std::string filename);

    private:
        std::string filename;
        std::string filetype;
        FromPDF *pdf;
        FromImage *image;
        FromExcel *excel;
        void detectFileType();
        void convertToJson();
};