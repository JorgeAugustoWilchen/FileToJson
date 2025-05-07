#include "frompdf.hpp"

FromPDF::FromPDF(const std::string &filePath)
{
    pdfPath = filePath;
    outputJsonPath = filePath.substr(0, filePath.find_last_of('.')) + ".json";
}

FromPDF::~FromPDF()
{
}

bool FromPDF::convertToJson()
{
    poppler::document *doc = poppler::document::load_from_file(pdfPath);
    if (!doc) {
        std::cerr << "Erro ao carregar o PDF: " << pdfPath << std::endl;
        return false;
    }

    json j;

    for (int i = 0; i < doc->pages(); ++i) {
        poppler::page *page = doc->create_page(i);
        if (page) {
            std::string text = page->text().to_utf8();
            j["pages"][i]["text"] = text;
        }
    }

    std::ofstream out(outputJsonPath);
    if (!out) {
        std::cerr << "Erro ao criar arquivo JSON: " << outputJsonPath << std::endl;
        return false;
    }

    out << j.dump(4);
    std::cout << "Arquivo JSON criado com sucesso: " << outputJsonPath << std::endl;
    return true;
}