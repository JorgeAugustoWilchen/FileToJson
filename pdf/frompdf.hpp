#include <string>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>


using json = nlohmann::json;

class FromPDF {
    public:
        FromPDF(const std::string& filePath);
        ~FromPDF();

        bool convertToJson();

    private:
        std::string pdfPath;
        std::string outputJsonPath;
};