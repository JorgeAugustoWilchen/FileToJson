#include "frompdf.hpp"
#include "fromimage.hpp"
#include "fromexcel.hpp"

class FileToJson
{
    public:
        FileToJson();
        ~FileToJson();
        std::string convert(std::string filename);

    private:
        FromPDF *pdf;
        FromImage *image;
        FromExcel *excel;

        enum FileType
        {
            PDF,
            IMAGE,
            EXCEL,
            UNKNOWN
        };
};